struct Target;
typedef void (Target::*Func)(unsigned char);

struct Entry {
    Func func;
    unsigned char arg;
};

struct Target {
    char pad[1];
};

extern "C" void shared_g_9f9065bc(Entry* out, Target*** it, Target*** end, Entry* e) {
    while (*it != *end) {
        (**it->*(e->func))(e->arg);
        ++*it;
    }
    int* s = (int*)e;
    int* d = (int*)out;
    int x = s[0];
    int y = s[1];
    d[1] = y;
    d[0] = x;
    d[2] = s[2];
    out->arg = e->arg;
}
