struct Obj { char pad[0x60]; int field_60; };
extern "C" int shared_g_debb08c4(Obj* self) {
    return self->field_60;
}
