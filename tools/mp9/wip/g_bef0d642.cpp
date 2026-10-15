struct Item {
    virtual ~Item();
    char pad[4];
    unsigned char f8;
    unsigned char f9;
    unsigned char fa;
    unsigned char fb;
    unsigned char fc;
    unsigned char fd;
};
extern "C" void* memmove(void*, const void*, unsigned);
struct Obj {
    char pad[8];
    Item** data;
    int count;
    int field_10;
    int field_14;
};
static inline void Dec(Obj* o) {
    if (--o->field_14 < 0) o->field_14 = 0;
}
static inline void Erase(Obj* o, Item** pos) {
    delete *pos;
    memmove(pos, pos + 1, (o->data + o->count - pos - 1) * 4);
    o->count--;
}
extern "C" void shared_g_bef0d642(Obj* self) {
    Item** p = self->data;
    while (p != self->data + self->count) {
        Item* it = *p;
        if (it->f8 != 0) {
            if (it->f9 == 1) Dec(self);
            Erase(self, p);
        } else {
            if (it->fd == 1 && it->fb == 0 && it->f9 == 1) {
                it->fb = 1;
                Dec(self);
            }
            p++;
        }
    }
}
