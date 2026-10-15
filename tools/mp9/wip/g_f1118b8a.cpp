struct Elem {
    virtual void v0(int);
    int field_4;
};
struct Buffer {
    Elem* data;
    int count;
};
extern "C" void shared_g_f1118b8a(Buffer* self) {
    Elem* p;
    int n = self->count;
    p = self->data + n;
    int z = self->count - n;
    self->count = z;
    while (n != 0) {
        --p;
        p->v0(-1);
        --n;
    }
}
