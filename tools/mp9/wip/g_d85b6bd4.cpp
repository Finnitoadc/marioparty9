extern "C" asm void shared_g_d85b6bd4(float* a, float* b, float* c, float* d) {
    nofralloc
    psq_l f4, 0x4(r4), 0, 0
    psq_l f3, 0x14(r3), 0, 0
    ps_mr f8, f4
    psq_l f7, 0x20(r3), 0, 0
    ps_mul f3, f3, f4
    psq_l f2, 0x0(r4), 1, 0
    psq_l f0, 0x10(r3), 1, 0
    ps_mul f7, f7, f8
    ps_madd f4, f0, f2, f3
    psq_l f1, 0x1c(r3), 1, 0
    ps_mr f5, f8
    psq_l f0, 0x2c(r3), 0, 0
    ps_madd f8, f1, f2, f7
    psq_l f1, 0x28(r3), 1, 0
    ps_mul f0, f0, f5
    ps_sum0 f6, f4, f3, f3
    psq_l f3, 0x8(r3), 0, 0
    ps_mr f4, f5
    ps_madd f5, f1, f2, f0
    lfs f1, 0x34(r3)
    ps_sum0 f7, f8, f7, f7
    fabs f6, f6
    ps_sum0 f5, f5, f0, f0
    lfs f0, 0x38(r3)
    fabs f7, f7
    ps_mul f3, f3, f4
    psq_l f4, 0x4(r3), 1, 0
    fmuls f1, f1, f6
    fmuls f0, f0, f7
    ps_madd f4, f4, f2, f3
    lfs f2, 0x3c(r3)
    fabs f5, f5
    fadds f0, f1, f0
    ps_sum0 f3, f4, f3, f3
    fmuls f1, f2, f5
    stfs f3, 0x0(r5)
    fadds f0, f1, f0
    stfs f0, 0x0(r6)
    blr
}
