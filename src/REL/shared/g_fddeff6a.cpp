struct Entry {
    char data[0x14];
};

extern "C" Entry* shared_g_fddeff6a(Entry** self, int i) {
    return &(*self)[i];
}
