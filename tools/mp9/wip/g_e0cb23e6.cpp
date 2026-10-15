struct Pipe {
    union {
        unsigned char u8;
        float f32;
    };
};

struct Vec { float x, y, z; };

struct Col { unsigned char c[4]; };

struct O {
    char pad[0x168];
    Vec v0;
    Vec v1;
    Col c0;
    Col c1;
    unsigned char field_188;
};

extern "C" {
void fn_801981B0(int a);
void fn_801981E0(int a, int b, int c, int d, int e, int f, int g);
void shared_g_89c044b5(O* o);
void* fn_80052990();
void* fn_80132FA0(void* a, int b);
void fn_8012E430(void* a, void* b);
void fn_80191CC0(void* a);
void fn_80191D30(void* a, void* b, void* c);
void fn_8019C430(void* a, int b);
void fn_8019C550(int a);
void fn_80196C70(int a, int b, int c);
void fn_80196EA0(int a, int b);
}

#define FIFO (*(volatile Pipe*)0xCC008000)

static inline void Emit(const Vec& v, const Col& cc) {
    float z; float y; float x;
    unsigned char d; unsigned char c; unsigned char b; unsigned char a;
    x = v.x; y = v.y; z = v.z;
    a = cc.c[0]; b = cc.c[1]; c = cc.c[2]; d = cc.c[3];
    FIFO.f32 = x;
    FIFO.f32 = y;
    FIFO.f32 = z;
    FIFO.u8 = a;
    FIFO.u8 = b;
    FIFO.u8 = c;
    FIFO.u8 = d;
}

extern "C" void shared_g_e0cb23e6(O* self) {
    void* p;
    char b40[0x30];
    char b10[0x30];
    fn_801981B0(1);
    fn_801981E0(4, 0, 0, 1, 0, 0, 2);
    fn_801981E0(5, 0, 0, 0, 0, 0, 2);
    shared_g_89c044b5(self);
    fn_80196EA0(self->field_188, 0);
    p = fn_80132FA0(fn_80052990(), 0);
    fn_8012E430(&p, b40);
    fn_80191CC0(b10);
    fn_80191D30(b40, b10, b10);
    fn_8019C430(b10, 0);
    fn_8019C550(0);
    fn_80196C70(0xa8, 0, 2);
    Emit(self->v0, self->c0);
    Emit(self->v1, self->c1);
}
