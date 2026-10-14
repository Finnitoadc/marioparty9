extern "C" char __files[];
extern "C" int fn_80212A5C(void* file, const char* fmt, ...);
extern "C" void fn_80217134(void);

extern "C" void shared_g_2b34b325(const char* msg) {
    fn_80212A5C(__files + 0xA0, msg);
    fn_80217134();
}
