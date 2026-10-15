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

extern "C" Node* shared_g_fae93e99(Tree* t, unsigned* key, Node** out, char* a, char* b) {
    Node* res = (Node*)((char*)t + 4);
    *out = 0;
    Node* cur = t->root;
    *a = 1;
    *b = 1;
    while (cur != 0) {
        res = cur;
        if (*key < cur->key) {
            cur = cur->left;
            *a = 1;
        } else {
            *out = cur;
            cur = cur->right;
            *a = 0;
            *b = 0;
        }
    }
    return res;
}
