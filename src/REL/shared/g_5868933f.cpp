struct Node {
    Node* left;
    Node* right;
    unsigned parent;
};
struct Iter { Node* cur; };

extern "C" void shared_g_5868933f(Iter* self) {
    Node* r = self->cur->right;
    if (r != 0) {
        Node* c = r;
        while (c->left != 0) c = c->left;
        self->cur = c;
        return;
    }
    Node* c;
    Node* p;
    while (c = self->cur, p = (Node*)(c->parent & ~1u), c != p->left) {
        self->cur = p;
    }
    self->cur = p;
}
