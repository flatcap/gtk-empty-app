#include <iostream>

#include "application.h"
#include "window.h"

Application::Application() :
	Gtk::Application("org.flatcap.test")
{
	Glib::set_application_name("test");
}

void Application::on_window_hide(Gtk::Window* window)
{
	delete window;
}

void Application::on_activate()
{
	Window* window = new Window();
	window->set_default_size(300, 100);

	add_window(*window);

	window->signal_hide().connect(sigc::bind<Gtk::Window*>(sigc::mem_fun(*this, &Application::on_window_hide), window));
	window->show();
}

