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
