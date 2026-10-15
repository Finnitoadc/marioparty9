struct Obj {
    char pad[0x40];
    void* field_40;
};
extern "C" void* shared_g_d7e5d9be(Obj* self) {
    return self->field_40;
}
