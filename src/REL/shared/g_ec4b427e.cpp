struct Buffer {
    char* data;
    int count;

    char* Begin() { return data; }
    char* End() { return data + count; }
    void Erase(char* first, char* last) { count -= last - first; }
    void Clear() { Erase(Begin(), End()); }
};

struct Obj {
    char pad[0x68];
    Buffer buf;
};

extern "C" void shared_g_ec4b427e(Obj* self) {
    self->buf.Clear();
}
