extern "C" asm float shared_g_103e369a(const float* a, const float* b) {
    nofralloc
    psq_l f2, 4(r3), 0, 0
    psq_l f1, 4(r4), 0, 0
    psq_l f0, 0(r3), 1, 0
    ps_mul f2, f2, f1
    psq_l f1, 0(r4), 1, 0
    ps_madd f1, f0, f1, f2
    ps_sum0 f1, f1, f2, f2
    blr
}
