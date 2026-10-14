extern "C" int fn_8021053C(const char* a, const char* b, unsigned int n);

static inline const unsigned int& Min(const unsigned int& a, const unsigned int& b) {
    return b < a ? b : a;
}

struct String {
    union {
        struct {
            unsigned int isLong : 1;
        } f;
        struct {
            unsigned char size;
            char buf[11];
        } s;
        struct {
            unsigned int cap;
            unsigned int size;
            char* ptr;
        } l;
    };

    unsigned int Size() const { return !f.isLong ? (s.size & 0x7F) : l.size; }
    const char* Data() const { const char* p; if (!f.isLong) { p = s.buf; } else { p = l.ptr; } return p; }

    int Compare(const String& o) const {
        const char* od = o.Data();
        unsigned int osz = o.Size();
        unsigned int rlen = Min(Size(), Size() - 0);
        int r = fn_8021053C(Data(), od, Min(rlen, osz));
        if (r == 0) {
            if (rlen < osz) {
                r = -1;
            } else if (rlen > osz) {
                r = 1;
            } else {
                r = 0;
            }
        }
        return r;
    }
};

struct Node {
    Node* left;
    Node* right;
    int field_8;
    String key;
};

struct Tree {
    int field_0;
    Node* root;
};

extern "C" Node* shared_g_08ffa278(Tree* t, const String& key, Node** out, unsigned char* a, unsigned char* b) {
    *out = 0;
    *a = 1;
    *b = 1;
    Node* y = (Node*)&t->root;
    Node* x = t->root;
    while (x != 0) {
        y = x;
        if (key.Compare(x->key) < 0) {
            x = x->left;
            *a = 1;
        } else {
            *out = x;
            x = x->right;
            *a = 0;
            *b = 0;
        }
    }
    return y;
}
