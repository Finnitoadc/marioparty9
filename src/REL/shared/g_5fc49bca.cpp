extern "C" int fn_80070750(void);

extern "C" int shared_g_5fc49bca(int n) {
    return fn_80070750() % n;
}
