extern "C" void fn_8020B5FC(void*);

struct Buffer {
    char* data;
    int count;

    char* Begin() { return data; }
    char* End() { return data + count; }
    void Erase(char* f, char* l) { count -= l - f; }
};

struct Obj {
    int field_0;
    Buffer buf;
};

extern "C" Obj* shared_g_5b814380(Obj* self, int del) {
    if (self != 0) {
        Buffer* b = &self->buf;
        if (b != 0) {
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
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
