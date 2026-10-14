struct Vec2 {
    float x, y;
};

extern "C" void fn_80048C10(void* obj, Vec2* v);

struct Obj {
    char pad[0x1C];
    void* field_1c;
};

extern "C" void shared_g_0ed64045(Obj* self, float v) {
    Vec2 s;
    s.y = v;
    s.x = v;
    fn_80048C10(self->field_1c, &s);
}
