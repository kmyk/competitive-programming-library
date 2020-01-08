#pragma once
#include <cstdlib>

/**
 * @note This is a workaround for WSL. We cannot use ulimit -s unlimited on the environment.
 * @note To use such techniques, you should take care of the alignment of rsp. If not, you'll get SIGSEGV around XMM registers.
 */

#define BEGIN_STACK_PIVOT(STACK_SIZE) \
    static volatile char *old_stack; \
    asm volatile("mov %%rsp, %0" : "=r" (old_stack) ); \
    char *new_stack = ((char *)malloc(STACK_SIZE) + (STACK_SIZE) - 0x10); \
    asm volatile("mov %0, %%rsp" : : "r" (new_stack) );

#define END_STACK_PIVOT() \
    asm volatile("mov %0, %%rsp" : : "r" (old_stack) );

#define STACK_PIVOT_MAIN(moin) \
    int main() { \
        BEGIN_STACK_PIVOT(1 << 28) \
        static int returncode = moin(); \
        END_STACK_PIVOT() \
        return returncode; \
    }
