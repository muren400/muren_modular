#ifndef PLASTIK_H
#define PLASTIK_H

#define CLOCK  19
#define RESET  18

#define GATE_1 16
#define GATE_2 14
#define GATE_3 12
#define GATE_4 10

#define BUTTON_1 24
#define BUTTON_2 26
#define BUTTON_3 28
#define BUTTON_4 30

#define ENC_1_A 32
#define ENC_1_B 34
#define ENC_2_A 36
#define ENC_2_B 38
#define ENC_3_A 40
#define ENC_3_B 42
#define ENC_4_A 44
#define ENC_4_B 46

// Assign human-readable names to some common 16-bit color values:
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF
#define GREY 0xA4F3
#define DARKGREY 0x738E

#define MINPRESSURE 50
#define MAXPRESSURE 1000

#define MAXOUTPUTS 4
#define MAXPATTERNS 16
#define MAXSTEPS 16
#define MAXNOTES 12
#define MAXDIVIDER 16

#endif