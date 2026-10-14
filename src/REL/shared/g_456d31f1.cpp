extern "C" long long* fn_800385B0(int x);

struct Obj {
    char pad0[0x10];
    int field_10;
};

extern "C" long long shared_g_456d31f1(Obj* self) {
    return *fn_800385B0(self->field_10);
}
