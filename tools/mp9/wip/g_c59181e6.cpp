struct Entry {
    int id;
    int arg;
    int field_8;
};

struct Obj {
    char pad[0x29C];
    Entry* begin;
    int count;
};

extern "C" int shared_g_0a501a14(Obj* self);
extern "C" int shared_g_03f0f2ae(Obj* self, int arg);

extern "C" int shared_g_c59181e6(Obj* self, unsigned id) {
    if (id > 4) {
        return 1;
    }
    if ((int)id == 4) {
        return shared_g_0a501a14(self);
    }
    int result = 1;
    Entry* e = self->begin;
    Entry* end = e + self->count;
    for (; e != end; e++) {
        if ((int)id == e->id) {
            if ((int)id == 4) {
                result = shared_g_0a501a14(self);
            } else {
                result = shared_g_03f0f2ae(self, e->arg);
            }
            break;
        }
    }
    return result;
}
