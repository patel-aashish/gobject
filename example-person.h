// Copyright (C) 2020 Aashish Patel
// 
// This file is part of example-person. The code is written following
// https://www.youtube.com/watch?v=1-_EBEr0fxI
// 
// example-person is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// example-person is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with example-person.  If not, see <http://www.gnu.org/licenses/>.

#ifndef EXAMPLE_PERSON_H
#define EXAMPLE_PERSON_H

#include <glib-object.h>

G_BEGIN_DECLS
#define EXAMPLE_TYPE_PERSON (example_person_get_type())

G_DECLARE_FINAL_TYPE(ExamplePerson, example_person, EXAMPLE, PERSON, GObject)

const gchar *example_person_get_name(ExamplePerson *self);
void         example_person_set_name(ExamplePerson *self,
                                     const gchar   *name);

G_END_DECLS
#endif /* EXAMPLE_PERSON_H */
