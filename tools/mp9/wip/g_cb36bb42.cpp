extern "C" int fn_80042D70(int h);
extern "C" void fn_8020B5FC(void* p);

struct E {
    virtual ~E();
    int h;
};

struct Node {
    Node* prev;
    Node* next;
    E val;
};

struct List {
    int count;
    Node sentinel;
};

static inline int Id(const E& e) {
    return fn_80042D70(e.h) ? e.h : 0;
}

struct Pred {
    int pad;
    const E* v;
    Pred(const E* e) : v(e) {}
    bool operator()(const E& e) const { return Id(e) == Id(*v); }
};

static inline void Erase(List* self, Node* it, Node* j) {
    if (it == j) return;
    Node* p = j->prev;
    it->prev->next = p->next;
    p->next->prev = it->prev;
    while (it != j) {
        it->val.~E();
        Node* n = it->next;
        fn_8020B5FC(it);
        self->count--;
        it = n;
    }
}

static inline void RemoveIf(List* self, Pred pr) {
    Node* end = &self->sentinel;
    Node* it = self->sentinel.next;
    while (it != end) {
        if (pr(it->val)) {
            Node* j = it->next;
            while (j != end) {
                if (!pr(j->val)) break;
                j = j->next;
            }
            Erase(self, it, j);
            if (j == end) break;
            it = j;
        }
        it = it->next;
    }
}

extern "C" void shared_g_cb36bb42(List* self, const E& v) {
    RemoveIf(self, Pred(&v));
}
