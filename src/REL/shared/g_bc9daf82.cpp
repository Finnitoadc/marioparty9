extern "C" void* memset(void*, int, unsigned);

struct Obj {
    char pad0[4];
    unsigned char field_4;
    char pad5[3];
    int field_8;
    int field_C;
    char a10[0x10];
    char a20[0x10];
    char a30[0x30];
    int field_60;
    int pad64[2];
    int field_6C;
};

extern "C" void shared_g_bc9daf82(Obj* self) {
    self->field_4 = 0;
    self->field_C = 0;
    self->field_8 = 0;
    memset(self->a10, 0, 0x10);
    memset(self->a20, 0, 0x10);
    memset(self->a30, 0, 0x30);
    self->field_6C = 0;
}
