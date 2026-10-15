struct O {
    int pad[4];
    virtual ~O();
};
struct A {
    O* field_00;
};
extern "C" void shared_g_905c548c(A* self, O* n) {
    O* old = self->field_00;
    if (n == old) return;
    self->field_00 = n;
    delete old;
}
