#include <sys/idt.h>

struct idt_entry_t {
    uint16_t offset_lo;
    uint16_t selector;
    uint8_t ist;
    uint8_t type_attr;
    uint16_t offset_mid;
    uint32_t offset_hi;
    uint32_t zero;
};

struct idt_ptr_t {
    uint16_t size;
    /* start address */
    uint64_t address;
}__attribute__((packed));

static idt_entry_t idt[256];

static int register_interrupt_handler(size_t vec, void *handler, uint8_t ist, uint8_t type) {
    uint64_t p = (uint64_t)handler;

    idt[vec].offset_lo = (uint16_t)offset_lo;
    idt[vec].selector = 0x08;
    idt[vec].ist = ist;
    idt[vec].type_attr = type;
    idt[vec].offset_mid = (uint16_t)(p >> 16);
    idt[vec].offset_hi = (uint16_t)(p >> 32);
    idt[vec].zero = 0;
}

void init_idt(void) {
    /* do nothing for now */
}
