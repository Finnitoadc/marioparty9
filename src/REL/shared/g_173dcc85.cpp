struct Item {
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074(int a);
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C(int a, int b);
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
};

struct Obj {
    char pad[0x14];
    Item* items[8];
    unsigned char flags[4];
};

extern "C" void shared_g_173dcc85(Obj* self, int idx, int a, int b, int c) {
    if (idx < 4) {
        if (b != -1) {
            self->items[idx]->v08C(b, 0);
        }
        self->items[idx]->v074(a);
        self->items[idx]->v0D8();
        self->flags[idx] = c != 1;
    }
}
