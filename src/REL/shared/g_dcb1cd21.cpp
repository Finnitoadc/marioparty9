struct Target { char pad[0xBB]; unsigned char field_BB; };
extern "C" Target* fn_800486E0(void* p);

struct Vec {
    int pad;
    void** data;
    int count;
};

extern "C" void shared_g_dcb1cd21(Vec* self, int v) {
    unsigned char b = v;
    void* p;
    void** it = self->data;
    while (it != self->data + self->count) {
        p = *it;
        if (fn_800486E0(p)) {
            Target* t = fn_800486E0(p);
            t->field_BB = (t->field_BB & 0xFE) | b;
        }
        it++;
    }
}
