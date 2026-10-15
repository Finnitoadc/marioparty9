struct A {
    char pad[0x30];
    int field_30;
};
extern "C" int shared_g_fc25ab18(int);
extern "C" int shared_g_e0e78600(int, int);
extern "C" int shared_g_53069e3d(void*, int, int);
extern "C" int shared_g_b3429c8b(void* self, A* o) {
    int a = shared_g_fc25ab18(o->field_30);
    int b = shared_g_e0e78600(o->field_30, a);
    return shared_g_53069e3d(self, b, 0);
}
