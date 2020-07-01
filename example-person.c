/**
 * Copyright (C) 2020 Aashish Patel
 * 
 * This file is part of example-person. The code is written following
 * https://www.youtube.com/watch?v=1-_EBEr0fxI
 * 
 * example-person is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * example-person is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with example-person.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "example-person.h"
/* Instance structure, this is not created by G_DEFINE_TYPE */
struct _ExamplePerson 
{
    GObject parent_instance;
    gchar   *name;
};

/* Define the ExamplePerson declared in the header file */
G_DEFINE_TYPE(ExamplePerson, example_person, G_TYPE_OBJECT)

/* Properties declaration */
enum
{
  PROP_0,
  PROP_NAME,
  PROP_LAST
};

/* Placeholder for properties */
static GParamSpec *properties [PROP_LAST]; 

static void
example_person_get_property (GObject    *object,
                             guint      prop_id,
                             GValue     *value,
                             GParamSpec *pspec)
{
  ExamplePerson *self = (ExamplePerson *)object;

  switch (prop_id)
    {
    case PROP_NAME:
        g_value_set_string (value, example_person_get_name(self));
        break;
    default:
        break;
    }
}

static void
example_person_set_property (GObject      *object,
                             guint        prop_id,
                             const GValue *value,
                             GParamSpec   *pspec)
{
  ExamplePerson *self = (ExamplePerson *)object;

  switch (prop_id)
    {
    case PROP_NAME:
      example_person_set_name (self, g_value_get_string(value));
      break;
    default:
      break;
    }
}

static void
example_person_class_init(ExamplePersonClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);

  /* Properties need to accessed through GObject interface
     here we are overiding virtual methods for setting and
     getting properties of GObject */
  object_class->get_property = example_person_get_property;
  object_class->set_property = example_person_set_property;

  /* Initialize the property, names, description, default value, access flags */
  properties[PROP_NAME] =
    g_param_spec_string ("name",
                         "Name",
                         "Name of the person",
                         NULL,
                         (G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS));
  /* Installs the properties */
  g_object_class_install_properties (object_class,
                               PROP_LAST,
                               properties);
}

static void
example_person_init(ExamplePerson *self)
{

}

const gchar *
example_person_get_name(ExamplePerson *self)
{
  return self->name;
}
 
void
example_person_set_name(ExamplePerson *self,
                        const gchar   *name)
{
  if (g_strcmp0(name, self->name) != 0)
    {
      g_free(self->name);
      self->name = g_strdup(name);
    }
}
