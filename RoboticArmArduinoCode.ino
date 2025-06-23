#include <Servo.h>

int xPin=A0;
int yPin=A1;
int buttonPin=2;


int xval;
int yval;
int buttonState;


int xServoPin=9;
int yServoPin=10;
int zServoPin=11;


int xServoPos;
int yServoPos;
int zServoPos;

Servo xServo; 
Servo yServo; 
Servo zServo;

void setup() { 
  Serial.begin(9600);
  pinMode(xPin, INPUT); 
  pinMode(yPin, INPUT); 
  pinMode(buttonPin,INPUT_PULLUP);
  

  xServo.attach(xServoPin); 
  yServo.attach(yServoPin); 
  zServo.attach(zServoPin);
  Serial.begin(9600);
};
void loop() { 
  xval=analogRead(xPin); 
  yval=analogRead(yPin); 
  buttonState=digitalRead(buttonPin);

  Serial.println(buttonState);
  // target map(source, lowSource, highSource 
  xServoPos=map(xval, 0, 1023, 0, 45); 
  yServoPos=map(yval, 0, 1023, 0, 90); 
  if(buttonState==LOW){
    zServoPos=0;
  }
  if(buttonState==HIGH){
    zServoPos=45;
  }
  xServo.write(xServoPos); 
  yServo.write(yServoPos);
  zServo.write(zServoPos);
}
