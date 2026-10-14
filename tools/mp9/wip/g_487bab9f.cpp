extern "C" void fn_8020B5FC(void* ptr);
struct Elem { virtual void Destroy(int flags); int field_4; };
struct Buffer { Elem* data; unsigned int count; };
extern "C" Buffer* shared_g_487bab9f(Buffer* self, int del) {
    if (self != 0) {
        if (self != 0) {
            if (self != 0) {
                if (self->data != 0) {
unsigned int n = self->count; Elem* last = self->data + n; self->count -= n; while (n != 0) { --last; last->Destroy(-1); n--; }
                    fn_8020B5FC(self->data);
                }
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
