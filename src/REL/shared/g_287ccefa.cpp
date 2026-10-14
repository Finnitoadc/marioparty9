struct Obj {
    char pad0[0x18];
    unsigned char field_18;
};

extern "C" bool shared_g_287ccefa(Obj* self) {
    return self->field_18 == 0;
}
