struct Item { char pad[0x11]; unsigned char field_11; };
struct Obj { char pad[8]; Item** field_8; int field_c; };
extern "C" int shared_g_95032430(Obj* self) {
    Item** end;
    Item** p;
    p = self->field_8;
    end = p + self->field_c;
    for (; p != end; p++) {
        if (!(*p)->field_11) return 0;
    }
    return 1;
}
