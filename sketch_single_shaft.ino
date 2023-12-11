#include <Servo.h>

const int servoMotorPin = 9; // Change this to the actual pin connected to the servo
char shaft = 'Z'; // 'Z' means  no shaft.

Servo digitalServo; // Create a servo object to control the digital servo motor

void setup() {
  pinMode(servoMotorPin, OUTPUT); // Set the servo pin as OUTPUT
  digitalServo.attach(servoMotorPin); // Attaching the servo to the specified pin
  digitalServo.writeMicroseconds(1500); // Set servo to initial position (adjust as needed)
  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  segregateMetalWaste(); // Call the function to segregate waste in a loop
  //if(digitalRead(9) == LOW){
  //  return;
  //}
}

void segregateMetalWaste() {
  if(Serial.available() > 0){
    shaft = Serial.read();
    if(shaft == 'A'){ // Plastic
      digitalWrite(LED_BUILTIN, HIGH);
      digitalServo.write(20); // Rotate servo (adjust pulse width as needed)
      delay(18000); // Wait for 2 seconds
      digitalServo.write(90); // Rotate servo (adjust pulse width as needed)
      delay(5000);
    } else if(shaft == 'B') { //Metal
      digitalWrite(LED_BUILTIN, HIGH);
      delay(2000);
      digitalWrite(LED_BUILTIN, LOW);
      digitalServo.write(110); // Rotate servo (adjust pulse width as needed)
      delay(19000); // Wait for 2 seconds
    } else if(shaft == 'C') { //Paper and Cardboard
      digitalWrite(LED_BUILTIN, HIGH);
      delay(6000);
      digitalWrite(LED_BUILTIN, LOW);
      digitalServo.write(0); // Rotate servo (adjust pulse width as needed)
      delay(15000);
    }
  }
}