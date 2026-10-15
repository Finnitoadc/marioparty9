struct S { int pad[11]; int n; };
extern "C" int shared_g_bd6637fd(S* self) {
    self->n = self->n + 1;
    return 0;
}
