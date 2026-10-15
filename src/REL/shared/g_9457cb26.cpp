struct Obj { char pad[0x1c]; int field_1c; };
extern "C" void fn_8007F1C0(int);
extern "C" void shared_g_9457cb26(Obj* self) {
    if (self->field_1c != -1) { fn_8007F1C0(2); self->field_1c = -1; }
}
