struct VObj {
    virtual void* Dtor(int del);
};

extern "C" void* shared_g_13ac7a27(char* self) {
    VObj* obj = *(VObj**)(self + 0x1bc);
    if (obj == 0) {
        return self;
    }
    *(VObj**)(self + 0x1bc) = 0;
    if (obj == 0) {
        return self;
    }
    return obj->Dtor(1);
}
