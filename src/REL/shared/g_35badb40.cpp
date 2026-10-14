struct Str {
    unsigned isLong : 1;
    unsigned rest : 31;
    unsigned size;
    char* ptr;
};

extern "C" int shared_g_35badb40(const Str* self, const signed char* s, unsigned pos, unsigned n) {
    const signed char* data;
    unsigned len;
    if (!self->isLong) {
        data = (const signed char*)self + 1;
        len = *(const unsigned char*)self & 0x7F;
    } else {
        data = (const signed char*)self->ptr;
        len = self->size;
    }
    if (pos < len && n != 0) {
        const signed char* end = data + len;
        for (const signed char* p = data + pos; p < end; p++) {
            const signed char* q = s;
            for (int i = 0; i < n; i++) {
                if (*p == *q) {
                    return p - data;
                }
                q++;
            }
        }
    }
    return -1;
}
