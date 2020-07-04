typedef struct _Shape Shape;
typedef struct _ShapeClass ShapeClass;
struct _Shape {
    GObject parent_instance;
};
typedef Shape* Shape_autoptr;
static inline void glib_autoptr_cleanup_Shape(Shape** _ptr) { glib_autoptr_cleanup_GObject((GObject**)_ptr); }
static inline Shape* _SHAPE(gpointer ptr) { return (((Shape*)g_type_check_instance_cast((GTypeInstance*)(ptr), (shape_get_type())))); }
static inline ShapeClass* _SHAPE_CLASS(gpointer ptr) { return (((ShapeClass*)g_type_check_class_cast((GTypeClass*)(ptr), (shape_get_type())))); }
static inline gboolean _IS_SHAPE(gpointer ptr)
{
    return ((__extension__({ GTypeInstance *__inst = (GTypeInstance*) (ptr); GType __t = (shape_get_type ()); gboolean __r; if (!__inst) __r = (0); else if (__inst->g_class && __inst->g_class->g_type == __t) __r = (!(0)); else __r = g_type_check_instance_is_a (__inst, __t); __r; })));
}
static inline gboolean _IS_SHAPE_CLASS(gpointer ptr)
{
    return ((__extension__({ GTypeClass *__class = (GTypeClass*) (ptr); GType __t = (shape_get_type ()); gboolean __r; if (!__class) __r = (0); else if (__class->g_type == __t) __r = (!(0)); else __r = g_type_check_class_is_a (__class, __t); __r; })));
}
static inline ShapeClass* _SHAPE_GET_CLASS(gpointer ptr) { return (((ShapeClass*)(((GTypeInstance*)(ptr))->g_class))); }
# 24 "shape.h"
#pragma GCC diagnostic pop
# 24 "shape.h"

struct _ShapeClass {
    GObjectClass parent;
    guint (*calculate_area)(Shape* self);
};

guint shape_calculate_area(Shape* self);
