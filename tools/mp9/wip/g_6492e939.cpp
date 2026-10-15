struct Bits { unsigned pad:26; int b5:1; unsigned b4:1; unsigned rest:4; };
struct O2 { char pad[0x5a4]; union { unsigned flags; Bits bits; }; };
extern "C" void shared_g_6492e939(O2* self, unsigned f) {
    if (((self->flags >> 5) & 1) == f) return;
    self->bits.b5 = f != 0;
    self->bits.b4 = 1;
}
