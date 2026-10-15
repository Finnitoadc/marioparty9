struct Obj { char pad[0x38]; int field_38; };

extern "C" int shared_g_ff3ede05(Obj* self) {
    return self->field_38;
}
