extern "C" void* memcpy(void* d, const void* s, unsigned n);
extern "C" void fn_80162C40(void* p, int n);

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual int v20();
    char pad[0x14 - 4];
    char* field_14;
    char pad2[4];
    char field_1c[4];
};

extern "C" int shared_g_84c6ed2a(Obj* self, void* dst, int n) {
    memcpy(dst, self->field_14 + self->v20() + 8, n);
    fn_80162C40(self->field_1c, n);
    return n;
}
