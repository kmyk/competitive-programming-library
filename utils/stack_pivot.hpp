#pragma once
#include <cstdlib>

/**
 * @note use as int main() { STACK_PIVOT main_(); exit(EXIT_SUCCESS); }
 */
#define STACK_PIVOT \
    size_t stack_size = 1 << 26; \
    char *malloced = (char *)malloc(stack_size); \
    char *addr = malloced + stack_size - sizeof(int); \
    __asm__("mov %0, %%rsp;" : "=g" (addr) );
