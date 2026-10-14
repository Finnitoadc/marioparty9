extern "C" int fn_80048FC0();
extern "C" unsigned int fn_8002AF40(void* p);
extern "C" int fn_8004EF20();
extern "C" void fn_8004EF50();
extern "C" void fn_8002AF70(void* p);
extern "C" void fn_8002AF00(void* p, int v);
extern "C" void fn_8004EF10(int v);

struct Obj {
    char pad[0x8];
    void* field_8;
    int field_C;
};

extern "C" void shared_g_5e488482(Obj* self) {
    if (fn_80048FC0() != 0) {
        if (fn_8002AF40(self->field_8) == 0) {
            self->field_C = fn_8004EF20();
            fn_8004EF50();
            for (unsigned int i = 0; i < 4; i++) {
                fn_8002AF70(self->field_8);
            }
            fn_8002AF00(self->field_8, 1);
        }
        fn_8002AF70(self->field_8);
    } else {
        if (fn_8002AF40(self->field_8) == 1) {
            fn_8002AF70(self->field_8);
            fn_8004EF10(self->field_C);
            fn_8002AF00(self->field_8, 0);
        }
    }
}
