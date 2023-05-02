#include <Keyboard.h>
//version for keyboard emulation

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

void setup() {
  Keyboard.begin();
  pinMode(clock1, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(data1, INPUT);
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

  pressKey(b1, 's');
  pressKey(a1, 'd');
  pressKey(y1, 'a');
  pressKey(x1, 'w');
  pressKey(l1, 'q');
  pressKey(r1, 'e');
  pressKey(start1, KEY_RETURN);
  pressKey(select1, KEY_LEFT_SHIFT);
  
  pressKey(up1, KEY_UP_ARROW);
  pressKey(down1, KEY_DOWN_ARROW);
  pressKey(left1, KEY_LEFT_ARROW);
  pressKey(right1, KEY_RIGHT_ARROW);
  //delay(10);
}

void pressKey(int button, int key){
  if(button == HIGH){
    Keyboard.press(key);
  }
  else{
    Keyboard.release(key);
  }
}

void pulse(int pin){
  digitalWrite(pin, HIGH);
  //delay(10);
  digitalWrite(pin, LOW);
}

