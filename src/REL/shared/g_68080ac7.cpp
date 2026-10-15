extern "C" void fn_8020B5FC(void* ptr);

struct Buffer {
    char* data;
    int count;

    char* Begin() { return data; }
    char* End() { return data + count; }
    void Erase(char* first, char* last) { count -= last - first; }
};

struct Holder {
    int pad[29];
    Buffer buf;
};

extern "C" Holder* shared_g_68080ac7(Holder* self, int del) {
    if (self != 0) {
        Buffer* b = &self->buf;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b->data != 0) {
                        b->Erase(b->Begin(), b->End());
                        fn_8020B5FC(b->data);
                    }
                }
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
