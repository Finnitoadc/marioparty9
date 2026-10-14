struct Obj {
    int field_0;
    int key;
};

extern "C" int shared_g_16b2cf36(Obj* a, Obj* b) {
    return a->key < b->key;
}
