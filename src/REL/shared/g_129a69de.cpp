struct Sub {
    char pad[0x14];
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(int on);
};

struct Inner {
    void* obj;
};

struct Obj {
    char pad0[0x4];
    Inner* inner;
    char pad8[0xC];
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15();
    char pad18[0x10];
    Sub* sub;
};

extern "C" void shared_g_ac27d302(void* self, int on);

extern "C" void shared_g_129a69de(Obj* self, int on) {
    shared_g_ac27d302(self->inner->obj, on);
    if (self->sub != 0) {
        self->sub->v04(on);
        if (on) {
            self->v15();
        }
    }
}
