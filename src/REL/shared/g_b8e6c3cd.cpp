struct Node {
    char pad[0x14];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int);
};

struct Obj {
    char pad[0xc];
    Node** field_c;
    unsigned field_10;
    Node* field_14;
    Node* field_18;
    Node* field_1c;
};

extern "C" void shared_g_b8e6c3cd(Obj* self, int a) {
    Node* n = self->field_18;
    Node* m = self->field_1c;
    if (n) {
        n->v3(a);
    }
    if (m) {
        m->v3(a);
    }
    for (unsigned i = 0; i < self->field_10; i++) {
        self->field_c[i]->v3(a);
    }
}
