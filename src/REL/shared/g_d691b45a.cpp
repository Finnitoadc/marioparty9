struct In { char pad[4]; void* p; };
struct S { In m; };
extern "C" void fn_8009ACF0(void* p);
extern "C" void fn_8020B5FC(void* p);
struct T { int pad; In m; };
extern "C" T* shared_g_d691b45a(T* self, int del) {
    if (self != 0) {
        if (&self->m != 0) {
            if (self->m.p != 0) fn_8009ACF0(self->m.p);
        }
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
