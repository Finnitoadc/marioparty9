struct Obj { char pad[8]; int field_8; };
extern "C" int shared_g_bd6fd205(Obj* self) {
    return self->field_8 != 1;
}
