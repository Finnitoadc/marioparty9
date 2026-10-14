extern "C" unsigned int fn_80070DC0(void);
extern "C" void fn_80070DB0(int id);

struct Obj {
    int field_0;
    int field_4;
    unsigned int field_8;
    int field_c;
    unsigned char active;
};

extern "C" void shared_g_11e271f9(Obj* self) {
    if (self->active) {
        if (self->field_8 == fn_80070DC0()) {
            fn_80070DB0(self->field_c);
            self->active = 0;
        }
    }
}
