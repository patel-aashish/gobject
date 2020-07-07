
GType rectangle_get_type(void);

typedef struct _Rectangle Rectangle;
typedef struct {
    ShapeClass parent_class;
} RectangleClass;

typedef Rectangle* Rectangle_autoptr;
static inline void glib_autoptr_cleanup_Rectangle(Rectangle** _ptr) { glib_autoptr_cleanup_Shape((Shape**)_ptr); }
static inline Rectangle* _RECTANGLE(gpointer ptr) { return (((Rectangle*)g_type_check_instance_cast((GTypeInstance*)(ptr), (rectangle_get_type())))); }
static inline gboolean _IS_RECTANGLE(gpointer ptr)
{
    return ((__extension__({ GTypeInstance *__inst = (GTypeInstance*) (ptr); GType __t = (rectangle_get_type ()); gboolean __r; if (!__inst) __r = (0); else if (__inst->g_class && __inst->g_class->g_type == __t) __r = (!(0)); else __r = g_type_check_instance_is_a (__inst, __t); __r; })));
}

Rectangle* rectangle_new(guint width, guint height);
void rectangle_free(Rectangle* self);

void rectangle_set_width(Rectangle* self, guint width);
void rectangle_set_height(Rectangle* self, guint height);
guint rectangle_get_width(Rectangle* self);
guint rectangle_get_height(Rectangle* self);
