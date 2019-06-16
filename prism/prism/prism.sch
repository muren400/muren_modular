EESchema Schematic File Version 4
LIBS:prism-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Rotary_Encoder_Switch SW1
U 1 1 5CCB6A55
P 6150 3100
F 0 "SW1" H 6150 3467 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 6150 3376 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm_CircularMountingHoles" H 6000 3260 50  0001 C CNN
F 3 "~" H 6150 3360 50  0001 C CNN
	1    6150 3100
	1    0    0    -1  
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J1
U 1 1 5CCC914F
P 3650 3000
F 0 "J1" H 3654 3342 50  0000 C CNN
F 1 "in1" H 3654 3251 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3650 3000 50  0001 C CNN
F 3 "~" H 3650 3000 50  0001 C CNN
	1    3650 3000
	1    0    0    -1  
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J2
U 1 1 5CCC9219
P 3650 3550
F 0 "J2" H 3654 3892 50  0000 C CNN
F 1 "in2" H 3654 3801 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3650 3550 50  0001 C CNN
F 3 "~" H 3650 3550 50  0001 C CNN
	1    3650 3550
	1    0    0    -1  
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J3
U 1 1 5CCC9241
P 3650 4100
F 0 "J3" H 3654 4442 50  0000 C CNN
F 1 "in3" H 3654 4351 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3650 4100 50  0001 C CNN
F 3 "~" H 3650 4100 50  0001 C CNN
	1    3650 4100
	1    0    0    -1  
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J4
U 1 1 5CCC9281
P 3650 4650
F 0 "J4" H 3654 4992 50  0000 C CNN
F 1 "in4" H 3654 4901 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 3650 4650 50  0001 C CNN
F 3 "~" H 3650 4650 50  0001 C CNN
	1    3650 4650
	1    0    0    -1  
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J5
U 1 1 5CCC954A
P 4350 3000
F 0 "J5" H 4354 3342 50  0000 C CNN
F 1 "out1" H 4354 3251 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 4350 3000 50  0001 C CNN
F 3 "~" H 4350 3000 50  0001 C CNN
	1    4350 3000
	1    0    0    -1  
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J6
U 1 1 5CCC95A7
P 4350 3550
F 0 "J6" H 4354 3892 50  0000 C CNN
F 1 "out2" H 4354 3801 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 4350 3550 50  0001 C CNN
F 3 "~" H 4350 3550 50  0001 C CNN
	1    4350 3550
	1    0    0    -1  
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J7
U 1 1 5CCC960B
P 4350 4100
F 0 "J7" H 4354 4442 50  0000 C CNN
F 1 "out3" H 4354 4351 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 4350 4100 50  0001 C CNN
F 3 "~" H 4350 4100 50  0001 C CNN
	1    4350 4100
	1    0    0    -1  
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J8
U 1 1 5CCC9676
P 4350 4650
F 0 "J8" H 4354 4992 50  0000 C CNN
F 1 "out4" H 4354 4901 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 4350 4650 50  0001 C CNN
F 3 "~" H 4350 4650 50  0001 C CNN
	1    4350 4650
	1    0    0    -1  
$EndComp
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5CCC997D
P 1900 2100
F 0 "A1" H 1900 1014 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 1900 923 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 2050 1150 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 1900 1100 50  0001 C CNN
	1    1900 2100
	1    0    0    -1  
$EndComp
$Comp
L Analog_DAC:MCP4728 U1
U 1 1 5CCC9AB8
P 4250 1450
F 0 "U1" H 4250 1928 50  0000 C CNN
F 1 "MCP4728" H 4250 1837 50  0000 C CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 4250 850 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22187E.pdf" H 4250 1700 50  0001 C CNN
	1    4250 1450
	1    0    0    -1  
$EndComp
$EndSCHEMATC
