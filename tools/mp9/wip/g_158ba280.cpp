extern "C" void fn_800715E0(float t);
extern "C" void* memset(void* dst, int c, unsigned long n);
extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
extern "C" void fn_8020B5FC(void* ptr);

struct Vec {
    float x, y, z;
};

struct M33 {
    float v[3][3];
};

struct Elem {
    Vec pos;
    M33 rot;

    Elem() {}

};

struct Deque {
    unsigned int first;
    unsigned int size;
    Elem** map;
    unsigned int mapStart;
    unsigned int mapCount;
    unsigned int mapCap;

    bool Empty() const { return size == 0; }
    Elem& Front() { return map[(mapStart + first / 21) % mapCap][first % 21]; }
    void PopFront(Elem* out) {
        *out = Front();
        --size;
        ++first;
        while (first >= 42) {
            fn_8020B5FC(map[mapStart]);
            if (++mapStart == mapCap) {
                mapStart = 0;
            }
            mapCount--;
            first -= 21;
        }
        if (size == 0) {
            first = 10;
        }
    }
};

struct Obj {
    char pad[0x10];
    Elem cur;
    Deque q;
    char pad58[0x30];
    int field_88;
};

extern "C" void shared_g_158ba280(Obj* self) {
    fn_800715E0(self->cur.rot.v[0][0]);
    if (self->q.Empty()) {
        memset(&self->cur, 0, 0x30);
    } else {
        self->q.PopFront(&self->cur);
    }
    self->field_88 = -1;
}
