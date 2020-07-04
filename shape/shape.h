// Copyright (C) 2020 Aashish Patel (aashish.a.pate@gmail.com)
//
// shape is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// shape is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with shape. If not, see <http://www.gnu.org/licenses/>.

#ifndef SHAPE_H
#define SHAPE_H

#include <glib-object.h>

G_BEGIN_DECLS
/* Type declaration */
#define SHAPE_TYPE (shape_get_type())
G_DECLARE_DERIVABLE_TYPE (Shape, shape, , SHAPE, GObject)

/* class struct is decalared by G_DECLARE, but we need a virtual public method hence we are defining it */
struct _ShapeClass
{
  GObjectClass parent;
  guint (*calculate_area) (Shape *self);
};

/* Dispatcher method for calculate_area */
guint shape_calculate_area (Shape *self);

G_END_DECLS
#endif // !SHAPE_H