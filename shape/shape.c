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

G_DEFINE_TYPE(ShapeType, shape_type, G_TYPE_OBJECT);

/* dispatcher method */
guint
shape_type_calculate_area(ShapeType *self)
{
  ShapeTypeClass *klass;

  g_print("%s",__func__);

  g_return_val_if_fail(SHAPE_IS_TYPE(self), 1);

  klass = SHAPE_TYPE_GET_CLASS(self);

  if (klass->calculate_area == NULL)
    {
      g_print("%s: calculate_area is not implemented\n", __func__);
      return 0;
    }

  return klass->calculate_area(self);
}

/* place holder for the dispose function */
static void
shape_type_dispose(GObject *object)
{
  g_print("%s: %p\n",__func__, object);
}

/* place holder for the finalize function */
static void
shape_type_finalize(GObject *object)
{
  g_print("%s: %p\n",__func__, object);
}

/* instance init function, init your public and private data here */
static void
shape_type_init(ShapeType *self)
{
  g_print("%s: %p\n",__func__, self);
}

static void
shape_type_class_init (ShapeTypeClass *klass)
{
  g_print("%s : %p\n", __func__, klass);
  /* get parent GObject class */
  GObjectClass *object_class = G_OBJECT_CLASS(klass);

  /* assign virtual method to NULL as its a abstract class */
  klass->calculate_area = NULL;

  /* hook instance dispose function */
  object_class->dispose = shape_type_dispose;
  object_class->finalize = shape_type_finalize;
}