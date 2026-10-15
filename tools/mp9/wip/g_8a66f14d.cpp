struct Elem {
    int field_00;
    void* ptr;
};
struct Vec {
    Elem* data;
    int count;
};
struct Holder {
    int pad;
    Vec v;
};
extern "C" void fn_8009ACF0(void*);
extern "C" void fn_8020B5FC(void*);
extern "C" Holder* shared_g_8a66f14d(Holder* self, int del) {
    if (self != 0) {
        Vec* p = &self->v;
        if (p != 0) {
            if (p != 0) {
                if (p != 0) {
                    if (p->data != 0) {
                        int n = p->count;
                        Elem* e = p->data + n;
                        p->count -= n;
                        for (; n != 0; n--) {
                            e--;
                            if (e != 0) {
                                if (e->ptr != 0) fn_8009ACF0(e->ptr);
                            }
                        }
                        fn_8020B5FC(p->data);
                    }
                }
            }
        }
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
