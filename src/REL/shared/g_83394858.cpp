struct Bits {
    unsigned char b0_a : 1;
    unsigned char b0_b : 7;
    unsigned char b1;
};

struct Obj {
    union {
        unsigned int flags;
        Bits bits;
    } u;
    int field_4;
    char* data;
};

extern "C" void shared_g_83394858(Obj* self) {
    if (!(self->u.flags >> 31)) {
        self->u.bits.b1 = 0;
        self->u.bits.b0_b = 0;
    } else {
        self->data[0] = 0;
        self->field_4 = 0;
    }
}
