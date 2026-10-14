// Close: stack copies are 4x lwz + lbz (memberwise) but stores kept; block copy gives lwz for flag,
// memberwise copy ctor eliminates stores entirely.
struct It {
    int* cur;
    int* begin;
    int* split;
    int* end;
    unsigned char flag;
};

extern "C" int shared_g_596e1416(It x, It y) {
    It a = x;
    It b = y;
    int n = b.cur - a.cur;
    if (b.cur >= b.split) {
        if (a.cur < b.split) {
            n -= b.end - b.begin;
        }
    } else {
        if (a.cur >= b.split) {
            n += b.end - b.begin;
        }
    }
    return n;
}
