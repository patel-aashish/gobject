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


#include "shape.h"

int 
main(int argc, char **argv)
{
  Shape *shape1;
  Shape *shape2;

  shape1 = g_object_new(SHAPE_TYPE, NULL);
  g_print("shape1(%p) is created.\n", shape1);
  g_object_unref(shape1);

  shape2 = g_object_new(SHAPE_TYPE, NULL);
  g_print("shape2(%p) is created.\n", shape2);
  g_object_unref(shape2);

  return 0;
}