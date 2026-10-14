extern "C" int fn_8005D980(void* self);

extern "C" int shared_g_c9686c3b(char* self) {
    if (*(unsigned char*)(self + 0x1b4) != 0) {
        return *(int*)(self + 0x1b8);
    }
    return fn_8005D980(self);
}
