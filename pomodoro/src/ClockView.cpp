#include "ClockView.h"
#include <cairomm/cairomm.h>
#include <giomm/resource.h>
#include <gdkmm/general.h>
#include <glibmm/main.h>
#include <ctime>
#include <cmath>
#include <iostream>

ClockView::ClockView(): m_radius(0.5),
                        m_line_width(0.05)
{
  Glib::signal_timeout().connect( sigc::mem_fun(*this, &ClockView::on_timeout), 1000 );
  try
  {
    m_image = Gdk::Pixbuf::create_from_resource("/images/tomato.png");
  }
  catch (const Gio::ResourceError &ex)
  {
    // std::cerr << "ResourceError: " << ex.what() << std::endl;
  }
  catch (const Gdk::PixbufError &ex)
  {
    // std::cerr << "PixbufError: " << ex.what() << std::endl;
  }
}

ClockView::~ClockView()
{
}

bool ClockView::on_draw(const Cairo::RefPtr<Cairo::Context> &cr)
{
  if (!m_image)
    return false;

  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  double image_aspect_ratio = (double)m_image->get_width() / m_image->get_height();
  double target_image_height;
  double target_image_width;
  if (width >= height)
  {
    target_image_height = height;
    target_image_width = image_aspect_ratio * target_image_height;
  }
  else
  {
    target_image_width = width;
    target_image_height = target_image_width / image_aspect_ratio;
  }

  m_image = m_image->scale_simple(target_image_width, target_image_height, Gdk::INTERP_BILINEAR);
  // Draw the image in the middle of the drawing area, or (if the image is
  // larger than the drawing area) draw the middle part of the image.
  Gdk::Cairo::set_source_pixbuf(cr, m_image,
                                (width - m_image->get_width()) / 2, (height - m_image->get_height()) / 2);

                                cr->scale(width, height);
  cr->paint();

  cr->translate(0.5, 0.5);
  cr->set_line_width(m_line_width);
  cr->set_source_rgb(181 / 255.0, 11/255.0, 11 / 255.0);

  cr->arc(0, 0, m_radius, 0, 2 * M_PI);
  cr->save();
  cr->set_source_rgba(1.0, 1.0, 1.0, 0.0);
  cr->fill_preserve();
  cr->restore();
  // cr->stroke_preserve();
  cr->clip();

  // clock ticks
  for (int i = 0; i < 12; i++)
  {
    double inset = 0.05;

    cr->save();
    cr->set_line_cap(Cairo::LINE_CAP_ROUND);

    if(i % 3 != 0)
    {
      inset *= 0.8;
      cr->set_line_width(0.03);
    }
    
    double x1 = (m_radius - inset) * cos (i * M_PI / 6);
    double y1 = (m_radius - inset ) * sin (i * M_PI / 6);

    cr->move_to(x1, y1);

    double x2 = m_radius * cos (i * M_PI / 6);
    double y2 = m_radius * sin (i * M_PI / 6);
    cr->line_to (x2, y2);

    cr->stroke();
    cr->restore(); /* stack-pen-size */
  }

  // store the current time
  time_t rawtime;
  time(&rawtime);
  struct tm * timeinfo = localtime (&rawtime);

  // compute the angles of the indicators of our clock
  double minutes = timeinfo->tm_min * M_PI / 30;
  double hours = timeinfo->tm_hour * M_PI / 6;
  double seconds= timeinfo->tm_sec * M_PI / 30;

  cr->save();
  cr->set_line_cap(Cairo::LINE_CAP_ROUND);

  // draw the seconds hand
  cr->save();
  cr->set_line_width(m_line_width / 3);
  cr->set_source_rgba(0.7, 0.7, 0.7, 0.8); // gray
  cr->move_to(0, 0);
  cr->line_to(sin(seconds) * (m_radius * 0.9),
    -cos(seconds) * (m_radius * 0.9));
  cr->stroke();
  cr->restore();

  // draw the minutes hand
  cr->set_source_rgba(0.117, 0.337, 0.612, 0.9);   // blue
  cr->move_to(0, 0);
  cr->line_to(sin(minutes + seconds / 60) * (m_radius * 0.8),
    -cos(minutes + seconds / 60) * (m_radius * 0.8));
  cr->stroke();

  // draw the hours hand
  cr->set_source_rgba(0.337, 0.612, 0.117, 0.9);   // green
  cr->move_to(0, 0);
  cr->line_to(sin(hours + minutes / 12.0) * (m_radius * 0.5),
    -cos(hours + minutes / 12.0) * (m_radius * 0.5));
  cr->stroke();
  cr->restore();

  // draw a little dot in the middle
  cr->arc(0, 0, m_line_width / 3.0, 0, 2 * M_PI);
  cr->fill();


  return true;
}

bool ClockView::on_timeout()
{
    // force our program to redraw the entire clock.
    Glib::RefPtr<Gdk::Window> win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(),
                get_allocation().get_height());
        win->invalidate_rect(r, false);
    }
    return true;
}