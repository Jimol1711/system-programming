#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

#define _POSIX_C_SOURCE 1

typedef int jmp_buf;

char *global_ptr;
jmp_buf excp;

void sigsegv_handler() {
    siglongjmp(excp, 1);
}

char *ultimaDireccionValida(char *ptr) {

    global_ptr = ptr;

    void (*hdlr)() = signal(SIGSEGV, sigsegv_handler);
    
    if(sigsetjmp(excp, 1)==0) { // try
        while(1) {
            char c = *global_ptr;
            global_ptr++;
        }
    }
    else { // catch
        global_ptr--;
    }
    signal(SIGSEGV,hdlr);
    return global_ptr;

}