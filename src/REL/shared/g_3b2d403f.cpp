struct Str {
    unsigned int word0;
    unsigned int len;
};

extern "C" int shared_g_3b2d403f(Str* self) {
    unsigned int n;
    if ((self->word0 >> 31) == 0) {
        n = *(unsigned char*)self & 0x7F;
    } else {
        n = self->len;
    }
    return n == 0;
}
