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

  std::cout << target_image_width << " " << target_image_height << std::endl;
  m_image = m_image->scale_simple(target_image_width, target_image_height, Gdk::INTERP_BILINEAR);
  // Draw the image in the middle of the drawing area, or (if the image is
  // larger than the drawing area) draw the middle part of the image.
  Gdk::Cairo::set_source_pixbuf(cr, m_image,
                                (width - m_image->get_width()) / 2, (height - m_image->get_height()) / 2);
  cr->paint();


  return true;
}