static void shape_init(Shape* self);
static void shape_class_init(ShapeClass* klass);
static gpointer shape_parent_class =
# 20 "shape.c" 3 4
    ((void*)0)
# 20 "shape.c"
    ;
static gint Shape_private_offset;
static void shape_class_intern_init(gpointer klass)
{
    shape_parent_class = g_type_class_peek_parent(klass);
    if (Shape_private_offset != 0)
        g_type_class_adjust_private_offset(klass, &Shape_private_offset);
    shape_class_init((ShapeClass*)klass);
}
__attribute__((__unused__)) static inline gpointer shape_get_instance_private(Shape* self) { return (((gpointer)((guint8*)(self) + (glong)(Shape_private_offset)))); }
GType shape_get_type(void)
{
    static volatile gsize g_define_type_id__volatile = 0;
    if ((__extension__({ typedef char _GStaticAssertCompileTimeAssertion_1[(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1] __attribute__((__unused__)); (void) (0 ? (gpointer) *(&g_define_type_id__volatile) : 0); (!(__extension__ ({ typedef char _GStaticAssertCompileTimeAssertion_2[(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1] __attribute__((__unused__)); (gpointer) __atomic_load_8 ((&g_define_type_id__volatile), 5); })) && g_once_init_enter (&g_define_type_id__volatile)); }))) {
        GType g_define_type_id = g_type_register_static_simple(((GType)((20) << (2))), g_intern_static_string("Shape"), sizeof(ShapeClass), (GClassInitFunc)(void (*)(void))shape_class_intern_init, sizeof(Shape), (GInstanceInitFunc)(void (*)(void))shape_init, (GTypeFlags)0);
        { { {};
    }
}
(__extension__({ typedef char _GStaticAssertCompileTimeAssertion_3[(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1] __attribute__((__unused__)); (void) (0 ? *(&g_define_type_id__volatile) = (g_define_type_id) : 0); g_once_init_leave ((&g_define_type_id__volatile), (gsize) (g_define_type_id)); }));
}
return g_define_type_id__volatile;
}
;
