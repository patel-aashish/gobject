static void shape_type_init(ShapeType* self);
static void shape_type_class_init(ShapeTypeClass* klass);
static gpointer shape_type_parent_class = ((void*)0);
static gint ShapeType_private_offset;
static void shape_type_class_intern_init(gpointer klass)
{
    shape_type_parent_class = g_type_class_peek_parent(klass);
    if (ShapeType_private_offset != 0)
        g_type_class_adjust_private_offset(klass, &ShapeType_private_offset);
    shape_type_class_init((ShapeTypeClass*)klass);
}
__attribute__((__unused__)) static inline gpointer shape_type_get_instance_private(ShapeType* self) { return (((gpointer)((guint8*)(self) + (glong)(ShapeType_private_offset)))); }

GType shape_type_get_type(void)
{
    static volatile gsize g_define_type_id__volatile = 0;
    if ((__extension__({ typedef char _GStaticAssertCompileTimeAssertion_1[(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1] __attribute__((__unused__)); (void) (0 ? (gpointer) *(&g_define_type_id__volatile) : 0); (!(__extension__ ({ typedef char _GStaticAssertCompileTimeAssertion_2[(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1] __attribute__((__unused__)); (gpointer) __atomic_load_8 ((&g_define_type_id__volatile), 5); })) && g_once_init_enter (&g_define_type_id__volatile)); }))) {
        GType g_define_type_id = g_type_register_static_simple(((GType)((20) << (2))), g_intern_static_string("ShapeType"), sizeof(ShapeTypeClass), (GClassInitFunc)(void (*)(void))shape_type_class_intern_init, sizeof(ShapeType), (GInstanceInitFunc)(void (*)(void))shape_type_init, (GTypeFlags)0);
        { { {};
    }
}
(__extension__({ typedef char _GStaticAssertCompileTimeAssertion_3[(sizeof *(&g_define_type_id__volatile) == sizeof (gpointer)) ? 1 : -1] __attribute__((__unused__)); (void) (0 ? *(&g_define_type_id__volatile) = (g_define_type_id) : 0); g_once_init_leave ((&g_define_type_id__volatile), (gsize) (g_define_type_id)); }));
}
return g_define_type_id__volatile;
}

