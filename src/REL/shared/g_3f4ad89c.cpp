extern "C" asm void shared_g_3f4ad89c(float* v, float s) {
    nofralloc
    psq_l f2, 0(r3), 0, 0
    ps_muls0 f0, f2, f1
    psq_l f2, 8(r3), 1, 0
    psq_st f0, 0(r3), 0, 0
    ps_muls0 f0, f2, f1
    psq_st f0, 8(r3), 1, 0
    blr
}
