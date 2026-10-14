// Deleting destructor of a small object that owns a buffer at +8 (same code as strap_base).
extern "C" {
void fn_8020B5FC(void* ptr);
void fn_80071420(void* self, int flags);
}

struct BufObj {
    void* vtbl;
    int field_4;
    void* buf;
};

extern "C" BufObj* shared_g_2b726490(BufObj* self, int del) {
    if (self != 0) {
        void** bufAddr = &self->buf;
        if (bufAddr != 0) {
            fn_8020B5FC(*bufAddr);
        }
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
