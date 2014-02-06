#ifndef _EXAMPLEAPPLICATION_H_
#define _EXAMPLEAPPLICATION_H_

#include <gtkmm.h>

class ExampleApplication: public Gtk::Application
{
protected:
	ExampleApplication();

public:
	static Glib::RefPtr<ExampleApplication> create();

protected:
	//Overrides of default signal handlers:
	virtual void on_activate();
	virtual void on_startup();

private:
	void create_window();

	void on_window_hide(Gtk::Window* window);
	void on_action_something();
	void on_action_edit();
	void on_action_quit();
};

#endif // _EXAMPLEAPPLICATION_H_

