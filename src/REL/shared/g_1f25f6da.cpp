struct Info {
    int field_0;
    int field_4;
    int field_8;
};

struct Obj {
    char pad[0x28];
    char field_28[0x148];
    Info* field_170;
    void* field_174;
};

extern "C" void* fn_8020B514(int size);
extern "C" void* fn_80041410(void* p);
extern "C" void fn_8005D990(void* p, int v);
extern "C" void fn_8005D970(void* p, int v);

extern "C" void shared_g_1f25f6da(Obj* self) {
    if (self->field_170->field_0 != 0) {
        void* p = fn_8020B514(4);
        if (p != 0) {
            p = fn_80041410(p);
        }
        self->field_174 = p;
        fn_8005D990(self->field_28, self->field_170->field_8);
        fn_8005D970(self->field_28, self->field_170->field_4);
    }
}
