#ifndef CLOCK_VIEW_H
#define CLOCK_VIEW_H

#include <gtkmm/drawingarea.h>
class ClockView: public Gtk::DrawingArea {
public:
ClockView();
virtual ~ClockView();

protected:
bool on_draw(const Cairo::RefPtr<Cairo::Context>& context) override;

Glib::RefPtr<Gdk::Pixbuf> m_image;

};
#endif