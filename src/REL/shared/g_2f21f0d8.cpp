struct List;

struct Node {
    int field_0;
    List* owner;
    Node* prev;
    Node* next;
};

struct List {
    int field_0;
    Node* head;
    Node* tail;
    int count;
};

extern "C" void shared_g_2f21f0d8(List* list, Node* node) {
    List* old = node->owner;
    if (old != 0) {
        if (node->next != 0) {
            node->next->prev = node->prev;
        } else {
            old->tail = node->prev;
        }
        if (node->prev != 0) {
            node->prev->next = node->next;
        } else {
            old->head = node->next;
        }
        node->owner = 0;
        node->prev = 0;
        node->next = 0;
        old->count--;
    }
    node->owner = list;
    node->prev = list->tail;
    if (list->tail != 0) {
        list->tail->next = node;
    } else {
        list->head = node;
    }
    list->tail = node;
    list->count++;
}
