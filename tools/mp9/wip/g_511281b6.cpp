extern "C" void fn_8020B5FC(void* ptr);
struct Elem { virtual void Destroy(int flags); int field_4; };
struct Buffer { Elem* data; int count;

};
struct Obj { char pad[0x8]; Buffer buf; };
extern "C" Obj* shared_g_511281b6(Obj* self, int del) {
    if (self != 0) {
        Buffer* b = &self->buf;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b->data != 0) {
Elem* last = b->data + b->count; int n = b->count; b->count -= n; while (n != 0) { --last; last->Destroy(-1); n--; }
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
