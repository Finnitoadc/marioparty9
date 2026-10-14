extern "C" void fn_8002AF70(void* obj);
extern "C" int fn_8002AF40(void* obj);
extern "C" void fn_8002AF00(void* obj, int flag);

struct Flags {
    char pad[0xBB];
    unsigned char field_bb;
};

struct Other {
    char pad[0x10];
    Flags* field_10;
};

struct Obj {
    char pad[0x20];
    void* field_20;
};

extern "C" void shared_g_275dc748(Obj* self, Other* o) {
    if (o->field_10->field_bb & 1) {
        if (self->field_20 != 0) {
            fn_8002AF70(self->field_20);
            if (fn_8002AF40(self->field_20) == 0) {
                fn_8002AF00(self->field_20, 1);
            }
        }
    }
}
