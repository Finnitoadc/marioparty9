struct Obj {
    char pad[0xe];
    unsigned char field_e;
    unsigned char field_f;
};

extern "C" void shared_g_32b92df1(Obj* self, unsigned char v, unsigned int flag) {
    if (self->field_f == 0) {
        self->field_e = v;
        if (flag == 1) {
            self->field_f = 1;
        }
    }
}
