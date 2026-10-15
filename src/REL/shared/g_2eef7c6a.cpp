struct Obj { int field_0; };

extern "C" void shared_g_e46cb6d8(Obj* self, int a);
extern "C" void fn_8020B5FC(void* p);

extern "C" Obj* shared_g_2eef7c6a(Obj* self, int del) {
    if (self != 0) {
        shared_g_e46cb6d8(self, 0);
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
