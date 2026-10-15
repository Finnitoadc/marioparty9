struct Hdr { unsigned short w; short pad; unsigned char d[1]; };
union U { unsigned char b[4]; float f; int i; };
struct A {
    int pad0[3];
    Hdr** data;
    int pad1[2];
    int* fmt;
    int pad2[3];
    int count;
    int Fmt(int i) { if (i >= 0 && i < count) return fmt[i]; return 0; }
    int W(int i) { if (i >= 0 && i < count) return data[i]->w; return 0; }
};
extern "C" int shared_g_42208c7f(A* a, int i, int x, int y) {
    if (i >= 0 && i < a->count) {
        unsigned f = a->Fmt(i);
        switch (f) {
        case 0: {
            int off = (x + y * a->W(i)) * 4;
            unsigned char* p = (unsigned char*)(off + (int)a->data[i]);
            U u;
            u.b[0] = p[4]; u.b[1] = p[5]; u.b[2] = p[6]; u.b[3] = p[7];
            return (int)u.f;
        }
        case 1: {
            int off = (x + y * a->W(i)) * 4;
            unsigned char* p = (unsigned char*)(off + (int)a->data[i]);
            U u;
            u.b[0] = p[4]; u.b[1] = p[5]; u.b[2] = p[6]; u.b[3] = p[7];
            return u.i;
        }
        case 2: {
            int off = (x + y * a->W(i)) * 2;
            return *(short*)(off + (int)a->data[i] + 4);
        }
        case 3: {
            int off = x + y * a->W(i);
            return *(unsigned char*)(off + (int)a->data[i] + 4);
        }
        case 4: {
            int w = a->W(i);
            signed char c = a->data[i]->d[y * ((w + 1) / 2) + x / 2];
            if (x & 1) return c & 0xF;
            return (c >> 4) & 0xF;
        }
        }
    }
    return 0;
}
