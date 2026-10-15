extern "C" asm void shared_g_ba6d8d83(void* dst, void* a, void* b, float t) {
    nofralloc
    psq_l f0, 0x0(r4), 0, 0
    psq_l f2, 0x0(r5), 0, 0
    ps_sub f3, f2, f0
    psq_l f2, 0x8(r5), 1, 0
    ps_madds0 f3, f3, f1, f0
    psq_l f0, 0x8(r4), 1, 0
    psq_st f3, 0x0(r3), 0, 0
    ps_sub f3, f2, f0
    ps_madds0 f3, f3, f1, f0
    psq_st f3, 0x8(r3), 1, 0
    blr
}
