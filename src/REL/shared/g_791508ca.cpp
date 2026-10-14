struct Str {
    unsigned isLong : 1;
    unsigned rest : 31;
    int size;
    char* ptr;
};

extern "C" void fn_8020B5FC(void* p);

static inline void FreeStr(Str* s) {
    if (s != 0) {
        if (s->isLong) {
            fn_8020B5FC(s->ptr);
        }
    }
}

struct Member {
    int field_0;
    Str s;
};

struct Obj {
    char pad[0x8];
    Str s;
    char pad14[0x8];
    Member m;
};

extern "C" Obj* shared_g_791508ca(Obj* self, int del) {
    if (self != 0) {
        Member* m = &self->m;
        if (m != 0) {
            FreeStr(&m->s);
        }
        if (self != 0) {
            FreeStr(&self->s);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
