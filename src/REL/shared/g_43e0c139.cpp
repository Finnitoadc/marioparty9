extern "C" int fn_8020BE80(float x);
extern "C" float lbl_8026E3B0;

struct Obj {
    char pad[0x50];
    unsigned char field_50;
    char pad51[0x58 - 0x51];
    int field_58;
};

extern "C" void shared_g_43e0c139(Obj* self, float x) {
    self->field_58 = fn_8020BE80(x * lbl_8026E3B0);
    self->field_50 = 0;
}
