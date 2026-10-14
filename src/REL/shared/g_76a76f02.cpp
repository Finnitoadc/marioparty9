extern "C" void fn_8005DA50(void* item, void* arg);

struct Array {
    void** data;
    unsigned int count;
    int capacity;
    void** Begin() { return data; }
    void** End() { return data + count; }
};

struct Obj {
    char pad[0x8];
    Array field_8;
    Array field_14;
};

extern "C" void shared_g_76a76f02(Obj* self, void* arg) {
    for (void** it = self->field_14.Begin(); it != self->field_14.End(); it++) {
        fn_8005DA50(*it, arg);
    }
    for (void** it = self->field_8.Begin(); it != self->field_8.End(); it++) {
        fn_8005DA50(*it, arg);
    }
}
