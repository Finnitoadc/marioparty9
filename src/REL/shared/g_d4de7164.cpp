struct Inner {
    int field_0;
    char data[1];
};

struct Holder {
    Inner* p;
};

extern "C" void* shared_g_d4de7164(Holder* self, int idx) {
    char* b = (char*)&self->p->data[0];
    if (b != 0) {
        int off = *(int*)(b + (idx + 1) * 16 + 0x14);
        if (off != 0) return b + off;
        return 0;
    }
    return 0;
}
