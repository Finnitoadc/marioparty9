extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* p, int flags);
extern "C" void shared_g_23fc310e(void* self, int flags);

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
    Buffer buf168;
    char pad2[0x4];
    Buffer buf174;
    char pad3[0x4];
    char field_180[0x4];
};

extern "C" Obj* shared_g_7e0013c5(Obj* self, int del) {
    if (self != 0) {
        fn_80071420(self->field_180, 0);
        if (self != 0) {
            Buffer* b174 = &self->buf174;
            if (b174 != 0) {
                if (b174 != 0) {
                    if (b174 != 0) {
                        if (b174 != 0) {
                            b174->Free();
                        }
                    }
                }
            }
            Buffer* b168 = &self->buf168;
            if (b168 != 0) {
                if (b168 != 0) {
                    if (b168 != 0) {
                        if (b168 != 0) {
                            b168->Free();
                        }
                    }
                }
            }
            shared_g_23fc310e(self, 0);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
