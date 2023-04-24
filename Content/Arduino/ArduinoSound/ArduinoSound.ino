#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

int EMF,PrefEMF;
float x,y,z;
void setup() 
{
  for (int i = 0; i < 5; i++) {
    pinMode(2+i, OUTPUT);
  }
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  Serial.begin(9600);
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  // set accelerometer range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_1000_DEG);

  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
}

void loop() {
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  x -= g.gyro.x - 0.011279;
  z -= g.gyro.z - 0.0188599999;
  Serial.print(x);
  Serial.print(" ");
  Serial.print(z);
  Serial.println("");
  
  EMF = Serial.read();
  if(EMF==5){
    digitalWrite(6, HIGH);
  }
  if(EMF==4){
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
  }
  if(EMF==3){
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
  }
  if(EMF==2){
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
  }
  if(EMF==1){
    digitalWrite(3, LOW);
  }
  digitalWrite(2, HIGH);
}
