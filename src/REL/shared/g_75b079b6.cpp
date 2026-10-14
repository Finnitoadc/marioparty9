extern "C" void fn_80041A10(void* p, int a);
extern "C" int fn_80041A20(void* p);

struct Obj {
    char pad[0x170];
    int* field_170;
    void* field_174;
};

extern "C" void shared_g_75b079b6(Obj* self) {
    if (*self->field_170 != 0) {
        fn_80041A10(self->field_174, 0);
        while (fn_80041A20(self->field_174) == 0) {
        }
    }
}
