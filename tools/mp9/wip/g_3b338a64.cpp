struct Node {
    Node* field_0;
    Node* field_4;
    int field_8;
    int field_C;
};

struct Tree {
    int field_0;
    Node field_4;
};

extern "C" Node* shared_g_3b338a64(Tree* self, int* key, Node** out, bool* left, bool* first) {
    *out = 0;
    Node* y = &self->field_4;
    Node* x = self->field_4.field_0;
    *left = true;
    *first = true;
    while (x != 0) {
        y = x;
        if (*key < x->field_C) {
            x = x->field_0;
            *left = true;
        } else {
            *out = x;
            x = x->field_4;
            *left = false;
            *first = false;
        }
    }
    return y;
}
