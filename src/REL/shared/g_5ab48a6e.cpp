extern "C" void fn_80061A60(void* p);

struct Obj {
    char pad[0x70];
    void* field_70;
};

extern "C" void shared_g_5ab48a6e(Obj* self) {
    fn_80061A60(self->field_70);
}
