struct Vec {
    float x, y, z;
};

extern "C" int fn_80065DE0(void* p);
extern "C" int fn_8010E9A0(int* h, const char* name);
extern "C" void fn_80113A60(int* h, float x, float y, float z);

struct Obj {
    char pad[0x8];
    unsigned int flag : 1;
    char pad2[0x4];
    const char* field_10;
    char pad3[0x50];
    Vec field_64;
    char pad4[0x34];
    void* field_A4;
};

extern "C" void shared_g_31a7c03e(Obj* self, const Vec* v) {
    float z;
    float y;
    float x;
    x = v->x;
    y = v->y;
    z = v->z;
    self->field_64.x = x;
    self->field_64.y = y;
    self->field_64.z = z;
    if (self->field_A4 != 0) {
        int a = fn_80065DE0(self->field_A4);
        int b = fn_8010E9A0(&a, !self->flag ? (const char*)self + 9 : self->field_10);
        fn_80113A60(&b, v->x, v->y, v->z);
    }
}
