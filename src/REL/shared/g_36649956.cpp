struct Color {
    unsigned char r, g, b, a;
};

extern "C" void shared_g_36649956(Color* dst, Color src) {
    *dst = src;
}
