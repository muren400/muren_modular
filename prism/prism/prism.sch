EESchema Schematic File Version 4
LIBS:prism-cache
EELAYER 29 0
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
P 1600 5050
F 0 "SW1" H 1600 5417 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 1600 5326 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm_CircularMountingHoles" H 1450 5210 50  0001 C CNN
F 3 "~" H 1600 5310 50  0001 C CNN
	1    1600 5050
	0    -1   -1   0   
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J1
U 1 1 5CCC914F
P 4200 2650
F 0 "J1" H 4204 2992 50  0000 C CNN
F 1 "in1" H 4204 2901 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 4200 2650 50  0001 C CNN
F 3 "~" H 4200 2650 50  0001 C CNN
	1    4200 2650
	0    -1   1    0   
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J2
U 1 1 5CCC9219
P 4750 2650
F 0 "J2" H 4754 2992 50  0000 C CNN
F 1 "in2" H 4754 2901 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 4750 2650 50  0001 C CNN
F 3 "~" H 4750 2650 50  0001 C CNN
	1    4750 2650
	0    -1   1    0   
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J3
U 1 1 5CCC9241
P 5300 2650
F 0 "J3" H 5304 2992 50  0000 C CNN
F 1 "in3" H 5304 2901 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 5300 2650 50  0001 C CNN
F 3 "~" H 5300 2650 50  0001 C CNN
	1    5300 2650
	0    -1   1    0   
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J4
U 1 1 5CCC9281
P 5850 2650
F 0 "J4" H 5854 2992 50  0000 C CNN
F 1 "in4" H 5854 2901 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 5850 2650 50  0001 C CNN
F 3 "~" H 5850 2650 50  0001 C CNN
	1    5850 2650
	0    -1   1    0   
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J5
U 1 1 5CCC954A
P 9700 2600
F 0 "J5" H 9704 2942 50  0000 C CNN
F 1 "out1" H 9704 2851 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 9700 2600 50  0001 C CNN
F 3 "~" H 9700 2600 50  0001 C CNN
	1    9700 2600
	-1   0    0    -1  
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J6
U 1 1 5CCC95A7
P 9700 3150
F 0 "J6" H 9704 3492 50  0000 C CNN
F 1 "out2" H 9704 3401 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 9700 3150 50  0001 C CNN
F 3 "~" H 9700 3150 50  0001 C CNN
	1    9700 3150
	-1   0    0    -1  
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J7
U 1 1 5CCC960B
P 9700 3700
F 0 "J7" H 9704 4042 50  0000 C CNN
F 1 "out3" H 9704 3951 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 9700 3700 50  0001 C CNN
F 3 "~" H 9700 3700 50  0001 C CNN
	1    9700 3700
	-1   0    0    -1  
$EndComp
$Comp
L audiojack2_ground_switch_numeric:AudioJack2_Ground_Switch J8
U 1 1 5CCC9676
P 9700 4250
F 0 "J8" H 9704 4592 50  0000 C CNN
F 1 "out4" H 9704 4501 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 9700 4250 50  0001 C CNN
F 3 "~" H 9700 4250 50  0001 C CNN
	1    9700 4250
	-1   0    0    -1  
$EndComp
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5CCC997D
P 3400 4850
F 0 "A1" H 3400 3764 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 3400 3673 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 3550 3900 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 3400 3850 50  0001 C CNN
	1    3400 4850
	1    0    0    -1  
$EndComp
$Comp
L Analog_DAC:MCP4728 U1
U 1 1 5CCC9AB8
P 7300 3000
F 0 "U1" H 7300 3478 50  0000 C CNN
F 1 "MCP4728" H 7300 3387 50  0000 C CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 7300 2400 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/22187E.pdf" H 7300 3250 50  0001 C CNN
	1    7300 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5D1F2DF2
P 6300 2900
F 0 "R?" V 6093 2900 50  0000 C CNN
F 1 "100k" V 6184 2900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6230 2900 50  0001 C CNN
F 3 "~" H 6300 2900 50  0001 C CNN
	1    6300 2900
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5D1F3FC0
P 6300 3000
F 0 "R?" V 6093 3000 50  0000 C CNN
F 1 "100k" V 6184 3000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6230 3000 50  0001 C CNN
F 3 "~" H 6300 3000 50  0001 C CNN
	1    6300 3000
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5D1F421C
P 6300 3100
F 0 "R?" V 6093 3100 50  0000 C CNN
F 1 "100k" V 6184 3100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6230 3100 50  0001 C CNN
F 3 "~" H 6300 3100 50  0001 C CNN
	1    6300 3100
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5D1F44B3
P 6300 3200
F 0 "R?" V 6093 3200 50  0000 C CNN
F 1 "100k" V 6184 3200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6230 3200 50  0001 C CNN
F 3 "~" H 6300 3200 50  0001 C CNN
	1    6300 3200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D1F61C2
P 7300 3400
F 0 "#PWR?" H 7300 3150 50  0001 C CNN
F 1 "GND" H 7305 3227 50  0000 C CNN
F 2 "" H 7300 3400 50  0001 C CNN
F 3 "" H 7300 3400 50  0001 C CNN
	1    7300 3400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5D1F676A
P 6900 2500
F 0 "#PWR?" H 6900 2350 50  0001 C CNN
F 1 "+5V" H 6915 2673 50  0000 C CNN
F 2 "" H 6900 2500 50  0001 C CNN
F 3 "" H 6900 2500 50  0001 C CNN
	1    6900 2500
	-1   0    0    1   
$EndComp
Wire Wire Line
	6900 2400 7300 2400
Wire Wire Line
	7300 2400 7300 2700
Wire Wire Line
	6900 2400 6900 2500
Wire Wire Line
	6900 2400 6100 2400
Wire Wire Line
	6100 2400 6100 2900
Wire Wire Line
	6100 3200 6150 3200
Wire Wire Line
	6100 3100 6150 3100
Connection ~ 6100 3100
Wire Wire Line
	6100 3100 6100 3200
Wire Wire Line
	6100 3000 6150 3000
Connection ~ 6100 3000
Wire Wire Line
	6100 3000 6100 3100
Wire Wire Line
	6100 2900 6150 2900
Connection ~ 6100 2900
Wire Wire Line
	6100 2900 6100 3000
Connection ~ 6900 2400
Wire Wire Line
	6450 2900 6550 2900
Wire Wire Line
	6450 3000 6500 3000
Wire Wire Line
	6450 3100 6600 3100
Wire Wire Line
	6450 3200 6700 3200
Wire Wire Line
	3900 5250 6500 5250
Wire Wire Line
	6500 5250 6500 3000
Connection ~ 6500 3000
Wire Wire Line
	6500 3000 6700 3000
Wire Wire Line
	3900 5350 6550 5350
Wire Wire Line
	6550 5350 6550 2900
Connection ~ 6550 2900
Wire Wire Line
	6550 2900 6700 2900
Wire Wire Line
	3900 5450 6600 5450
Wire Wire Line
	6600 5450 6600 3100
Connection ~ 6600 3100
Wire Wire Line
	6600 3100 6700 3100
$Comp
L Device:R R?
U 1 1 5D242F8C
P 4050 3250
F 0 "R?" V 3843 3250 50  0000 C CNN
F 1 "100k" V 3934 3250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3980 3250 50  0001 C CNN
F 3 "~" H 4050 3250 50  0001 C CNN
	1    4050 3250
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5D241135
P 4600 3400
F 0 "R?" V 4393 3400 50  0000 C CNN
F 1 "100k" V 4484 3400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4530 3400 50  0001 C CNN
F 3 "~" H 4600 3400 50  0001 C CNN
	1    4600 3400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5D249509
P 5000 1600
F 0 "#PWR?" H 5000 1350 50  0001 C CNN
F 1 "GND" H 5005 1427 50  0000 C CNN
F 2 "" H 5000 1600 50  0001 C CNN
F 3 "" H 5000 1600 50  0001 C CNN
	1    5000 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 2850 4200 3250
Wire Wire Line
	4200 4850 3900 4850
Wire Wire Line
	4750 2850 4750 3400
Wire Wire Line
	4750 4950 3900 4950
Wire Wire Line
	5300 2850 5300 3550
Wire Wire Line
	5300 5050 3900 5050
Wire Wire Line
	5850 2850 5850 3650
Wire Wire Line
	5850 5150 3900 5150
Connection ~ 4200 3250
Wire Wire Line
	4200 3250 4200 4850
Connection ~ 4750 3400
Wire Wire Line
	4750 3400 4750 4950
$Comp
L Device:R R?
U 1 1 5D29E74E
P 5150 3550
F 0 "R?" V 4943 3550 50  0000 C CNN
F 1 "100k" V 5034 3550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5080 3550 50  0001 C CNN
F 3 "~" H 5150 3550 50  0001 C CNN
	1    5150 3550
	0    1    1    0   
$EndComp
Connection ~ 5300 3550
Wire Wire Line
	5300 3550 5300 5050
$Comp
L Device:R R?
U 1 1 5D29EC1B
P 5700 3650
F 0 "R?" V 5493 3650 50  0000 C CNN
F 1 "100k" V 5584 3650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5630 3650 50  0001 C CNN
F 3 "~" H 5700 3650 50  0001 C CNN
	1    5700 3650
	0    1    1    0   
$EndComp
Connection ~ 5850 3650
Wire Wire Line
	5850 3650 5850 5150
Wire Wire Line
	5550 3650 3800 3650
Wire Wire Line
	3800 3650 3800 3550
Wire Wire Line
	3800 1600 5000 1600
Wire Wire Line
	5000 3550 3800 3550
Connection ~ 3800 3550
Wire Wire Line
	3800 3550 3800 3400
Wire Wire Line
	4450 3400 3800 3400
Connection ~ 3800 3400
Wire Wire Line
	3800 3400 3800 3250
Wire Wire Line
	3900 3250 3800 3250
Connection ~ 3800 3250
Wire Wire Line
	3800 3250 3800 2950
Wire Wire Line
	5750 2850 5750 2950
Wire Wire Line
	5750 2950 5200 2950
Connection ~ 3800 2950
Wire Wire Line
	3800 2950 3800 1600
Wire Wire Line
	5200 2850 5200 2950
Connection ~ 5200 2950
Wire Wire Line
	5200 2950 4650 2950
Wire Wire Line
	4650 2850 4650 2950
Connection ~ 4650 2950
Wire Wire Line
	4650 2950 4100 2950
Wire Wire Line
	4100 2850 4100 2950
Connection ~ 4100 2950
Wire Wire Line
	4100 2950 3800 2950
NoConn ~ 4300 2850
NoConn ~ 4850 2850
NoConn ~ 5400 2850
NoConn ~ 5950 2850
$Comp
L power:GND #PWR?
U 1 1 5D2B4536
P 3450 6150
F 0 "#PWR?" H 3450 5900 50  0001 C CNN
F 1 "GND" H 3455 5977 50  0000 C CNN
F 2 "" H 3450 6150 50  0001 C CNN
F 3 "" H 3450 6150 50  0001 C CNN
	1    3450 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 5850 3450 5850
Connection ~ 3450 5850
Wire Wire Line
	3450 5850 3500 5850
$Comp
L power:+5V #PWR?
U 1 1 5D2BCED3
P 3600 3650
F 0 "#PWR?" H 3600 3500 50  0001 C CNN
F 1 "+5V" H 3615 3823 50  0000 C CNN
F 2 "" H 3600 3650 50  0001 C CNN
F 3 "" H 3600 3650 50  0001 C CNN
	1    3600 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 3650 3600 3850
NoConn ~ 3500 3850
NoConn ~ 3300 3850
$Comp
L Device:R_POT_TRIM R?
U 1 1 5D2DBE43
P 9200 2600
F 0 "R?" H 9130 2646 50  0000 R CNN
F 1 "50k" H 9130 2555 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical" V 9130 2600 50  0001 C CNN
F 3 "~" H 9200 2600 50  0001 C CNN
	1    9200 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_TRIM R?
U 1 1 5D2E06DF
P 9200 3150
F 0 "R?" H 9130 3196 50  0000 R CNN
F 1 "50k" H 9130 3105 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical" V 9130 3150 50  0001 C CNN
F 3 "~" H 9200 3150 50  0001 C CNN
	1    9200 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_TRIM R?
U 1 1 5D2E0DEA
P 9200 3700
F 0 "R?" H 9130 3746 50  0000 R CNN
F 1 "50k" H 9130 3655 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical" V 9130 3700 50  0001 C CNN
F 3 "~" H 9200 3700 50  0001 C CNN
	1    9200 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_TRIM R?
U 1 1 5D2E1462
P 9200 4250
F 0 "R?" H 9130 4296 50  0000 R CNN
F 1 "50k" H 9130 4205 50  0000 R CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical" V 9130 4250 50  0001 C CNN
F 3 "~" H 9200 4250 50  0001 C CNN
	1    9200 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 2600 9350 2600
Wire Wire Line
	9500 3150 9350 3150
Wire Wire Line
	9500 3700 9350 3700
Wire Wire Line
	9500 4250 9350 4250
Wire Wire Line
	7900 2900 9200 2900
Wire Wire Line
	9200 2900 9200 2750
Wire Wire Line
	7900 3000 8750 3000
Wire Wire Line
	8750 3000 8750 3350
Wire Wire Line
	8750 3350 9200 3350
Wire Wire Line
	9200 3350 9200 3300
Wire Wire Line
	7900 3100 8700 3100
Wire Wire Line
	8700 3100 8700 3900
Wire Wire Line
	8700 3900 9200 3900
Wire Wire Line
	9200 3900 9200 3850
Wire Wire Line
	7900 3200 8650 3200
Wire Wire Line
	8650 3200 8650 4450
Wire Wire Line
	8650 4450 9200 4450
Wire Wire Line
	9200 4450 9200 4400
$Comp
L power:GND #PWR?
U 1 1 5D2F00A6
P 8600 2400
F 0 "#PWR?" H 8600 2150 50  0001 C CNN
F 1 "GND" V 8605 2272 50  0000 R CNN
F 2 "" H 8600 2400 50  0001 C CNN
F 3 "" H 8600 2400 50  0001 C CNN
	1    8600 2400
	0    1    1    0   
$EndComp
Wire Wire Line
	9200 2450 9200 2400
Wire Wire Line
	9200 3000 9000 3000
Wire Wire Line
	9000 3000 9000 2400
Connection ~ 9000 2400
Wire Wire Line
	9000 2400 9200 2400
Wire Wire Line
	9200 3550 8950 3550
Wire Wire Line
	8950 3550 8950 2400
Wire Wire Line
	8600 2400 8900 2400
Connection ~ 8950 2400
Wire Wire Line
	8950 2400 9000 2400
Wire Wire Line
	9200 4100 8900 4100
Wire Wire Line
	8900 4100 8900 2400
Connection ~ 8900 2400
Wire Wire Line
	8900 2400 8950 2400
Wire Wire Line
	1700 5350 2100 5350
Wire Wire Line
	1500 5350 1500 5450
Wire Wire Line
	1500 5450 2250 5450
Wire Wire Line
	1600 5350 1600 6000
Wire Wire Line
	1600 6000 3450 6000
$Comp
L power:+5V #PWR?
U 1 1 5D317EA1
P 2250 5750
F 0 "#PWR?" H 2250 5600 50  0001 C CNN
F 1 "+5V" H 2265 5923 50  0000 C CNN
F 2 "" H 2250 5750 50  0001 C CNN
F 3 "" H 2250 5750 50  0001 C CNN
	1    2250 5750
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5D3184F2
P 2250 5600
F 0 "R?" H 2180 5554 50  0000 R CNN
F 1 "100k" H 2180 5645 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2180 5600 50  0001 C CNN
F 3 "~" H 2250 5600 50  0001 C CNN
	1    2250 5600
	-1   0    0    1   
$EndComp
Connection ~ 2250 5450
Wire Wire Line
	2250 5450 2900 5450
$Comp
L Device:R R?
U 1 1 5D318BC2
P 2100 5500
F 0 "R?" H 2030 5454 50  0000 R CNN
F 1 "100k" H 2030 5545 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2030 5500 50  0001 C CNN
F 3 "~" H 2100 5500 50  0001 C CNN
	1    2100 5500
	-1   0    0    1   
$EndComp
Connection ~ 2100 5350
Wire Wire Line
	2100 5350 2900 5350
Wire Wire Line
	2100 5650 2100 5750
Wire Wire Line
	2100 5750 2250 5750
Connection ~ 2250 5750
Wire Wire Line
	1500 4750 1500 4550
Wire Wire Line
	1500 4550 1150 4550
Wire Wire Line
	1150 4550 1150 6000
Wire Wire Line
	1150 6000 1600 6000
Connection ~ 1600 6000
Wire Wire Line
	1700 4750 1700 4550
Wire Wire Line
	1700 4550 1950 4550
Wire Wire Line
	1950 4550 1950 5250
$Comp
L Device:R R?
U 1 1 5D324268
P 1950 5400
F 0 "R?" H 1880 5354 50  0000 R CNN
F 1 "100k" H 1880 5445 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1880 5400 50  0001 C CNN
F 3 "~" H 1950 5400 50  0001 C CNN
	1    1950 5400
	-1   0    0    1   
$EndComp
Wire Wire Line
	1950 5550 1950 5750
Wire Wire Line
	3450 5850 3450 6000
Connection ~ 1950 5250
Wire Wire Line
	1950 5250 2900 5250
Wire Wire Line
	1950 5750 2100 5750
Connection ~ 2100 5750
Connection ~ 3450 6000
Wire Wire Line
	3450 6000 3450 6150
$EndSCHEMATC
