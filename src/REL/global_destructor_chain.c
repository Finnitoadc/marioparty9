// Same functions as the DOL copy, compiled with REL flags (variable lands in .bss).
#include "../src/Runtime.PPCEABI.H/global_destructor_chain.c"

// In modules the destructor chain reference lives in this file.
#pragma force_active on
#pragma section ".dtors$10"
__declspec(section ".dtors$10")
    extern void* const __destroy_global_chain_reference = __destroy_global_chain;
#pragma force_active reset
