extern "C" void fn_8005D940(void* self);
extern "C" void fn_8005D960(void* self);
extern "C" void fn_8005DA50(void* self, int on);

extern "C" void shared_g_594a08e0(void* self, int on) {
    if (on == 0) {
        fn_8005D940(self);
    } else {
        fn_8005D960(self);
    }
    fn_8005DA50(self, on);
}
