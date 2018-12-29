// DHT Temperature & Humidity Sensor
// Unified Sensor Library Example
// Written by Tony DiCola for Adafruit Industries
// Released under an MIT license.

// Depends on the following Arduino libraries:
// - Adafruit Unified Sensor Library: https://github.com/adafruit/Adafruit_Sensor
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define MY_DEBUG


// Enable and select radio type attached
#define MY_RADIO_RF24
//#define MY_RADIO_NRF5_ESB
//#define MY_RADIO_RFM69
//#define MY_RADIO_RFM95

// Set LOW transmit power level as default, if you have an amplified NRF-module and
// power your radio separately with a good regulator you can turn up PA level.
#define MY_RF24_PA_LEVEL RF24_PA_LOW

// Enable serial gateway
#define MY_GATEWAY_SERIAL

// Define a lower baud rate for Arduinos running on 8 MHz (Arduino Pro Mini 3.3V & SenseBender)
#if F_CPU == 8000000L
#define MY_BAUD_RATE 38400
#endif

// Enable inclusion mode
#define MY_INCLUSION_MODE_FEATURE
// Enable Inclusion mode button on gateway
//#define MY_INCLUSION_BUTTON_FEATURE

// Inverses behavior of inclusion button (if using external pullup)
//#define MY_INCLUSION_BUTTON_EXTERNAL_PULLUP

// Set inclusion mode duration (in seconds)
#define MY_INCLUSION_MODE_DURATION 60
// Digital pin used for inclusion mode button
//#define MY_INCLUSION_MODE_BUTTON_PIN  3

// Set blinking period
#define MY_DEFAULT_LED_BLINK_PERIOD 300

// Inverses the behavior of leds
//#define MY_WITH_LEDS_BLINKING_INVERSE

// Flash leds on rx/tx/err
// Uncomment to override default HW configurations
//#define MY_DEFAULT_ERR_LED_PIN 4  // Error led pin
//#define MY_DEFAULT_RX_LED_PIN  6  // Receive led pin
//#define MY_DEFAULT_TX_LED_PIN  5  // the PCB, on board LED

#include <MySensors.h>

#define DHTPIN 5 // Pin which is connected to the DHT sensor.
#define DHTTYPE DHT11 // DHT 11 

#define CHILD_ID_HUM 0
#define CHILD_ID_TEMP 1

int led = 9;
int i = 0;
float max = 25.00;
float min = 21.00;
float aktualniTeplota = 0;
float aktualniVlhkost = 0;
bool metric = true;
// Uncomment the type of sensor in use:



MyMessage msgHum(CHILD_ID_HUM, V_HUM);
MyMessage msgTemp(CHILD_ID_TEMP, V_TEMP);


DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void presentation()  
{ 
  // Send the sketch version information to the gateway
  sendSketchInfo("TemperatureAndHumidity", "1.1");

  // Register all sensors to gw (they will be created as child devices)
  present(CHILD_ID_HUM, S_HUM);
  present(CHILD_ID_TEMP, S_TEMP);

  metric = getControllerConfig().isMetric;
}

void setup() {
pinMode(led, OUTPUT);0
Serial.begin(9600); 
// Initialize device.
dht.begin();
Serial.println("DHTxx Unified Sensor Example");
// Print temperature sensor details.
sensor_t sensor;
dht.temperature().getSensor(&sensor);
Serial.println("------------------------------------");
Serial.println("Temperature");
Serial.print ("Sensor: "); Serial.println(sensor.name);
Serial.print ("Driver Ver: "); Serial.println(sensor.version);
Serial.print ("Unique ID: "); Serial.println(sensor.sensor_id);
Serial.print ("Max Value: "); Serial.print(sensor.max_value); Serial.println(" *C");
Serial.print ("Min Value: "); Serial.print(sensor.min_value); Serial.println(" *C");
Serial.print ("Resolution: "); Serial.print(sensor.resolution); Serial.println(" *C"); 
Serial.println("------------------------------------");
// Print humidity sensor details.
dht.humidity().getSensor(&sensor);
Serial.println("------------------------------------");
Serial.println("Humidity");
Serial.print ("Sensor: "); Serial.println(sensor.name);
Serial.print ("Driver Ver: "); Serial.println(sensor.version);
Serial.print ("Unique ID: "); Serial.println(sensor.sensor_id);
Serial.print ("Max Value: "); Serial.print(sensor.max_value); Serial.println("%");
Serial.print ("Min Value: "); Serial.print(sensor.min_value); Serial.println("%");
Serial.print ("Resolution: "); Serial.print(sensor.resolution); Serial.println("%"); 
Serial.println("------------------------------------");
// Set delay between sensor readings based on sensor details.
delayMS = sensor.min_delay / 1000;
}

void loop() {
// Delay between measurements.
delay(delayMS);
// Get temperature event and print its value.

sensors_event_t event; 

dht.temperature().getEvent(&event);
if (isnan(event.temperature)) {
Serial.println("Error reading temperature!");
}
else {
Serial.print("Temperature: ");
aktualniTeplota = event.temperature;
Serial.print(aktualniTeplota);
Serial.println(" *C");
if (i == 0) {
if (aktualniTeplota < max){
digitalWrite(led, HIGH);
}
else if(aktualniTeplota > max){
i = 1;
digitalWrite(led, LOW);
}
}
else if(i == 1 && aktualniTeplota < min){
i = 0;
digitalWrite(led, HIGH);
}
Serial.print(i);
}
// Get humidity event and print its value.
dht.humidity().getEvent(&event);
if (isnan(event.relative_humidity)) {
Serial.println("Error reading humidity!");
}
else {
Serial.print("Humidity: ");
aktualniVlhkost = event.relative_humidity;
Serial.print(aktualniVlhkost);
Serial.println("%");
}

}
