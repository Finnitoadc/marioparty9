struct V2 { float x, y; };
struct S { char pad[0x44]; float field_44; float field_48; };
extern "C" void shared_g_c4969c78(S* self, V2* v) {
    float y;
    float x;
    x = v->x;
    y = v->y;
    self->field_44 = x;
    self->field_48 = y;
}
