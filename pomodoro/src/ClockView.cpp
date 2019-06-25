#include "ClockView.h"
#include <cairomm/cairomm.h>
#include <giomm/resource.h>
#include <gdkmm/general.h>
#include <iostream>

ClockView::ClockView()
{
    try
  {
    m_image = Gdk::Pixbuf::create_from_resource("/images/tomato.png");
  }
  catch(const Gio::ResourceError& ex)
  {
    // std::cerr << "ResourceError: " << ex.what() << std::endl;
  }
  catch(const Gdk::PixbufError& ex)
  {
    // std::cerr << "PixbufError: " << ex.what() << std::endl;
  }
}

ClockView::~ClockView()
{
}

bool ClockView::on_draw(const Cairo::RefPtr<Cairo::Context> &cr)
{
    // This is where we draw on the window
    // Gtk::Allocation allocation = get_allocation();
    // const int width = allocation.get_width();
    // const int height = allocation.get_height();
    // const int lesser = MIN(width, height);

    // cr->scale(width, height);

    // cr->set_line_width(0.002);

    //Outer circle
    // cr->save();
    // cr->arc(0.5, 0.5, 0.3, 0, 2.0 * M_PI);
    // cr->set_source_rgba(149 / 255.0, 17 / 255.0, 23 / 255.0, 0.8);
    // cr->fill_preserve();
    // cr->stroke();
    // cr->restore();

    //Inner top semi circle
    // cr->save();
    // cr->arc(0.5, 0.5, 0.27, 3.0 * M_PI_4, - M_PI_4);
    // cr->set_source_rgba(1.0, 1.0, 1.0, 0.5);
    // cr->fill();
    // cr->restore();

    //Inner bottom semi circle
    // cr->save();
    // cr->arc(0.5, 0.5, 0.27, - M_PI_4, 3.0 * M_PI_4);
    // cr->set_source_rgba(1.0, 1.0, 1.0, 0.35);
    // cr->fill();
    // cr->restore();

    //Right quarter
    // cr->save();
    // cr->move_to(0.5, 0.5);
    // cr->line_to(0.5, 0.3);
    // cr->arc(0.5, 0.5, 0.2, - M_PI_2, 25 * M_PI / 180.0);
    // cr->set_source_rgba(179 / 255.0, 17 / 255.0, 23 / 255.0, 0.7);
    // cr->stroke_preserve();
    // cr->fill();
    // cr->restore();

    //Bottom quarter
    // cr->save();
    // cr->translate(0.5, 0.5);
    // cr->rotate_degrees(120);
    // cr->translate(-0.5, -0.5);
    // cr->move_to(0.5, 0.5);
    // cr->line_to(0.5, 0.3);
    // cr->arc(0.5, 0.5, 0.2, - M_PI_2, 25 * M_PI / 180.0);
    // cr->set_source_rgba(179 / 255.0, 17 / 255.0, 23 / 255.0, 0.7);
    // cr->stroke_preserve();
    // cr->fill();
    // cr->restore();

      if (!m_image)
    return false;

  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  // Draw the image in the middle of the drawing area, or (if the image is
  // larger than the drawing area) draw the middle part of the image.
  // Gdk::Cairo::set_source_pixbuf(cr, m_image,
  //   (width - m_image->get_width())/2, (height - m_image->get_height())/2);
  double image_aspect_ratio = (double)m_image->get_width() / m_image->get_height();
  double target_image_height;
  double target_image_width;
if (width >= height)
{
  target_image_height = height;
  target_image_width = image_aspect_ratio * target_image_height; 
} else {
  target_image_width = width;
  target_image_height = target_image_width / image_aspect_ratio;
}

std::cout << target_image_width << " " << target_image_height << std::endl;
m_image = m_image->scale_simple(target_image_width, target_image_height, Gdk::INTERP_BILINEAR);


// double x_scale = width * 0.5;
// double y_scale = height * 0.5;
// Gdk::Cairo::set_source_pixbuf(cr, m_image,0, 0);

Gdk::Cairo::set_source_pixbuf(cr, m_image,
    (width - m_image->get_width())/2, (height - m_image->get_height())/2);
  cr->paint();



  return true;
}