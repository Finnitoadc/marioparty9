struct O { void* field_0; };
extern "C" void shared_g_69c2e268(void* p, int n);
extern "C" void fn_8020B5FC(void* p);

extern "C" O* shared_g_c33c9b7a(O* self, int del) {
    if (self != 0) {
        shared_g_69c2e268(self->field_0, 1);
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
