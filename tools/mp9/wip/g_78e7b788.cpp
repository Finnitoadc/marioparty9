struct Elem {
    int pad[0];
    virtual ~Elem();
    int field_04;
};
struct Vec {
    Elem* data;
    int count;
};
struct Sub {
    int pad;
    int field_04;
};
struct Obj;
struct D {
    virtual ~D();
};
struct Holder {
    char pad0[8];
    D* field_08;
    char pad1[0x20];
    Vec v2c;
    int* field_34;
    int* field_38;
    Vec v3c;
    char pad2[0x18];
    int* field_5c;
    Vec v60;
    char pad3[0xc];
    Sub field_6c;
};
extern "C" void fn_80086F10(void*, int);
extern "C" void fn_80046040(int, int);
extern "C" void fn_8020B5FC(void*);
extern "C" void shared_g_049107ea(void*, int);
static inline void ClearVec(Vec* p) {
    if (p != 0) {
        if (p != 0) {
            if (p != 0) {
                if (p->data != 0) {
                    int n = p->count;
                    Elem* e = p->data + n;
                    p->count -= n;
                    for (; n != 0; n--) {
                        e--;
                        e->~Elem();
                    }
                    fn_8020B5FC(p->data);
                }
            }
        }
    }
}
extern "C" Holder* shared_g_78e7b788(Holder* self, int del) {
    if (self != 0) {
        if (&self->field_6c != 0) fn_80086F10(&self->field_6c.field_04, -1);
        ClearVec(&self->v60);
        if (&self->field_5c != 0) fn_80046040(*self->field_5c, 1);
        ClearVec(&self->v3c);
        if (&self->field_38 != 0) fn_80046040(*self->field_38, 1);
        ClearVec(&self->v2c);
        if (&self->field_08 != 0) {
            if (self->field_08 != 0) delete self->field_08;
        }
        shared_g_049107ea(self, 0);
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
