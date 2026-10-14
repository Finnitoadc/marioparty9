extern "C" void fn_80192CD0(void* a, void* b);

extern "C" void* shared_g_d51a2006(void* self, void* a) {
    fn_80192CD0(a, self);
    return self;
}
