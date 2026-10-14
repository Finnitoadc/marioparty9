struct Str {
    unsigned isLong : 1;
    unsigned rest : 31;
    int pad;
    char* ptr;

    char* Get() { return !isLong ? (char*)this + 1 : ptr; }
};

struct Obj {
    char pad[0x38];
    int idx;
    Str s[29];
    Str a[14];
    Str b[14];
    Str c[14];
};

extern "C" char* shared_g_34b0b47d(Obj* self, int n) {
    switch (n) {
    case 0:
        return self->a[self->idx].Get();
    case 1:
        return self->b[self->idx].Get();
    case 2:
        return self->c[self->idx].Get();
    case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
    default:
        return self->s[n - 3].Get();
    }
}
