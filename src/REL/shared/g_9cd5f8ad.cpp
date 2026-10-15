struct T { int pad[5]; virtual ~T(); };
struct O { char pad[0x1c]; T* arr[1]; };
extern "C" void shared_g_9cd5f8ad(O* self, int a, int b) {
    T*& p = self->arr[a + b * 0x22];
    if (p != 0) {
        T* t = p;
        p = 0;
        delete t;
    }
}
