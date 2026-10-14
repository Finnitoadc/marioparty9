struct Entry {
    char data[0x44];
};

extern "C" Entry* shared_g_07d4877d(Entry** self, int i) {
    return &(*self)[i];
}
