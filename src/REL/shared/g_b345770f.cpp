struct E {
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
};

extern "C" int shared_g_b345770f(E* arr, int i) {
    return arr[i].field_0C;
}
