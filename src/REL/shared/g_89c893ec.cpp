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
    char pad[0xD8];
    Buffer b1;
    char gap[8];
    Buffer b2;
};

extern "C" Holder* shared_g_89c893ec(Holder* self, int del) {
    if (self != 0) {
        Buffer* b = &self->b2;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b != 0) {
                        b->Free();
                    }
                }
            }
        }
        b = &self->b1;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    b->Free();
                }
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
