#ifndef __STRING_H__
#define __STRING_H__

void *memcpy(void *dest, const void *src, size_t cnt);
void *memset(void *s, int c, size_t cnt);
void *memmove(void *dest, const void *src, size_t cnt);
int memcmp(const void *s1, const void *s2, size_t cnt);

#endif
