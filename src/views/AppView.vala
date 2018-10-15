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

namespace App.Views {

    /**
     * The {@code AppView} class.
     *
     * @since 1.0.0
     */
    public class AppView : Gtk.Box {

        private AppController controller;

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

        /**
         * Constructs a new {@code AppView} object.
         */
        public AppView (AppController controller) {
            this.controller = controller;

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
                        stage = "create";
                        orientation = Gtk.Orientation.VERTICAL;
                        get_style_context ().add_class (Gtk.STYLE_CLASS_FLAT);
                        box_buttons.show ();
                        break;
                    case 1:
                        stage = "import";
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

            // Action button box
            box_action_buttons = new Gtk.Box (Gtk.Orientation.HORIZONTAL, 16);
            box_action_buttons.halign = Gtk.Align.END;
            box_action_buttons.add (button_back);
            //box_action_buttons.add (button_next); We don't have currently two or more steps, so we don't need that yet.
            box_action_buttons.add (button_done);

            // Button box
            box_buttons = new Gtk.Box (Gtk.Orientation.HORIZONTAL, 0);
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
                    break;
                case "create":
                    // Currently empty. Just in case we want to add new views later. Eg.: for selecting different types of authentication.
                    stage = "welcome";
                    break;
                case "import":
                    // Currently empty. Just in case we want to add new views later.
                    break;
            }
        }

        public void back () {
            switch (stage) {
                case "create":
                    stage = "welcome";
                    box_buttons.hide ();
                    break;
            }
        }

        private void form_create_container () {
            controller.window.set_default_size (800, 240);

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

            label_password_description = new Gtk.Label (_("You have to rememeber that password. If you lose it, you lose access to your password's.")
                + " <a href=\"https://www.wikihow.com/Create-a-Password-You-Can-Remember\">" + _("How to password") + "</a>");
            label_password_description.set_use_markup (true);
            label_password_description.halign = Gtk.Align.START;

            entry_password = new Gtk.Entry ();
            entry_password.hexpand = true;
            entry_password.set_visibility (false);
            entry_password.placeholder_text = _("Use a random password you never used before!");

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
            entry_reminder.placeholder_text = _("Something that is in the right drawer with the color green.");

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
            Gtk.Grid grid = new Gtk.Grid ();
            stack.add_named (grid, "done");
        }
    }
}
