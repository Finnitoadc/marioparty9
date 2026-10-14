struct Info {
    char pad[0xBB];
    unsigned char flags;
};

extern "C" Info* fn_800486E0(void* obj);

extern "C" int shared_g_5ccc98af(void* self) {
    if (fn_800486E0(self)) {
        return fn_800486E0(self)->flags & 1;
    }
    return 0;
}
