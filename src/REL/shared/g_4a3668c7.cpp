extern "C" void fn_8020B5FC(void* ptr);

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
    char pad[8];
    Buffer b8;
    char pad2[4];
    Buffer b14;
};

extern "C" Obj* shared_g_4a3668c7(Obj* self, int del) {
    if (self != 0) {
        Buffer* b = &self->b14;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    b->Free();
                }
            }
        }
        Buffer* c = &self->b8;
        if (c != 0) {
            if (c != 0) {
                if (c != 0) {
                    c->Free();
                }
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
