struct Vec {
    float x, y, z;
    Vec(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};

extern "C" void* fn_80065DA0(void* obj);
extern "C" void fn_801318F0(void* node, int flag, float mtx[3][4]);

extern "C" Vec shared_g_1534e8a0(void* obj) {
    float mtx[3][4];
    fn_801318F0(fn_80065DA0(obj), 1, mtx);
    return Vec(mtx[0][3], mtx[1][3], mtx[2][3]);
}
