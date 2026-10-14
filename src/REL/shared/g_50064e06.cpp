extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_8002C0A0(void* obj, int flags);

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
    char pad[0x1D0];
    Buffer buf;
};

extern "C" Obj* shared_g_50064e06(Obj* self, int del) {
    if (self != 0) {
        Buffer* b = &self->buf;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    b->Free();
                }
            }
        }
        fn_8002C0A0(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
