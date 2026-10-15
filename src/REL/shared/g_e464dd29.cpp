extern "C" void fn_8020B5FC(void* p);
struct Str { unsigned isLong : 1; unsigned len : 31; int field_4; void* ptr; };
struct Obj {
    int field_0; int field_4;
    Str a; // 8
    Str b; // 0x14
    Str c; // 0x20
    int pad2[2];
    Str d; // 0x34 -> but 0x3c ptr
    Str e; // 0x40
};
extern "C" Obj* shared_g_e464dd29(Obj* self, int del) {
    if (self != 0) {
        if (&self->e != 0) { if (self->e.isLong) fn_8020B5FC(self->e.ptr); }
        if (&self->d != 0) { if (self->d.isLong) fn_8020B5FC(self->d.ptr); }
        if (&self->c != 0) { if (self->c.isLong) fn_8020B5FC(self->c.ptr); }
        if (&self->b != 0) { if (self->b.isLong) fn_8020B5FC(self->b.ptr); }
        if (&self->a != 0) { if (self->a.isLong) fn_8020B5FC(self->a.ptr); }
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
