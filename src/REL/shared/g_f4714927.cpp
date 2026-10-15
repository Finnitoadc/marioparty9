struct O {
    virtual void v0(); virtual void v1(); virtual void f(int);
    char pad[0x14 - 4];
    int field_14;
    int field_18;
    int field_1c;
    char pad2[0x60 - 0x20];
    int arr[8];
    char pad3[0x90 - 0x80];
    int field_90;
};
extern "C" void shared_g_f4714927(O* o) {
    int v = o->arr[o->field_14];
    o->field_1c = v;
    if (o->field_90 != 0) {
        *((char*)v + o->field_90 - 0x14) = 1;
    }
    o->f(8);
}
