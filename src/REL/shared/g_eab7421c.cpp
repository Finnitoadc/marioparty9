struct Obj {
    char pad[8];
    float field_8;
};

extern "C" float shared_g_eab7421c(Obj* self) {
    return self->field_8;
}
