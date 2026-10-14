struct Obj {
    char pad[0x7D4];
    unsigned char flag;
    char pad2[3];
    char data[4];
};

extern "C" void* shared_g_be8174a3(Obj* self) {
    if (self->flag) {
        return 0;
    }
    return self->data;
}
