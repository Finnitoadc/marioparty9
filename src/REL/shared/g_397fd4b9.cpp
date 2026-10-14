extern "C" void fn_8020B5FC(void* ptr);

struct OwnBuf {
    unsigned int flags;
    int field_4;
    void* data;
};

extern "C" OwnBuf* shared_g_397fd4b9(OwnBuf* self, int del) {
    if (self != 0) {
        if (self != 0) {
            if (self->flags >> 31) {
                fn_8020B5FC(self->data);
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
