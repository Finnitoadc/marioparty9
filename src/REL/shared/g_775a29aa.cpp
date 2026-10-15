extern "C" void fn_8002EA40(void* a, void* b);

extern "C" void shared_g_775a29aa(void* a, void** b) {
    fn_8002EA40(a, *(void**)b[1]);
}
