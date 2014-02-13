#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <gtkmm.h>

class Window : public Gtk::ApplicationWindow
{
public:
	explicit Window();

private:
	void on_action_something();
	void on_action_close();
};

#endif // _WINDOW_H_

