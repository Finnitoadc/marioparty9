extern "C" void fn_80191D30(void* a, void* b);

extern "C" int shared_g_1087bded(char* self, int unused, void* arg) {
    fn_80191D30(arg, self + 0x84);
    return 1;
}
