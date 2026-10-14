struct Str {
    unsigned isLong : 1;
    unsigned rest : 31;
    int size;
    char* ptr;
};

extern "C" void fn_8020B5FC(void* p);

extern "C" void shared_g_014409fb(void* self, Str* s) {
    if (s != 0) {
        if (s != 0) {
            if (s->isLong) {
                fn_8020B5FC(s->ptr);
            }
        }
    }
}
