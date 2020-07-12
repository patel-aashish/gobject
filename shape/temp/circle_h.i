GType circle_get_type(void);
typedef struct _Circle Circle;
typedef struct {
    ShapeClass parent_class;
} CircleClass;

typedef Circle* Circle_autoptr;
static inline void glib_autoptr_cleanup_Circle(Circle** _ptr) { glib_autoptr_cleanup_Shape((Shape**)_ptr); }
static inline Circle* _CIRCLE(gpointer ptr) { return (((Circle*)g_type_check_instance_cast((GTypeInstance*)(ptr), (circle_get_type())))); }
static inline gboolean _IS_CIRCLE(gpointer ptr)
{
    return ((__extension__({ GTypeInstance *__inst = (GTypeInstance*) (ptr); GType __t = (circle_get_type ()); gboolean __r; if (!__inst) __r = (0); else if (__inst->g_class && __inst->g_class->g_type == __t) __r = (!(0)); else __r = g_type_check_instance_is_a (__inst, __t); __r; })));
}

Circle* circle_new(guint radius);
void circle_free(Circle* circle);

void circle_set_radius(Circle* self, guint radius);
guint circle_get_radius(Circle* self);
