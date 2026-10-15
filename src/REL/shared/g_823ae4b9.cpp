struct Item { char pad[0xb8]; unsigned char field_b8; };
struct S {
    char pad[0x58];
    Item** field_58;
    unsigned field_5c;
};
extern "C" void shared_g_823ae4b9(S* self, unsigned char v) {
    for (unsigned i = 0; i < self->field_5c; i++) {
        self->field_58[i]->field_b8 = v;
    }
}
