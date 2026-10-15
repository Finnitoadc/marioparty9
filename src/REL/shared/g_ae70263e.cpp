extern "C" int strlen(const char* s);
extern "C" void shared_g_35badb40(void* self, const char* s, int a, int n);
extern "C" void shared_g_ae70263e(void* self, const char* s, int a) {
    shared_g_35badb40(self, s, a, strlen(s));
}
