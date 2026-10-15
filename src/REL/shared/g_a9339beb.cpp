struct T { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();  virtual void f(int a, int b, int c, int d, int e, float f1, float f2, float f3, float f4); };
struct O { float a, b, c, d; };
extern "C" void shared_g_a9339beb(O* o, int a, T* t, int b, int c, int d, int e) {
    float d4 = o->d; float c4 = o->c; float b4 = o->b; float a4 = o->a;
    t->f(b, c, d, e, a, a4, b4, c4, d4);
}
