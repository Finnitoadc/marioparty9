struct Obj {
    char pad[0x14];
    void* field_14;
};
extern "C" void fn_80048BD0(void*);
extern "C" void shared_g_c65e8e44(Obj* self) {
    fn_80048BD0(self->field_14);
}
