struct Obj {
    char pad[0x10];
    int count;
};

extern "C" void fn_8019A090(unsigned char n);
extern "C" void fn_80199F30(int a, int b, int c, int d);
extern "C" void fn_80199A90(int a, int b, int c, int d, int e);
extern "C" void fn_80199B10(int a, int b, int c, int d, int e, int f);
extern "C" void fn_80199D50(int a, int b);
extern "C" void fn_80199AD0(int a, int b, int c, int d, int e);
extern "C" void fn_80199B70(int a, int b, int c, int d, int e, int f);

extern "C" void shared_g_1e84127c(Obj* self) {
    int i;
    fn_8019A090(self->count + 1);
    fn_80199F30(0, 0, 0, 0xFF);
    fn_80199A90(0, 0xF, 0xF, 0xF, 8);
    fn_80199B10(0, 0, 0, 0, 0, 0);
    fn_80199D50(0, 0);
    fn_80199AD0(0, 7, 7, 7, 6);
    fn_80199B70(0, 0, 0, 0, 0, 0);
    for (i = 1; i <= self->count; i++) {
        fn_80199F30(i, i, 0, 0xFF);
        fn_80199A90(i, 8, 0xF, 0xF, 0);
        fn_80199B10(i, 0, 0, 3, 0, 0);
        fn_80199D50(i, 0);
        fn_80199AD0(i, 7, 7, 7, 6);
        fn_80199B70(i, 0, 0, 0, 0, 0);
    }
}
