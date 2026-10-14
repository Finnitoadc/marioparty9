struct Info {
    char pad[0xBB];
    unsigned char flags;
};

extern "C" void shared_g_2b81419d(Info* p, int on) {
    p->flags = (p->flags & 0xFE) | (unsigned char)on;
}
