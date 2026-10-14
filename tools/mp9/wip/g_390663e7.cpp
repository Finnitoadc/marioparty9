extern "C" void fn_8020B5FC(void* p);
extern "C" void fn_80071590();

struct Item {
    virtual void Delete(int del);
    unsigned char field_4[4];
    volatile unsigned char field_8;
    unsigned char field_9;
};

struct Deque {
    unsigned int start;
    int size;
    Item*** map;
    unsigned int mapStart;
    int mapSize;
    unsigned int mapCap;

    Item*& Front() {
        return map[(mapStart + (start >> 8)) % mapCap][start & 0xFF];
    }
    void PopFront() {
        size--;
        start++;
        while (start >= 0x200) {
            fn_8020B5FC(map[mapStart]);
            mapStart++;
            if (mapStart == mapCap) {
                mapStart = 0;
            }
            mapSize--;
            start -= 0x100;
        }
        if (size == 0) {
            start = 0x80;
        }
    }
};

struct Obj {
    char pad[0x8];
    volatile unsigned char field_8;
    Deque queue;
};

extern "C" void shared_g_390663e7(Obj* self) {
    if (self->queue.size == 0) {
        goto end;
    }
    while (self->queue.size != 0) {
        Item* item = self->queue.Front();
        item->field_9 = 1;
        while (item->field_8 != 0) {
            fn_80071590();
        }
        self->queue.PopFront();
        if (item != 0) {
            item->Delete(1);
        }
        fn_80071590();
    }
end:
    self->field_8 = 0;
}
