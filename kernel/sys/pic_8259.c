#include <stdint.h>
#include <sys/pic_8259.h>
#include <lib/pio.h>

void pic8259_eoi(uint8_t cur_vec) {
    /* we must signal EOI to both PICS */
    if (cur_vec >= 8) {
        port_out_b(0xa0, 0x20);
    }

    port_out_b(0x20, 0x20);
}

void pic8259_remap(uint8_t master_offset, uint8_t slave_offset) {
    /* save original masks */
    uint8_t pic0_mask = port_in_b(0x21);
    uint8_t pic1_mask = port_in_b(0xa1);

    /* begin init sequence */
    port_out_b(0x20, 0x11);
    io_wait();
    port_out_b(0x20, 0x11);
    io_wait();
    /* set offsets */
    port_out_b(0x21, master_offset);
    io_wait();
    port_out_b(0xa1, slave_offset);
    io_wait();
    /* locate slave PIC */
    port_out_b(0x21, 4);
    io_wait();
    /* cascade identity */
    port_out_b(0xa1, 2);
    io_wait();

    /* 8086 mode */
    port_out_b(0x21, 0x01);
    io_wait();
    port_out_b(0xa1, 0x01);
    io_wait();

    /* restore masks */
    port_out_b(0x21, pic0_mask);
    port_out_b(0xa1, pic1_mask);
}

void pic8259_mask(uint8_t vec, int s) {
    uint16_t port;
    uint8_t value;

    if (vec < 8) {
        port = 0x21;
    } else {
        port = 0xa1;
        vec -= 8;
    }

    if (!s)
        value = port_in_b(port) & ~((uint8_t)1 << vec);
    else
        value = port_in_b(port) | ((uint8_t)1 << vec);
    port_out_b(port, value);
    io_wait();
}

/* mask all interrupts */
void pic8259_maskall(void) {
    port_out_b(0x21, 0xff);
    port_out_b(0xa1, 0xff);
}
