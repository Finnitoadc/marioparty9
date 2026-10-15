struct B {
    char pad[0xBB];
    unsigned char field_BB;
};

extern "C" B* fn_800486E0();

extern "C" void shared_g_a795d283(void* self, int v) {
    B* b = fn_800486E0();
    b->field_BB = (b->field_BB & 0xFE) | (unsigned char)v;
}
