struct Header {
    char pad[0x10];
    int field_10;
};

struct Obj {
    Header* hdr;
};

extern "C" char* shared_g_4377f6df(Obj* self) {
    Header* h = self->hdr;
    if (h->field_10 != 0) {
        return (char*)h + h->field_10;
    }
    return 0;
}
