extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_80071420(void* self, int flags);
extern "C" void fn_8009ACF0(void* p);

struct Elem {
    int field_0;
    void* field_4;
    ~Elem() { if (field_4 != 0) fn_8009ACF0(field_4); }
};
static inline void Destroy3(Elem* p, int del) {
    if (p != 0) {
        if (p->field_4 != 0) {
            fn_8009ACF0(p->field_4);
        }
        if (del > 0) fn_8020B5FC(p);
    }
}

static inline void Destroy(Elem* p) {
    if (p != 0) {
        if (p->field_4 != 0) {
            fn_8009ACF0(p->field_4);
        }
    }
}

static inline void DestroyBack(Elem* p, int n) { while (n != 0) { --p; Destroy(p); n--; } }
static inline void DestroyBack2(Elem* p, int n) { for (; n != 0; n--) { --p; Destroy(p); } }
static inline void DestroyFwd(Elem* first, Elem* last) { while (first != last) { --last; Destroy(last); } }
struct Array {
    Elem* data;
    unsigned int count;

    void Free() {
        if (data != 0) {
Elem* p; unsigned int n; n = count; p = data + n; count -= n; while (n != 0) { --p; Destroy(p); n--; }
            fn_8020B5FC(data);
        }
    }
};

struct Holder {
    char pad[0x8];
    Array arr;
};

extern "C" Holder* shared_g_48328375(Holder* self, int del) {
    if (self != 0) {
        Array* a = &self->arr;
        if (a != 0) {
            if (a != 0) {
                if (a != 0) {
                    a->Free();
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
