struct Vec { float x, y, z; };

static inline void VecAdd(const Vec* pa, const Vec* pb, Vec* pab) {
    register const Vec* a = pa;
    register const Vec* b = pb;
    register Vec* ab = pab;
    register float y, x;
    asm {
        psq_l x, 0(a), 0, 0
        psq_l y, 0(b), 0, 0
        ps_add x, x, y
        psq_st x, 0(ab), 0, 0
        psq_l x, 8(a), 1, 0
        psq_l y, 8(b), 1, 0
        ps_add x, x, y
        psq_st x, 8(ab), 1, 0
    }
}

static inline void VecSub(const Vec* pa, const Vec* pb, Vec* pab) {
    register const Vec* a = pa;
    register const Vec* b = pb;
    register Vec* ab = pab;
    register float y, x;
    asm {
        psq_l x, 0(a), 0, 0
        psq_l y, 0(b), 0, 0
        ps_sub y, x, y
        psq_l x, 8(a), 1, 0
        psq_st y, 0(ab), 0, 0
        psq_l y, 8(b), 1, 0
        ps_sub y, x, y
        psq_st y, 8(ab), 1, 0
    }
}

struct Finder {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6(Vec* a, Vec* b, Vec* c, int d, Vec* e, float f);
};

struct Entry {
    Finder* obj;
    int extra;
};

struct Obj {
    char pad[0x620];
    Vec field_620;
    char pad2[0x7B4 - 0x62C];
    Entry* entries;
    unsigned count;
    char pad3[0x850 - 0x7BC];
    unsigned char found;
    int index;
    Vec field_858;
    char pad4[0x864 - 0x864];
    Vec field_864;
    char pad5[0x8D4 - 0x870];
    Vec field_8D4;
    char pad6[0x8E0 - 0x8E0];
    float field_8E0;
};

extern "C" unsigned char shared_g_987faef2(Obj* self) {
    Vec tmp;
    VecAdd(&self->field_620, &self->field_8D4, &tmp);
    for (unsigned i = 0; i < self->count; i++) {
        Vec out1;
        Vec out2;
        if (self->entries[i].obj->v6(&tmp, &out1, &out2, self->entries[i].extra, &self->field_864, self->field_8E0)) {
            tmp = out1;
            self->found = 1;
            self->index = i;
            self->field_858 = out2;
        }
    }
    if (self->found) {
        VecSub(&tmp, &self->field_8D4, &tmp);
        self->field_620 = tmp;
    }
    return self->found;
}
