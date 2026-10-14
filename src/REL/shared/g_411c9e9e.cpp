struct Obj {
    char pad[0x10];
    int field_10;
    char pad14;
    unsigned char field_15;
    char pad16;
    unsigned char field_17;
    unsigned char field_18;

    bool IsBusy() { return field_17 != 0 || field_18 != 0; }
};

extern "C" int shared_g_411c9e9e(Obj* self) {
    if (self->field_15 == 0 && self->IsBusy()) {
        return -1;
    }
    return self->field_10;
}
