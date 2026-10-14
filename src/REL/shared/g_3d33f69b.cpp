extern "C" void fn_80192D90(void* a, void* b, void* c);

extern "C" void* shared_g_3d33f69b(void* self, void* a, void* b) {
    fn_80192D90(a, b, self);
    return self;
}
