// Close: first.cur/last.cur get swapped regs (r6/r7) and the two final stw are scheduled later than target
extern "C" void* memmove(void* dst, const void* src, unsigned long n);

struct It {
    int* cur;
    int* begin;
    int* split;
    int* end;
    unsigned char flag;
};

struct Ring {
    int* data;
    unsigned int count;
    unsigned int field_8;

    int* End() { return data + count; }
    void Shrink(int k) {
        field_8 += k;
        count -= k;
    }
};

extern "C" void shared_g_1a164e83(Ring* self, const It& first, const It& last) {
    int* e = self->End();
    if (first.cur <= last.cur) {
        int n = last.cur - first.cur;
        memmove(e - n, first.cur, n * 4);
        self->Shrink(last.cur - first.cur);
    } else {
        int n = last.cur - last.begin;
        int* d = e - n;
        memmove(d, last.begin, n * 4);
        int m = first.end - first.cur;
        memmove(d - m, first.cur, m * 4);
        int k = (last.cur - last.begin) + (first.end - first.cur);
        self->count -= k;
        self->field_8 += k;
    }
}
