import subprocess
p='src/REL/shared/g_fae93e99.cpp'
head=open(p).read()
head=head[:head.index('extern "C" void*')]
tmpl='''extern "C" Node* shared_g_fae93e99(Tree* t, unsigned* key, Node** out, char* a, char* b) {
%s
    while (cur != 0) {
        res = cur;
        if (*key < cur->key) {
            cur = cur->left;
            *a = 1;
        } else {
            *out = cur;
            cur = cur->right;
            *a = 0;
            *b = 0;
        }
    }
    return res;
}
'''
alts=['''    *out = 0;
    *a = 1;
    *b = 1;
    Node* res = (Node*)&t->root;
    Node* cur = t->root;''','''    Node* res = (Node*)&t->root;
    Node* cur = t->root;
    *out = 0;
    *a = 1;
    *b = 1;''','''    Node* res; Node* cur;
    res = (Node*)&t->root;
    *out = 0;
    cur = t->root;
    *a = 1;
    *b = 1;''','''    Node* res = (Node*)((char*)t + 4);
    *out = 0;
    Node* cur = t->root;
    *a = 1;
    *b = 1;''']
for i,a in enumerate(alts):
    open(p,'w').write(head+tmpl%a)
    o=subprocess.run(['python','tools/mp9/trytext.py','fae93e99'],capture_output=True,text=True).stdout
    print(i,o.splitlines()[0],o.count('\n*'))
