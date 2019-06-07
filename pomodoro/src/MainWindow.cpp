#include "MainWindow.h"

MainWindow::MainWindow() {
    set_title("Pomodoro");
    set_name("MainWindow");
    set_resizable(false);
    set_default_size(320, 600);
    set_position(Gtk::WIN_POS_CENTER);
    
    Glib::ustring data = "#MainWindow {background-color: #ff00ea;}";
    m_css_provider = Gtk::CssProvider::create();
    if (!m_css_provider->load_from_data(data))
    {
        std::exit(1);
    }
    
    m_screen = Gdk::Screen::get_default();
    m_style_context = get_style_context();
    m_style_context->add_provider_for_screen(m_screen, m_css_provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

MainWindow::~MainWindow() {

}