extern "C" void fn_8005D970(void* p, int a);

struct Obj {
    char pad[0x15c];
    void* field_15c;
};

extern "C" void shared_g_33117a29(Obj* self, int a) {
    fn_8005D970(self, a);
    if (self->field_15c != 0) {
        fn_8005D970(self->field_15c, a);
    }
}
