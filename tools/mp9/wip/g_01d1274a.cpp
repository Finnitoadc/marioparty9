struct Node { Node* a; Node* b; };
struct Obj { Node* head; Node n; };
static inline void link(Node*& p, Node* n) { p = n; }
extern "C" void shared_g_01d1274a(Obj* self) {
    Node* n = &self->n;
    self->head = 0;
    Node** pb = &n->b;
    *pb = n;
    n->a = n;
}
