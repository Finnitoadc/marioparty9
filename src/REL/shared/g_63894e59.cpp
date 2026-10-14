struct Cell {
    int kind;
};

struct Grid {
    char pad[0x1C];
    Cell* cells[1];
};

extern "C" int shared_g_63894e59(Grid* self, int x, int y) {
    Cell* c = self->cells[x + y * 0x22];
    if (c == 0) {
        return 0;
    }
    if (c->kind >= 4 && c->kind < 6) {
        return 1;
    }
    return 0;
}
