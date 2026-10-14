extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_8006AFD0(void* obj, int flags);

struct OwnBuf {
    unsigned int flags;
    int field_4;
    void* data;
};

struct Obj {
    char pad[0x90];
    OwnBuf buf90;
    OwnBuf buf9c;
};

extern "C" Obj* shared_g_01329087(Obj* self, int del) {
    if (self != 0) {
        if (&self->buf9c != 0) {
            if (self->buf9c.flags >> 31) {
                fn_8020B5FC(self->buf9c.data);
            }
        }
        if (&self->buf90 != 0) {
            if (self->buf90.flags >> 31) {
                fn_8020B5FC(self->buf90.data);
            }
        }
        fn_8006AFD0(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
