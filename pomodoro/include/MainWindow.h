#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/cssprovider.h>

#include "MainGrid.h"
#include "ClockView.h"

class MainWindow: public Gtk::Window {
    public:
    MainWindow();
    virtual ~MainWindow();
    MainWindow(MainWindow const&) = delete;
    void operator=(MainWindow const&) = delete;

    private:
    MainGrid m_main_grid;
    ClockView m_clock_view;
    
    Glib::RefPtr<Gtk::CssProvider> m_css_provider;
    Glib::RefPtr<Gdk::Screen> m_screen;
    Glib::RefPtr<Gtk::StyleContext> m_style_context;
};
#endif