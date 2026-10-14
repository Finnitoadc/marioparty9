struct Ring {
    int* buf;
    unsigned int head;
    unsigned int count;
    unsigned int cap;
};

extern "C" int* shared_g_671f8bfd(Ring* r) {
    return &r->buf[(r->head + r->count - 1) % r->cap];
}
