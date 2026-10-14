struct Vec {
    float x, y, z;
};

extern "C" Vec* fn_80060100(void* obj);

struct Obj {
    char pad[0x68];
    char sub[0x758];
    unsigned char field_7c0;
    char pad2[3];
    int field_7c4;
    Vec field_7c8;
    unsigned char field_7d4;
};

extern "C" void shared_g_ebf52cfa(Obj* self, unsigned char on) {
    self->field_7c0 = on;
    self->field_7c4 = 0;
    if (on) {
        Vec* p = fn_80060100(self->sub);
        self->field_7c8 = *p;
        self->field_7d4 = 1;
    }
}
