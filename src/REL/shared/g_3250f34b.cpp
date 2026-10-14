struct Elem {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Update();
};

struct Node {
    char pad[0xC];
    Node* next;
    Elem* obj;
};

struct List {
    char pad[0xC];
    Node* head;
    int field_10;
};

extern "C" void shared_g_3250f34b(List* lists) {
    for (unsigned int i = 0; i < 12; i++) {
        for (Node* n = lists[i].head; n != 0; n = n->next) {
            n->obj->Update();
        }
    }
}
