struct S {
    int pad[3];
    void* field_c;
};
extern "C" void fn_8020B5FC(void*);
extern "C" void shared_g_eb70ae66(S* s) {
    fn_8020B5FC(s->field_c);
}
