extern "C" int fn_80042A60(void* p);

extern "C" int shared_g_bdcee978(void** self) {
    return fn_80042A60(self[1]);
}
