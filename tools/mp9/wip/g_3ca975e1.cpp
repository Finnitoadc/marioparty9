extern "C" void fn_8002CD90(void* obj, float* v);
extern "C" void fn_8002D7A0(void* obj, float* v);

extern "C" asm void shared_g_3ca975e1(void* self, const float* pos, const float* rot) {
    nofralloc
    stwu r1, -0x30(r1)
    mflr r0
    psq_l f1, 0(r4), 0, 0
    stw r0, 0x34(r1)
    addi r6, r1, 0x14
    stw r31, 0x2c(r1)
    mr r31, r5
    stw r30, 0x28(r1)
    mr r30, r4
    stw r29, 0x24(r1)
    mr r29, r3
    psq_l f0, 0x13c(r3), 0, 0
    ps_add f0, f1, f0
    psq_l f1, 8(r4), 1, 0
    mr r4, r6
    psq_st f0, 0(r6), 0, 0
    psq_l f0, 0x144(r3), 1, 0
    ps_add f0, f1, f0
    psq_st f0, 8(r6), 1, 0
    bl fn_8002CD90
    psq_l f4, 0(r31), 0, 0
    addi r4, r1, 0x8
    psq_l f0, 0x13c(r29), 0, 0
    mr r3, r29
    lfs f2, 0(r30)
    ps_add f3, f4, f0
    lfs f1, 4(r30)
    lfs f0, 8(r30)
    stfs f2, 0x124(r29)
    psq_l f4, 8(r31), 1, 0
    stfs f1, 0x128(r29)
    stfs f0, 0x12c(r29)
    psq_st f3, 0(r4), 0, 0
    psq_l f0, 0x144(r29), 1, 0
    ps_add f3, f4, f0
    psq_st f3, 8(r4), 1, 0
    bl fn_8002D7A0
    lfs f2, 0(r31)
    lfs f1, 4(r31)
    lfs f0, 8(r31)
    stfs f2, 0x130(r29)
    stfs f1, 0x134(r29)
    stfs f0, 0x138(r29)
    lwz r31, 0x2c(r1)
    lwz r30, 0x28(r1)
    lwz r29, 0x24(r1)
    lwz r0, 0x34(r1)
    mtlr r0
    addi r1, r1, 0x30
    blr
}
