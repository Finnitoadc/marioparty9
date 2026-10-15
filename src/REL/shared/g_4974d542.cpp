struct V3 { float x, y, z; };
struct S { char pad[0x20]; V3 field_20; };
extern "C" void shared_g_4974d542(S* self, const V3& v) {
    self->field_20 = v;
}
