extern "C" void fn_8020B5FC(void* ptr);

struct Ring;

struct Iter {
    int** cur;
    int** base;
    int** first;
    int** end;

    Iter(int** c, int** b, int** f, int** e) : cur(c), base(b), first(f), end(e) {}
    int** operator*() { return cur; }
    void Next() {
        cur++;
        if (cur == end) {
            cur = base;
        }
    }
    bool operator!=(const Iter& o) const { return cur != o.cur; }
};

struct Ring {
    int** data;
    unsigned start;
    unsigned count;
    unsigned cap;

    unsigned Index() {
        return cap != 0 ? (start + count) % cap : 0;
    }
    Iter Begin() {
        return Iter(data + start, data, data + start, data + cap);
    }
    Iter End() {
        unsigned idx = Index();
        return Iter(data + idx, data, data + start, data + cap);
    }
};

struct Obj {
    int field_0;
    int field_4;
    Ring ring;
};

extern "C" Obj* shared_g_eca34639(Obj* self, int del) {
    if (self != 0) {
        self->field_4 = 0;
        if (self->ring.count != 0) {
            Iter e = self->ring.End();
            for (Iter it = self->ring.Begin(); it != e; it.Next()) {
                if (*it != 0) {
                    fn_8020B5FC(*it);
                }
            }
        }
        Ring* q = &self->ring;
        if (q != 0) {
            if (q->data != 0) {
                q->count -= q->count - q->count;
                fn_8020B5FC(q->data);
            }
        }
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}
