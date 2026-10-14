struct Vec {
    float x, y, z;
};

struct Obj {
    char pad[0x10];
    Vec axis[3];
};

extern "C" void shared_g_5f7e7226(Obj* self, float m[3][4]) {
    float m22, m12, m02, m21, m11, m01, m20, m10, m00;
    m00 = m[0][0];
    m10 = m[1][0];
    m20 = m[2][0];
    m01 = m[0][1];
    m11 = m[1][1];
    m21 = m[2][1];
    m02 = m[0][2];
    m12 = m[1][2];
    m22 = m[2][2];
    self->axis[0].x = m00;
    self->axis[0].y = m10;
    self->axis[0].z = m20;
    self->axis[1].x = m01;
    self->axis[1].y = m11;
    self->axis[1].z = m21;
    self->axis[2].x = m02;
    self->axis[2].y = m12;
    self->axis[2].z = m22;
}
