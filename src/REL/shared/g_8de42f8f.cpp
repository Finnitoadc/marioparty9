struct P { int pad; int field_4; };
struct O { char pad[0xc]; P* field_c; };

extern "C" void fn_80086F10(void* p, int n);
extern "C" void fn_8020B5FC(void* p);

extern "C" void shared_g_8de42f8f(O* self) {
    P* p = self->field_c;
    if (p != 0) {
        fn_80086F10(&p->field_4, -1);
        fn_8020B5FC(p);
    }
}
