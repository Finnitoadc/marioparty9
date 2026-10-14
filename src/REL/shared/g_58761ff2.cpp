extern "C" void* fn_80065DA0(void* obj);
extern "C" int fn_80065DE0(void* obj);

struct Node {
    char pad[0xC];
    int field_c;
};

struct Data {
    int w[8];
};

struct Iter {
    int field_0;
    char pad[0x2C];
};

extern "C" Node* fn_8010EFF0(int* key, int a);
extern "C" void fn_80136D10(Iter* out, void* p, int v);
extern "C" int fn_801368C0(Iter* it);
extern "C" Data* fn_80110E90(int* key, int b);

extern "C" int shared_g_58761ff2(void* self, void* obj, int a, int b, Data* data) {
    void* p = fn_80065DA0(obj);
    int k = fn_80065DE0(obj);
    Node* n = fn_8010EFF0(&k, a);
    if (n == 0) {
        return 0;
    }
    Iter it;
    fn_80136D10(&it, p, n->field_c);
    if (it.field_0 == 0) {
        return 0;
    }
    int k2 = fn_801368C0(&it);
    Data* d = fn_80110E90(&k2, b);
    for (int i = 0; i < 8; i++) {
        d->w[i] = data->w[i];
    }
    return 1;
}
