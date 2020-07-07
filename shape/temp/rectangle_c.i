struct _Rectangle {
    Shape parent;
};

static void rectangle_init(Rectangle* self);
static void rectangle_class_init(RectangleClass* klass);
static gpointer rectangle_parent_class =    ((void*)0)    ;
static gint Rectangle_private_offset;
static void rectangle_class_intern_init(gpointer klass)
{
    rectangle_parent_class = g_type_class_peek_parent(klass);
    if (Rectangle_private_offset != 0)
        g_type_class_adjust_private_offset(klass, &Rectangle_private_offset);
    rectangle_class_init((RectangleClass*)klass);
}
__attribute__((__unused__)) static inline gpointer rectangle_get_instance_private(Rectangle* self) { return (((gpointer)((guint8*)(self) + (glong)(Rectangle_private_offset)))); }
GType rectangle_get_type(void)
{
    static volatile gsize g_define_type_id__volatile = 0;
    if ((__extension__({ typedef char _GStaticAssertCompileTimeAssertion_1[(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1] __attribute__((__unused__)); (void) (0 ? (gpointer) *(&g_define_type_id__volatile) : 0); (!(__extension__ ({ typedef char _GStaticAssertCompileTimeAssertion_2[(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1] __attribute__((__unused__)); (gpointer) __atomic_load_8 ((&g_define_type_id__volatile), 5); })) && g_once_init_enter (&g_define_type_id__volatile)); }))) {
        GType g_define_type_id = g_type_register_static_simple((shape_get_type()), g_intern_static_string("Rectangle"), sizeof(RectangleClass), (GClassInitFunc)(void (*)(void))rectangle_class_intern_init, sizeof(Rectangle), (GInstanceInitFunc)(void (*)(void))rectangle_init, (GTypeFlags)0);
        { { {};
    }
}
(__extension__({ typedef char _GStaticAssertCompileTimeAssertion_3[(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1] __attribute__((__unused__)); (void) (0 ? *(&g_define_type_id__volatile) = (g_define_type_id) : 0); g_once_init_leave ((&g_define_type_id__volatile), (gsize) (g_define_type_id)); }));
}
return g_define_type_id__volatile;
}

static void
rectangle_init(Rectangle* self)
{
}

static void
rectangle_class_init(RectangleClass* Klass)
{
}
