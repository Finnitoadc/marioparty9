struct Buttons {
    char pad[0x20];
    unsigned int held;
    unsigned int pressed;
    unsigned int released;
};

extern "C" void shared_g_c52f4b03(Buttons* self, unsigned int v) {
    unsigned int changed = v ^ self->held;
    self->held = v;
    self->pressed = changed & v;
    self->released = changed & (v == 0);
}
