struct N { int pad; N* next; };
extern "C" N* shared_g_4822a0d5(N* self) { return self->next->next; }
