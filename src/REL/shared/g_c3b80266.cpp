struct S { char pad[0x3c4]; unsigned flags; };
extern "C" void shared_g_c3b80266(S* self, int on) {
    if (on) self->flags |= 4;
    else self->flags &= ~4u;
}
