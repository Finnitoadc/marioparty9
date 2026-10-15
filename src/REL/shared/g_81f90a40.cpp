struct Data {
    int field_0;
    int field_4;
    unsigned char field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
};

struct Obj {
    Data* data;
};

extern "C" void* fn_8020B514(int size);

extern "C" Obj* shared_g_81f90a40(Obj* self) {
    Data* d = (Data*)fn_8020B514(0x30);
    if (d != 0) {
        d->field_0 = 0;
        d->field_4 = 0;
        d->field_8 = 0;
        d->field_C = 0;
        d->field_10 = 0;
        d->field_14 = 0;
        d->field_18 = 0;
        d->field_1C = 0;
        d->field_20 = 0;
        d->field_24 = 0;
        d->field_28 = 0;
        d->field_2C = 0;
    }
    self->data = d;
    return self;
}
