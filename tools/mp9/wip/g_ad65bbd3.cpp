extern "C" asm void shared_g_ad65bbd3(float* a, float* b, float* c, float* d) {
    nofralloc
    psq_l f0, 4(r4), 0, 0
    psq_l f1, 8(r3), 0, 0
    psq_l f2, 0(r4), 1, 0
    ps_mul f0, f0, f1
    psq_l f1, 4(r3), 1, 0
    psq_l f3, 4(r4), 0, 0
    psq_l f4, 0x14(r3), 0, 0
    ps_madd f1, f2, f1, f0
    ps_mul f3, f3, f4
    psq_l f4, 0x10(r3), 1, 0
    ps_sum0 f1, f1, f0, f0
    ps_madd f4, f2, f4, f3
    stfs f1, 0(r6)
    frsp f0, f1
    ps_sum0 f2, f4, f3, f3
    stfs f1, 0(r5)
    fcmpo cr0, f2, f0
    bge L1
    stfs f2, 0(r5)
L1:
    lfs f0, 0(r6)
    fcmpo cr0, f2, f0
    ble L2
    stfs f2, 0(r6)
L2:
    addi r3, r3, 0x1c
    psq_l f3, 4(r4), 0, 0
    psq_l f4, 4(r3), 0, 0
    psq_l f1, 0(r4), 1, 0
    ps_mul f3, f3, f4
    psq_l f4, 0(r3), 1, 0
    lfs f0, 0(r5)
    ps_madd f4, f1, f4, f3
    ps_sum0 f2, f4, f3, f3
    fcmpo cr0, f2, f0
    bge L3
    stfs f2, 0(r5)
L3:
    lfs f0, 0(r6)
    fcmpo cr0, f2, f0
    blelr
    stfs f2, 0(r6)
    blr
}
