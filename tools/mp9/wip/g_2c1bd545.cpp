extern "C" int fn_8020C6D8(void* p);
extern "C" void fn_8020C7DC(void* p, int v);
struct X { char pad[0x188]; char pad2[0x318 - 0x188]; unsigned char field_318; };
struct O { char pad[0x328]; X* field_328; };
extern "C" void shared_g_2c1bd545(O* o) {
    X* x = o->field_328;
    if (x->field_318 == 0) {
        if (fn_8020C6D8(x) == 0) {
            fn_8020C7DC((char*)o->field_328 + 0x188, 1);
        }
    }
}
