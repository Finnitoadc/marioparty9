extern "C" asm void shared_g_4daeb52f(float* a, const float* b) {
    nofralloc
    psq_l f2, 0(r3), 0, 0
    psq_l f1, 0(r4), 0, 0
    ps_add f0, f2, f1
    psq_l f2, 8(r3), 1, 0
    psq_l f1, 8(r4), 1, 0
    psq_st f0, 0(r3), 0, 0
    ps_add f0, f2, f1
    psq_st f0, 8(r3), 1, 0
    blr
}
