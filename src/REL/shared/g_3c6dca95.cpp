extern "C" void fn_80192930(void* a, void* b, void* c);

extern "C" void* shared_g_3c6dca95(void* self, void* a, void* b) {
    fn_80192930(a, b, self);
    return self;
}
