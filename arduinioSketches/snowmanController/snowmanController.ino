#include <P1AM.h>

int ONBOARD_LED_PIN = 14;
int CHANNEL = 1;
int HAT_MOTOR_PIN = 1;
int OUTPUT_PINS[] = {ONBOARD_LED_PIN, HAT_MOTOR_PIN}; 
int INPUT_PINS[] = {};



int timer = 0;

void setup() {

  Serial.begin(115200);  //initialize serial communication at 115200 bits per second 
  while (!P1.init()){ 
    ; //Wait for Modules to Sign on   
  }

  // put your setup code here, to run once:
  pinMode(ONBOARD_LED_PIN, OUTPUT);
  for(int i=0; i < sizeof(INPUT_PINS); i++) {
      pinMode(INPUT_PINS[i], INPUT);
  }
  
}

void loop() {
  //for(int i=0; i < 20; i++) {
  // put your main code here, to run repeatedly:
    turnOnLED(ONBOARD_LED_PIN);
    delay(500);
    turnOffLED(ONBOARD_LED_PIN);
    delay(500);
  //}

}

void turnOnMotor(int motorId, int motorSpeed){
  digitalWrite(motorId, motorSpeed);
}

void turnOffMotor(int motorId) {
  digitalWrite(motorId,0);
}

void turnOnLED(int ledId) {
  //P1.writeDiscrete(HIGH,CHANNEL,ledId);
  digitalWrite(ledId, HIGH);
}

void turnOffLED(int ledId) {
  //P1.writeDiscrete(LOW,CHANNEL,ledId);
  digitalWrite(ledId, LOW);
}