extern "C" void fn_8005DA60(void* p);

struct Obj {
    int field_0;
    int field_4;
    void* field_8;
};

extern "C" void shared_g_288e3439(Obj* self) {
    fn_8005DA60(self->field_8);
}
