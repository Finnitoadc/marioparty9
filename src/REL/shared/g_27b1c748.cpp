extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* self, int flags);

extern "C" void fn_8003F020(void* p, int n);

struct Ptr {
    void* p;
};

struct Buffer {
    char* data;
    int count;

    char* Begin() { return data; }
    char* End() { return data + count; }
    void Erase(char* first, char* last) { count -= last - first; }
    void Clear() { Erase(Begin(), End()); }
};

struct Holder {
    char pad[0x14];
    int field_14;
    char pad18[0x48 - 0x18];
    Buffer buf;
    char pad50[0x60 - 0x50];
    Ptr ptr;
    int field_64;
};

extern "C" Holder* shared_g_27b1c748(Holder* self, int del) {
    if (self != 0) {
        self->field_14 = 0;
        if (self->field_64 != -1) {
            self->field_64 = 1;
        }
        Ptr* p = &self->ptr;
        if (p != 0) {
            fn_8003F020(p->p, 1);
        }
        Buffer* b = &self->buf;
        if (b != 0) {
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
        }
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
