/**
 * Copyright (C) 2020 Aashish Patel (aashish.a.pate@gmail.com)
 *
 * shape is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * shape is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with shape. If not, see <http://www.gnu.org/licenses/>.
 */

#include "rectangle.h"

/* For final types instance struct should be defined in source file */
struct _Rectangle
{
    Shape parent;
};

G_DEFINE_TYPE(Rectangle, rectangle, SHAPE_TYPE)

static void
rectangle_init (Rectangle *self)
{

}

static void
rectangle_class_init (RectangleClass *Klass)
{

}