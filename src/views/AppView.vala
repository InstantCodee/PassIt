/*
* Copyright (C) 2018  Mondei1 <klier.nicolas@gmx.de>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

using App.Configs;
using App.Widgets;
using App.Views;
using App.Controllers;

/**
 * Code inspiration from 'Archetype' by kjlaw89. Class: https://github.com/kjlaw89/archetype/blob/master/src/views/AppView.vala
 */
namespace App.Views {

    /**
     * The {@code AppView} class.
     *
     * @since 1.0.0
     */
    public class AppView : Gtk.Box {

        public Gtk.Box              box_buttons;
        public Gtk.Box              box_action_buttons;

        private Gtk.Button          button_next;
        private Gtk.Button          button_back;
        private Gtk.Button          button_done;

        private Gtk.Entry           entry_password;
        private Gtk.Entry           entry_reminder;

        private Gtk.Label           label_enter_password;
        private Gtk.Label           label_password_description;
        private Gtk.Label           label_enter_reminder;
        private Gtk.Label           label_reminder_description;
        private Gtk.Label           label_headline_done;
        private Gtk.Label           label_done;

        private Gtk.Image           image_password; // dialog-password
        private Gtk.Image           image_reminder; // dialog-information

        private Gtk.Stack           stack;

        private string _stage;
        public string stage {
            get { return _stage; }
            private set {
                stack.visible_child_name = value;   // Change active view
                _stage = value;
            }
        }
        public string DATA_DIR = (Environment.get_user_data_dir() + "/passit/");

        /**
         * Constructs a new {@code AppView} object.
         */
        public AppView () {
            stack = new Gtk.Stack ();
            stack.set_transition_type (Gtk.StackTransitionType.SLIDE_LEFT_RIGHT);
            stack.set_transition_duration (200);
            stack.vhomogeneous = true;

            // Welcome Granite view
            var welcome_view = new Granite.Widgets.Welcome (_("Welcome"), _("Create or import an password container"));
            welcome_view.append ("list-add", _("Create Container"), _("Create a new container"));
            welcome_view.append ("document-import-rtl", _("Import Container"), _("Import your exisiting cointainer"));
            welcome_view.activated.connect ((index) => {
                switch (index) {
                    case 0:
                        next ();
                        orientation = Gtk.Orientation.VERTICAL;
                        get_style_context ().add_class (Gtk.STYLE_CLASS_FLAT);
                        box_buttons.show ();
                        break;
                    case 1:
                        orientation = Gtk.Orientation.VERTICAL;
                        get_style_context ().add_class (Gtk.STYLE_CLASS_FLAT);
                        box_buttons.show ();
                        break;
                }
            });

            // Add Welcome view to the window
            stack.add_named (welcome_view, "welcome");

            // Add views to stack.
            form_create_container ();
            form_done ();

            // Back button
            button_back = new Gtk.Button.with_mnemonic (_("Back"));
            button_back.halign = Gtk.Align.END;
            button_back.clicked.connect (() => {
                back ();
            });

            // Next button
            button_next = new Gtk.Button.with_mnemonic (_("Next"));
            button_next.get_style_context ().add_class ("suggested-action");
            button_next.halign = Gtk.Align.END;
            button_next.clicked.connect (() => {
                next ();
            });

            // Done button
            button_done = new Gtk.Button.with_mnemonic (_("Done"));
            button_done.get_style_context ().add_class ("suggested-action");
            button_done.halign = Gtk.Align.END;
            button_done.clicked.connect (() => {
                next ();
            });
            button_done.sensitive = false;

            // Action button box
            box_action_buttons = new Gtk.Box (Gtk.Orientation.HORIZONTAL, 16);
            box_action_buttons.halign = Gtk.Align.END;
            box_action_buttons.add (button_back);
            //box_action_buttons.add (button_next); We don't have currently two or more steps, so we don't need that yet.
            box_action_buttons.add (button_done);

            // Button box
            box_buttons = new Gtk.Box (Gtk.Orientation.HORIZONTAL, 0);
            box_buttons.halign = Gtk.Align.END;
            box_buttons.margin = 15;
            box_buttons.add (box_action_buttons);

            this.add (stack);
            this.add (box_buttons);

            stage = "welcome";
        }

        public void next () {
            switch (stage) {
                case "welcome":
                    stage = "create";
                    print ("Here!");

                    button_done.clicked.connect (() => {
                        // Spawn system command
                        print ("Spawnn: " + "echo \"" + entry_password.get_text () + "\" > " + DATA_DIR + "test.txt\n");
                        Process.spawn_command_line_sync ("echo \"" + entry_password.get_text () + "\" > " + DATA_DIR + "test.txt");
                    });
                    break;
                case "create":
                    // Currently empty. Just in case we want to add new views later. Eg.: for selecting different types of authentication.
                    stage = "done";
                    button_done.hide ();
                    break;
            }
        }

        public void back () {
            switch (stage) {
                case "create":
                    stage = "welcome";
                    box_buttons.hide ();
                    break;
                case "done":
                    stage = "create";
                    button_done.show ();
                    break;
            }
        }

        private void can_next () {
            button_done.sensitive = false;
            switch (stage) {
                case "create":
                    if (entry_password.get_text () == "") {
                        entry_password.get_style_context ().remove_class ("wrong_input");
                        return;
                    }
                    try {
                        Regex password_regex = new Regex ("[^a-zA-Z0-9ä-ü]");  // Regex how a password should not be. (min: 7 normal chars and 1 special char)
                        if (!password_regex.match (entry_password.get_text ()) || entry_password.get_text ().len () < 12) {
                            // If the password not only contains aA-zZ and 0-9
                            entry_password.get_style_context ().add_class ("wrong_input");
                            button_done.sensitive = false;
                        } else {
                            // If the password matches the minimums.
                            entry_password.get_style_context ().remove_class ("wrong_input");
                            button_done.sensitive = true;
                        }
                    } catch (RegexError e) {
                        entry_password.get_style_context ().add_class ("wrong_input");
                    }
                    break;
            }
        }

        private void form_create_container () {
            Gtk.Grid grid = new Gtk.Grid ();
            grid.expand = true;
            grid.column_spacing = 12;
            grid.row_spacing = 12;
            grid.margin = 30;

            //=============
            // Password
            //=============
            image_password = new Gtk.Image.from_icon_name ("dialog-password", Gtk.IconSize.DIALOG);

            label_enter_password = new Gtk.Label ("<b>" + _("Choose your password wisely") + "</b>");
            label_enter_password.set_use_markup (true);
            label_enter_password.halign = Gtk.Align.START;

            label_password_description = new Gtk.Label (_("You have to rememeber that password. If you lose it, you lose access to your password's. ")
                + " <a href=\"https://www.wikihow.com/Create-a-Password-You-Can-Remember\">" + _("How to password") + "</a>.");
            label_password_description.set_use_markup (true);
            label_password_description.halign = Gtk.Align.START;

            entry_password = new Gtk.Entry ();
            entry_password.hexpand = true;
            entry_password.set_visibility (false);
            entry_password.placeholder_text = _("11 normal chars and 1 special char are minimum");
            entry_password.key_release_event.connect(() => {
                can_next ();
                return false;
            });

            //=============
            // Reminder
            //=============
            image_reminder = new Gtk.Image.from_icon_name ("dialog-information", Gtk.IconSize.DIALOG);

            label_enter_reminder = new Gtk.Label ("<b>" + _("Reminder are important") + "</b>");
            label_enter_reminder.set_use_markup (true);
            label_enter_reminder.halign = Gtk.Align.START;

            label_reminder_description = new Gtk.Label (_("This text get shown If you forgot your password to help reminding you. But do not say too much."));
            label_reminder_description.set_use_markup (true);
            label_reminder_description.halign = Gtk.Align.START;

            entry_reminder = new Gtk.Entry ();
            entry_reminder.hexpand = true;
            entry_reminder.placeholder_text = _("Something that is in the right drawer with the green color.");

            // Password
            grid.attach (image_password, -1, 2, 3, 4);
            grid.attach (label_enter_password, 2, 2, 1, 1);
            grid.attach (label_password_description, 2, 2, 1, 6);
            grid.attach (entry_password, 2, 2, 1, 12);

            // Reminder
            grid.attach (image_reminder, -1, 2, 3, 23);
            grid.attach (label_enter_reminder, 2, 2, 1, 20);
            grid.attach (label_reminder_description, 2, 2, 1, 25);
            grid.attach (entry_reminder, 2, 2, 1, 31);

            stack.add_named (grid, "create");
        }

        private void form_done () {
            Gtk.Box box = new Gtk.Box (Gtk.Orientation.VERTICAL, 0);
            box.halign = Gtk.Align.CENTER;
            box.valign = Gtk.Align.CENTER;

            label_headline_done = new Gtk.Label ("<b>" + _("Congratulation!") + "</b>");
            label_headline_done.set_use_markup (true);
            label_done = new Gtk.Label (_("I just created your new container."));

            box.add (label_headline_done);
            box.add (label_done);

            stack.add_named (box, "done");
        }
    }
}
