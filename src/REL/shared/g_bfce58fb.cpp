struct B { char pad[0x18]; int field_18; };
struct A { char pad[0xc]; B* field_c; };

extern "C" int shared_g_bfce58fb(A* self) {
    return self->field_c->field_18;
}
