extern "C" void fn_8020B5FC(void* p);
struct Str { unsigned isLong : 1; unsigned len : 31; int field_4; void* ptr; };
struct Buffer {
    Str* data;
    int count;
    Str* Begin() { return data; }
    Str* End() { return data + count; }
    void Erase(Str* f, Str* l) { count -= l - f; }
    void Clear() { Erase(Begin(), End()); }
};
extern "C" Buffer* shared_g_d41b01ed(Buffer* self, int del) {
    if (self != 0) {
        if (&*self != 0) {
        if (&*self != 0) {
            if (self->data != 0) {
                int n = self->count;
                Str* e = self->data + n;
                self->count -= n;
                for (int i = n; i != 0; i--) {
                    e--;
                    if (e != 0) {
                        if (e->isLong) fn_8020B5FC(e->ptr);
                    }
                }
                fn_8020B5FC(self->data);
            }
        }
        }
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
