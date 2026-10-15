extern "C" int fn_80213120(const char* a, const char* b);

struct Name {
    char pad[8];
    unsigned int flags;
    int pad2;
    char* heap;
};

struct Obj {
    char pad[0xc];
    Name** data;
    int count;
};

extern "C" Name* shared_g_81569983(Obj* self, const char* key) {
    Name** end;
    Name** p = self->data;
    Name* result = 0;
    end = p + self->count;
    for (; p != end; p++) {
        Name* n = *p;
        const char* s;
        s = !(n->flags >> 31) ? (char*)n + 9 : n->heap;
        if (fn_80213120(s, key) == 0) {
            result = *p;
            break;
        }
    }
    return result;
}
