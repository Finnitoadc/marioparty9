// 1 diff: li r0,1 scheduled before stw r8,0(r5) at function start
struct Node {
    Node* left;
    Node* right;
    int field_8;
    float key;
};

struct Tree {
    int field_0;
    Node* root;
};

static inline bool Less(const float& a, const float& b) {
    return a < b;
}

extern "C" Node* shared_g_74b89e6f(Tree* t, const float* key, Node** parent, unsigned char* left, unsigned char* first) {
    *parent = 0;
    Node* last = (Node*)&t->root;
    Node* n = t->root;
    *left = 1;
    *first = 1;
    while (n != 0) {
        last = n;
        if (Less(*key, n->key)) {
            n = n->left;
            *left = 1;
        } else {
            *parent = n;
            n = n->right;
            *left = 0;
            *first = 0;
        }
    }
    return last;
}
