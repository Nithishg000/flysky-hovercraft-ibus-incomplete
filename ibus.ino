#include <Servo.h>

Servo motor1;
Servo motor2;
Servo motor3;

void setup() {
  Serial.begin(115200);

  motor1.attach(9);
  motor2.attach(10);
  motor3.attach(11);
}

void loop() {
  if (Serial.available() > 0) {
    int iBusData[32];

    for (int i = 0; i < 32; i++) {
      iBusData[i] = Serial.read();
    }

    if (iBusData[0] == 0x20 && iBusData[1] == 0x40) {
      int channel1 = (iBusData[3] << 8) | iBusData[2];
      int channel2 = (iBusData[5] << 8) | iBusData[4];
      int channel3 = (iBusData[7] << 8) | iBusData[6];

      int angle1 = map(channel1, 1000, 2000, 0, 180);
      int angle2 = map(channel2, 1000, 2000, 0, 180);
      int angle3 = map(channel3, 1000, 2000, 0, 180);

      motor1.write(angle1);
      motor2.write(angle2);
      motor3.write(angle3);
    }
  }
}
