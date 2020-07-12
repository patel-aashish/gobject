
typedef struct _CirclePrivate {
    guint radius;
} CirclePrivate;

struct _Circle {
    Shape parent;
    CirclePrivate* priv;
};

static void circle_init(Circle* self);
static void circle_class_init(CircleClass* klass);
static gpointer circle_parent_class =     ((void*)0);
static gint Circle_private_offset;
static void circle_class_intern_init(gpointer klass)
{
    circle_parent_class = g_type_class_peek_parent(klass);
    if (Circle_private_offset != 0)
        g_type_class_adjust_private_offset(klass, &Circle_private_offset);
    circle_class_init((CircleClass*)klass);
}
__attribute__((__unused__)) static inline gpointer circle_get_instance_private(Circle* self) { return (((gpointer)((guint8*)(self) + (glong)(Circle_private_offset)))); }
GType circle_get_type(void)
{
    static volatile gsize g_define_type_id__volatile = 0;
    if ((__extension__({ typedef char _GStaticAssertCompileTimeAssertion_1[(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1] __attribute__((__unused__)); (void) (0 ? (gpointer) *(&g_define_type_id__volatile) : 0); (!(__extension__ ({ typedef char _GStaticAssertCompileTimeAssertion_2[(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1] __attribute__((__unused__)); (gpointer) __atomic_load_8 ((&g_define_type_id__volatile), 5); })) && g_once_init_enter (&g_define_type_id__volatile)); }))) {
        GType g_define_type_id = g_type_register_static_simple((shape_get_type()), g_intern_static_string("Circle"), sizeof(CircleClass), (GClassInitFunc)(void (*)(void))circle_class_intern_init, sizeof(Circle), (GInstanceInitFunc)(void (*)(void))circle_init, (GTypeFlags)0);
        { { {};
    }
}
(__extension__({ typedef char _GStaticAssertCompileTimeAssertion_3[(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1] __attribute__((__unused__)); (void) (0 ? *(&g_define_type_id__volatile) = (g_define_type_id) : 0); g_once_init_leave ((&g_define_type_id__volatile), (gsize) (g_define_type_id)); }));
}
return g_define_type_id__volatile;
}

guint circle_calculate_area(Circle* self);

