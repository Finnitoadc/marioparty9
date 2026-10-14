typedef struct {
    int a, b, c;
} Elem;

typedef struct {
    Elem* data;
    int count;
} Array;

static inline int ArrayCount(Array* arr) {
    return arr->count;
}

static inline Elem* ArrayAt(Array* arr, int i) {
    return &arr->data[i];
}

Elem* fn_8000C5C0(Array* arr) {
    return ArrayAt(arr, ArrayCount(arr) - 1);
}
