GType shape_type_get_type(void);

typedef struct _ShapeType ShapeType;

typedef struct _ShapeTypeClass ShapeTypeClass;

struct _ShapeType {
    GObject parent_instance;
};

typedef ShapeType* ShapeType_autoptr;

static inline void glib_autoptr_cleanup_ShapeType(ShapeType** _ptr) { glib_autoptr_cleanup_GObject((GObject**)_ptr); }

static inline ShapeType* SHAPE_TYPE(gpointer ptr) { return (((ShapeType*)g_type_check_instance_cast((GTypeInstance*)(ptr), (shape_type_get_type())))); }

static inline ShapeTypeClass* SHAPE_TYPE_CLASS(gpointer ptr) { return (((ShapeTypeClass*)g_type_check_class_cast((GTypeClass*)(ptr), (shape_type_get_type())))); }

static inline gboolean SHAPE_IS_TYPE(gpointer ptr)
{
    return ((__extension__({ GTypeInstance *__inst = (GTypeInstance*) (ptr); GType __t = (shape_type_get_type ()); gboolean __r; if (!__inst) __r = (0); else if (__inst->g_class && __inst->g_class->g_type == __t) __r = (!(0)); else __r = g_type_check_instance_is_a (__inst, __t); __r; })));
}

static inline gboolean SHAPE_IS_TYPE_CLASS(gpointer ptr)
{
    return ((__extension__({ GTypeClass *__class = (GTypeClass*) (ptr); GType __t = (shape_type_get_type ()); gboolean __r; if (!__class) __r = (0); else if (__class->g_type == __t) __r = (!(0)); else __r = g_type_check_class_is_a (__class, __t); __r; })));
}

static inline ShapeTypeClass* SHAPE_TYPE_GET_CLASS(gpointer ptr) { return (((ShapeTypeClass*)(((GTypeInstance*)(ptr))->g_class))); }

struct _ShapeTypeClass {
    GObjectClass parent;
    guint (*calculate_area)(Shape* self);
};
