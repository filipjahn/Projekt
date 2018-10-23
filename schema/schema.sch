EESchema Schematic File Version 4
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
L MCU_Module:Arduino_UNO_R2 A?
U 1 1 5BCF51F0
P 7050 2100
F 0 "A?" H 7050 3278 50  0000 C CNN
F 1 "Arduino_UNO_R2" H 7050 3187 50  0000 C CNN
F 2 "Module:Arduino_UNO_R2" H 7200 1050 50  0001 L CNN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 6850 3150 50  0001 C CNN
	1    7050 2100
	1    0    0    -1  
$EndComp
$Comp
L Sensor:DHT11 U?
U 1 1 5BCF53E5
P 4600 1800
F 0 "U?" H 4370 1846 50  0000 R CNN
F 1 "DHT11" H 4370 1755 50  0000 R CNN
F 2 "" H 4750 2050 50  0001 C CNN
F 3 "http://akizukidenshi.com/download/ds/aosong/DHT11.pdf" H 4750 2050 50  0001 C CNN
	1    4600 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 850  7250 850 
Wire Wire Line
	7250 850  7250 1100
Wire Wire Line
	4500 850  4500 1500
Wire Wire Line
	4900 1800 5600 1800
Wire Wire Line
	5600 1800 5600 2000
Wire Wire Line
	5600 2000 6550 2000
Wire Wire Line
	4500 2100 4500 3400
Wire Wire Line
	4500 3400 6950 3400
Wire Wire Line
	6950 3400 6950 3200
$Comp
L Relay:SANYOU_SRD_Form_C K?
U 1 1 5BCF5D5B
P 9200 1550
F 0 "K?" H 9630 1596 50  0000 L CNN
F 1 "SANYOU_SRD_Form_C" H 9630 1505 50  0000 L CNN
F 2 "Relay_THT:Relay_SPDT_SANYOU_SRD_Series_Form_C" H 9650 1500 50  0001 L CNN
F 3 "http://www.sanyourelay.ca/public/products/pdf/SRD.pdf" H 9200 1550 50  0001 C CNN
	1    9200 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 5BCF60D2
P 10550 1550
F 0 "D?" V 10588 1433 50  0000 R CNN
F 1 "LED" V 10497 1433 50  0000 R CNN
F 2 "" H 10550 1550 50  0001 C CNN
F 3 "~" H 10550 1550 50  0001 C CNN
	1    10550 1550
	0    -1   -1   0   
$EndComp
$Comp
L power:+BATT #PWR?
U 1 1 5BCF73F9
P 9850 2300
F 0 "#PWR?" H 9850 2150 50  0001 C CNN
F 1 "+BATT" H 9865 2473 50  0000 C CNN
F 2 "" H 9850 2300 50  0001 C CNN
F 3 "" H 9850 2300 50  0001 C CNN
	1    9850 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 1250 9300 1000
Wire Wire Line
	9300 1000 10550 1000
Wire Wire Line
	10550 1000 10550 1400
Wire Wire Line
	10550 1700 10550 2300
Wire Wire Line
	10550 2300 9850 2300
Wire Wire Line
	9850 2300 9400 2300
Wire Wire Line
	9400 2300 9400 1850
Connection ~ 9850 2300
$Comp
L Device:R 10kΩ
U 1 1 5BCF78EF
P 8450 2250
F 0 "10kΩ" V 8657 2250 50  0000 C CNN
F 1 "R" V 8566 2250 50  0000 C CNN
F 2 "" V 8380 2250 50  0001 C CNN
F 3 "~" H 8450 2250 50  0001 C CNN
	1    8450 2250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9000 1250 9000 850 
Wire Wire Line
	9000 850  7250 850 
Connection ~ 7250 850 
Wire Wire Line
	8600 2250 9000 2250
Wire Wire Line
	9000 2250 9000 1850
Wire Wire Line
	8300 2250 8200 2250
Wire Wire Line
	8200 2250 8200 3350
Wire Wire Line
	8200 3350 7150 3350
Wire Wire Line
	7150 3350 7150 3200
$EndSCHEMATC
