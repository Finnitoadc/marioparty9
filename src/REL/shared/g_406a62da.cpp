extern "C" int fn_80061900(void* self);

struct Obj {
    char pad[0x168];
    unsigned char flag;
};

extern "C" int shared_g_406a62da(Obj* self) {
    if (self->flag) {
        return 0;
    }
    return fn_80061900(self);
}
