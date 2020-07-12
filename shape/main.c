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
#include "rectangle.h"
#include "circle.h"

int 
main(int argc, char **argv)
{
  Rectangle *rect;
  Circle    *circle;
  rect = rectangle_new(4,5);
  g_print("Rectangle(%p) is created.\n", rect);
  g_print("Area of rectangle(%p) is %u\n", rect, shape_calculate_area(_SHAPE(rect)));
  rectangle_free(rect);

  circle = circle_new(5);
  g_print("Circle(%p) is created.\n", circle);
  g_print("Area of circle(%p) is %u\n", circle, shape_calculate_area(_SHAPE(circle)));
  circle_free(circle);
  return 0;
}