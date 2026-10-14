extern "C" asm void shared_g_2314100b(register float* dst, register const float* src, register float s) {
    nofralloc
    psq_l f2, 0(src), 0, 0
    ps_muls0 f0, f2, s
    psq_l f2, 8(src), 1, 0
    psq_st f0, 0(dst), 0, 0
    ps_muls0 f0, f2, s
    psq_st f0, 8(dst), 1, 0
    blr
}
