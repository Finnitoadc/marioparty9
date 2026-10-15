extern "C" int fn_80042D70(int v);

struct Obj {
    int field_0;
    int field_4;
};

extern "C" Obj* shared_g_98bbe148(Obj* self, Obj* other) {
    self->field_4 = fn_80042D70(other->field_4) ? other->field_4 : 0;
    return self;
}
