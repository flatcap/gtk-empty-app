#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <gtkmm.h>

class Application: public Gtk::Application
{
public:
	Application();

protected:
	virtual void on_activate();

	void on_window_hide(Gtk::Window* window);
};

#endif // _APPLICATION_H_

