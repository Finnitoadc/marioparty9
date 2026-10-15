struct Obj {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
};

extern "C" char shared_zero1[];
extern "C" char shared_g_627244bb[];
extern "C" void fn_8020BBD8(void* p, void* a, void* b, int c, int d);

extern "C" Obj* shared_g_c00c21b3(Obj* self) {
    self->field_0 = 0;
    fn_8020BBD8(&self->field_4, shared_zero1, shared_g_627244bb, 4, 2);
    self->field_C = 0;
    self->field_10 = 0;
    self->field_14 = 0;
    return self;
}
