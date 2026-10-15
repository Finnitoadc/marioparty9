struct Item { char pad[0x184]; int field_184; };
struct S { char pad[0x5c]; Item** field_5C; };
extern "C" Item* shared_g_f23b6218(S* self, int id) {
    Item** a = self->field_5C;
    Item* r = 0;
    if (id == a[0]->field_184) r = a[0];
    else if (id == a[1]->field_184) r = a[1];
    else if (id == a[2]->field_184) r = a[2];
    else if (id == a[3]->field_184) r = a[3];
    return r;
}
