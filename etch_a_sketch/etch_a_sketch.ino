/*
  Stepper Motor Demonstration 1
  Stepper-Demo1.ino
  Demonstrates 28BYJ-48 Unipolar Stepper with ULN2003 Driver
  Uses Arduino Stepper Library

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

//Include the Arduino Stepper Library
#include <Stepper.h>

// Define Constants

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

Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);

void setup()
{
// Nothing  (Stepper Library sets pins as outputs)
}

void loop()
{
  // Slow - 4-step CW sequence to observe lights on driver board
  steppermotor.setSpeed(1);    
  StepsRequired  =  4;
  steppermotor.step(StepsRequired);
  delay(2000);

   // Rotate CW 1/2 turn slowly
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotor.setSpeed(100);   
  steppermotor.step(StepsRequired);
  delay(1000);
  
  // Rotate CCW 1/2 turn quickly
  StepsRequired  =  - STEPS_PER_OUT_REV / 2;   
  steppermotor.setSpeed(700);  
  steppermotor.step(StepsRequired);
  delay(2000);

}

/////////////////////////

// -------------
// | 1 | 2 | 3 |
// |-----------|
// | 4 | 5 | 6 |
// |-----------|
// | 7 | 8 | 9 |
// -------------

void A()
{
  d5();
  d2();
  d2();
  d2();
  d3();
  d6();
  d9();
  d8();
  d8();
  d8();
  d4();
  d4();
  m6();
  m6(); 
  d8(); 
}

void B()
{
  d5();
  d2();
  d2();
  d2();
  d2();
  d6();
  d6();
  d9();
  d7();
  d4();
  m6();
  d9();
  d7();
  d4(); 
  m6(); 
  m6();
}

void C()
{
  d6();
  d1();
  d2();
  d3();
  d6();
  d9();
  m1();
  m4();
  m7();
  m8();
  m8();
  m9();
  d6();
  d3(); 
  m7(); 
  m6();
}

void D()
{
  d5();
  d2();
  d2();
  d2();
  d2();
  d6();
  d6();
  d9();
  d8();
  d8();
  d7();
  d4();
  d4();
  m6(); 
  m6(); 
  m6();
}

void E()
{
  d6();
  d1();
  d2();
  d6();
  d6();
  m4();
  m4();
  d2();
  d3();
  d6();
  d6();
  m4();
  m4();
  m7(); 
  m8(); 
  m8();
  m9();
  d6();
  d6();
  
}
void F()
{
  d5();
  d2();
  d2();
  d6();
  d6();
  m4();
  d1();
  d3();
  d6();
  d6();
  m4();
  m4();
  m7();
  m8(); 
  m8(); 
  m8();
  m6();
  m6();
  m6();
}

void G()
{
  d6();
  d1();
  d2();
  d3();
  d6();
  d6();
  m4();
  m4();
  m7();
  m8();
  m8();
  m9();
  d6();
  d3(); 
  d2(); 
  d4();
  m9(); 
  m8(); 
  m6();
}

void H()
{
  d5();
  d2();
  d2();
  d2();
  d2();
  m8();
  d9();
  d6();
  d3();
  d2();
  m8();
  d8();
  d8();
  d8(); 
}

void I()
{
  d5();
  d3();
  d2();
  d2();
  d1();
  d6();
  d6();
  m7();
  m8();
  m8();
  d8();
  d6();
}
void J()
{
  d6();
  d1();
  m9();
  d3();
  d2();
  d2();
  d1();
  d4();
  m6();
  d6();
  m8();
  m8();
  m8();
  d8(); 
}
void K()
{
  d5();
  d2();
  d2();
  d2();
  d2();
  m8();
  d9();
  d3();
  d3();
  m7();
  m7();
  d9();
  d9();
}

void L()
{
  d5();
  d2();
  d2();
  d2();
  d2();
  m8();
  m8();
  m8();
  d9();
  d6();
}
void M()
{
  d5();
  d2();
  d2();
  d2();
  d3();
  d9();
  d8();
  m2();
  d3();
  d9();
  d8();
  d8();
  d8();
}
void N()
{
  d5();
  d2();
  d2();
  d2();
  d2();
  m8();
  d9();
  d9();
  d3();
  d2();
  d2();
  m8();
  m8();
  d8(); 
  d8(); 
}
void O()
{
  d6();
  d1();
  d2();
  d2();
  d3();
  d6();
  d9();
  d8();
  d8();
  d7();
  m6();
}

void P()
{
  d5();
  d2();
  d2();
  d2();
  d3();
  d6();
  d9();
  d7();
  d4();
  m7();
  m8();
  m6();
  m6();
  m6(); 
}
void Q()
{
  d6();
  d1();
  d2();
  d2();
  d3();
  d6();
  d9();
  d8();
  d8();
  d7();
  m3();
  d9();
}

void R()
{
  d5();
  d2();
  d2();
  d6();
  d1();
  d3();
  d6();
  d9();
  d7();
  d9();
  d8();
}

void S()
{
  d5();
  d6();
  d6();
  d3();
  d1();
  d4();
  d1();
  d3();
  d6();
  d6();
  m4();
  m4();
  m7();
  m9(); 
  m6(); 
  m9();
  m8(); 
  m6(); 
}
void T()
{
  d6();
  d2();
  d2();
  d2();
  d1();
  d6();
  d6();
  m7();
  m8();
  m8();
  m8();
  m6();
}

void U()
{
  d6();
  d1();
  d2();
  d2();
  d2();
  m8();
  m8();
  m8();
  m9();
  d6();
  d3();
  d2();
  d2();
  d2(); 
  m8(); 
  m8();
  m8(); 
  m8(); 
  m6();
}

void V()
{
  m6();
  d6();
  d1();
  d1();
  d2();
  d2();
  m8();
  m8();
  m9();
  m9();
  d3();
  d3();
  d2();
  d2(); 
  m8(); 
  m8();
  m7(); 
  m7(); 
  m6();
  m6();
}
void W()
{
  d6();
  d1();
  d2();
  d2();
  d2();
  m8();
  m8();
  m8();
  m9();
  d3();
  d2();
  d2();
  m8();
  m8(); 
  d8(); 
  d6();
  d3(); 
  d2(); 
  d2();
  d2(); 
  m8(); 
  m8();
  m8();
  m8();
  m6();
}

void X()
{
  d5();
  d8();
  d3();
  d1();
  d2();
  m8();
  m9();
  d3();
  d2();
  m8();
  m7();
  d9();
  d8();
}

void Y()
{
  d6();
  d2();
  d1();
  d2();
  d2();
  m8();
  d9();
  d9();
  d2();
  d2();
  m8();
  m7();
  m8();
  m8(); 
  m6(); 
}

void Z()
{
  d5();
  d3();
  d3();
  d3();
  d2();
  d4();
  d4();
  d4();
  m6();
  m6();
  m9();
  m7();
  m7();
  d8(); 
  d6(); 
  d6();
}

void bang()
{
  d5();
  m2();
  d2();
  d2();
  d2();
  m8();
  m8();
  m8();
  m8();
}

void questionMark()
{
  d5();
  m2();
  d2();
  d3();
  d2();
  d4();
  d4();
  m6();
  m9();
  m7();
  m8();
  m9();
}

void d(int loc){
  m(loc);
  drawPixel();
}

void m(int loc){
  switch(loc){
    case 1:
      up();
      left();
    case 2:
      up();
    case 3:
      up();
      right();
    case 4:
      left();
    case 5:
      // Do nothing
    case 6:
      right()
    case 7:
      down();
      left();
    case 8:
      down();
    case 9:
      right();
      down();
    default:
      Serial.print("Invalid moveTo value.");
  }

void drawPixel(){
  up();
  right();
  down();
  left();
}
