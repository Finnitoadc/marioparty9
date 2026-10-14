extern "C" void fn_8020B5FC(void* ptr);

struct Buffer {
    void* data;
    int count;
};

static inline void Sub(int* dst, int* src) {
    *dst = *dst - *src;
}

extern "C" Buffer* shared_g_2340a535(Buffer* self, int del) {
    if (self != 0) {
        if (&self->data != 0) {
            if (&self->data != 0) {
                void* data = self->data;
                if (data != 0) {
                    Sub(&self->count, &self->count);
                    fn_8020B5FC(data);
                }
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
