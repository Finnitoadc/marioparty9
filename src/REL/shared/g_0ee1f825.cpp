struct Obj {
    char pad[0x174];
    int field_174;
};

extern "C" void fn_8005D990(void* obj, int v);

extern "C" void shared_g_0ee1f825(Obj* self, int v) {
    self->field_174 = v;
    fn_8005D990(self, v);
}
