#include "Runtime.PPCEABI.H/NMWException.h"

DestructorChain* __global_destructor_chain;

void* __register_global_object(void* object, void* destructor, void* regmem) {
    ((DestructorChain*)regmem)->next = __global_destructor_chain;
    ((DestructorChain*)regmem)->destructor = destructor;
    ((DestructorChain*)regmem)->object = object;
    __global_destructor_chain = (DestructorChain*)regmem;
    return object;
}

void __destroy_global_chain(void) {
    DestructorChain* gdc;
    while ((gdc = __global_destructor_chain) != 0) {
        __global_destructor_chain = gdc->next;
        DTORCALL(gdc->destructor, gdc->object);
    }
}
