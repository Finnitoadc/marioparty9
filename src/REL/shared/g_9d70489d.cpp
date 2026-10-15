extern "C" void fn_80086B60(void* p);
extern "C" void fn_80047E60(void* self, void* tmp, int n, int z);
extern "C" void fn_80086F10(void* p, int v);

extern "C" void shared_g_9d70489d(void* self, int unused, int n) {
    char tmp[0x10];
    fn_80086B60(tmp);
    fn_80047E60(self, tmp, n, 0);
    fn_80086F10(tmp, -1);
}
