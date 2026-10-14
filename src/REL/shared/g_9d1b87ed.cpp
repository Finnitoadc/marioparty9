extern "C" void* fn_80046040(unsigned int res, int flags);

extern "C" void* shared_g_9d1b87ed(unsigned int* self, unsigned int value) {
    unsigned int old = *self;
    if (value == old) {
        return self;
    }
    *self = value;
    return fn_80046040(old, 1);
}
