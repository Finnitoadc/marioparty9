struct Obj {
    char pad[0x10];
    int field_10;
    char pad2[1];
    unsigned char field_15;
    char pad3[1];
    unsigned char field_17;
    unsigned char field_18;

    int Flag() const {
        int t = 0;
        if (field_17 != 0 || field_18 != 0) t = 1;
        return t;
    }
};

extern "C" int fn_80070680(int id);
extern "C" void fn_8006E0C0(int a, int b);

extern "C" void shared_g_8e6a190c(Obj* self, int arg) {
    int id;
    if (self->field_15 == 0 && self->Flag() != 0) {
        id = -1;
    } else {
        id = self->field_10;
    }
    if (id != -1) {
        fn_8006E0C0(fn_80070680(id), arg);
    }
}
