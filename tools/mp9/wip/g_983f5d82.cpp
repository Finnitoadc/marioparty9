extern "C" asm void shared_g_983f5d82(const float* a, const float* b, float* o1, float* o2) {
    nofralloc
    psq_l f7, 4(r4), 0, 0
    psq_l f6, 0x14(r3), 0, 0
    psq_l f4, 0(r4), 1, 0
    ps_mr f3, f7
    ps_mul f6, f6, f7
    psq_l f0, 0x10(r3), 1, 0
    psq_l f2, 8(r3), 0, 0
    psq_l f5, 4(r3), 1, 0
    ps_madd f7, f0, f4, f6
    lfs f1, 0x20(r3)
    ps_mul f2, f2, f3
    lfs f0, 0x1c(r3)
    ps_sum0 f6, f7, f6, f6
    ps_madd f3, f5, f4, f2
    fabs f4, f6
    ps_sum0 f2, f3, f2, f2
    fmuls f1, f1, f4
    stfs f2, 0(r5)
    fadds f0, f0, f1
    stfs f0, 0(r6)
    blr
}
