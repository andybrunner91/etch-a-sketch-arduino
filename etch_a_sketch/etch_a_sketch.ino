/*
  Stepper Motor Demonstration 1
  Stepper-Demo1.ino
  Demonstrates 28BYJ-48 Unipolar Stepper with ULN2003 Driver
  Uses Arduino Stepper Library

  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

// 5 pixels tall x 3 lines of text + 6 buffer = 20 pixels tall

// 3 rev tall / 20 pixels tall = 0.15 revs / pixel

//Include the Arduino Stepper Library
#include <Stepper.h>

// Define Constants

// in revolutions of the knob
const float PIXEL_SIZE = 0.072;

bool isLastMoveRight;
bool isLastMoveDown;

const int DELAY = 250;
// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 

//  Amount of Gear Reduction
const float GEAR_RED = 64;

// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;

const float BUFFER_STEPS = 0.06*STEPS_PER_OUT_REV;

const float STEPS_PER_MOVE = STEPS_PER_OUT_REV * PIXEL_SIZE;

const float X_REVS = 3.9;
// screen is 4 revolutions wide.  Give a .5 revolution buffer
const float MAX_X = STEPS_PER_OUT_REV * X_REVS;

// screen is 3 revolutions tall.  Give a .5 revolution buffer
const float MAX_Y = STEPS_PER_OUT_REV * 2.5;

const float INITIAL_X = 0;
const float INITIAL_Y = 5*STEPS_PER_MOVE;

float currentX;
float currentY;

char FIRST_LINE[] = "MOVE OVER";
char SECOND_LINE[] = "MARK ROBER!";


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

  Serial.begin(9600);
  stepperMotorVertical.setSpeed(700);
  stepperMotorHorizontal.setSpeed(700);
  currentX = INITIAL_X;
  currentY = INITIAL_Y;
  isLastMoveRight = false;
  isLastMoveDown = false;
  delay(1000);

  //runOverrides();

  printStrings();

  //reset();

}

void runOverrides(){

//  for (int i = 0; i < 3; i++){
//    overrideDown();
//  }
  for (int i = 0; i < 2; i++){
    overrideLeft();
  }
//  for (int i = 0; i < 3; i++){
//    overrideRight();
//  } 
//  for (int i = 0; i < 5; i++){
//    overrideUp();
//  } 
}

void checkFirstLine(){
   if(!firstLineFits()){
    Serial.println("Too many characters!");
    delay(1000);
    exit(1);
  }
  else{
    Serial.println("String fits!");
  }
}

void checkSecondLine(){
   if(!secondLineFits()){
    Serial.println("Too many characters!");
    delay(1000);
    exit(1);
  }
  else{
    Serial.println("String fits!");
  }
}
void printStrings(){

  checkFirstLine();
  checkSecondLine();
  printFirstLine();
  reset();
  printSecondLine();
}

void printFirstLine(){

  for( int i = 0; i < sizeof(FIRST_LINE); i++){
    drawCharacter(FIRST_LINE[i]);
    charSpace();
  }
}

void printSecondLine(){

  for( int i = 0; i < sizeof(SECOND_LINE); i++){
    drawCharacter(SECOND_LINE[i]);
    charSpace();
  }
}

/////////////////////////

void printCoordinates(){
    Serial.print("CurrentX:");
    Serial.println(currentX);
    Serial.print("CurrentY:");
    Serial.println(currentY);
}
void up(){
    printCoordinates();
  if( currentY - STEPS_PER_MOVE >= 0){
    Serial.println("Going up");
    if(isLastMoveDown){
      stepperMotorVertical.step(-BUFFER_STEPS);
      isLastMoveDown = false;
    }
    stepperMotorVertical.step(-STEPS_PER_MOVE);
    currentY -= STEPS_PER_MOVE;
  }
  else{
    Serial.println("Out of bounds up");
    delay(1000);
    exit(0);

  }
  delay(DELAY);
}
void right(){
  printCoordinates();
  if( currentX + STEPS_PER_MOVE <= MAX_X){
    Serial.println("Going right");
    if(!isLastMoveRight){
      stepperMotorHorizontal.step(-BUFFER_STEPS);
      isLastMoveRight = true;
    }
    stepperMotorHorizontal.step(-STEPS_PER_MOVE);
    currentX += STEPS_PER_MOVE;
  }
  else{
    Serial.println("Out of bounds right");
    delay(1000);
    exit(0);
  }
  delay(DELAY);

}
void down(){
    printCoordinates();
   if( currentY + STEPS_PER_MOVE <= MAX_Y){
    Serial.println("Going down");
    if(!isLastMoveDown){
      stepperMotorVertical.step(BUFFER_STEPS);
      isLastMoveDown = true;
    }
    stepperMotorVertical.step(STEPS_PER_MOVE);
    currentY += STEPS_PER_MOVE;
   }
   else{
    Serial.println("Out of bounds down");
    delay(1000);
    exit(0);
  }
  delay(DELAY);
}
void left(){
    printCoordinates();
  if( currentX - STEPS_PER_MOVE >= -30){
    Serial.println("Going left");
    if(isLastMoveRight){
      stepperMotorHorizontal.step(BUFFER_STEPS);
      isLastMoveRight = false;
    }
    stepperMotorHorizontal.step(STEPS_PER_MOVE);
    currentX -= STEPS_PER_MOVE;
  }
  else{
    Serial.println("Out of bounds left");
    delay(1000);
    exit(0);
  }
  delay(DELAY);
}
void overrideUp(){
  Serial.println("Override up");
      if(isLastMoveDown){
      stepperMotorVertical.step(-BUFFER_STEPS);
      isLastMoveDown = false;
    }
  stepperMotorVertical.step(-STEPS_PER_MOVE);
  delay(DELAY);
}
void overrideRight(){
  Serial.println("Override right");
      if(!isLastMoveRight){
      stepperMotorHorizontal.step(-BUFFER_STEPS);
      isLastMoveRight = true;
    }
  stepperMotorHorizontal.step(-STEPS_PER_MOVE);
  delay(DELAY);

}
void overrideDown(){
  Serial.println("Override down");
      if(!isLastMoveDown){
      stepperMotorVertical.step(BUFFER_STEPS);
      isLastMoveDown = true;
    }
  stepperMotorVertical.step(STEPS_PER_MOVE);
  delay(DELAY);
}

void overrideLeft(){
  Serial.println("Override left");
      if(isLastMoveRight){
      stepperMotorHorizontal.step(BUFFER_STEPS);
      isLastMoveRight = false;
    }
  stepperMotorHorizontal.step(STEPS_PER_MOVE);
  delay(DELAY);
}

void reset(){
  down();
  while( currentX > 0){
    left();
  }
//  for( int i = 0; i < 5; i++){
//    overrideLeft();
//  }
  overrideLeft();
  overrideLeft();
  for( int i = 0; i < 7; i++){
    down();
  }
  overrideRight();
  overrideRight();
//  while( currentY > 5*STEPS_PER_MOVE){
//    overrideUp();
//  }
//  overrideRight();
//  currentX = INITIAL_X;
//  currentY= INITIAL_Y;
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
      Serial.println("Invalid moveTo value.");
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
  m(6);
}

void charSpace()
{
  right();
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
  m(6);

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
  m(6); 
}

void E()
{
  d(6);
  d(1);
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
  m(9);
  d(6);
  d(6);
  m(6);
  
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
  m(6); 
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
  m(6);
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
  m(6); 
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
  m(6);
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
  m(6);
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
  m(6);
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
  m(6); 
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
  m(6);
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
  m(6);
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
  m(6); 
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
  m(6);
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
  m(6);
}

void drawCharacter(char c){
  Serial.println("Starting this char:");
  Serial.println(c);
  switch(c){
    case 'A':
      A();
      break;
    case 'B':
      B();
      break;
    case 'C':
      C();
      break;
    case 'D':
      D();
      break;
    case 'E':
      E();
      break;
    case 'F':
      drawF();
      break;
    case 'G':
      G();
      break;
    case 'H':
      H();
      break;
    case 'I':
      I();
      break;
    case 'J':
      J();
      break;
    case 'K':
      K();
      break;
    case 'L':
      L();
      break;
    case 'M':
      M();
      break;
    case 'N':
      N();
      break;
    case 'O':
      O();
      break;
    case 'P':
      P();
      break;
    case 'Q':
      Q();
      break;
    case 'R':
      R();
      break;
    case 'S':
      S();
      break;
    case 'T':
      T();
      break;
    case 'U':
      U();
      break;
    case 'V':
      V();
      break;
    case 'W':
      W();
      break;
    case 'X':
      X();
      break;
    case 'Y':
      Y();
      break;
    case 'Z':
      Z();
      break;
    case '!':
      bang();
      break;
    case '?':
      questionMark();
      break;
    case ' ':
      space();
      break;
  }
}

bool firstLineFits()
{
  int pixel_width = 0;
  for(int i = 0; i < sizeof(FIRST_LINE); i++){
    switch (FIRST_LINE[i]){
      case 'I': 
      case 'J':
      case 'L':
      case 'T':
      case 'X':
      case 'Y':
      case '?':
        pixel_width += 4;
        break;
       case 'M':
       case 'Q':
       case 'V':
       case 'W':
        pixel_width += 6;
        break;
       case '!':
       case ' ':
        pixel_width += 2;
        break;
       default:
        pixel_width += 5;
        break;
    }
  }
  Serial.println("The input string is this many pixels wide:");
  Serial.println(pixel_width - 1);
  Serial.println("The board is this many pixels wide:");
  Serial.println(X_REVS / PIXEL_SIZE);
  return (pixel_width - 1 < (X_REVS / PIXEL_SIZE));
}

bool secondLineFits()
{
  int pixel_width = 0;
  for(int i = 0; i < sizeof(SECOND_LINE); i++){
    switch (SECOND_LINE[i]){
      case 'I': 
      case 'J':
      case 'L':
      case 'T':
      case 'X':
      case 'Y':
      case '?':
        pixel_width += 4;
        break;
       case 'M':
       case 'Q':
       case 'V':
       case 'W':
        pixel_width += 6;
        break;
       case '!':
       case ' ':
        pixel_width += 2;
        break;
       default:
        pixel_width += 5;
        break;
    }
  }
  Serial.println("The input string is this many pixels wide:");
  Serial.println(pixel_width - 1);
  Serial.println("The board is this many pixels wide:");
  Serial.println(X_REVS / PIXEL_SIZE);
  return (pixel_width - 1 < (X_REVS / PIXEL_SIZE));
}
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
