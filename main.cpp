#include <gtkmm.h>
#include <iostream>

#include "application.h"

int main(int argc, char *argv[])
{
	Glib::RefPtr<Application> application = Application::create();

	const int status = application->run(argc, argv);
	return status;
}
