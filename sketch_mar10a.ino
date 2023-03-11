int IN1_A=7;
int IN2_A=8;
int IN1_B=9;
int IN2_B=10;

int echo_pin = 2;
int trigger_pin=3;
// For two motors instance at once
#include <L298NX2.h>
L298NX2 motors(IN1_A,IN2_A,IN1_B,IN2_B);

void turn_right(L298NX2 motor){
  motor.forwardA();
  motor.backwardB();
}

void setup() {
  // put your setup code here, to run once:
  pinMode(echo_pin,INPUT);
  pinMode(trigger_pin,OUTPUT);
  Serial.begin(9600);
}

double calc_distance(){
  digitalWrite(trigger_pin,LOW);
  delay(10);
  digitalWrite(trigger_pin,HIGH);
  delay(10);
  digitalWrite(trigger_pin,LOW);
  double duration=pulseIn(echo_pin,HIGH);
  return duration*0.034/2;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(calc_distance());

}
