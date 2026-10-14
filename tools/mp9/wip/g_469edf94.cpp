extern "C" void fn_8003F020(void* p, int a);
extern "C" void fn_80055F60(void* p, int a);
extern "C" void fn_80041D00(void* p);

struct Base {
    virtual ~Base();
};

struct Obj {
    char pad[0x184];
    Base* field_184;
    Base* field_188[8];
    void* field_1A8[4];
    char field_1B8[0x8];
    void* field_1C0;
    int field_1C4;
    int field_1C8;
    int field_1CC;

    void Clear() {
        field_184 = 0;
        char* p = field_1B8;
        field_1C4 = 0;
        field_1C8 = 0;
        field_1CC = 0;
        field_1C0 = 0;
        for (int j = 0; j < 8; j++) {
            field_188[j] = 0;
        }
        fn_80041D00(p);
    }
};

extern "C" void shared_g_469edf94(Obj* self) {
    if (self->field_1C8 == 0) {
        return;
    }
    if (self->field_184 != 0) {
        delete self->field_184;
        self->field_184 = 0;
    }
    for (unsigned int i = 0; i < 8; i++) {
        if (self->field_188[i] != 0) {
            delete self->field_188[i];
            self->field_188[i] = 0;
        }
    }
    for (unsigned int i = 0; i < 4; i++) {
        if (self->field_1A8[i] != 0) {
            fn_8003F020(self->field_1A8[i], 1);
            self->field_1A8[i] = 0;
        }
    }
    if (self->field_1C0 != 0) {
        fn_80055F60(self->field_1C0, 1);
        self->field_1C0 = 0;
    }
    self->Clear();
}
