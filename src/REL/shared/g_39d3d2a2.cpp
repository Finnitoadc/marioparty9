struct E { int a; int b; };
struct S { char pad[0x88]; E* field_88; };
extern "C" int shared_g_39d3d2a2(S* self, int i) {
    return self->field_88[i].b;
}
