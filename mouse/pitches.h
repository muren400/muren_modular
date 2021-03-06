/*************************************************
 * Public Constants
 *************************************************/
#include <inttypes.h>

#define NOTE_B0  31
#define NOTE_C1  31
#define NOTE_CS1 31
#define NOTE_D1  31
#define NOTE_DS1 31
#define NOTE_E1  31
#define NOTE_F1  31
#define NOTE_FS1 31
#define NOTE_G1  31
#define NOTE_GS1 31
#define NOTE_A1  31
#define NOTE_AS1 31
#define NOTE_B1  31
#define NOTE_C2  31
#define NOTE_CS2 31
#define NOTE_D2  31
#define NOTE_DS2 31
#define NOTE_E2  31
#define NOTE_F2  31
#define NOTE_FS2 31
#define NOTE_G2  31
#define NOTE_GS2 31
#define NOTE_A2  31
#define NOTE_AS2 31
#define NOTE_B2  31
#define NOTE_C3  31
#define NOTE_CS3 31
#define NOTE_D3  31
#define NOTE_DS3 31
#define NOTE_E3  31
#define NOTE_F3  31
#define NOTE_FS3 31
#define NOTE_G3  31
#define NOTE_GS3 31
#define NOTE_A3  31
#define NOTE_AS3 31 //start again

#define NOTE_B3  31
#define NOTE_C4  33
#define NOTE_CS4 35
#define NOTE_D4  37
#define NOTE_DS4 39
#define NOTE_E4  41
#define NOTE_F4  44
#define NOTE_FS4 46
#define NOTE_G4  49
#define NOTE_GS4 52
#define NOTE_A4  55
#define NOTE_AS4 58
#define NOTE_B4  62
#define NOTE_C5  65
#define NOTE_CS5 69
#define NOTE_D5  73
#define NOTE_DS5 78
#define NOTE_E5  82
#define NOTE_F5  87
#define NOTE_FS5 93
#define NOTE_G5  98
#define NOTE_GS5 104
#define NOTE_A5  110
#define NOTE_AS5 117
#define NOTE_B5  123
#define NOTE_C6  131
#define NOTE_CS6 139
#define NOTE_D6  147
#define NOTE_DS6 156
#define NOTE_E6  165
#define NOTE_F6  175
#define NOTE_FS6 185
#define NOTE_G6  196
#define NOTE_GS6 208
#define NOTE_A6  220
#define NOTE_AS6 233
#define NOTE_B6  247
#define NOTE_C7  262
#define NOTE_CS7 277
#define NOTE_D7  294
#define NOTE_DS7 311
#define NOTE_E7  330
#define NOTE_F7  349
#define NOTE_FS7 370
#define NOTE_G7  392
#define NOTE_GS7 415
#define NOTE_A7  440
#define NOTE_AS7 466
#define NOTE_B7  494
#define NOTE_C8  523
#define NOTE_CS8 554
#define NOTE_D8  587
#define NOTE_DS8 622
#define NOTE_E8  659
#define NOTE_F8  698
#define NOTE_FS8 740
#define NOTE_G8  784
#define NOTE_GS8 831
#define NOTE_A8  880
#define NOTE_AS8 932
#define NOTE_B8  988
#define NOTE_C9  1047
#define NOTE_CS9 1109
#define NOTE_D9  1175
#define NOTE_DS9 1245

#define NUMBER_B0  0
#define NUMBER_C1  1
#define NUMBER_CS1 2
#define NUMBER_D1  3
#define NUMBER_DS1 4
#define NUMBER_E1  5
#define NUMBER_F1  6
#define NUMBER_FS1 7
#define NUMBER_G1  8
#define NUMBER_GS1 9
#define NUMBER_A1  10
#define NUMBER_AS1 11
#define NUMBER_B1  12
#define NUMBER_C2  13
#define NUMBER_CS2 14
#define NUMBER_D2  15
#define NUMBER_DS2 16
#define NUMBER_E2  17
#define NUMBER_F2  18
#define NUMBER_FS2 19
#define NUMBER_G2  20
#define NUMBER_GS2 21
#define NUMBER_A2  22
#define NUMBER_AS2 23
#define NUMBER_B2  24
#define NUMBER_C3  25
#define NUMBER_CS3 26
#define NUMBER_D3  27
#define NUMBER_DS3 28
#define NUMBER_E3  29
#define NUMBER_F3  30
#define NUMBER_FS3 31
#define NUMBER_G3  32
#define NUMBER_GS3 33
#define NUMBER_A3  34
#define NUMBER_AS3 35 //start again
#define NUMBER_B3  36
#define NUMBER_C4  37
#define NUMBER_CS4 38
#define NUMBER_D4  39
#define NUMBER_DS4 39
#define NUMBER_E4  40
#define NUMBER_F4  41
#define NUMBER_FS4 42
#define NUMBER_G4  43
#define NUMBER_GS4 44
#define NUMBER_A4  45
#define NUMBER_AS4 46
#define NUMBER_B4  47
#define NUMBER_C5  48
#define NUMBER_CS5 49
#define NUMBER_D5  50
#define NUMBER_DS5 51
#define NUMBER_E5  52
#define NUMBER_F5  53
#define NUMBER_FS5 54
#define NUMBER_G5  55
#define NUMBER_GS5 56
#define NUMBER_A5  57
#define NUMBER_AS5 58
#define NUMBER_B5  59
#define NUMBER_C6  60
#define NUMBER_CS6 61
#define NUMBER_D6  62
#define NUMBER_DS6 63
#define NUMBER_E6  64
#define NUMBER_F6  65
#define NUMBER_FS6 66
#define NUMBER_G6  67
#define NUMBER_GS6 68
#define NUMBER_A6  69
#define NUMBER_AS6 70
#define NUMBER_B6  71
#define NUMBER_C7  72
#define NUMBER_CS7 73
#define NUMBER_D7  74
#define NUMBER_DS7 75
#define NUMBER_E7  76
#define NUMBER_F7  77
#define NUMBER_FS7 78
#define NUMBER_G7  79
#define NUMBER_GS7 80
#define NUMBER_A7  81
#define NUMBER_AS7 82
#define NUMBER_B7  83
#define NUMBER_C8  84
#define NUMBER_CS8 85
#define NUMBER_D8  86
#define NUMBER_DS8 87
#define NUMBER_E8  88
#define NUMBER_F8  89
#define NUMBER_FS8 90
#define NUMBER_G8  91
#define NUMBER_GS8 92
#define NUMBER_A8  93
#define NUMBER_AS8 94
#define NUMBER_B8  95
#define NUMBER_C9  96
#define NUMBER_CS9 97
#define NUMBER_D9  98
#define NUMBER_DS9 99 

#define MIDINOTE_B0  23
#define MIDINOTE_C1  24
#define MIDINOTE_CS1 25
#define MIDINOTE_D1  26
#define MIDINOTE_DS1 27
#define MIDINOTE_E1  28
#define MIDINOTE_F1  29
#define MIDINOTE_FS1 30
#define MIDINOTE_G1  31
#define MIDINOTE_GS1 32
#define MIDINOTE_A1  33
#define MIDINOTE_AS1 34
#define MIDINOTE_B1  35
#define MIDINOTE_C2  36
#define MIDINOTE_CS2 37
#define MIDINOTE_D2  38
#define MIDINOTE_DS2 39
#define MIDINOTE_E2  40
#define MIDINOTE_F2  41
#define MIDINOTE_FS2 42
#define MIDINOTE_G2  43
#define MIDINOTE_GS2 44
#define MIDINOTE_A2  45
#define MIDINOTE_AS2 46
#define MIDINOTE_B2  47
#define MIDINOTE_C3  48
#define MIDINOTE_CS3 49
#define MIDINOTE_D3  50
#define MIDINOTE_DS3 51
#define MIDINOTE_E3  52
#define MIDINOTE_F3  53
#define MIDINOTE_FS3 54
#define MIDINOTE_G3  55
#define MIDINOTE_GS3 56
#define MIDINOTE_A3  57
#define MIDINOTE_AS3 58 //start again
#define MIDINOTE_B3  59
#define MIDINOTE_C4  60
#define MIDINOTE_CS4 61
#define MIDINOTE_D4  62
#define MIDINOTE_DS4 63
#define MIDINOTE_E4  64
#define MIDINOTE_F4  65
#define MIDINOTE_FS4 66
#define MIDINOTE_G4  67
#define MIDINOTE_GS4 68
#define MIDINOTE_A4  69
#define MIDINOTE_AS4 70
#define MIDINOTE_B4  71
#define MIDINOTE_C5  72
#define MIDINOTE_CS5 73
#define MIDINOTE_D5  74
#define MIDINOTE_DS5 75
#define MIDINOTE_E5  76
#define MIDINOTE_F5  77
#define MIDINOTE_FS5 78
#define MIDINOTE_G5  79
#define MIDINOTE_GS5 80
#define MIDINOTE_A5  81
#define MIDINOTE_AS5 82
#define MIDINOTE_B5  83
#define MIDINOTE_C6  84
#define MIDINOTE_CS6 85
#define MIDINOTE_D6  86
#define MIDINOTE_DS6 87
#define MIDINOTE_E6  88
#define MIDINOTE_F6  89
#define MIDINOTE_FS6 90
#define MIDINOTE_G6  91
#define MIDINOTE_GS6 92
#define MIDINOTE_A6  93
#define MIDINOTE_AS6 94
#define MIDINOTE_B6  95
#define MIDINOTE_C7  96
#define MIDINOTE_CS7 97
#define MIDINOTE_D7  98
#define MIDINOTE_DS7 99
#define MIDINOTE_E7  100
#define MIDINOTE_F7  101
#define MIDINOTE_FS7 102
#define MIDINOTE_G7  103
#define MIDINOTE_GS7 104
#define MIDINOTE_A7  105
#define MIDINOTE_AS7 106
#define MIDINOTE_B7  107
#define MIDINOTE_C8  108
#define MIDINOTE_CS8 109
#define MIDINOTE_D8  110
#define MIDINOTE_DS8 111
#define MIDINOTE_E8  112
#define MIDINOTE_F8  113
#define MIDINOTE_FS8 114
#define MIDINOTE_G8  115
#define MIDINOTE_GS8 116
#define MIDINOTE_A8  117
#define MIDINOTE_AS8 118
#define MIDINOTE_B8  119
#define MIDINOTE_C9  120
#define MIDINOTE_CS9 121
#define MIDINOTE_D9  122
#define MIDINOTE_DS9 123

static const uint16_t sNotePitches[] = {
    NOTE_B0, NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1,
    NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1, NOTE_C2, NOTE_CS2, NOTE_D2,
    NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2,
    NOTE_B2, NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3,
    NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3, NOTE_C4, NOTE_CS4, NOTE_D4,
    NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4,
    NOTE_B4, NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5,
    NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5, NOTE_C6, NOTE_CS6, NOTE_D6,
    NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6,
    NOTE_B6, NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7,
    NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7, NOTE_C8, NOTE_CS8, NOTE_D8, NOTE_DS8,
    NOTE_E8, NOTE_F8, NOTE_FS8,
    NOTE_G8, NOTE_GS8, NOTE_A8, NOTE_AS8, NOTE_B8, NOTE_C9, NOTE_CS9, NOTE_D9, NOTE_DS9,
};
