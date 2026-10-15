struct Node {
    Node* left;
    Node* right;
    int pad;
    unsigned key;
};

struct Tree {
    int field_0;
    Node* root;
};

extern "C" Node* shared_g_fae93e99(Tree* t, unsigned* key, Node** out, bool* a, bool* b) {
    Node* res = (Node*)((char*)t + 4);
    *out = 0;
    Node* cur = t->root;
    *a = true;
    *b = true;
    while (cur != 0) {
        res = cur;
        if (*key < cur->key) {
            cur = cur->left;
            *a = true;
        } else {
            *out = cur;
            cur = cur->right;
            *a = false;
            *b = false;
        }
    }
    return res;
}
