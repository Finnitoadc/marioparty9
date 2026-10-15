struct S { int field_0; int field_4; int* field_8; };
extern "C" void shared_g_a645d15c(S* self) {
    self->field_0 = 0;
    self->field_4 = 0;
    self->field_8 = &self->field_4;
}
