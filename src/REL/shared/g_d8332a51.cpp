struct Inner { int field_0; int field_4; };
struct Obj { Inner* field_0; };
extern "C" int shared_g_d8332a51(Obj* self) {
    Inner* p = (Inner*)((char*)self->field_0 + 4);
    if (p != 0) {
        return p->field_4;
    }
    return 0;
}
