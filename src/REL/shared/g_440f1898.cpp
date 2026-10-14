extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80041460(void* p, int x);
extern "C" void fn_8005CE40(void* self, int del);

struct Member {
    char pad[0x148];
    int field_148;
};

struct Obj {
    char pad[0x148];
    Member field_148;
};

extern "C" Obj* shared_g_440f1898(Obj* self, int del) {
    if (self != 0) {
        Member* m = &self->field_148;
        if (m != 0) {
            fn_80041460(&m->field_148, -1);
            if (m != 0) {
                fn_8005CE40(m, 0);
            }
        }
        if (self != 0) {
            fn_8005CE40(self, 0);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
