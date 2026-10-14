struct Vec {
    float x, y, z;
};

extern "C" void fn_80060190(void* obj, Vec* v);

struct Obj {
    char pad[0x68];
    char sub[0x5A8];
    float field_610;
};

extern "C" void shared_g_cc9431c0(Obj* self, Vec* v) {
    fn_80060190(self->sub, v);
    self->field_610 = v->y;
}
