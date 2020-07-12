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
typedef struct _RectanglePrivate
{
  guint width;
  guint height;
} RectanglePrivate;

struct _Rectangle
{
  Shape parent;
  RectanglePrivate *priv;
};

/* Defines a type with private data and a convenience function for getting the private structure */
G_DEFINE_TYPE_WITH_PRIVATE (Rectangle, rectangle, SHAPE_TYPE)

enum
{
  PROP_0,
  PROP_HEIGHT,
  PROP_WIDTH,
  PROP_LAST
};

static GParamSpec *properties [PROP_LAST];

guint rectangle_calculate_area (Rectangle* self);

static void
rectangle_get_property (GObject    *object,
                        guint      prop_id,
                        GValue     *val,
                        GParamSpec *pspec)
{
  g_print ("%s\n",__func__);
  Rectangle *self = _RECTANGLE(object);

  switch (prop_id)
  {
  case PROP_HEIGHT:
    g_value_set_uint(val, rectangle_get_height(self));
    break;
  case PROP_WIDTH:
    g_value_set_uint(val, rectangle_get_width(self));
    break;
  default:
    g_print("%s: %u is not supported\n", __func__, prop_id);
    break;
  }

}

static void
rectangle_set_property (GObject        *object,
                        guint           prop_id,
                        const GValue   *val,
                        GParamSpec     *pspec)
{
  g_print("%s\n", __func__);
  Rectangle *self = _RECTANGLE(object);

  switch (prop_id)
  {
  case PROP_HEIGHT:
    rectangle_set_height(self,g_value_get_uint(val));
    break;
  case PROP_WIDTH:
    rectangle_set_width(self,g_value_get_uint(val));
    break;
  default:
    g_print("%s: %u is not supported\n", __func__, prop_id);
    break;
  }
}

static void
rectangle_init (Rectangle* self)
{
  g_print("%s: %p\n", __func__, self);

  RectanglePrivate *priv;

  /* Initialize private data members */
  self->priv = priv = rectangle_get_instance_private(self);
  priv->width = 0;
  priv->height = 0;
}

static void
rectangle_class_init (RectangleClass *klass)
{
  g_print("%s: %p\n", __func__, klass);

  ShapeClass *shape_class = _SHAPE_CLASS(klass);
  GObjectClass *gobject_class = G_OBJECT_CLASS(klass);

  shape_class->calculate_area = (void *)rectangle_calculate_area;
  gobject_class->get_property = rectangle_get_property;
  gobject_class->set_property = rectangle_set_property;

  properties[PROP_HEIGHT] =
    g_param_spec_uint ("height",                          /* name */
                       "height",                          /* nickname */
                       "set/get height of the rectangle", /* description */
                       0,                                 /* min value */
                       G_MAXUINT,                         /* max value */
                       0,                                 /* default value */
                       G_PARAM_CONSTRUCT | G_PARAM_READWRITE);
  properties[PROP_WIDTH] = 
    g_param_spec_uint("width",                            /* name */
                      "width",                            /* nickname */
                      "set/get width of the rectangle",   /* description */
                      0,                                  /* min value */
                      G_MAXUINT,                          /* max value */
                      0,                                  /* default value */
                      G_PARAM_CONSTRUCT | G_PARAM_READWRITE);
  g_object_class_install_properties (gobject_class,
                                     PROP_LAST,
                                     properties);
}

Rectangle*
rectangle_new (guint width,
               guint height)
{
  g_print("%s \n", __func__);
  Rectangle* rect;
  RectanglePrivate *priv;
  rect = g_object_new(RECTANGLE_TYPE, NULL);
  g_assert(rect != NULL);

  priv = rectangle_get_instance_private(rect);
  priv->width = width;
  priv->height= height;

  g_print("%s: Rectangle(%p) created with width(%u) and height(%u)\n",
      __func__, rect, priv->width, priv->height);

  return rect;
}

void
rectangle_free (Rectangle *self)
{
  g_print("%s\n", __func__);
  g_assert(self != NULL);
  g_return_if_fail(_IS_RECTANGLE(self));

  g_object_unref(self);
}

guint
rectangle_calculate_area (Rectangle *self)
{
  g_print("%s\n", __func__);
  g_assert(self != NULL);
  RectanglePrivate *priv = rectangle_get_instance_private(self);

  return (priv->width) * (priv->height);
}

void
rectangle_set_width(Rectangle *self,
                    guint     width)
{
  g_print("%s\n", __func__);
  g_assert(self != NULL);
  g_return_if_fail(_IS_RECTANGLE(self));
  RectanglePrivate *priv = rectangle_get_instance_private(self);
  if(width != priv->width)
    {
      priv->width = width;
    }
}

void
rectangle_set_height(Rectangle *self,
                     guint height)
{
  g_print("%s\n", __func__);
  g_assert(self != NULL);
  g_return_if_fail(_IS_RECTANGLE(self));
  RectanglePrivate *priv = rectangle_get_instance_private(self);

  if (height != priv->height)
    {
      priv->height = height;
    }
}

guint
rectangle_get_width(Rectangle *self)
{
  g_print("%s\n",__func__);
  g_assert(self != NULL);
  g_return_val_if_fail(_IS_RECTANGLE(self), -1);
  RectanglePrivate *priv = rectangle_get_instance_private(self);
  return priv->width;
}

guint
rectangle_get_height(Rectangle *self)
{
  g_print("%s\n", __func__);
  g_assert(self != NULL);
  g_return_val_if_fail(_IS_RECTANGLE(self), -1);
  RectanglePrivate* priv = rectangle_get_instance_private(self);
  return priv->height;
}