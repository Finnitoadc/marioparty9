struct Vec { float x, y, z; };
extern "C" void fn_8013A700(void* self, float x, float y, float z);

extern "C" void shared_g_9c5b33b7(void* self, Vec* v) {
    fn_8013A700(self, v->x, v->y, v->z);
}
