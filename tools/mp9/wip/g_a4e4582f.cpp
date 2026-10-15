struct Item {
    virtual ~Item();
};
struct Node {
    Node* prev;
    Node* next;
    Item item;
};
struct List {
    int count;
    Node head;
};
extern "C" void fn_8020B5FC(void*);
static inline void erase(List* l) {
    Node* first = l->head.next;
    Node* end = &l->head;
    if (first != end) {
        Node* a = end->prev;
        first->prev->next = a->next;
        Node* c = a->next;
        c->prev = first->prev;
        while (first != end) {
            first->item.~Item();
            Node* d = first;
            first = first->next;
            fn_8020B5FC(d);
            l->count--;
        }
    }
}
static inline void clear(List* l) {
    if (l != 0) {
        if (l != 0) {
            erase(l);
        }
    }
}
extern "C" List* shared_g_a4e4582f(List* self, int del) {
    if (self != 0) {
        clear(self);
        if (del > 0) fn_8020B5FC(self);
    }
    return self;
}
