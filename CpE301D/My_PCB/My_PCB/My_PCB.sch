EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "lun. 30 mars 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 8950 1450 1    60   ~ 0
Vin
Text Label 9350 1450 1    60   ~ 0
IOREF
Text Label 8900 2500 0    60   ~ 0
A0
Text Label 8900 2600 0    60   ~ 0
A1
Text Label 8900 2700 0    60   ~ 0
A2
Text Label 8900 2800 0    60   ~ 0
A3
Text Label 8900 2900 0    60   ~ 0
A4(SDA)
Text Label 8900 3000 0    60   ~ 0
A5(SCL)
Text Label 10550 3000 0    60   ~ 0
0(Rx)
Text Label 10550 2800 0    60   ~ 0
2
Text Label 10550 2900 0    60   ~ 0
1(Tx)
Text Label 10550 2700 0    60   ~ 0
3(**)
Text Label 10550 2600 0    60   ~ 0
4
Text Label 10550 2500 0    60   ~ 0
5(**)
Text Label 10550 2400 0    60   ~ 0
6(**)
Text Label 10550 2300 0    60   ~ 0
7
Text Label 10550 2100 0    60   ~ 0
8
Text Label 10550 2000 0    60   ~ 0
9(**)
Text Label 10550 1900 0    60   ~ 0
10(**/SS)
Text Label 10550 1800 0    60   ~ 0
11(**/MOSI)
Text Label 10550 1700 0    60   ~ 0
12(MISO)
Text Label 10550 1600 0    60   ~ 0
13(SCK)
Text Label 10550 1400 0    60   ~ 0
AREF
NoConn ~ 9400 1600
Text Label 10550 1300 0    60   ~ 0
A4(SDA)
Text Label 10550 1200 0    60   ~ 0
A5(SCL)
Text Notes 10850 1000 0    60   ~ 0
Holes
Text Notes 8550 750  0    60   ~ 0
Shield for Arduino that uses\nthe same pin disposition\nlike "Uno" board Rev 3.
$Comp
L Connector_Generic:Conn_01x08 P1
U 1 1 56D70129
P 9600 1900
F 0 "P1" H 9600 2350 50  0000 C CNN
F 1 "Power" V 9700 1900 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" V 9750 1900 20  0000 C CNN
F 3 "" H 9600 1900 50  0000 C CNN
	1    9600 1900
	1    0    0    -1  
$EndComp
Text Label 8650 1800 0    60   ~ 0
Reset
$Comp
L power:+3.3V #PWR01
U 1 1 56D70538
P 9150 1450
F 0 "#PWR01" H 9150 1300 50  0001 C CNN
F 1 "+3.3V" V 9150 1700 50  0000 C CNN
F 2 "" H 9150 1450 50  0000 C CNN
F 3 "" H 9150 1450 50  0000 C CNN
	1    9150 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR02
U 1 1 56D707BB
P 9050 1350
F 0 "#PWR02" H 9050 1200 50  0001 C CNN
F 1 "+5V" V 9050 1550 50  0000 C CNN
F 2 "" H 9050 1350 50  0000 C CNN
F 3 "" H 9050 1350 50  0000 C CNN
	1    9050 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 56D70CC2
P 9300 3150
F 0 "#PWR03" H 9300 2900 50  0001 C CNN
F 1 "GND" H 9300 3000 50  0000 C CNN
F 2 "" H 9300 3150 50  0000 C CNN
F 3 "" H 9300 3150 50  0000 C CNN
	1    9300 3150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 56D70CFF
P 10300 3150
F 0 "#PWR04" H 10300 2900 50  0001 C CNN
F 1 "GND" H 10300 3000 50  0000 C CNN
F 2 "" H 10300 3150 50  0000 C CNN
F 3 "" H 10300 3150 50  0000 C CNN
	1    10300 3150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x06 P2
U 1 1 56D70DD8
P 9600 2700
F 0 "P2" H 9600 2300 50  0000 C CNN
F 1 "Analog" V 9700 2700 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x06" V 9750 2750 20  0000 C CNN
F 3 "" H 9600 2700 50  0000 C CNN
	1    9600 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P5
U 1 1 56D71177
P 10800 650
F 0 "P5" V 10900 650 50  0000 C CNN
F 1 "CONN_01X01" V 10900 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 10721 724 20  0000 C CNN
F 3 "" H 10800 650 50  0000 C CNN
	1    10800 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P6
U 1 1 56D71274
P 10900 650
F 0 "P6" V 11000 650 50  0000 C CNN
F 1 "CONN_01X01" V 11000 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 10900 650 20  0001 C CNN
F 3 "" H 10900 650 50  0000 C CNN
	1    10900 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P7
U 1 1 56D712A8
P 11000 650
F 0 "P7" V 11100 650 50  0000 C CNN
F 1 "CONN_01X01" V 11100 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" V 11000 650 20  0001 C CNN
F 3 "" H 11000 650 50  0000 C CNN
	1    11000 650 
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x01 P8
U 1 1 56D712DB
P 11100 650
F 0 "P8" V 11200 650 50  0000 C CNN
F 1 "CONN_01X01" V 11200 650 50  0001 C CNN
F 2 "Socket_Arduino_Uno:Arduino_1pin" H 11024 572 20  0000 C CNN
F 3 "" H 11100 650 50  0000 C CNN
	1    11100 650 
	0    -1   -1   0   
$EndComp
NoConn ~ 10800 850 
NoConn ~ 10900 850 
NoConn ~ 11000 850 
NoConn ~ 11100 850 
$Comp
L Connector_Generic:Conn_01x08 P4
U 1 1 56D7164F
P 10000 2600
F 0 "P4" H 10000 2100 50  0000 C CNN
F 1 "Digital" V 10100 2600 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x08" V 10150 2550 20  0000 C CNN
F 3 "" H 10000 2600 50  0000 C CNN
	1    10000 2600
	-1   0    0    -1  
$EndComp
Wire Notes Line
	8525 825  9925 825 
Wire Notes Line
	9925 825  9925 475 
Wire Wire Line
	9350 1450 9350 1700
Wire Wire Line
	9350 1700 9400 1700
Wire Wire Line
	9400 1900 9150 1900
Wire Wire Line
	9400 2000 9050 2000
Wire Wire Line
	9400 2300 8950 2300
Wire Wire Line
	9400 2100 9300 2100
Wire Wire Line
	9400 2200 9300 2200
Connection ~ 9300 2200
Wire Wire Line
	8950 2300 8950 1450
Wire Wire Line
	9050 2000 9050 1350
Wire Wire Line
	9150 1900 9150 1450
Wire Wire Line
	9400 2500 8900 2500
Wire Wire Line
	9400 2600 8900 2600
Wire Wire Line
	9400 2700 8900 2700
Wire Wire Line
	9400 2800 8900 2800
Wire Wire Line
	9400 2900 8900 2900
Wire Wire Line
	9400 3000 8900 3000
$Comp
L Connector_Generic:Conn_01x10 P3
U 1 1 56D721E0
P 10000 1600
F 0 "P3" H 10000 2150 50  0000 C CNN
F 1 "Digital" V 10100 1600 50  0000 C CNN
F 2 "Socket_Arduino_Uno:Socket_Strip_Arduino_1x10" V 10150 1600 20  0000 C CNN
F 3 "" H 10000 1600 50  0000 C CNN
	1    10000 1600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	10200 2100 10550 2100
Wire Wire Line
	10200 2000 10550 2000
Wire Wire Line
	10200 1900 10550 1900
Wire Wire Line
	10200 1800 10550 1800
Wire Wire Line
	10200 1700 10550 1700
Wire Wire Line
	10200 1600 10550 1600
Wire Wire Line
	10200 1400 10550 1400
Wire Wire Line
	10200 1300 10550 1300
Wire Wire Line
	10200 1200 10550 1200
Wire Wire Line
	10200 3000 10550 3000
Wire Wire Line
	10200 2900 10550 2900
Wire Wire Line
	10200 2800 10550 2800
Wire Wire Line
	10200 2700 10550 2700
Wire Wire Line
	10200 2600 10550 2600
Wire Wire Line
	10200 2500 10550 2500
Wire Wire Line
	10200 2400 10550 2400
Wire Wire Line
	10200 2300 10550 2300
Wire Wire Line
	10200 1500 10300 1500
Wire Wire Line
	10300 1500 10300 3150
Wire Wire Line
	9300 2100 9300 2200
Wire Wire Line
	9300 2200 9300 3150
Wire Notes Line
	8500 500  8500 3450
Wire Notes Line
	8500 3450 11200 3450
Wire Wire Line
	9400 1800 8650 1800
Text Notes 9700 1600 0    60   ~ 0
1
Wire Notes Line
	11200 1000 10700 1000
Wire Notes Line
	10700 1000 10700 500 
$Comp
L dk_LED-Indication-Discrete:LTST-C193TBKT-5A LED1
U 1 1 5EA762A0
P 3700 6250
F 0 "LED1" H 3650 6450 60  0000 C CNN
F 1 "LTST-C193TBKT-5A" H 3650 6550 60  0000 C CNN
F 2 "digikey-footprints:0603" H 3900 6450 60  0001 L CNN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/Lite-On%20PDFs/LTST-C193TBKT-5A.pdf" H 3900 6550 60  0001 L CNN
F 4 "160-1827-1-ND" H 3900 6650 60  0001 L CNN "Digi-Key_PN"
F 5 "LTST-C193TBKT-5A" H 3900 6750 60  0001 L CNN "MPN"
F 6 "Optoelectronics" H 3900 6850 60  0001 L CNN "Category"
F 7 "LED Indication - Discrete" H 3900 6950 60  0001 L CNN "Family"
F 8 "https://media.digikey.com/pdf/Data%20Sheets/Lite-On%20PDFs/LTST-C193TBKT-5A.pdf" H 3900 7050 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/lite-on-inc/LTST-C193TBKT-5A/160-1827-1-ND/2355044" H 3900 7150 60  0001 L CNN "DK_Detail_Page"
F 10 "LED BLUE CLEAR CHIP SMD" H 3900 7250 60  0001 L CNN "Description"
F 11 "Lite-On Inc." H 3900 7350 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3900 7450 60  0001 L CNN "Status"
	1    3700 6250
	-1   0    0    -1  
$EndComp
$Comp
L dk_LED-Indication-Discrete:LTST-C193TBKT-5A LED2
U 1 1 5EA7A4DA
P 3700 6700
F 0 "LED2" H 3700 6550 60  0000 C CNN
F 1 "LTST-C193TBKT-5A" H 3650 6900 60  0000 C CNN
F 2 "digikey-footprints:0603" H 3900 6900 60  0001 L CNN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/Lite-On%20PDFs/LTST-C193TBKT-5A.pdf" H 3900 7000 60  0001 L CNN
F 4 "160-1827-1-ND" H 3900 7100 60  0001 L CNN "Digi-Key_PN"
F 5 "LTST-C193TBKT-5A" H 3900 7200 60  0001 L CNN "MPN"
F 6 "Optoelectronics" H 3900 7300 60  0001 L CNN "Category"
F 7 "LED Indication - Discrete" H 3900 7400 60  0001 L CNN "Family"
F 8 "https://media.digikey.com/pdf/Data%20Sheets/Lite-On%20PDFs/LTST-C193TBKT-5A.pdf" H 3900 7500 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/lite-on-inc/LTST-C193TBKT-5A/160-1827-1-ND/2355044" H 3900 7600 60  0001 L CNN "DK_Detail_Page"
F 10 "LED BLUE CLEAR CHIP SMD" H 3900 7700 60  0001 L CNN "Description"
F 11 "Lite-On Inc." H 3900 7800 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3900 7900 60  0001 L CNN "Status"
	1    3700 6700
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_US R2
U 1 1 5EA89893
P 4050 6700
F 0 "R2" V 4150 6700 50  0000 C CNN
F 1 "1K" V 3950 6700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4090 6690 50  0001 C CNN
F 3 "~" H 4050 6700 50  0001 C CNN
	1    4050 6700
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R1
U 1 1 5EA89135
P 4050 6250
F 0 "R1" V 3950 6250 50  0000 C CNN
F 1 "1K" V 4150 6250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4090 6240 50  0001 C CNN
F 3 "~" H 4050 6250 50  0001 C CNN
	1    4050 6250
	0    1    1    0   
$EndComp
Wire Wire Line
	4200 6700 4300 6700
Wire Wire Line
	4300 6700 4300 6250
Wire Wire Line
	4200 6250 4300 6250
Connection ~ 4300 6250
Wire Wire Line
	4300 6250 4300 6100
Text Label 4300 6150 0    50   ~ 0
+5V
Text Label 3450 6250 0    50   ~ 0
5(**)
Text Label 3450 6700 0    50   ~ 0
6(**)
Wire Wire Line
	3400 6700 3600 6700
Wire Wire Line
	3400 6250 3600 6250
$Comp
L My_PCB-rescue:8-1437565-1-2020-04-27_21-41-58 SW1
U 1 1 5EAE560C
P 900 1900
F 0 "SW1" H 1700 2287 60  0000 C CNN
F 1 "8-1437565-1" H 1700 2181 60  0000 C CNN
F 2 "pushbutton:8-1437565-1" H 1700 2140 60  0001 C CNN
F 3 "" H 900 1900 60  0000 C CNN
	1    900  1900
	1    0    0    -1  
$EndComp
Text Label 750  3450 0    50   ~ 0
+5V
$Comp
L Device:R_US R4
U 1 1 5EAD6879
P 750 3250
F 0 "R4" H 818 3296 50  0000 L CNN
F 1 "100" H 818 3205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 790 3240 50  0001 C CNN
F 3 "~" H 750 3250 50  0001 C CNN
	1    750  3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5EAF9A1E
P 2600 2950
F 0 "#PWR0101" H 2600 2700 50  0001 C CNN
F 1 "GND" H 2605 2777 50  0000 C CNN
F 2 "" H 2600 2950 50  0001 C CNN
F 3 "" H 2600 2950 50  0001 C CNN
	1    2600 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  2700 750  2700
Connection ~ 750  2700
Wire Wire Line
	750  2700 600  2700
Wire Wire Line
	750  3400 750  3500
Wire Wire Line
	2500 2100 2600 2100
Wire Wire Line
	2500 2900 2600 2900
Wire Wire Line
	2600 2900 2600 2950
Text Label 700  1900 0    50   ~ 0
2
Text Label 600  2700 0    50   ~ 0
3(**)
$Comp
L My_PCB-rescue:8-1437565-1-2020-04-27_21-41-58 SW2
U 1 1 5EAE98B0
P 900 2700
F 0 "SW2" H 1600 2200 60  0000 C CNN
F 1 "8-1437565-1" H 1600 2100 60  0000 C CNN
F 2 "pushbutton:8-1437565-1" H 1700 2940 60  0001 C CNN
F 3 "" H 900 2700 60  0000 C CNN
	1    900  2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	750  2700 750  3100
$Comp
L Device:R_US R3
U 1 1 5EB1E255
P 800 2150
F 0 "R3" H 868 2196 50  0000 L CNN
F 1 "100" H 868 2105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 840 2140 50  0001 C CNN
F 3 "~" H 800 2150 50  0001 C CNN
	1    800  2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	600  1900 800  1900
Wire Wire Line
	800  2000 800  1900
Connection ~ 800  1900
Wire Wire Line
	800  1900 900  1900
Wire Wire Line
	800  2300 800  2400
Text Label 800  2300 0    50   ~ 0
+5V
$Comp
L power:GND #PWR0102
U 1 1 5EB27724
P 2600 2100
F 0 "#PWR0102" H 2600 1850 50  0001 C CNN
F 1 "GND" H 2605 1927 50  0000 C CNN
F 2 "" H 2600 2100 50  0001 C CNN
F 3 "" H 2600 2100 50  0001 C CNN
	1    2600 2100
	1    0    0    -1  
$EndComp
$Comp
L 2020-04-27_22-38-17:3362P-1-103LF Pot1
U 1 1 5EA7D454
P 2500 3950
F 0 "Pot1" V 2847 3871 60  0000 R CNN
F 1 "10K" V 2953 3871 60  0000 R CNN
F 2 "potentiometer:3362P-1-103LF" H 2925 3515 60  0001 C CNN
F 3 "" H 2500 3950 60  0000 C CNN
	1    2500 3950
	0    1    1    0   
$EndComp
Wire Wire Line
	2500 3950 2500 3850
Wire Wire Line
	2800 4350 2850 4350
Text Label 2500 3900 0    50   ~ 0
+5V
Text Label 2900 4350 0    50   ~ 0
A0
$Comp
L Device:CP1 C1
U 1 1 5EA8512F
P 2850 4600
F 0 "C1" H 2965 4646 50  0000 L CNN
F 1 "0.1uF" H 2965 4555 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 2850 4600 50  0001 C CNN
F 3 "~" H 2850 4600 50  0001 C CNN
	1    2850 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 4450 2850 4350
Connection ~ 2850 4350
Wire Wire Line
	2850 4350 3000 4350
$Comp
L power:GND #PWR0103
U 1 1 5EA901E5
P 2500 4750
F 0 "#PWR0103" H 2500 4500 50  0001 C CNN
F 1 "GND" H 2505 4577 50  0000 C CNN
F 2 "" H 2500 4750 50  0001 C CNN
F 3 "" H 2500 4750 50  0001 C CNN
	1    2500 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 4750 2500 4750
Connection ~ 2500 4750
$Comp
L Connector:Conn_01x03_Female LM35/34
U 1 1 5EA7D82E
P 900 3800
F 0 "LM35/34" V 838 3612 50  0000 R CNN
F 1 "Conn_01x03_Female" V 750 3550 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 900 3800 50  0001 C CNN
F 3 "~" H 900 3800 50  0001 C CNN
	1    900  3800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	800  4000 800  4150
Wire Wire Line
	900  4000 900  4150
Wire Wire Line
	1000 4000 1000 4150
Text Label 800  4100 0    50   ~ 0
+5V
Text Label 900  4000 0    50   ~ 0
A1
Text Label 1000 4050 0    50   ~ 0
GND
Wire Notes Line
	2100 5050 3300 5050
Wire Notes Line
	3300 5050 3300 3750
Wire Notes Line
	3300 3750 2100 3750
Wire Notes Line
	2100 3750 2100 5050
Wire Notes Line
	550  3700 550  4250
Wire Notes Line
	550  4250 1950 4250
Wire Notes Line
	1950 4250 1950 3700
Wire Notes Line
	1950 3700 550  3700
Wire Notes Line
	550  1450 550  3600
Wire Notes Line
	550  3600 2950 3600
Wire Notes Line
	2950 3600 2950 1450
Wire Notes Line
	550  1450 2950 1450
Wire Wire Line
	2400 800  2250 800 
Wire Wire Line
	2400 900  2250 900 
Wire Wire Line
	2400 1000 2250 1000
Wire Wire Line
	2400 1100 2250 1100
$Comp
L Connector:Conn_01x04_Female PORTE1
U 1 1 5EADEC14
P 2600 900
F 0 "PORTE1" H 2628 876 50  0000 L CNN
F 1 "Conn_01x04_Female" H 2628 785 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 2600 900 50  0001 C CNN
F 3 "~" H 2600 900 50  0001 C CNN
	1    2600 900 
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Female DS18S20
U 1 1 5EAEC6D9
P 3350 2900
F 0 "DS18S20" V 3288 2712 50  0000 R CNN
F 1 "Conn_01x03_Female" V 3197 2712 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 3350 2900 50  0001 C CNN
F 3 "~" H 3350 2900 50  0001 C CNN
	1    3350 2900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3250 3100 3250 3150
Wire Wire Line
	3350 3100 3350 3150
Wire Wire Line
	3450 3100 3450 3150
Text Label 3250 3150 2    50   ~ 0
GND
Text Label 3350 3150 0    50   ~ 0
A4
Text Label 3450 3150 0    50   ~ 0
+5V
$Comp
L RF_Module:RFM95W-915S2 RFM95W1
U 1 1 5EB0AD40
P 5100 1550
F 0 "RFM95W1" H 4700 2250 50  0000 C CNN
F 1 "RFM95W-915S2" H 4650 2150 50  0000 C CNN
F 2 "RF_Module:HOPERF_RFM9XW_SMD" H 1800 3200 50  0001 C CNN
F 3 "https://www.hoperf.com/data/upload/portal/20181127/5bfcbea20e9ef.pdf" H 1800 3200 50  0001 C CNN
	1    5100 1550
	1    0    0    -1  
$EndComp
$Comp
L dk_RF-Antennas:2450AT18A100E ANTENNA1
U 1 1 5EB0CBA4
P 5900 1250
F 0 "ANTENNA1" H 5900 1497 60  0000 C CNN
F 1 "2450AT18A100E" H 5900 1391 60  0000 C CNN
F 2 "digikey-footprints:Antenna_1.6x3.2mm_2450AT18A100E" H 6100 1450 60  0001 L CNN
F 3 "https://www.johansontechnology.com/datasheets/2450AT18A100/2450AT18A100.pdf" H 6100 1550 60  0001 L CNN
F 4 "712-1005-1-ND" H 6100 1650 60  0001 L CNN "Digi-Key_PN"
F 5 "2450AT18A100E" H 6100 1750 60  0001 L CNN "MPN"
F 6 "RF/IF and RFID" H 6100 1850 60  0001 L CNN "Category"
F 7 "RF Antennas" H 6100 1950 60  0001 L CNN "Family"
F 8 "https://www.johansontechnology.com/datasheets/2450AT18A100/2450AT18A100.pdf" H 6100 2050 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/johanson-technology-inc/2450AT18A100E/712-1005-1-ND/1560834" H 6100 2150 60  0001 L CNN "DK_Detail_Page"
F 10 "RF ANT 2.4GHZ CHIP SOLDER SMD" H 6100 2250 60  0001 L CNN "Description"
F 11 "Johanson Technology Inc." H 6100 2350 60  0001 L CNN "Manufacturer"
F 12 "Active" H 6100 2450 60  0001 L CNN "Status"
	1    5900 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 1250 5600 1250
Text Label 5200 2150 0    50   ~ 0
GND
Text Label 5100 2150 1    50   ~ 0
GND
Text Label 5000 2150 2    50   ~ 0
GND
Wire Wire Line
	5100 1050 5100 950 
Text Label 5100 950  0    50   ~ 0
+3.3V
Text Label 4150 1550 0    60   ~ 0
10(**/SS)
Wire Wire Line
	4150 1550 4600 1550
Text Label 4150 1450 0    60   ~ 0
12(MISO)
Text Label 4150 1350 0    60   ~ 0
11(**/MOSI)
Wire Wire Line
	4150 1350 4600 1350
Wire Wire Line
	4150 1450 4600 1450
Wire Wire Line
	4150 1250 4600 1250
Text Label 4150 1250 0    60   ~ 0
13(SCK)
Text Label 4200 1750 0    60   ~ 0
5(**)
Wire Wire Line
	4200 1750 4600 1750
Wire Wire Line
	5600 1950 5950 1950
Wire Wire Line
	5600 1850 5950 1850
Text Label 5950 1950 0    60   ~ 0
2
Text Label 5950 1850 0    60   ~ 0
3(**)
Wire Notes Line
	4000 2200 6450 2200
Wire Notes Line
	6450 2200 6450 600 
Wire Notes Line
	6450 600  4000 600 
Wire Notes Line
	4000 600  4000 2200
$Comp
L Driver_Motor:DRV8833PW DRV8833
U 1 1 5EB4C4AA
P 5500 4200
F 0 "DRV8833" H 5500 3411 50  0000 C CNN
F 1 "DRV8833PW" H 5500 3320 50  0000 C CNN
F 2 "Package_SO:TSSOP-16_4.4x5mm_P0.65mm" H 5950 4650 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/drv8833.pdf" H 5350 4750 50  0001 C CNN
	1    5500 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 4300 6300 4300
Wire Wire Line
	6100 4400 6300 4400
Wire Wire Line
	5700 3500 5700 3250
Text Label 5700 3250 1    50   ~ 0
+5V
Text Label 5500 4900 0    50   ~ 0
GND
Wire Wire Line
	4900 4300 4750 4300
Wire Wire Line
	4900 4400 4750 4400
Text Label 4750 4300 0    60   ~ 0
A2
Text Label 4750 4400 0    60   ~ 0
A3
Wire Wire Line
	5800 3250 5800 3500
Text Label 5800 3250 1    60   ~ 0
9(**)
Wire Notes Line
	4500 3000 7500 3000
Wire Notes Line
	4500 5300 4500 3000
$Comp
L 2020-04-28_02-19-46:282837-2 TE1
U 1 1 5EB6BF9A
P 6700 3250
F 0 "TE1" V 7547 3478 60  0000 L CNN
F 1 "282837-2" V 7653 3478 60  0000 L CNN
F 2 "TE:282837-2" H 7600 3490 60  0001 C CNN
F 3 "" H 6700 3250 60  0000 C CNN
	1    6700 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	6700 3250 6300 3250
Wire Wire Line
	6300 3250 6300 4300
Wire Wire Line
	6700 5050 6300 5050
Wire Wire Line
	6300 5050 6300 4400
Wire Notes Line
	7500 3000 7500 5300
Wire Notes Line
	4500 5300 7550 5300
Wire Notes Line
	3000 2700 3000 3250
Wire Notes Line
	3000 3250 4400 3250
Wire Notes Line
	4400 3250 4400 2700
Wire Notes Line
	4400 2700 3000 2700
Wire Notes Line
	2050 600  2050 1250
Wire Notes Line
	2050 1250 3450 1250
Wire Notes Line
	3450 1250 3450 600 
Wire Notes Line
	3450 600  2050 600 
$Comp
L Connector:Conn_01x06_Female SPI1
U 1 1 5EBA3564
P 1100 6000
F 0 "SPI1" H 992 5475 50  0000 C CNN
F 1 "Conn_01x06_Female" H 992 5566 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 1100 6000 50  0001 C CNN
F 3 "~" H 1100 6000 50  0001 C CNN
	1    1100 6000
	-1   0    0    1   
$EndComp
Wire Wire Line
	1300 5700 1450 5700
Wire Wire Line
	1300 5800 1450 5800
Wire Wire Line
	1300 5900 1450 5900
Wire Wire Line
	1300 6000 1450 6000
Wire Wire Line
	1300 6100 1450 6100
Wire Wire Line
	1300 6200 1450 6200
Text Label 1450 6200 0    50   ~ 0
+5V
Text Label 1450 5700 0    50   ~ 0
GND
Text Label 1450 6100 0    60   ~ 0
10(**/SS)
Text Label 1450 6000 0    60   ~ 0
11(**/MOSI)
Text Label 1450 5900 0    60   ~ 0
12(MISO)
Text Label 1450 5800 0    60   ~ 0
13(SCK)
$Comp
L Connector:Conn_01x04_Female I2C1
U 1 1 5EBBDD88
P 1150 7100
F 0 "I2C1" H 1042 6675 50  0000 C CNN
F 1 "Conn_01x04_Female" H 1042 6766 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 1150 7100 50  0001 C CNN
F 3 "~" H 1150 7100 50  0001 C CNN
	1    1150 7100
	-1   0    0    1   
$EndComp
Wire Wire Line
	1350 6900 1500 6900
Wire Wire Line
	1350 7000 1500 7000
Wire Wire Line
	1350 7100 1500 7100
Wire Wire Line
	1350 7200 1500 7200
Text Label 1500 7200 0    50   ~ 0
+5V
Text Label 1500 6900 0    50   ~ 0
GND
Text Label 1500 7100 0    60   ~ 0
A4(SDA)
Text Label 1500 7000 0    60   ~ 0
A5(SCL)
Text Label 9150 1500 0    50   ~ 0
+3.3V
Wire Notes Line
	700  5300 2150 5300
Wire Notes Line
	2150 5300 2150 6450
Wire Notes Line
	2150 6450 700  6450
Wire Notes Line
	700  6450 700  5300
Wire Notes Line
	700  6550 2050 6550
Wire Notes Line
	2050 6550 2050 7350
Wire Notes Line
	2050 7350 700  7350
Wire Notes Line
	700  7350 700  6550
Wire Notes Line
	3050 5750 4500 5750
Wire Notes Line
	4500 5750 4500 7100
Wire Notes Line
	3050 7100 3050 5750
Wire Notes Line
	3050 7100 4500 7100
$EndSCHEMATC
