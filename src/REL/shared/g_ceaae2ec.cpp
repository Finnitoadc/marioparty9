struct Vec { float x, y, z; };
extern "C" void fn_8013A880(void* self, float x, float y, float z);

extern "C" void shared_g_ceaae2ec(void* self, Vec* v) {
    fn_8013A880(self, v->x, v->y, v->z);
}
