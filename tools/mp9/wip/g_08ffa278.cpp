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
            unsigned int size_cap;
            unsigned int size;
            char* ptr;
        } l;
    };

    unsigned int Size() const { return !f.isLong ? (s.size & 0x7F) : l.size; }
    const char* Data() const { return !f.isLong ? s.buf : l.ptr; }

    void Get(const char*& d, unsigned int& n) const {
        if (!f.isLong) {
            d = s.buf;
            n = s.size & 0x7F;
        } else {
            d = l.ptr;
            n = l.size;
        }
    }

    int Compare(const String& o, unsigned int pos) const {
        unsigned int rlen;
        unsigned int left;
        unsigned int n2;
        unsigned int n1;
        unsigned int sz;
        const char* d;
        const char* str;
        unsigned int n;
        if (!o.f.isLong) {
            str = o.s.buf;
            n = o.s.size & 0x7F;
        } else {
            str = o.l.ptr;
            n = o.l.size;
        }
        n2 = n;
        n1 = Size();
        if (!f.isLong) {
            d = ((const char*)&this->s) + 1;
            sz = this->s.size & 0x7F;
        } else {
            d = l.ptr;
            sz = l.size;
        }
        left = sz - pos;
        rlen = Min(left, n1);
        int r = fn_8021053C(d, str, Min(rlen, n2));
        if (r == 0) {
            if (rlen < n) {
                return -1;
            } else if (rlen == n) {
                return 0;
            }
            return 1;
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
    Node* y = (Node*)&t->root;
    Node* x = t->root;
    *out = 0;
    *a = 1;
    *b = 1;
    while (x != 0) {
        y = x;
        if (key.Compare(x->key, 0) < 0) {
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
