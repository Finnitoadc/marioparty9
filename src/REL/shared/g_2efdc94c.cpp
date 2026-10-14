struct Obj {
    char pad0[0x20];
    int field_20;
};

extern "C" bool shared_g_2efdc94c(Obj* self) {
    int v = self->field_20;
    if (v == 0) {
        return true;
    }
    if (v == -1) {
        return true;
    }
    if (v == 9) {
        return true;
    }
    if (v == 10) {
        return true;
    }
    if (v == 16) {
        return true;
    }
    if (v == 17) {
        return true;
    }
    return v == 7;
}
