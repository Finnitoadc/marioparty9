extern "C" void fn_8009ACF0(void* p);

struct Sub {
    int field_0;
    void* field_4;
};

struct Obj {
    int field_0;
    Sub field_4;
};

extern "C" void shared_g_578cbd11(void* self, Obj* a) {
    if (a != 0) {
        if (&a->field_4 != 0) {
            if (a->field_4.field_4 != 0) {
                fn_8009ACF0(a->field_4.field_4);
            }
        }
    }
}
