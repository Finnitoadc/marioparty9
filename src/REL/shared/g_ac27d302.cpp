struct Info {
    char pad[0xBB];
    unsigned char flags;
};

extern "C" Info* fn_800486E0(void* obj);

extern "C" void shared_g_ac27d302(void* self, int on) {
    if (fn_800486E0(self)) {
        Info* p = fn_800486E0(self);
        p->flags = (p->flags & 0xFE) | (unsigned char)on;
    }
}
