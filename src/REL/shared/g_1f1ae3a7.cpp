struct V {
    virtual ~V();
};

struct Obj {
    char pad[0x1EC];
    V* arr1EC[8];
    V* arr20C[8];
    V* field_22C;
    int field_230;
    int field_234;
    int field_238;
    int field_23C;
};

extern "C" void shared_g_1f1ae3a7(Obj* self) {
    if (self->field_234 != 0) {
        for (unsigned i = 0; i < 8; i++) {
            if (self->arr1EC[i] != 0) {
                delete self->arr1EC[i];
                self->arr1EC[i] = 0;
            }
            if (self->arr20C[i] != 0) {
                delete self->arr20C[i];
                self->arr20C[i] = 0;
            }
        }
        if (self->field_22C != 0) {
            delete self->field_22C;
            self->field_22C = 0;
        }
        for (int j = 0; j < 8; j++) {
            self->arr1EC[j] = 0;
        }
        self->field_234 = 0;
        self->field_238 = 0;
        self->field_23C = -1;
        self->field_230 = 0;
    }
}
