#include <Joystick.h>

Joystick_ Joystick1(0x03, JOYSTICK_TYPE_JOYSTICK
,  8, 0,  true, true, false, false, false
, false, false, false, false, false, false);

const int data1 = 9;
const int latch = 13;
const int clock1 = 11;

int b1 = LOW;
int y1 = LOW;
int select1 = LOW;
int start1 = LOW;
int up1 = LOW;
int down1 = LOW;
int left1 = LOW;
int right1 = LOW;
int a1 = LOW;
int x1 = LOW;
int l1 = LOW;
int r1 = LOW;

int jx1 = 1;
int jy1 = 1;

void setup() {
  Joystick1.begin();
  
  pinMode(clock1, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(data1, INPUT);

  Joystick1.setXAxisRange(0, 2);
  Joystick1.setYAxisRange(0, 2);

  Joystick1.setXAxis(1);
  Joystick1.setYAxis(1);
}

void loop() {
  pulse(latch);

  b1 = !digitalRead(data1);
  pulse(clock1);
  y1 = !digitalRead(data1);
  pulse(clock1);
  select1 = !digitalRead(data1);
  pulse(clock1);
  start1 = !digitalRead(data1);
  pulse(clock1);
  up1 = !digitalRead(data1);
  pulse(clock1);
  down1 = !digitalRead(data1);
  pulse(clock1);
  left1 = !digitalRead(data1);
  pulse(clock1);
  right1 = !digitalRead(data1);
  pulse(clock1);
  a1 = !digitalRead(data1);
  pulse(clock1);
  x1 = !digitalRead(data1);
  pulse(clock1);
  l1 = !digitalRead(data1);
  pulse(clock1);
  r1 = !digitalRead(data1);
  pulse(clock1);

  Joystick1.setButton(0, select1);
  Joystick1.setButton(1, start1);
  Joystick1.setButton(2, b1);
  Joystick1.setButton(3, y1);
  Joystick1.setButton(4, a1);
  Joystick1.setButton(5, x1);
  Joystick1.setButton(6, l1);
  Joystick1.setButton(7, r1);

  jx1 = 1;
  jy1 = 1;
  if(up1 == HIGH){
    jy1--;
  }
  if(down1 == HIGH){
    jy1++;
  }
  if(left1 == HIGH){
    jx1--;
  }
  if(right1 == HIGH){
    jx1++;
  }
  
  Joystick1.setXAxis(jx1);
  Joystick1.setYAxis(jy1);
  //delay(10);
}

void pulse(int pin){
  digitalWrite(pin, HIGH);
  delay(10);
  digitalWrite(pin, LOW);
}

