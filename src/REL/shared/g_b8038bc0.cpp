extern "C" void fn_8009ACF0(void* p);

struct Inner { void* field_0; };
struct Elem {
    int pad[3];
    Inner m;
    int pad2;
};

struct Vec {
    Elem* data;
    int count;
};

extern "C" void shared_g_b8038bc0(Vec* self) {
    int n = self->count;
    Elem* e = self->data + n;
    self->count -= n;
    for (int i = n; i != 0; i--) {
        e--;
        if (e != 0) {
            if (&e->m != 0) {
                if (*(void**)((char*)e + 0x10) != 0) fn_8009ACF0(*(void**)((char*)e + 0x10));
            }
        }
    }
}
