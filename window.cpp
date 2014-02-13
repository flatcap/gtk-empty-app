#include <iostream>

#include "window.h"

Window::Window()
{
	add_action("close", sigc::mem_fun(*this, &Window::on_action_close));
}

void Window::on_action_close()
{
	hide();
}

