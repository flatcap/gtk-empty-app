#include <gtkmm.h>
#include <iostream>

#include "application.h"

int main (int argc, char *argv[])
{
	Glib::RefPtr<Application> app (new Application());
	return app->run(argc, argv);
}
