struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    char pad[0x18];
    unsigned int flags;
};

struct Node {
    char pad[0xC];
    Node* next;
    Item* item;
};

struct List {
    char pad[0xC];
    Node* head;
    char pad2[0x4];
};

struct Obj {
    List lists[12];
    char pad[0x120 - 12 * 0x14];
    int field_120;
};

extern "C" void shared_g_0f3731ac(Obj* self) {
    if (self->field_120 != 0) {
        for (unsigned int i = 0; i < 12; i++) {
            for (Node* n = self->lists[i].head; n != 0; n = n->next) {
                Item* it = n->item;
                if (it->flags & 2) {
                    it->v3();
                }
            }
        }
    }
}
