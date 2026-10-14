extern "C" int fn_8007D190(int a, int b);

struct Obj {
    char pad[0xC];
    unsigned char active;
};

extern "C" int shared_g_293055ae(Obj* self, int a, int b) {
    if (self->active) {
        return fn_8007D190(a, b);
    }
    return -1;
}
