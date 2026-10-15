struct Vec { int x, y, z; };
extern "C" void fn_80192CD0(Vec* dst, Vec* src);

struct Poly { int field_0; Vec v[4]; };

static inline void sub(register const Vec* a, register const Vec* b, register Vec* c) {
    asm {
        psq_l f1, 0(b), 0, 0
        psq_l f0, 0(a), 0, 0
        ps_sub f2, f0, f1
        psq_l f0, 8(a), 1, 0
        psq_l f1, 8(b), 1, 0
        psq_st f2, 0(c), 0, 0
        ps_sub f2, f0, f1
        psq_st f2, 8(c), 1, 0
    }
}

static inline void cp(Vec* d, const Vec& s) {
    *d = s;
}

extern "C" void shared_g_b9ed8a4e(Vec* out, Poly* p, int i) {
    if (i < 3) {
        Vec d;
        Vec* cur = &p->v[i];
        Vec* nxt = &p->v[(i + 1) % 3];
        sub(nxt, cur, &d);
        fn_80192CD0(&d, &d);
        int x = d.x;
        int y = d.y;
        out->y = y;
        out->x = x;
        out->z = d.z;
    } else {
        cp(out, p->v[3]);
    }
}
