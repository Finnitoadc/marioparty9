extern "C" void shared_g_f827005e(int a0, int* best, int* cnt, int* out, int* in, int* n) {
    int tmp[4];
    for (int k = 0; k < 4; k++) {
        tmp[k] = *n;
    }
    *best = in[0];
    for (int i = 0; i < *n; i++) {
        if (*best == in[i]) {
            (*cnt)++;
        }
        for (int j = 0; j < *n; j++) {
            if (i != j && in[i] >= in[j]) {
                tmp[i] = tmp[i] - 1;
                if (in[i] > *best) {
                    *best = in[i];
                    *cnt = 0;
                }
            }
        }
    }
    for (int i = 0; i < *n; i++) {
        out[i] = tmp[i];
    }
}
