extern "C" int fn_80048FA0(void* p, int a);

struct Vector {
    int field_0;
    void** buf;
    unsigned int count;
};

extern "C" int shared_g_9b37621c(Vector* self, int a) {
    return fn_80048FA0(self->buf[self->count - 1], a);
}
