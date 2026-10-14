extern "C" int fn_8020BDC8(void* p);
extern "C" void fn_8020BE34(void* p);

extern "C" void shared_g_6750f80c(char* self) {
    if (fn_8020BDC8(self + 0x98) != 0) {
        fn_8020BE34(self);
    }
}
