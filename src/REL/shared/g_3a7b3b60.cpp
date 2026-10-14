extern "C" void fn_8005DA60(void* p);

struct Obj {
    char pad0[0x8];
    int field_8;
};

extern "C" void shared_g_3a7b3b60(Obj* self) {
    fn_8005DA60(&self->field_8);
}
