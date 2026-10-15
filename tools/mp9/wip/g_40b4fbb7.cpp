extern "C" void fn_80086B90(void* a, void* b);
extern "C" void fn_80086F10(void* a, int b);

struct Buffer {
    char* data;
    int count;

    char* Begin() { return data; }
    char* End() { return data + count; }
    void Erase(char* first, char* last) { count -= last - first; }
    void Clear() { Erase(Begin(), End()); }
};

struct Obj {
    Buffer b0;
    int pad0;
    Buffer b1;
    int pad1;
    Buffer b2;
    int pad2;
    int field_24;
    int field_28;
};

extern "C" void shared_g_40b4fbb7(Obj* self) {
    int tmp = 0;
    self->field_28 = 0;
    fn_80086B90(&self->field_24, &tmp);
    fn_80086F10(&tmp, -1);
    self->b0.Clear();
    self->b1.Clear();
    self->b2.Clear();
}
