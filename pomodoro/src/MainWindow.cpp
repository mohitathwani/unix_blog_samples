#include "MainWindow.h"

MainWindow::MainWindow() {
    set_title("Pomodoro");
    set_name("MainWindow");
    set_resizable(false);
    // set_default_size(320, 600);
    set_default_size(600,600);
    set_position(Gtk::WIN_POS_CENTER);

    m_css_provider = Gtk::CssProvider::create();
    try
    {
        // m_css_provider->load_from_path("/usr/local/share/pomodoro/MainWindow.css");
        m_css_provider->load_from_resource("/stylesheets/MainWindow.css");
    }
    catch(const Glib::Error& e)
    {
        // std::exit(1);
        // std::cerr << e.what() << '\n';
    }
    m_screen = Gdk::Screen::get_default();
    m_style_context = get_style_context();
    m_style_context->add_provider_for_screen(m_screen, m_css_provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    // add(m_main_grid);
    add(m_clock_view);

    show_all();
}

MainWindow::~MainWindow() {

}