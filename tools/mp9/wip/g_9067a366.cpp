extern "C" void fn_8020B5FC(void* ptr);

struct Elem {
    int pad[15];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int a);
};

struct Vec {
    Elem** data;
    unsigned count;

    void DeleteAll() {
        int off = 0;
        unsigned i = 0;
        unsigned n = count;
        for (; i < n; i++, off += 4) {
            Elem* e = *(Elem**)((char*)data + off);
            if (e != 0) e->v5(1);
        }
    }
    char* Begin() { return (char*)data; }
    char* End() { return (char*)data + count; }
    void Erase(char* first, char* last) { count -= last - first; }
};

struct Holder {
    Vec* p;
};

extern "C" void shared_g_9067a366(Holder* self, Vec* v) {
    Vec* old = self->p;
    if (v != old) {
        self->p = v;
        if (old != 0) {
            old->DeleteAll();
            old->Erase(old->Begin(), old->End());
            if (old != 0) {
                if (old != 0) {
                    if (old != 0) {
                        if (old != 0) {
                            if (old->data != 0) {
                                old->Erase(old->Begin(), old->End());
                                fn_8020B5FC(old->data);
                            }
                        }
                    }
                }
            }
            fn_8020B5FC(old);
        }
    }
}
