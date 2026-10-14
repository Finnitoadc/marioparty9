extern "C" char* fn_80052990();

struct Entry {
    signed char v[8];
    int field_08;
};

struct Table {
    unsigned short field_00;
    unsigned short count;
    char pad[0x8];
    Entry* entries;

    Entry* Get(int i) {
        if (i < count && i >= 0) {
            return &entries[i];
        }
        return 0;
    }
};

extern "C" int shared_g_22813f98(int x) {
    Table* t = (Table*)(fn_80052990() + 0x2878);
    int n = 0;
    unsigned int size = t->count;
    for (unsigned int i = 0; i < size; i++) {
        Entry* e = t->Get(i);
        bool ok = false;
        if (t != 0 && e != 0) {
            ok = true;
        }
        if (ok) {
            for (int j = 0; j < 8; j++) {
                if (x == e->v[j]) {
                    n++;
                }
            }
        }
    }
    return n;
}
