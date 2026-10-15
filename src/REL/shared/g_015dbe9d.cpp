struct N { int field_0; };
struct It { N* field_0; };
extern "C" N* shared_g_015dbe9d(It* self) {
    N* n = self->field_0;
    self->field_0 = (N*)n->field_0;
    return n;
}
