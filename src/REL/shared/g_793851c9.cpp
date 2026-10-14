struct Obj {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
};

extern "C" int shared_g_793851c9(Obj* self) {
    int n;
    if (self->field_10 == 0) {
        n = 0;
    } else {
        n = (self->field_10 - 1) * 0x55;
    }
    return n - (self->field_0 + self->field_4);
}
