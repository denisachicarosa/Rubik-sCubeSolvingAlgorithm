
#ifndef CLASSFACE_H
#define CLASSFACE_H

#include "Buffer.h"


#define WHITE 0       //down
#define YELLOW 1      //up
#define RED 2         //front
#define GREEN 3       //left
#define BLUE 4        //right
#define ORANGE 5      //back

#define CENTER 4
#define FACES 6
#define SQ_NB 9 




class Face 
{
  public:
    short sqr[SQ_NB];           //folosesc short ca sa economisesc memorie
    short color;  
    int up, down, left, right;  //  fetele care se modifica la o rotire a fetei curente
    Face()
    {
        for (int i = 0; i < SQ_NB; i++)
            sqr[i] = -1;
        color = -1;     
    }
    
    int fillColors (short col[])
    {
        color = col[CENTER];
        for (int i = 0; i < SQ_NB; i++ )
            sqr[i] = col[i];
        switch (color)
        {
          case WHITE:
          {
            down = ORANGE;
            up = RED;
            left = GREEN;
            right = BLUE;
            break;
          }
          case YELLOW:
          {
            down = RED;
            up = ORANGE;
            left = GREEN;
            right = BLUE;
            break;
          }
          case RED:
          {
            down = WHITE;
            up = YELLOW;
            left = GREEN;
            right = BLUE;
            break;
          }
          case GREEN:
          {
            down = WHITE;
            up = YELLOW;
            left = ORANGE;
            right = RED;
            break;
          }
          case BLUE:
          {
            down = WHITE;
            up = YELLOW;
            left = RED;
            right = ORANGE;
            break;
          }
        }
    }

    void afisFace() 
    {
        for (int  i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3;j++)
                    Serial.print (shToCh (sqr[ 3 * i + j]));
                Serial.println();   
            }
    }
    void copyFace(Face f)
    {
      for(int i = 0; i < SQ_NB; i++)
        sqr[i] = f.sqr[i];
    }

    void rotateCW()
    {
      short newColors[SQ_NB];
      newColors[0] = sqr[6];
      newColors[1] = sqr[3];
      newColors[2] = sqr[0];
      newColors[3] = sqr[7];
      newColors[4] = sqr[4];
      newColors[5] = sqr[1];
      newColors[6] = sqr[8];
      newColors[7] = sqr[5];
      newColors[8] = sqr[2];
      for (int i = 0 ; i < SQ_NB; i++)
        sqr[i] = newColors[i];
    }

    void rotateCCW()
    {
      short newColors[SQ_NB];
      newColors[0] = sqr[2];
      newColors[1] = sqr[5];
      newColors[2] = sqr[8];
      newColors[3] = sqr[1];
      newColors[4] = sqr[4];
      newColors[5] = sqr[7];
      newColors[6] = sqr[0];
      newColors[7] = sqr[3];
      newColors[8] = sqr[6];
      for (int i = 0 ; i < SQ_NB; i++)
        sqr[i] = newColors[i];
    }
};

#endif
