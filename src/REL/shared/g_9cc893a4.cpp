struct Obj {
    char pad[0x28];
    int field_28;
};

extern "C" int shared_g_9cc893a4(Obj* self) {
    return self->field_28;
}
