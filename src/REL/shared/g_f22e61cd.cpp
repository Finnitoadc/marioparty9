struct BitRef {
    unsigned int* p;
    unsigned int mask;
};

extern "C" int shared_g_f22e61cd(BitRef* self) {
    return (*self->p & self->mask) != 0;
}
