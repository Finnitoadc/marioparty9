struct Item {
    virtual ~Item();
    char pad[0x1C];
    int field_20;
};

struct Node {
    char pad[0xC];
    Node* next;
    Item* item;
};

struct Obj {
    char pad[0x110];
    Node* head;
    char pad2[0xC];
    int count;
};

extern "C" void shared_g_93a5dd57(Obj* self) {
    if (self->count != 0) {
        Node* n = self->head;
        while (n != 0) {
            Item* it = n->item;
            n = n->next;
            if (it->field_20 != 2) {
                it->field_20 = 2;
            } else {
                if (it != 0) delete it;
            }
        }
    }
}
