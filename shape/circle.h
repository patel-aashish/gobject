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

#ifndef CIRCLE_H

#include "shape.h"

G_BEGIN_DECLS
#define CIRCLE_TYPE (circle_get_type())

G_DECLARE_FINAL_TYPE(Circle, circle, ,CIRCLE, Shape)

Circle* circle_new  (guint radius);
void    circle_free (Circle *circle);

/* Helper functions for accessing the private data */
void  circle_set_radius (Circle *self, guint radius);
guint circle_get_radius (Circle *self);

G_END_DECLS

#endif // !CIRCLE_H