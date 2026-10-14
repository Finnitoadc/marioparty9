struct Obj {
    int field_0;
    int field_4;
    unsigned int field_8;
    char buf[4];
    char* field_10;
};

extern "C" char* shared_g_5a38b408(Obj* self) {
    if ((self->field_8 >> 31) == 0) {
        return (char*)self + 9;
    }
    return self->field_10;
}
