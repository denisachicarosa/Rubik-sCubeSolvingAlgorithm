
#include "ClassFace.h"
#include "ClassCube.h"
#include "Buffer.h"
#include "Cross.h"
#include "Corners.h"
#include "Edges.h"
#include "YellowFace.h"
#include "LastLayerPermutation.h"
#define V0_PIN 9 // PWN in loc de POTENTIOMETRU


#include <LiquidCrystal.h>

#define BUTTONPIN 19
#define LEDGREEN 28
#define LEDWHITE 22
#define LEDYELLOW 24
#define LEDRED 26
#define LEDBLUE 30
#define LEDORANGE 32


LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int buttonsPin[6] = {14, 15, 16, 17, 18, 19};
bool getInput = false;
bool cubeSolved = false;
bool doneReading = false;
bool algoritm = false;
bool transferStrToChr = false;
unsigned long currentTime;
unsigned long lastTime;
unsigned long difference;
String steps;
int nextMove = 0;
int buttonState = 0;
char moves[150];
Cube C;



void minimizeMoves (String& steps)
{
    bool movesChanged = false;
    int i = 0;
    do
    {
        movesChanged = false;
        if (steps.length() > i + 3)
        {
            if (steps[i] == steps[i + 1] && steps[i] == steps[i + 2] && steps[i] == steps[i + 3])
            {
                steps.remove(i, 4);
                movesChanged = true;
            }
        }
        if (steps.length() > i + 2 )
            if (steps[i] == steps[i + 1] && steps[i] == steps[i + 2])
            {
                steps.remove(i, 2);
                steps[i] += 32;
                movesChanged = true;
            }
        if (i < steps.length())
          i++;
        else
          i = 0;
    }
    while (i < steps.length());
}

int getColor()
{
  int b;
  int state;
  for (b = 0; b < 6; b++)
    {
      state = digitalRead(buttonsPin [b]);
      if (state == true)
      {
        currentTime = millis();
        if (currentTime - lastTime >= 50)
          {
            lastTime = currentTime;
            return b;
          }
      }
    }
}

bool input() 
{
  if(!C.readData())
    if(doneReading == false)
    {
      Serial.println("CUBE FILLED !");
      doneReading = true;
      return true;
     }
  return false;
}


void done()
{
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Cube solved!");
}


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(2, 0);  // 2 = a cata casuta din linie sa fie aprinsa
                        // 1 = pe a cata linie ne pozitionam; 0 = prima linie, 1 = a doua linie
  pinMode(V0_PIN, OUTPUT); // PWN in loc de POTENTIOMETRU
  analogWrite(V0_PIN, 90); // PWN in loc de POTENTIOMETRU
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDWHITE, OUTPUT);
  pinMode(LEDYELLOW, OUTPUT);
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDBLUE, OUTPUT);
  pinMode(LEDORANGE, OUTPUT);
  pinMode(BUTTONPIN, INPUT);
  
  nextMove = 0;
  lastTime = millis();
}

void writeLCD (int i)
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print(moves[i]);
  lcd.setCursor(2, 1);  // 2 = a cata casuta din linie sa fie aprinsa
                        // 1 = pe a cata linie ne pozitionam; 0 = prima linie, 1 = a doua linie
  lcd.print(" Press Next ");
  delay(2000);
}

void loop() {
  while(!doneReading) input();
    
  if (algoritm == false)
  {
    Cross::solveCross(C, steps);
    Corners::solveCorners(C, steps);
    Edges::solveEdges(C, steps);
    YellowFace::solveYellowCross(C, steps);
    YellowFace::solveCorners(C, steps);
    LastLayerPermutation::solveLastLayerCorners(C, steps);
    LastLayerPermutation::solveLayer(C, steps);
    minimizeMoves(steps);
    algoritm = true;
  }

  if (transferStrToChr == false)
  {
    steps.toCharArray(moves, steps.length() + 1);
    transferStrToChr = true;
  }

  if (nextMove != steps.length() )
  {
    writeLCD(nextMove);
    buttonState = digitalRead(BUTTONPIN);
    if (buttonState == HIGH)
    {
      writeLCD(nextMove);
      nextMove++;
    }
    
    digitalWrite(LEDWHITE, buttonState);
  }
  if (nextMove == steps.length())
    cubeSolved = true;
}
