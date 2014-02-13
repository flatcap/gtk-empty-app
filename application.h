#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <gtkmm.h>

class Application: public Gtk::Application
{
protected:
	Application();

public:
	static Glib::RefPtr<Application> create();

protected:
	virtual void on_activate();
	virtual void on_startup();

private:
	void create_window();

	void on_window_hide(Gtk::Window* window);
	void on_action_something();
	void on_action_edit();
	void on_action_quit();
};

#endif // _APPLICATION_H_

