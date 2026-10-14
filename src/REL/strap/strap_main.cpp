// "strap" scene: the wrist strap warning screen shown on first boot.
typedef unsigned char u8;
typedef unsigned int u32;

typedef void (*Ctor)(void);
extern "C" Ctor _ctors[];
extern "C" Ctor _dtors[];

struct StrapScene {
    void** vtbl;
    int field_4;
    void* sub;
    u8 pressed;
    void* res;
};

extern "C" {
void* fn_8020B514(u32 size);              // operator new
void fn_8020B5FC(void* ptr);              // operator delete
void fn_8008B020(int a, int b);
void fn_80046040(void* res, int flags);
void* fn_80046CF0(void* self, char* path, char* name, int a, int b);
void fn_80074710(int a, float t);
void fn_80074B60(int a, float t);
void* fn_80070680(int pad);
int fn_8006DBC0(void* pad, int mask);
void fn_80071590(void);
u32 fn_8008C800(void);
void fn_8008C7F0(u32 flags);
void fn_8006DD40(int a);
void fn_80073660(int a);
extern float lbl_8026E3B0;

// strap_base.cpp
void* fn_115_3E0(StrapScene* self);
void* fn_115_490(StrapScene* self, int del);
void fn_115_5A0(StrapScene* self, int arg);

StrapScene* fn_115_0(StrapScene* self, int del);
void fn_115_90(StrapScene* self);
void fn_115_3B0(void);
}

// Declaration only (never defined): used to emit virtual calls through the vtable.
struct VObj {
    virtual void Dtor(int del);
};

static char sPath[] = "/strap1";
static char* sPathPtr = sPath;
static float sWaitTime = 1.0f;
static float sMaxTime = 19.0f;
static char sName[] = "strap";
static void* sVtblScene[] = {0, 0, (void*)fn_115_0, (void*)fn_115_90, (void*)fn_115_3B0};

struct FrameRate {
    float value;
    FrameRate(float v) { value = v; }
};

static FrameRate sFrameRate(60.0f);
static StrapScene* sScene;

extern "C" StrapScene* fn_115_0(StrapScene* self, int del) {
    if (self != 0) {
        self->vtbl = sVtblScene;
        fn_8008B020(1, 1);
        void** res = &self->res;
        if (res != 0) {
            fn_80046040(*res, 1);
        }
        fn_115_490(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}

static inline float Frames(float sec) { return sec * lbl_8026E3B0; }
static inline int IsAnyPressed(StrapScene* self) {
    if (self->pressed != 0) {
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        if (fn_8006DBC0(fn_80070680(i), (int)0xFFFF1FFF) != 0) {
            self->pressed = 1;
        }
    }
    return self->pressed;
}

extern "C" void fn_115_90(StrapScene* self) {
    fn_80074710(1, 0.5f);

    for (int i = 0; (float)i < Frames(sWaitTime); i++) {
        IsAnyPressed(self);
        fn_80071590();
    }

    fn_8008C7F0(fn_8008C800() | 0x10000000);

    for (int i = 0; (float)i < Frames(sMaxTime) && !IsAnyPressed(self); i++) {
        fn_80071590();
    }

    fn_80074B60(1, 0.5f);
    fn_115_5A0(self, 0);
}

extern "C" void _prolog(void) {
    Ctor* ctor = _ctors;
    while (*ctor != 0) {
        (*ctor)();
        ctor++;
    }

    StrapScene* scene = (StrapScene*)fn_8020B514(0x14);
    if (scene != 0) {
        fn_115_3E0(scene);
        scene->vtbl = sVtblScene;
        scene->pressed = 0;
        scene->res = 0;
        void* res = fn_8020B514(4);
        if (res != 0) {
            res = fn_80046CF0(res, sPathPtr, sName, 0, 0);
        }
        void* old = scene->res;
        if (res != old) {
            scene->res = res;
            fn_80046040(old, 1);
        }
        fn_8006DD40(0);
        fn_80073660(1);
        fn_8008B020(0, 0);
    }
    sScene = scene;
}

extern "C" void _epilog(void) {
    if (sScene != 0) {
        ((VObj*)sScene)->Dtor(1);
    }
    Ctor* dtor = _dtors;
    while (*dtor != 0) {
        (*dtor)();
        dtor++;
    }
}

extern "C" void _unresolved(void) {
}

extern "C" void fn_115_3B0(void) {
}
