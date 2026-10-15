extern "C" void fn_80086B60(int* a, int* b);
extern "C" void shared_g_cb533578(int* dst, int* src) {
    dst[0] = src[0];
    fn_80086B60(dst + 1, src + 1);
}
