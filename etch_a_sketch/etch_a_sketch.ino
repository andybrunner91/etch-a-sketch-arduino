/*
  Stepper Motor Demonstration 1
  Stepper-Demo1.ino
  Demonstrates 28BYJ-48 Unipolar Stepper with ULN2003 Driver
  Uses Arduino Stepper Library

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// 4 revolutions wide
// 3 revolutions tall

// 5 pixels tall x 3 lines of text + 6 buffer = 20 pixels tall

// 3 rev tall / 20 pixels tall = 0.15 revs / pixel

//Include the Arduino Stepper Library
#include <Stepper.h>

// Define Constants

const float PIXEL_SIZE = 0.15;
const int DELAY = 125;
// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 

//  Amount of Gear Reduction
const float GEAR_RED = 64;

// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

// Define Variables

// Number of Steps Required
int StepsRequired;

// Create Instance of Stepper Class
// Specify Pins used for motor coils
// The pins used are 8,9,10,11 
// Connected to ULN2003 Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-3-2-4 for proper step sequencing

Stepper stepperMotorVertical(STEPS_PER_REV, 4, 6, 5, 7);
Stepper stepperMotorHorizontal(STEPS_PER_REV, 8, 10, 9, 11);




void loop()
{

}

void setup()
{
//    // Slow - 4-step CW sequence to observe lights on driver board
//  stepperMotorVertical.setSpeed(1);    
//  StepsRequired  =  4;
//  stepperMotorVertical.step(StepsRequired);
//  delay(2000);
//
//  // Slow - 4-step CW sequence to observe lights on driver board
//  stepperMotorHorizontal.setSpeed(1);    
//  StepsRequired  =  4;
//  stepperMotorHorizontal.step(StepsRequired);
//  delay(2000);
  stepperMotorVertical.setSpeed(700);
  stepperMotorHorizontal.setSpeed(700);
//
//  for (int i = 0; i < 10; i++){
//    left();
//  }
//  

  H();
  space();
  O();
  space();
  A();
  
//   // Rotate CW 1/2 turn slowly
//  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
//  stepperMotorVertical.setSpeed(100);   
//  stepperMotorVertical.step(StepsRequired);
//  delay(1000);
//  
//  // Rotate CCW 1/2 turn quickly
//  StepsRequired  =  - STEPS_PER_OUT_REV / 2;   
//  stepperMotorVertical.setSpeed(700);  
//  stepperMotorVertical.step(StepsRequired);
//  delay(2000);

// Nothing  (Stepper Library sets pins as outputs)
}

/////////////////////////

void up(){
  Serial.print("Going up");
  stepperMotorVertical.step(-STEPS_PER_OUT_REV * PIXEL_SIZE);
  delay(DELAY);
}
void right(){
  Serial.print("Going right");
  stepperMotorHorizontal.step(-STEPS_PER_OUT_REV * PIXEL_SIZE);
  delay(DELAY);

}
void down(){
  Serial.print("Going down");
  stepperMotorVertical.step(STEPS_PER_OUT_REV * PIXEL_SIZE);
  delay(DELAY);
}
void left(){
  Serial.print("Going left");
  stepperMotorHorizontal.step(STEPS_PER_OUT_REV * PIXEL_SIZE);
  delay(DELAY);

}


void m(int loc){
  switch(loc){
    case 1:
      up();
      left();
      break;
    case 2:
      up();
      break;
    case 3:
      up();
      right();
      break;
    case 4:
      left();
      break;
    case 5:
      // Do nothing
      break;
    case 6:
      right();
      break;
    case 7:
      down();
      left();
      break;
    case 8:
      down();
      break;
    case 9:
      right();
      down();
      break;
    default:
      Serial.print("Invalid moveTo value.");
  }
}

  void d(int loc){
  m(loc);
  drawPixel();
}

void drawPixel(){
  up();
  right();
  down();
  left();
}
void bang()
{
  d(5);
  m(2);
  d(2);
  d(2);
  d(2);
  m(8);
  m(8);
  m(8);
  m(8);
}

void space()
{
  right();
  right();
}
void A()
{
  d(5);
  d(3);
  d(4);
  d(2);
  d(2);
  d(3);
  d(6);
  d(9);
  d(8);
  d(7);
  d(6);
  d(8); 
}

void B()
{
  d(5);
  d(6);
  d(1);
  d(3);
  d(4);
  d(2);
  d(2);
  d(6);
  d(6);
  d(9);
  d(7);
  d(9);
  d(7); 
  m(6);
}

void C()
{
  d(6);
  d(1);
  d(2);
  d(3);
  d(6);
  d(9);
  m(1);
  m(4);
  m(7);
  m(8);
  m(8);
  m(9);
  d(6);
  d(3); 
  m(7); 
  m(6);
}

void D()
{
  d(5);
  d(2);
  d(2);
  d(2);
  d(2);
  d(6);
  d(6);
  d(9);
  d(8);
  d(8);
  d(7);
  d(4);
  m(6); 
  m(6); 
}

void E()
{
  d(5);
  d(2);
  d(2);
  d(5);
  d(5);
  m(4);
  m(4);
  d(2);
  d(3);
  d(6);
  d(6);
  m(4);
  m(4);
  m(7); 
  m(8); 
  m(8);
  m(9);
  d(6);
  d(6);
  
}

// F() is already a macro
void drawF()
{
  d(5);
  d(2);
  d(2);
  d(6);
  d(6);
  m(4);
  d(1);
  d(3);
  d(6);
  d(6);
  m(4);
  m(4);
  m(7);
  m(8); 
  m(8); 
  m(8);
  m(6);
  m(6);
  m(6);
}

void G()
{
  d(6);
  d(1);
  d(2);
  d(3);
  d(6);
  d(6);
  m(4);
  m(4);
  m(7);
  m(8);
  m(8);
  m(9);
  d(6);
  d(3); 
  d(2); 
  d(4);
  m(9); 
  m(8); 
  m(6);
}

void H()
{
  d(5);
  d(2);
  d(2);
  d(2);
  d(2);
  m(8);
  d(9);
  d(6);
  d(3);
  d(2);
  m(8);
  d(8);
  d(8);
  d(8); 
}

void I()
{
  d(5);
  d(3);
  d(2);
  d(2);
  d(1);
  d(6);
  d(6);
  m(7);
  m(8);
  m(8);
  d(8);
  d(6);
}
void J()
{
  d(6);
  d(1);
  m(9);
  d(3);
  d(2);
  d(2);
  d(1);
  d(4);
  m(6);
  d(6);
  m(8);
  m(8);
  m(8);
  d(8); 
}
void K()
{
  d(5);
  d(2);
  d(2);
  d(2);
  d(2);
  m(8);
  d(9);
  d(3);
  d(3);
  m(7);
  m(7);
  d(9);
  d(9);
}

void L()
{
  d(5);
  d(2);
  d(2);
  d(2);
  d(2);
  m(8);
  m(8);
  m(8);
  d(9);
  d(6);
}
void M()
{
  d(5);
  d(2);
  d(2);
  d(2);
  d(3);
  d(9);
  d(8);
  m(2);
  d(3);
  d(9);
  d(8);
  d(8);
  d(8);
}
void N()
{
  d(5);
  d(2);
  d(2);
  d(2);
  d(2);
  m(8);
  d(9);
  d(9);
  d(3);
  d(2);
  d(2);
  m(8);
  m(8);
  d(8); 
  d(8); 
}
void O()
{
  d(6);
  d(1);
  d(2);
  d(2);
  d(3);
  d(6);
  d(9);
  d(8);
  d(8);
  d(7);
  m(6);
}

void P()
{
  d(5);
  d(2);
  d(2);
  d(2);
  d(3);
  d(6);
  d(9);
  d(7);
  d(4);
  m(7);
  m(8);
  m(6);
  m(6);
  m(6); 
}
void Q()
{
  d(6);
  d(1);
  d(2);
  d(2);
  d(3);
  d(6);
  d(9);
  d(8);
  d(8);
  d(7);
  m(3);
  d(9);
}

void R()
{
  d(5);
  d(2);
  d(2);
  d(6);
  d(1);
  d(3);
  d(6);
  d(9);
  d(7);
  d(9);
  d(8);
}

void S()
{
  d(5);
  d(6);
  d(6);
  d(3);
  d(1);
  d(4);
  d(1);
  d(3);
  d(6);
  d(6);
  m(4);
  m(4);
  m(7);
  m(9); 
  m(6); 
  m(9);
  m(8); 
  m(6); 
}
void T()
{
  d(6);
  d(2);
  d(2);
  d(2);
  d(1);
  d(6);
  d(6);
  m(7);
  m(8);
  m(8);
  m(8);
  m(6);
}

void U()
{
  d(6);
  d(1);
  d(2);
  d(2);
  d(2);
  m(8);
  m(8);
  m(8);
  m(9);
  d(6);
  d(3);
  d(2);
  d(2);
  d(2); 
  m(8); 
  m(8);
  m(8); 
  m(8); 
  m(6);
}

void V()
{
  m(6);
  d(6);
  d(1);
  d(1);
  d(2);
  d(2);
  m(8);
  m(8);
  m(9);
  m(9);
  d(3);
  d(3);
  d(2);
  d(2); 
  m(8); 
  m(8);
  m(7); 
  m(7); 
  m(6);
  m(6);
}
void W()
{
  d(6);
  d(1);
  d(2);
  d(2);
  d(2);
  m(8);
  m(8);
  m(8);
  m(9);
  d(3);
  d(2);
  d(2);
  m(8);
  m(8); 
  d(8); 
  d(6);
  d(3); 
  d(2); 
  d(2);
  d(2); 
  m(8); 
  m(8);
  m(8);
  m(8);
  m(6);
}

void X()
{
  d(5);
  d(8);
  d(3);
  d(1);
  d(2);
  m(8);
  m(9);
  d(3);
  d(2);
  m(8);
  m(7);
  d(9);
  d(8);
}
// -------------
// | 1 | 2 | 3 |
// |-----------|
// | 4 | 5 | 6 |
// |-----------|
// | 7 | 8 | 9 |
// -------------
void Y()
{
  d(6);
  d(2);
  d(1);
  d(2);
  d(2);
  m(8);
  d(9);
  d(6);
  d(2);
  d(2);
  m(8);
  m(7);
  m(8); 
  m(9); 
}

void Z()
{
  d(5);
  d(3);
  d(3);
  d(3);
  d(2);
  d(4);
  d(4);
  d(4);
  m(6);
  m(6);
  m(9);
  m(7);
  m(7);
  d(8); 
  d(6); 
  d(6);
}



void questionMark()
{
  d(5);
  m(2);
  d(2);
  d(3);
  d(2);
  d(4);
  d(4);
  m(6);
  m(9);
  m(7);
  m(8);
  m(9);
}
