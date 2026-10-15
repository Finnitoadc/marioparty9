struct Str {
    unsigned flags;
    int len;
    char* ptr;
};
struct Table {
    int pad0[10];
    char* entries;
    int pad1[4];
    int arr[2];
    int cur;
};
extern "C" void fn_80062D90(int a, char* b, void* c);
extern "C" void shared_g_ba06a5cd(void* a, Table* t, int i) {
    Str* s = (Str*)(t->entries + 0x20) + i;
    char* name = !(s->flags >> 31) ? (char*)s + 1 : s->ptr;
    fn_80062D90(t->arr[t->cur], name, a);
}
