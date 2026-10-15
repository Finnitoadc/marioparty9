extern "C" void fn_80046040(void* p, int x);
extern "C" void fn_8020B5FC(void* ptr);

struct Elem {
    virtual ~Elem();
    int field_4;
};

struct Vec {
    Elem* data;
    int count;

    Elem* Begin() { return data; }
    Elem* End() { return data + count; }
    void Erase(Elem* first, Elem* last) { count -= last - first; }
    void DestroyAll() {
        int n = count;
        Elem* e = End();
        count -= End() - Begin();
        while (n != 0) { e--; e->~Elem(); n--; }
    }
};

struct Entry {
    void* field_0;
    Vec v;
    int pad;
};

struct Obj {
    char pad[0x1C4];
    Entry* arr;
    unsigned count;
};

extern "C" void shared_g_9e85db48(Obj* self) {
    unsigned i = 0;
    unsigned n = self->count;
    int off = 0;
    for (; i < n; i++, off += 0x10) {
        fn_80046040(*(void**)((char*)self->arr + off), 1);
        Entry* e = (Entry*)((char*)self->arr + off);
        e->v.DestroyAll();
    }
    int m = self->count;
    Entry* p = self->arr + m;
    self->count -= m;
    while (m != 0) {
        p--;
        if (p != 0) {
            Vec* v = &p->v;
            if (v != 0) {
                if (v != 0) {
                    if (v != 0) {
                        if (v->data != 0) {
                            v->DestroyAll();
                            fn_8020B5FC(v->data);
                        }
                    }
                }
            }
        }
        m--;
    }
}
