extern "C" void fn_80055F60(int, int);

struct Obj {
    char pad[0xC];
    int field_C;
};

extern "C" void shared_g_5b817a4f(Obj* self) {
    fn_80055F60(self->field_C, 1);
}
