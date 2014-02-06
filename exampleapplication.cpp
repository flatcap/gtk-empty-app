#include "exampleapplication.h"
#include "examplewindow.h"
#include <iostream>

ExampleApplication::ExampleApplication() :
	Gtk::Application("org.gtkmm.examples.application")
{
	Glib::set_application_name("Gtk::Application Example");
}

Glib::RefPtr<ExampleApplication> ExampleApplication::create()
{
	return Glib::RefPtr<ExampleApplication>(new ExampleApplication());
}

void ExampleApplication::on_startup()
{
	//Call the base class's implementation:
	Gtk::Application::on_startup();

	//Create the Application menu:
	//We can use add_action because Gtk::Application derives from ActionMap:
	add_action("something", sigc::mem_fun(*this, &ExampleApplication::on_action_something));
	add_action("copy",      sigc::mem_fun(*this, &ExampleApplication::on_action_edit));
	add_action("quit",      sigc::mem_fun(*this, &ExampleApplication::on_action_quit));

	Glib::RefPtr<Gio::Menu> app_menu = Gio::Menu::create();
	app_menu->append("_Something", "app.something");
	app_menu->append("_Quit",      "app.quit");

	set_app_menu(app_menu);

	//Create the per-Window menu:
	Glib::RefPtr<Gio::Menu> win_menu = Gio::Menu::create();

	Glib::RefPtr<Gio::Menu> submenu_file = Gio::Menu::create();
	submenu_file->append("_New", "win.new");
	submenu_file->append("_Close", "win.close");
	win_menu->append_submenu("File", submenu_file);

	Glib::RefPtr<Gio::Menu> submenu_edit = Gio::Menu::create();
	submenu_edit->append("_Cut", "win.cut");
	Glib::RefPtr<Gio::MenuItem> item = Gio::MenuItem::create("_Copy", "app.copy");
	submenu_edit->append_item(item);
	item = Gio::MenuItem::create("_Paste", "win.paste");
	submenu_edit->append_item(item);
	win_menu->append_submenu("Edit", submenu_edit);

	set_menubar(win_menu);
}

void ExampleApplication::create_window()
{
	ExampleWindow* window = new ExampleWindow();
	window->set_default_size(300, 100);

	//Make sure that the application runs for as long this window is still open:
	add_window(*window);

	//Delete the window when it is hidden.
	//That's enough for this simple example.
	window->signal_hide().connect(sigc::bind<Gtk::Window*>(sigc::mem_fun(*this, &ExampleApplication::on_window_hide), window));

	window->show();
}

void ExampleApplication::on_window_hide(Gtk::Window* window)
{
	delete window;
}

void ExampleApplication::on_activate()
{
	//std::cout << "debug1: " << G_STRFUNC << std::endl;
	// The application has been started, so let's show a window.
	// A real application might want to reuse this "empty" window in on_open(),
	// when asked to open a file, if no changes have been made yet.
	create_window();
}

void ExampleApplication::on_action_something()
{
	std::cout << G_STRFUNC << std::endl;
}

void ExampleApplication::on_action_edit()
{
	std::cout << G_STRFUNC << std::endl;
}

void ExampleApplication::on_action_quit()
{
	std::cout << G_STRFUNC << std::endl;
	quit();
}
