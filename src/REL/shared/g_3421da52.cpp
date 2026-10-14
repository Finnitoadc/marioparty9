extern "C" unsigned char* fn_800486E0(int x);

struct Obj {
    int field_0;
    int* field_4;
    unsigned int field_8;
};

extern "C" void shared_g_3421da52(Obj* self, unsigned char v) {
    for (unsigned int i = 0; i < self->field_8; i++) {
        unsigned char* p = fn_800486E0(self->field_4[i]);
        p[0xBB] &= 0xFD; p[0xBB] |= 2;
        fn_800486E0(self->field_4[i])[0xB8] = v;
    }
}
