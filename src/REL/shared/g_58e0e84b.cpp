extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* self, int flags);

struct Deletable {
    virtual void v0(int del);
};

struct Ptr {
    Deletable* p;
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
    char pad[0xC];
    Buffer buf;
    char pad14[0x74 - 0x14];
    Ptr ptr;
};

extern "C" Holder* shared_g_58e0e84b(Holder* self, int del) {
    if (self != 0) {
        Ptr* p = &self->ptr;
        if (p != 0) {
            if (p->p != 0) {
                p->p->v0(1);
            }
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
