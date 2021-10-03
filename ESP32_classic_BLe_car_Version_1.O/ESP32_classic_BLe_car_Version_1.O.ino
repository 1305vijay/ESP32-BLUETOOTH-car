#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED)  || !defined(CONFIG_BLUEDROID_ENABLED)
#error 
#endif
BluetoothSerial SerialBT;
// enable pin of l293d
int motor1 =33;  //left_motor1  //WHEN WE STAND INFRONT OF CAR LEFT SIDE MOTOR
int motor2 =32;  //left_motor2  //WHEN WE STAND INFRONT OF CAR RIGHT SIDE MOTOR
int motor3 =26;  //right_motor3 //WHEN WE STAND INFRONT OF CAR LEFT SIDE MOTOR
int motor4 =25;//right_motor4 //WHEN WE STAND INFRONT OF CAR RIGHT SIDE MOTOR
int ENA =14;
int ENB =12;
char t;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
SerialBT.begin("ESP32s-CAR");
Serial.println("the bluetooth device is ready to connect!");
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
pinMode(motor3,OUTPUT);
pinMode(motor4,OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (SerialBT.available())
  {
    t=SerialBT.read();
    Serial.println(t);
  }
 
 if (SerialBT.available()){
  if (t =='f'){                // GAVE HIGH VALUE TO ONLY TWO PINS I.E MOTOR1 AND MOTOR2 AS EACH PIN IS CONNECTED TO TWO MOTORS OF EACH SIDE
    digitalWrite(motor1,HIGH);// IF WE GIVE HIGH VALUE TO MOTOR1 I.E O/P OF MOTOR1 TO MOVE FORWARD
    digitalWrite(motor2,LOW); // O/P OF MOTOR2 IS FOR TO ROTATE MOTOR IN REVERSE DIRECTION SO GIVE LOW VALUE TO SHUTDOWN.
    digitalWrite(motor3,HIGH);
    digitalWrite(motor4,LOW);
    Serial.print("forward");
  }
  if (t=='b'){
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,HIGH);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,HIGH);
    Serial.print("backward");
    
  }
  if (t =='r') {
    digitalWrite(motor1,HIGH);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,HIGH);
    Serial.print("right");
  }
  if (t =='l') {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,HIGH);
    digitalWrite(motor3,HIGH);
    digitalWrite(motor4,LOW);
    Serial.print("left");
  }
  if (t == 's') {
    digitalWrite(motor1,LOW);
    digitalWrite(motor2,LOW);
    digitalWrite(motor3,LOW);
    digitalWrite(motor4,LOW);
    Serial.print("Stop");
  }
 }
 delay(20);
}
