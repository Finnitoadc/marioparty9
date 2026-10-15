extern "C" void fn_8020B5FC(void* ptr);

struct Elem {
    virtual ~Elem();
};

struct Deque {
    char pad[0xC];
    unsigned start;
    int size;
    Elem*** map;
    unsigned head;
    int blocks;
    unsigned mapSize;

    void PopBlock() {
        fn_8020B5FC(map[head]);
        head = head + 1;
        if (head == mapSize) {
            head = 0;
        }
        blocks--;
        start -= 0x100;
    }
    Elem* Pop() {
        unsigned off = start;
        Elem* e = map[(head + (off >> 8)) % mapSize][off & 0xFF];
        size--;
        start = off + 1;
        while (start >= 0x200) {
            PopBlock();
        }
        if (size == 0) {
            start = 0x80;
        }
        return e;
    }
};

extern "C" void shared_g_78fa22f0(Deque* self) {
    if (self->size != 0)
    while (self->size != 0) {
        Elem* e = self->Pop();
        delete e;
    }
}
