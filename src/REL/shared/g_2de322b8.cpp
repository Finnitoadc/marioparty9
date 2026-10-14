struct A {
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
    virtual void v10(void* p, int n);
};

struct B {
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
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28(int n, void* p);
};

extern "C" void fn_80061B50(A* a);

struct Obj {
    char pad0[0x68];
    A field_68;
    char pad6C[0x238 - 0x6C];
    B field_238;
    char pad23C[0x5F0 - 0x23C];
    int field_5F0;
    char pad5F4[0x620 - 0x5F4];
    char field_620[0x6A5 - 0x620];
    unsigned char field_6A5;
    unsigned char field_6A6;
};

static inline void Set(Obj* self, int a, int b) {
    self->field_68.v10(self->field_620, a);
    fn_80061B50(&self->field_68);
    self->field_238.v28(b, self->field_620);
}

extern "C" void shared_g_2de322b8(Obj* self) {
    int s = self->field_5F0;
    if (s == 1) goto L1;
    if (s == 0) goto L0;
    if (s != 2) goto LD;
    goto L2;
L1:
    Set(self, 1, 0);
    return;
L0:
    if (self->field_6A5 == 0 || self->field_6A6 == 0) {
        Set(self, 2, 0x20);
        return;
    }
L2:
    Set(self, 0, 1);
    return;
LD:
    Set(self, 2, 0x20);
}
