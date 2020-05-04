#include <stdint.h>
#include <stddef.h>
#include <lib/string.h>

/* copy from one buffer to another in memory */
void *memcpy(void *dest, const void *src, size_t cnt) {
    uint8_t *p = dest;
    const uint8_t *s = src;

    for (size_t i = 0; i < cnt; i++) {
        p[i] = s[i];
    }

    return dest;
}

void *memset(void *s, int c, size_t cnt) {
    uint8_t *p = s;

    for (size_t i = 0; i < cnt; i++) {
        p[i] = (uint8_t)c;
    }

    return s;
}

void *memmove(void *dest, const void *src, size_t cnt) {
    uint8_t *p = dest;
    const uint8_t *s = src;

    if (src > dest) {
        for (size_t i = 0; i < cnt; i++) {
            p[i] = s[i];
        }
    } else if (src < dest) {
        for (size_t i = cnt; i > 0; i--) {
            /* shift index to catch zero index */
            p[i - 1] = s[i - 1];
        }
    }

    return dest;
}

int memcmp(const void *s1, const void *s2, size_t cnt) {
    const uint8_t *p1 = s1;
    const uint8_t *p2 = s2;

    for (size_t i = 0; i < cnt; i++) {
        /* compare element-by-element */
        if (p1[i] != p2[i]) {
            return p1[i] < p2[i] ? -1 : 1;
        }
    }
}
