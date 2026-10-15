extern "C" void* memcpy(void* d, const void* s, unsigned n);
extern "C" void fn_80162CB0(void* p, int n);

struct Obj {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    char field_1C[1];
};

extern "C" int shared_g_a1ac53b9(Obj* self, const void* src, int len) {
    memcpy((char*)self->field_14 + self->v20() + 8, src, len);
    fn_80162CB0(self->field_1C, len);
    return len;
}
