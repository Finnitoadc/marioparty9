extern "C" void fn_8020B5FC(void* ptr);

struct Buffer {
    char* data;
    int count;

    char* Begin() { return data; }
    char* End() { return data + count; }
    void Erase(char* first, char* last) { count -= last - first; }
    void Clear() { Erase(Begin(), End()); }
    void Free() {
        if (data != 0) {
            Clear();
            fn_8020B5FC(data);
        }
    }
};

struct Holder {
    Buffer buf;
};

extern "C" Holder* shared_g_2340a535(Holder* self, int del) {
    if (self != 0) {
        if (&self->buf != 0) {
            if (&self->buf != 0) {
                self->buf.Free();
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
