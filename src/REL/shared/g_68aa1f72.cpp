struct V { float x, y, z; };
extern "C" void shared_g_68aa1f72(V* d, const V* s) {
    float z = -s->z; float y = -s->y; float x = -s->x;
    d->z = z; d->x = x; d->y = y;
}
