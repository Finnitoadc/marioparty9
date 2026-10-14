extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80086F10(void* obj, int flags);
extern "C" void fn_8005CE40(void* self, int flags);

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

struct Handle {
    int field_0;
    char obj[4];
};

struct Obj {
    char pad[0x148];
    Handle handle;
    Buffer buf;
};

extern "C" Obj* shared_g_0289f34b(Obj* self, int del) {
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
        Handle* h = &self->handle;
        if (h != 0) {
            fn_80086F10(h->obj, -1);
        }
        fn_8005CE40(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
