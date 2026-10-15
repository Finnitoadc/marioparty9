struct Obj { int pad[2]; int field_8; };

extern "C" void fn_80099710(void* p, int a);
extern "C" void fn_80071420(void* p, int a);
extern "C" void fn_8020B5FC(void* p);

extern "C" Obj* shared_g_58d138f7(Obj* self, int del) {
    if (self != 0) {
        fn_80099710(&self->field_8, 0);
        fn_80071420(self, 0);
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
