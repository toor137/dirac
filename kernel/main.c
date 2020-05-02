#include <stdint.h>
#include <stddef.h>
#include <startup/stivale.h>

void kmain(struct stivale_struct_t *stivale) {
    for (;;) asm volatile ("hlt");
}
