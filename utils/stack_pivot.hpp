#pragma once
#include <cstdlib>

#define BEGIN_STACK_PIVOT(STACK_SIZE) \
    static volatile char *old_stack; \
    asm volatile("mov %%rsp, %0" : "=r" (old_stack) ); \
    char *new_stack = (char *)malloc(STACK_SIZE) + (STACK_SIZE) - sizeof(void *); \
    asm volatile("mov %0, %%rsp" : : "r" (new_stack) );

#define END_STACK_PIVOT() \
    asm volatile("mov %0, %%rsp" : : "r" (old_stack) );
