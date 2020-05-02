; this file specifies the stivale header as detailed by https://github.com/qloader2/qloader2/blob/master/STIVALE.md
section .stivaleheader

align 4

stivale_header:
    .stack: dq 0xeffff0
    .videomode: dw 0 ; using vga text mode for now
    .fbwidth: dw 0 ; ignore framebuffer info
    .fbheight: dw 0
    .fbbpp: dw 0
