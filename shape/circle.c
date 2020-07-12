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

/* Property for accessing private data via gobject set/get property mechanism */
enum
{
  PROP_0,
  PROP_RADIUS,
  PROP_LAST
};

static GParamSpec *properties [PROP_LAST];

guint circle_calculate_area (Circle *self);

static void
circle_get_property (GObject    *object,
                     guint      prop_id,
                     GValue     *value,
                     GParamSpec *pspec)
{
  g_print("%s\n", __func__);
  Circle *self = _CIRCLE(object);

  switch (prop_id)
    {
    case PROP_RADIUS:
      g_value_set_uint(value, circle_get_radius(self));
      break;
    default:
      g_print("%s: %u is not supported\n", __func__, prop_id);
      break;
    }
}

static void
circle_set_property (GObject      *object,
                     guint        prop_id,
                     const GValue *value,
                     GParamSpec   *pspec)
{
  g_print("%s\n", __func__);
  Circle *self = _CIRCLE(object);

  switch (prop_id)
  {
  case PROP_RADIUS:
    circle_set_radius(self, g_value_get_uint(value));
    break;
  default:
    g_print("%s: %u is not supported\n", __func__,prop_id);
    break;
  }
}

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
  GObjectClass *gobject_class = G_OBJECT_CLASS(klass);

  shape_class->calculate_area = (void *)circle_calculate_area;
  gobject_class->get_property = circle_get_property;
  gobject_class->set_property = circle_set_property;

  properties[PROP_RADIUS] = g_param_spec_uint("radius",
      "radius",                 /* nickname */
      "set/get circle radius",  /* description */
      0,                        /* min value */
      G_MAXUINT,                /* max value */
      0,                        /* default */
      G_PARAM_CONSTRUCT | G_PARAM_READWRITE);

  g_object_class_install_properties (gobject_class,
                                     PROP_LAST,
                                     properties);
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