extern "C" void fn_8020B5FC(void* ptr);

struct E {
    virtual ~E();
};

struct Vec {
    char* data;
    int count;

    char* Begin() { return data; }
    char* End() { return data + count; }
    void Erase(char* f, char* l) { count -= l - f; }
    void Clear() { Erase(Begin(), End()); }
    void Free() {
        if (data != 0) {
            Clear();
            fn_8020B5FC(data);
        }
    }
    void DeleteAll() {
        E** it = (E**)data;
        E** end = (E**)data + count;
        for (; it != end; it++) {
            delete *it;
        }
    }
};

extern "C" Vec* shared_g_22dff6de(Vec* self, int del) {
    if (self != 0) {
        self->DeleteAll();
        Vec* b = self;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b != 0) {
                        b->Free();
                    }
                }
            }
        }
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
