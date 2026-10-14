// Base object shared by the strap scene.
typedef unsigned char u8;
typedef unsigned int u32;

struct StrapSub {
    void** vtbl;
    int field_4;
    void* buf;
};

struct StrapBase {
    void** vtbl;
    int field_4;
    StrapSub* sub;
};

extern "C" {
void* fn_8020B514(u32 size);              // operator new
void fn_8020B5FC(void* ptr);              // operator delete
void* fn_80071350(void* self);
void fn_80071420(void* self, int flags);
void fn_800714E0(void* self, int a);
void fn_80071580(void* self, int a);
void fn_800714A0(void* self, int a);
void fn_8008CB30(void* self);
void fn_8008CB40(void* self, int arg);
void fn_800715E0(float v);
extern u32 lbl_8026E2A4;

StrapBase* fn_115_3E0(StrapBase* self);
StrapBase* fn_115_490(StrapBase* self, int del);
StrapSub* fn_115_530(StrapSub* self, int del);
void fn_115_5D0(StrapSub* self);
void fn_115_5A0(void* self, int arg);
void fn_115_3B0(void);
}

// Declaration only (never defined): used to emit virtual calls through the vtable.
struct VObj {
    virtual void Dtor(int del);
    virtual void Slot1();
    virtual void Slot2();
};

static StrapBase* sBase;

static void* sVtblSub[] = {0, 0, (void*)fn_115_530, (void*)fn_115_5D0};
static void* sVtblBase[] = {0, 0, (void*)fn_115_490, 0, (void*)fn_115_3B0};

extern "C" StrapBase* fn_115_3E0(StrapBase* self) {
    fn_80071350(self);
    sBase = self;
    self->vtbl = sVtblBase;

    StrapSub* sub = (StrapSub*)fn_8020B514(0xC);
    if (sub != 0) {
        fn_80071350(sub);
        sub->vtbl = sVtblSub;
        sub->buf = fn_8020B514(1);
        fn_800714E0(sub, 6);
        fn_80071580(sub, 0x10);
        fn_800714A0(sub, 0x7FFFFFFF);
    }
    self->sub = sub;
    fn_8008CB30(self);
    return self;
}

extern "C" StrapBase* fn_115_490(StrapBase* self, int del) {
    if (self != 0) {
        self->vtbl = sVtblBase;
        if (self->sub != 0) {
            ((VObj*)self->sub)->Dtor(1);
        }
        if (&self->sub != 0) {
            sBase = 0;
        }
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}

extern "C" StrapSub* fn_115_530(StrapSub* self, int del) {
    if (self != 0) {
        void** bufAddr = &self->buf;
        if (bufAddr != 0) {
            fn_8020B5FC(*bufAddr);
        }
        fn_80071420(self, 0);
        if (del > 0) {
            fn_8020B5FC(self);
        }
    }
    return self;
}

extern "C" void fn_115_5A0(void* self, int arg) {
    fn_8008CB40(self, arg);
    fn_800715E0(-1.0f);
}

extern "C" void fn_115_5D0(StrapSub* self) {
    if ((lbl_8026E2A4 & 0x80) != 0) {
        void* buf = self->buf;
        if (buf != 0) {
            self->buf = 0;
            fn_8020B5FC(buf);
        }
        StrapBase* inst = sBase;
        ((VObj*)inst)->Slot2();
        fn_8008CB40(inst, -1);
        fn_800715E0(-1.0f);
        fn_800715E0(-1.0f);
    }
}
