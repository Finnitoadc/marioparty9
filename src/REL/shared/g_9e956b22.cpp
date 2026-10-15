struct Item {
    int a;
    int b;
};

struct Obj {
    int field_0;
    Item** data;
    int count;
};

extern "C" Item* shared_g_9e956b22(Obj* self, int a, int b) {
    Item** end = self->data + self->count;
    Item** p = self->data;
    for (; p != end; p++) {
        Item* it = *p;
        if (a == it->a && b == it->b) {
            return it;
        }
    }
    return 0;
}
