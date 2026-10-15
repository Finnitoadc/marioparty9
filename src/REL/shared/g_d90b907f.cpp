struct S { char pad[0x14]; int* arr; };
extern "C" int shared_g_d90b907f(S* self, int i) { return self->arr[i]; }
