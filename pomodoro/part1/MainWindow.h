#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/cssprovider.h>

class MainWindow: public Gtk::Window {
    public:
    MainWindow();
    virtual ~MainWindow();

    private:
    Glib::RefPtr<Gtk::CssProvider> m_css_provider;
    Glib::RefPtr<Gdk::Screen> m_screen;
    Glib::RefPtr<Gtk::StyleContext> m_style_context;
};
#endif