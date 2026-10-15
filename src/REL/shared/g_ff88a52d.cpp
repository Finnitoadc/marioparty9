struct Obj { char pad[0x10]; char field_10[4]; };
extern "C" char* shared_g_ff88a52d(Obj* self) {
    return self->field_10;
}
