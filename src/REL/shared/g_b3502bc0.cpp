extern "C" void fn_8020B5FC(void* ptr);
extern "C" void* shared_g_23fc310e(void* self, int del);

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

struct Obj {
    char pad[0x168];
    Buffer buf2;
    int pad2;
    Buffer buf1;
};

extern "C" Obj* shared_g_b3502bc0(Obj* self, int del) {
    if (self != 0) {
        Buffer* b = &self->buf1;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b != 0) {
                        b->Free();
                    }
                }
            }
        }
        b = &self->buf2;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b != 0) {
                        b->Free();
                    }
                }
            }
        }
        shared_g_23fc310e(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
