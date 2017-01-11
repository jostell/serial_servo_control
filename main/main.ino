#include <Servo.h>

#define SERVO_PIN 3
Servo servo;

int deg = 5; // 0 makes some noise

void setup() {
  Serial.begin(9600);
  while (!Serial)
  {
    ;
  }
  servo.attach(SERVO_PIN);
  servo.write(deg); 
  delay(100);
}

void loop() {
  while (Serial.available() > 0)
  {
    deg = Serial.parseInt();
    deg = constrain(deg, 0, 360);
    if (Serial.read() == '\n')
    {
      servo.write(deg);
      delay(100);
    }
    Serial.print(deg, DEC);
    Serial.println("");
  }
  delay(10);
}
