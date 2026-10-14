extern "C" float shared_g_c68a324e(int a0, int a1) {
    *(float*)(a1 + 0) = *(float*)(a0 + 4);
    *(float*)(a1 + 4) = *(float*)(a0 + 8);
    *(float*)(a1 + 8) = *(float*)(a0 + 12);
    return *(float*)(a0 + 8);
}
