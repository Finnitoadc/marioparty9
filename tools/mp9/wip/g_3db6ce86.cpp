extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80086B90(void* dst, void* src);
extern "C" void fn_80086F10(void* obj, int flags);

struct Buffer {
    char* data;
    int count;
    int field_8;

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
    int v;
    Handle() : v(0) {}
    void Release() { fn_80086F10(this, -1); }
    void Swap(Handle& o) { fn_80086B90(this, &o); }
};

struct Obj {
    Buffer buf0;
    Buffer buf1;
    Buffer buf2;
    Handle handle;

    void ClearAll() {
        buf0.Clear();
        buf1.Clear();
        buf2.Clear();
        handle.Release();
    }
};

extern "C" Obj* shared_g_3db6ce86(Obj* self, int del) {
    if (self != 0) {
        Handle tmp;
        self->handle.Swap(tmp);
        tmp.Release();
        self->ClearAll();
        Buffer* b = &self->buf2;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b != 0) {
                        b->Free();
                    }
                }
            }
        }
        b = &self->buf1;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b != 0) {
                        b->Free();
                    }
                }
            }
        }
        b = &self->buf0;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b != 0) {
                        b->Free();
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
