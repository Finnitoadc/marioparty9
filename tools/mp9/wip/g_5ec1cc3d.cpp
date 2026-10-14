extern "C" void* memset(void* p, int c, unsigned long n);
extern "C" void fn_8020B5FC(void* p);

struct Obj;
typedef void (Obj::*Func)();

struct Elem {
    Func func;
    int field_C[9];
};

struct Deque {
    unsigned int start;
    int size;
    Elem** map;
    unsigned int mapStart;
    int mapSize;
    unsigned int mapCap;

    int Size() const { return size; }
    bool Empty() const { return size == 0; }
    Elem& Front() {
        unsigned int blk = start / 21;
        return map[(mapStart + blk) % mapCap][start - blk * 21];
    }
    void PopFront() {
        size--;
        start++;
        while (start >= 42) {
            fn_8020B5FC(map[mapStart]);
            mapStart++;
            if (mapStart == mapCap) {
                mapStart = 0;
            }
            mapSize--;
            start -= 21;
        }
        if (size == 0) {
            start = 10;
        }
    }
};

struct Obj {
    char pad[0x10];
    Elem cur;
    Deque queue;
    char pad58[0x88 - 0x58];
    int field_88;
};

extern "C" void shared_g_5ec1cc3d(Obj* self) {
    while (self->cur.func) {
        if (self->queue.Size() == 0) {
            memset(&self->cur, 0, sizeof(Elem));
        } else {
            self->cur = self->queue.Front();
            self->queue.PopFront();
        }
        self->field_88 = -1;
    }
}
