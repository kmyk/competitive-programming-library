#pragma once
#include <cstdlib>

/**
 * @note use as int main() { STACK_PIVOT(1 << 30) main_(); exit(EXIT_SUCCESS); }
 */
#define STACK_PIVOT(STACK_SIZE) \
    char *malloced = (char *)malloc(STACK_SIZE); \
    char *addr = malloced + (STACK_SIZE) - sizeof(int); \
    __asm__("mov %0, %%rsp; call" : "=g" (addr) );
