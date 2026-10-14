struct Vec {
    int x, y, z;
};

extern "C" float lbl_8026E3B4;
extern "C" Vec lbl_80237470;

struct Obj {
    char pad0[0x2C];
    float field_2c;
    float field_30;
    float field_34;
    unsigned char field_38;
    Vec field_3c;
};

static inline void copyVec(Vec* d, const Vec* s) {
    int x = s->x;
    int y = s->y;
    d->y = y;
    d->x = x;
    d->z = s->z;
}

extern "C" void shared_g_59da3235(Obj* self) {
    self->field_2c += lbl_8026E3B4;
    if (self->field_2c < self->field_34) {
        return;
    }
    self->field_38 = 1;
    copyVec(&self->field_3c, &lbl_80237470);
}
