struct Obj {
    char pad[0x17];
    unsigned char a;
    unsigned char b;
};

extern "C" int shared_g_c2157065(Obj* self) {
    int r = 0;
    if (self->a != 0 || self->b != 0) r = 1;
    return r;
}
