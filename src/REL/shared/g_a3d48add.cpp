extern "C" void shared_g_fbb1947c(void*);
struct Obj {
    char pad[0x44];
    void* field_44;
    char pad2[0xa0];
    int field_e8;
};
extern "C" void shared_g_a3d48add(Obj* self, int a, int b, int d) {
    shared_g_fbb1947c(self->field_44);
    self->field_e8 = a;
    if (d) {
        self->field_e8 = -1;
    }
}
