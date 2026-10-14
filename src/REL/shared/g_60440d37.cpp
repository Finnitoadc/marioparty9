struct Hdr {
    int field_0;
    int field_4;
};

struct Obj {
    Hdr* hdr;
};

extern "C" void* shared_g_60440d37(Obj* self) {
    Hdr* h = self->hdr;
    if (h->field_4 != 0) {
        return (char*)h + h->field_4;
    }
    return 0;
}
