struct FlagBuf {
    unsigned int flags;
    int field_4;
    char* buf;
};

extern "C" char* shared_g_16623138(FlagBuf* self) {
    if ((self->flags >> 31) == 0) {
        return (char*)self + 1;
    }
    return self->buf;
}
