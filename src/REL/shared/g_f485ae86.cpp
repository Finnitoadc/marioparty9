struct Node {
    Node* field_0;
    Node* field_4;
    unsigned field_8;
};

struct It {
    Node* field_0;
    Node* field_4;
};

extern "C" char* shared_g_f485ae86(It* self) {
    Node* n = self->field_4;
    self->field_0 = n;
    n = n->field_0;
    if (n != 0) {
        Node* c;
        while ((c = n->field_4) != 0) n = c;
        self->field_0 = n;
    } else {
        Node* p;
        while (p = (Node*)(self->field_0->field_8 & ~1u), self->field_0 == p->field_0)
            self->field_0 = p;
        self->field_0 = p;
    }
    return (char*)self->field_0 + 0xc;
}
