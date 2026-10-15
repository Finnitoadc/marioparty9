extern "C" void fn_8005DA50(void* o, int v);
struct O { char pad[0x15c]; unsigned char field_15c; unsigned char field_15d; unsigned char pad2; unsigned char field_15f; };
extern "C" void shared_g_dac8309e(O* o, int b) {
    if (b == 0 && o->field_15c != 0) {
        fn_8005DA50(o, o->field_15d);
    }
    o->field_15f = b;
}
