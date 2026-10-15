extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_8002AE40(void* obj, int flags);
extern "C" void shared_g_049107ea(void* self, int del);

struct Own {
    void* ptr;
};

struct Obj {
    char pad[8];
    Own own;
};

extern "C" Obj* shared_g_9986dcc9(Obj* self, int del) {
    if (self != 0) {
        Own* o = &self->own;
        if (o != 0) {
            fn_8002AE40(o->ptr, 1);
        }
        shared_g_049107ea(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
