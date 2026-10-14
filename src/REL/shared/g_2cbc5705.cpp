struct Vec {
    int x, y, z;
};

struct Obj {
    char pad[0x14];
    void* field_14;
};

extern "C" Vec* fn_80060100(void* node);

extern "C" void shared_g_2cbc5705(Vec* out, Obj* self) {
    Vec* p = fn_80060100(self->field_14);
    int x = p->x;
    int y = p->y;
    out->y = y;
    out->x = x;
    out->z = p->z;
}
