struct B { int field_0; };
struct A { int field_0; B* field_4; int field_8; };

extern "C" int shared_g_5ccc98af(void* p);

extern "C" int shared_g_f66f599b(A* self) {
    if (self->field_8 == 0) {
        return 0;
    }
    return shared_g_5ccc98af((void*)self->field_4->field_0);
}
