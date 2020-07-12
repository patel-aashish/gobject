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

#include "circle.h"

typedef struct _CirclePrivate
{
  guint radius;
} CirclePrivate;

struct _Circle
{
  Shape parent;
  CirclePrivate *priv;
};

G_DEFINE_TYPE_WITH_PRIVATE (Circle, circle, SHAPE_TYPE)

guint circle_calculate_area (Circle *self);

static void
circle_init (Circle *self)
{
  g_print ("%s: %p \n", __func__, self);

  CirclePrivate *priv;

  self->priv = priv = circle_get_instance_private(self);
  priv->radius = 0;
}

static void
circle_class_init (CircleClass *klass)
{
  g_print("%s: %p \n", __func__, klass);

  ShapeClass *shape_class = _SHAPE_CLASS(klass);

  shape_class->calculate_area = (void *)circle_calculate_area;
}

Circle*
circle_new (guint radius)
{
  g_print("%s \n", __func__);
  Circle *circle;
  CirclePrivate *priv;
  circle = g_object_new(CIRCLE_TYPE, NULL);
  g_assert(circle != NULL);
  priv = circle_get_instance_private(circle);
  priv->radius = radius;

  g_print("%s: Circle(%p) created with radius %u\n",
          __func__, circle, priv->radius);
  
  return circle;
}

void
circle_free (Circle *self)
{
  g_print("%s\n", __func__);
  g_assert(self != NULL);
  g_return_if_fail(_IS_CIRCLE(self));

  g_object_unref(self);
}

guint
circle_calculate_area (Circle *self)
{
  g_print("%s\n", __func__);
  g_assert(self != NULL);
  CirclePrivate *priv = circle_get_instance_private(self);
  guint area = (guint) (G_PI * (priv->radius * priv->radius));
  return area;
}

void
circle_set_radius (Circle *self, guint radius)
{
  g_print("%s\n", __func__);
  g_assert(self != NULL);
  g_return_if_fail(_IS_CIRCLE(self));
  CirclePrivate *priv = circle_get_instance_private(self);

  if (radius != priv->radius)
    {
      priv->radius = radius;
    }
}

guint
circle_get_radius (Circle *self)
{
  g_print("%s\n", __func__);
  g_assert(self != NULL);
  g_return_val_if_fail(_IS_CIRCLE(self), 0);
  CirclePrivate *priv = circle_get_instance_private(self);
  return priv->radius;
}