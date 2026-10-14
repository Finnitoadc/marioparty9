extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* obj, int flags);
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
    char pad[0x164];
    char field_164[0xC];
    Buffer buf;
};

extern "C" Obj* shared_g_01006975(Obj* self, int del) {
    if (self != 0) {
        Buffer* b = &self->buf;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b != 0) {
                        b->Free();
                    }
                }
            }
        }
        fn_80071420(self->field_164, 0);
        shared_g_23fc310e(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
