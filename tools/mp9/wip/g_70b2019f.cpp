extern "C" void fn_8020B5FC(void* ptr);
extern "C" void fn_8005CE40(void* self, int flags);

struct Buffer {
    char* data;
    int count;

    char* Begin() { return data; }
    char* End() { return data + count; }
    void Erase(char* first, char* last) { count -= last - first; }
    void Clear() { Erase(Begin(), End()); }
};

struct Elem {
    char pad[0x8];
    Buffer buf;
    char pad10[0x10];
};

static inline void Destroy(Elem* e) {
    if (e != 0) {
        Buffer* b = &e->buf;
        if (b != 0) {
            if (b != 0) {
                if (b != 0) {
                    if (b->data != 0) {
                        b->Clear();
                        fn_8020B5FC(b->data);
                    }
                }
            }
        }
    }
}

struct Array {
    Elem* data;
    int count;

    void Free() {
        if (data != 0) {
            int n = count;
            Elem* p = data + n;
            count -= n;
            while (n != 0) {
                --p;
                Destroy(p);
                n--;
            }
            fn_8020B5FC(data);
        }
    }
    ~Array() {
        if (this != 0) {
            if (this != 0) {
                if (this != 0) {
                    Free();
                }
            }
        }
    }
    static void operator delete(void* p) { fn_8020B5FC(p); }
};

struct Ptr {
    Array* p;
    ~Ptr() { delete p; }
};

struct Holder {
    char pad[0x148];
    Ptr ptr;
};

extern "C" Holder* shared_g_70b2019f(Holder* self, int del) {
    if (self != 0) {
        Ptr* pp = &self->ptr;
        if (pp != 0) {
            delete pp->p;
        }
        if (self != 0) {
            fn_8005CE40(self, 0);
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
