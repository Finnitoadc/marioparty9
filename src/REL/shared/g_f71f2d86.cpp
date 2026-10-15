extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* self, int x);

struct Buffer {
    char* data;
    int count;

    char* Begin() { return data; }
    char* End() { return data + count; }
    void Erase(char* first, char* last) { count -= last - first; }
    void Clear() { Erase(Begin(), End()); }
};

struct S {
    char pad[0x24];
    Buffer buf;
};

extern "C" S* shared_g_f71f2d86(S* self, int del) {
    if (self != 0) {
        Buffer* b = &self->buf;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b->data != 0) {
                        b->Clear();
                        fn_8020B5FC(b->data);
                    }
                }
            }
        }
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
