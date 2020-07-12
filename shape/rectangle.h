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

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

G_BEGIN_DECLS

#define RECTANGLE_TYPE (rectangle_get_type())

G_DECLARE_FINAL_TYPE(Rectangle, rectangle, , RECTANGLE, Shape)

Rectangle* rectangle_new (guint width, guint height);
void       rectangle_free(Rectangle *self);

/* helper function for set/get private data members */
void  rectangle_set_width (Rectangle *self, guint width);
void  rectangle_set_height(Rectangle *self, guint height);
guint rectangle_get_width (Rectangle *self);
guint rectangle_get_height(Rectangle *self);

G_END_DECLS

#endif // !RECTANGLE_H