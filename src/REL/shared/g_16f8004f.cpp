extern "C" float shared_g_16f8004f(int a0, int a1) {
    float t0 = *(float*)(a1 + 0);
    float t1 = *(float*)(a1 + 4);
    *(float*)(a0 + 76) = t0;
    *(float*)(a0 + 80) = t1;
    return t0;
}
