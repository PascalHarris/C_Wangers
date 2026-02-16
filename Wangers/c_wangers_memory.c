#include "c_wangers_memory.h"

void* s_memcpy(void* dest, const void* src, size_t n) {
    assert(dest != NULL);
    assert(src != NULL);
    assert(n > 0);

    if (dest == src) {
        return dest; // no need to copy
    }

    if ((uintptr_t)dest < (uintptr_t)src + n && (uintptr_t)dest + n > (uintptr_t)src) {
        // Memory regions overlap, use memmove
        return memmove(dest, src, n);
    }

    // Memory regions do not overlap, use memcpy
    return memcpy(dest, src, n);
}
