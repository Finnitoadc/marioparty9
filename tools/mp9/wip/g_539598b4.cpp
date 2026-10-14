extern "C" void fn_8005DA50(void* p, unsigned char n);
extern "C" void fn_8020B5FC(void* ptr);
extern "C" void* memset(void* p, int c, unsigned long n);

struct Cls;
typedef void (Cls::*Func)();

struct Rest {
    unsigned char field_0;
    char pad[3];
    int field_4[8];
};

struct Elem {
    Func func;
    Rest rest;
};

struct Deque {
    unsigned int start;
    unsigned int count;
    Elem** map;
    unsigned int mapStart;
    unsigned int mapCount;
    unsigned int mapCap;

    Elem& Front() {
        unsigned int blk = start / 21;
        return map[(mapStart + blk) % mapCap][start - blk * 21];
    }
    void PopFront() {
        count--;
        start++;
        while (start >= 42) {
            fn_8020B5FC(map[mapStart]);
            mapStart++;
            if (mapStart == mapCap) {
                mapStart = 0;
            }
            mapCount--;
            start -= 21;
        }
        if (count == 0) {
            start = 10;
        }
    }
};

struct Obj {
    char pad[0xC];
    void* field_C;
    Elem cur;
    Deque queue;
    char pad58[0x88 - 0x58];
    int field_88;
};

static inline void Assign(Elem* d, const Elem& s) { *d = s; }
static inline void Set(Elem* d, Elem s) { *d = s; }
static inline void Set2(Elem* d, const Elem* s) { *d = *s; }
extern "C" void shared_g_539598b4(Obj* self) {
    fn_8005DA50(self->field_C, self->cur.rest.field_0);
    if (self->queue.count == 0) {
        memset(&self->cur, 0, sizeof(Elem));
    } else {
        Assign(&self->cur, self->queue.Front());
        self->queue.PopFront();
    }
    self->field_88 = -1;
}
