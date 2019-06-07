#include <gtkmm/application.h>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
  auto app =
    Gtk::Application::create(argc, argv,
      "net.athwani.mohit");

    MainWindow main_window;

  return app->run(main_window);
}