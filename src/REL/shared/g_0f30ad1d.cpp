struct Obj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual int v18();
};

extern "C" void* fn_8003ECB0(int a);
extern "C" int fn_8005D980(Obj* o);
extern "C" void fn_8003F480(void* p, int a);
extern "C" void fn_8003F4A0(void* p, int a);
extern "C" void fn_8003F4E0(void* p, int a);
extern "C" void fn_8003F540(void* p, int a);
extern "C" void fn_8003F5B0(void* p, int a);

extern "C" void shared_g_0f30ad1d(Obj* self, int a, int b, int c, int d) {
    void* p = fn_8003ECB0(d);
    if (p != 0) {
        fn_8003F480(p, fn_8005D980(self));
        fn_8003F4A0(p, self->v18());
        fn_8003F4E0(p, a);
        fn_8003F540(p, b);
        fn_8003F5B0(p, c);
    }
}
