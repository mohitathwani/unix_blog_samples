#include "MainGrid.h"
#include <gtkmm/button.h>

MainGrid::MainGrid() {
    insert_column(1);
    insert_row(0);
    insert_row(1);
    insert_row(2);
    insert_row(3);

    auto button = new Gtk::Button("Hola!");
    attach(*button, 1, 1, 1, 1);


}

MainGrid::~MainGrid() {

}