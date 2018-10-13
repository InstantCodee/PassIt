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

        public CreateController     createController;

        /**
         * Constructs a new {@code AppView} object.
         */
        public AppView (Gtk.Application application) {
            // Welcome Granite view
            var welcome_view = new Granite.Widgets.Welcome (_("Welcome"), _("Create or import an password container"));
            welcome_view.append ("list-add", _("Create Container"), _("Create a new container"));
            welcome_view.append ("document-import-rtl", _("Import Container"), _("Import your exisiting cointainer"));
            welcome_view.activated.connect ((index) => {
                switch (index) {
                    case 0:
                        try {
                            this.createController = new CreateController (application);
                            this.createController.activate ();
                        } catch (Error e) {
                            warning (e.message);
                        }

                        break;
                    case 1:
                        try {

                        } catch (Error e) {
                            warning (e.message);
                        }

                        break;
                }
            });

            // Add Welcome view to the window
            this.add (welcome_view);
        }
    }
}
