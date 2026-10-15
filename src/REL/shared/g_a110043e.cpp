struct S { char pad[0x1C]; void* field_1C; };
extern "C" void fn_80048BD0(void* p);
extern "C" void shared_g_a110043e(S* self) {
    fn_80048BD0(self->field_1C);
}
