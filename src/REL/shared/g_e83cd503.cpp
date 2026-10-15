struct P { int a, b; };
struct Mat { P p[6]; };
struct S { char pad[0x15c]; void* field_15C; char pad2[0x168 - 0x160]; Mat field_168; };
extern "C" void fn_80060270(void* p, const Mat* m);
extern "C" void shared_g_e83cd503(S* self) {
    void* o = self->field_15C;
    if (o != 0) {
        Mat m;
        for (int i = 0; i < 6; i++) { int y = self->field_168.p[i].b; int x = self->field_168.p[i].a; m.p[i].b = y; m.p[i].a = x; }
        fn_80060270(o, &m);
    }
}
