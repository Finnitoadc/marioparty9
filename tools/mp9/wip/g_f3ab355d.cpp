extern "C" void* memset(void* p, int c, unsigned n);
extern "C" void fn_80071590();
extern "C" int fn_80061900(int x);
extern "C" void fn_8020B5FC(void* p);

struct Item { int v[12]; };

struct Obj {
    char pad0[0xC];
    int field_C;
    Item cur;
    unsigned field_40;
    unsigned field_44;
    Item** field_48;
    unsigned field_4C;
    unsigned field_50;
    unsigned field_54;
    char pad1[0x88 - 0x58];
    int field_88;
};

extern "C" void shared_g_f3ab355d(Obj* self) {
    while (fn_80061900(self->field_C) == 0) {
        fn_80071590();
    }
    if (self->field_44 == 0) {
        memset(&self->cur, 0, 0x30);
    } else {
        unsigned a = self->field_40;
        unsigned blk = a / 21;
        unsigned idx = self->field_4C + blk;
        Item* e = self->field_48[idx % self->field_54] + (a - blk * 21);
        self->cur = *e;
        self->field_44 = self->field_44 - 1;
        self->field_40 = a + 1;
        while (self->field_40 >= 0x2A) {
            fn_8020B5FC(self->field_48[self->field_4C]);
            self->field_4C = self->field_4C + 1;
            if (self->field_4C == self->field_54) {
                self->field_4C = 0;
            }
            self->field_50 = self->field_50 - 1;
            self->field_40 = self->field_40 - 21;
        }
        if (self->field_44 == 0) {
            self->field_40 = 10;
        }
    }
    self->field_88 = -1;
}
