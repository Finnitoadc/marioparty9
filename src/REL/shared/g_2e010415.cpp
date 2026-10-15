extern "C" void memset(void* p, int v, unsigned n);
extern "C" void shared_g_2e010415(char* self) {
    memset(self, 0, 0x2c);
    memset(self + 0x2c, 0, 0x2c);
}
