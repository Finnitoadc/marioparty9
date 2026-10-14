extern "C" void fn_800385F0(void* self);

extern "C" void shared_g_99034325(char* self, unsigned char a, unsigned char b) {
    self[0x58] = a;
    self[0x59] = b;
    fn_800385F0(self);
}
