extern "C" void fn_8020B5FC(void* ptr);

struct Elem {
    unsigned flag : 1;
    int field_04;
    void* field_08;
    int field_0C;
};

struct Vec {
    Elem* data;
    int count;
};

extern "C" Vec* shared_g_e128a072(Vec* self, int del) {
    if (self != 0) {
        Vec* b = self;
        if (b != 0) {
            if (b != 0) {
                if (b->data != 0) {
                    Elem* p = b->data + b->count;
                    int n = b->count;
                    b->count -= n;
                    while (n != 0) {
                        p--;
                        if (p != 0) {
                            if (p != 0) {
                                if (p->flag) {
                                    fn_8020B5FC(p->field_08);
                                }
                            }
                        }
                        n--;
                    }
                    fn_8020B5FC(b->data);
                }
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
