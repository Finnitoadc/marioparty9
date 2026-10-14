struct Elem {
    char pad[0x14];
};

struct It {
    Elem* p;
};

extern "C" It* shared_g_3481c21a(It* self) {
    self->p++;
    return self;
}
