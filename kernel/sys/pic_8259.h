#ifndef __PIC_8259_H__
#define __PIC_8259_H__

#include <stdint.h>

void pic8259_eoi(uint8_t);
void pic8259_remap(uint8_t, uint8_t);
void pic8259_mask(uint8_t, int);
void pic8259_mask_all(void);

#endif
