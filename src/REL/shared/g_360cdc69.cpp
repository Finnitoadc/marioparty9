struct Sub {
    char pad[0x14];
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09();
    virtual void v10();
};

struct Obj {
    char pad[0x28];
    Sub* sub;
};

extern "C" void shared_g_360cdc69(Obj* self) {
    if (self->sub != 0) {
        self->sub->v10();
    }
}
