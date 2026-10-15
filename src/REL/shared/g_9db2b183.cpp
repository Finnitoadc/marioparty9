struct Obj {
    char pad[0x1c];
    int field_1c;
};

extern "C" int* shared_g_9db2b183(Obj* self) {
    return &self->field_1c;
}
