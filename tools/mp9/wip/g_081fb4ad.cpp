struct Elem {
    char pad[0xC];
};

struct MapIter {
    Elem** cur;
    Elem** begin;
    Elem** start;
    Elem** end;

    MapIter() {}
    MapIter(Elem** c, Elem** b, Elem** e) { cur = c; begin = b; start = c; end = e; }
    MapIter& operator+=(int n) {
        int cap = end - begin;
        int pos = (cur - begin) + n;
        if (pos < 0) {
            pos += cap;
        } else if (pos >= cap) {
            pos -= cap;
        }
        cur = begin + pos;
        return *this;
    }
};


static inline MapIter operator+(MapIter it, int n) {
    it += n;
    return it;
}

struct Iter {
    MapIter m;
    Elem* p;

    Iter(MapIter it, int cnt, unsigned int off) { Elem* e = (cnt == 0 ? 0 : *it.cur) + off; m = it; p = e; }
};

struct Deque {
    unsigned int first;
    unsigned int size;
    Elem** map;
    int mapStart;
    int mapCount;
    int mapCap;
};

static inline MapIter MapBegin(Deque* d) {
    return MapIter(d->map + d->mapStart, d->map, d->map + d->mapCap);
}

static inline Iter MakeIter(Deque* d, MapIter m, unsigned int idx) {
    m += idx / 85;
    return Iter(m, d->mapCount, idx % 85);
}

extern "C" Iter shared_g_081fb4ad(Deque* d) {
    return MakeIter(d, MapBegin(d), d->size + d->first);
}
