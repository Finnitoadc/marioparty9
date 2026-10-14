typedef void (*Ctor)(void);

extern Ctor _ctors[];
extern Ctor _dtors[];

extern unsigned int fn_8008C800(void);
extern void fn_8008CB80(const char* name);
extern int fn_80070DB0(int value);
extern void fn_800958E0(const char* path);
extern void fn_80093BD0(void);
extern void fn_800816A0(const char* path);
extern void fn_800808B0(const char* group);
extern void fn_80080D90(void);

void _prolog(void) {
    Ctor* ctor = _ctors;
    while (*ctor != 0) {
        (*ctor)();
        ctor++;
    }

    if (((fn_8008C800() >> 28) & 1) == 0) {
        fn_8008CB80("strap");
        fn_80070DB0(0);
    } else {
        fn_800958E0("/mess/bin/ns.msbp");
        fn_80093BD0();
        fn_800816A0("/sound/9stars.brsar");
        fn_800808B0("GRP_COMMON");
        fn_80080D90();
        fn_8008CB80("menu_title");
        fn_80070DB0(0);
    }
}

void _epilog(void) {
    Ctor* dtor = _dtors;
    while (*dtor != 0) {
        (*dtor)();
        dtor++;
    }
}

void _unresolved(void) {
}
