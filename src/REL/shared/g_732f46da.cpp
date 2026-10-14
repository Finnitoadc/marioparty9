struct Mtx48 {
    int m[12];
};

struct Inner {
    char pad[0x84];
    Mtx48 mtx;
    void SetMtx(Mtx48* a) { for (int i = 0; i < 12; i++) mtx.m[i] = a->m[i]; }
};

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
    virtual void Create();
    char pad[0x1B8];
    Inner* field_1bc;
};

extern "C" void shared_g_732f46da(Obj* self, Mtx48* m) {
    if (self->field_1bc == 0) {
        self->Create();
    }
    self->field_1bc->SetMtx(m);
}
