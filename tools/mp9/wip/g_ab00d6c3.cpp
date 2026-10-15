struct Vec { int x, y, z; };
extern "C" Vec lbl_80237470;
struct Inner { char pad[0x120]; Vec field_120; };
struct S {
    char pad[0x588];
    Inner* field_588;
    unsigned char field_58C;
};
static inline void Cp(Vec* d, const Vec* p) { *d = *p; }
extern "C" void shared_g_ab00d6c3(S* self, int v) {
    self->field_58C = v;
    if (v == 0) {
        Inner* d = self->field_588;
        Cp(&d->field_120, &lbl_80237470);
    }
}
