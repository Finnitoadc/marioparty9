struct Node { Node* left; Node* right; Node* parent; int key; int val; };
struct Obj { char pad[0x16c]; Node head; };
extern "C" int shared_g_c26f7509(Obj* self, int k) {
    Node* n = self->head.left;
    Node* r = &self->head;
    while (n != 0) {
        if (n->key >= k) { r = n; n = n->left; }
        else { n = n->right; }
    }
    if (r == &self->head || k < r->key) r = &self->head;
    if (&self->head == r) return 0;
    return r->val;
}
