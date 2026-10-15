struct O { int x; };
struct S { char pad[0x23c]; O* arr[1]; };
extern "C" O* shared_g_6627d9b0(S* self, int i) {
    O* v = self->arr[i];
    if (v != 0) return v;
    return 0;
}
