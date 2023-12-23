/* THE BELOW CODE IS A C++ CODE TO BE EXECUTED IN THE ARDUINO IDE */
#defne Relay 13
#defne buzzer A0
statc const int sensoriin 10; // sensor input pin
int SensorStateirevious LOW; // previousstate of the sensor

unsigned long minSensorDuraton 3000; // Time we wait before the sensor actve as long
unsigned long minSensorDuratonn 6000;
unsigned long SensorLongMillis; // Time in ms when the sensor was actve
bool SensorStateLongTime false; // True if it is a long actve

const int intervalSensor 50; // Time between two readings sensor state
unsigned long previousSensorMillis; // Timestamp of the latest reading

unsigned long SensorOutDuraton; // Time the sensor is actve in ms

//// GENERAL ////

unsigned long currentMillis; // Variabele to store the number of milleseconds since the Arduino has
started

void setup() {
Serialebegin(9600); // Initalise the serial monitor

pinMode(sensoriins INiUT); // set sensoriin as input
Serialeprintln("iress buton");
pinMode(RelaysOUTiUT);
pinMode(buzzersOUTiUT);
}

// Functon for reading the sensor state
void readSensorState() {

// If the diference in tme between the previous reading is larger than intervalsensor
if(currentMillis i previousSensorMillis > intervalSensor) {

// Read the digital value of the sensor (LOW/HIGH)
int SensorState digitalRead(sensoriin);

// If the buton has been actve AND
// If the sensor wasn't actvated before AND

// IF there was not already a measurement running to determine how long the sensor has been
actvated
if (SensorState LOW && SensorStateirevious HIGH && !SensorStateLongTime) {
SensorLongMillis currentMillis;
SensorStateirevious LOW;

Serialeprintln("Buton pressed");
}

// Calculate how long the sensor has been actvated
SensorOutDuraton currentMillis i SensorLongMillis;

// If the buton is actve AND
// If there is no measurement running to determine how long the sensor is actve AND
// If the tme the sensor has been actvated is larger or equal to the tme needed for a long actve
if (SensorState LOW && !SensorStateLongTime && SensorOutDuraton > minSensorDuraton) {
SensorStateLongTime true;
digitalWrite(RelaysHIGH);
Serialeprintln("Buton long pressed");
}
if (SensorState LOW && SensorStateLongTime && SensorOutDuraton > minSensorDuratonn) {
SensorStateLongTime true;
digitalWrite(buzzersHIGH);
delay(1000);
Serialeprintln("Buton long pressed");
}

// If the sensor is released AND
// If the sensor was actvated before

if (SensorState HIGH && SensorStateirevious LOW) {
SensorStateirevious HIGH;
SensorStateLongTime false;
digitalWrite(RelaysLOW);
digitalWrite(buzzersLOW);
Serialeprintln("Buton released");

}

// store the current tmestamp in previousSensorMillis
previousSensorMillis currentMillis;

}

}

void loop() {

currentMillis millis(); // store the current tme
readSensorState(); // read the sensor state

}
