extern "C" void fn_8005DA70(void* a, const char* b, int c);
extern "C" void fn_8005DA50(void* a, int b);
struct S {
    char pad0[8];
    unsigned isLong : 1;
    char data[7];
    char* ptr;
    char pad1[0x80 - 0x14];
    void* p80;
    char pad2[0xa4 - 0x84];
    void* pa4;
};
extern "C" void shared_g_d696b6f6(S* self, int a) {
    if (self->pa4 != 0) {
        fn_8005DA70(self->pa4, !self->isLong ? (char*)self + 9 : self->ptr, a);
    }
    if (self->p80 != 0) {
        fn_8005DA50(self->p80, a);
    }
}
