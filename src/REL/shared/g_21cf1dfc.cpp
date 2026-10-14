extern "C" void fn_8020B5FC(void* ptr);

struct FlagBuf {
    unsigned int flags;
    int field_4;
    void* buf;
};

extern "C" FlagBuf* shared_g_21cf1dfc(FlagBuf* self, int del) {
    if (self != 0) {
        if ((self->flags >> 31) != 0) {
            fn_8020B5FC(self->buf);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
