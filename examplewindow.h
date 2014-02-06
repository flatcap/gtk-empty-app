#ifndef _EXAMPLEWINDOW_H_
#define _EXAMPLEWINDOW_H_

#include <gtkmm.h>

class ExampleWindow : public Gtk::ApplicationWindow
{
public:
	explicit ExampleWindow();

private:
	void on_action_something();
	void on_action_close();
};

#endif // _EXAMPLEWINDOW_H_

