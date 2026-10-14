extern "C" int fn_8005D9A0(void* self);

extern "C" int shared_g_98a2ed67(char* self) {
    if (*(unsigned char*)(self + 0x1ac) != 0) {
        return *(int*)(self + 0x1b0);
    }
    return fn_8005D9A0(self);
}
