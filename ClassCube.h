#ifndef CLASSCUBE_H
#define CLASSCUBE_H

#include "ClassFace.h"
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

class Cube 
{
  public:
    Face F[FACES];
    ReadingBuffer buff;
    short filled[FACES];  ///vector care spune ce fata am citit          

    Cube()
    {
        for (int  i = 0; i < FACES; i++)
            filled[i] = false;
        
        buff.init(SQ_NB);
    }

    bool readData()         //functia returneaza true daca inca nu a citit toate datele din cub
    {
        if (cubeFilled()) return false;  // daca cubul e plin, nu mai citesc date
        
        buff.readData();
        if (buff.filled())
        {
            setFaces(buff.getBuffer());
            buff.reset();
        }
        return true;
    }

    short setFaces(short data[])
    {
        if (!filled[data[CENTER]]) //daca nu am citit fata cu indicele in centrul setului de data
            filled[data[CENTER]] = true;
        else return FACES;          //nu returnez -1, ci 6 pentru eroare. idk if needed

        
        F[data[CENTER]].fillColors(data);
        F[data[CENTER]].afisFace();

        return data[CENTER];
        
    }

    void printFace()
    {
        for (int i = 0; i < FACES; i++)
            F[i].afisFace();
        Serial.println();
    }

    bool cubeFilled()
    {
        for (int i = 0; i < FACES; i++)
            if (filled[i] == false) return false;
        return true;
    }
    
    void upCW ()
    {
      F[YELLOW].rotateCW ();

      int r0, r1, r2;
      r0 = F[RED].sqr[0];
      r1 = F[RED].sqr[1];
      r2 = F[RED].sqr[2];

      //RED FACE UPDATE
      F[RED].sqr[0] = F[BLUE].sqr[0];
      F[RED].sqr[1] = F[BLUE].sqr[1];
      F[RED].sqr[2] = F[BLUE].sqr[2];

      //BLUE FACE UPDATE
      F[BLUE].sqr[0] = F[ORANGE].sqr[0];
      F[BLUE].sqr[1] = F[ORANGE].sqr[1];
      F[BLUE].sqr[2] = F[ORANGE].sqr[2];

      //ORANGE FACE UPDATE
      F[ORANGE].sqr[0] = F[GREEN].sqr[0];
      F[ORANGE].sqr[1] = F[GREEN].sqr[1];
      F[ORANGE].sqr[2] = F[GREEN].sqr[2];

      //GREEN FACE UPDATE
      F[GREEN].sqr[0] = r0;
      F[GREEN].sqr[1] = r1;
      F[GREEN].sqr[2] = r2;
    }
    
    void downCW ()
    {
      F[WHITE].rotateCW ();

      int r6, r7, r8;
      r6 = F[RED].sqr[6];
      r7 = F[RED].sqr[7];
      r8 = F[RED].sqr[8];

      //RED FACE UPDATE
      F[RED].sqr[6] = F[GREEN].sqr[6];
      F[RED].sqr[7] = F[GREEN].sqr[7];
      F[RED].sqr[8] = F[GREEN].sqr[8];

      //GREEN FACE UPDATE
      F[GREEN].sqr[6] = F[ORANGE].sqr[6];
      F[GREEN].sqr[7] = F[ORANGE].sqr[7];
      F[GREEN].sqr[8] = F[ORANGE].sqr[8];

      //ORANGE FACE UPDATE
      F[ORANGE].sqr[6] = F[BLUE].sqr[6];
      F[ORANGE].sqr[7] = F[BLUE].sqr[7];
      F[ORANGE].sqr[8] = F[BLUE].sqr[8];

      //BLUE FACE UPDATE
      F[BLUE].sqr[6] = r6;
      F[BLUE].sqr[7] = r7;
      F[BLUE].sqr[8] = r8;
    }
    
    void leftCW ()
    {
      F[GREEN].rotateCW ();
      // THE OTHER FACES
      int r0, r3, r6;
      r0 = F[RED].sqr[0];
      r3 = F[RED].sqr[3];
      r6 = F[RED].sqr[6];

      //RED FACE UPDATE
      F[RED].sqr[0] = F[YELLOW].sqr[0];
      F[RED].sqr[3] = F[YELLOW].sqr[3];
      F[RED].sqr[6] = F[YELLOW].sqr[6];

      //YELLOW FACE UPDATE
      F[YELLOW].sqr[0] = F[ORANGE].sqr[8];
      F[YELLOW].sqr[3] = F[ORANGE].sqr[5];
      F[YELLOW].sqr[6] = F[ORANGE].sqr[2];

      //ORANGE FACE UPDATE
      F[ORANGE].sqr[2] = F[WHITE].sqr[6];
      F[ORANGE].sqr[5] = F[WHITE].sqr[3];
      F[ORANGE].sqr[8] = F[WHITE].sqr[0];

      //WHITE FACE UPDATE
      F[WHITE].sqr[0] = r0;
      F[WHITE].sqr[3] = r3;
      F[WHITE].sqr[6] = r6;
    }
    
    void rightCW ()
    {
      F[BLUE].rotateCW ();

      int r2, r5, r8;
      r2 = F[RED].sqr[2];
      r5 = F[RED].sqr[5];
      r8 = F[RED].sqr[8];

      //RED FACE UPDATE
      F[RED].sqr[2] = F[WHITE].sqr[2];
      F[RED].sqr[5] = F[WHITE].sqr[5];
      F[RED].sqr[8] = F[WHITE].sqr[8];

      //WHITE FACE UPDATE
      F[WHITE].sqr[2] = F[ORANGE].sqr[6];
      F[WHITE].sqr[5] = F[ORANGE].sqr[3];
      F[WHITE].sqr[8] = F[ORANGE].sqr[0];

      //ORANGE FACE UPDATE
      F[ORANGE].sqr[0] = F[YELLOW].sqr[8];
      F[ORANGE].sqr[3] = F[YELLOW].sqr[5];
      F[ORANGE].sqr[6] = F[YELLOW].sqr[2];

      //YELLOW FACE UPDATE
      F[YELLOW].sqr[2] = r2;
      F[YELLOW].sqr[5] = r5;
      F[YELLOW].sqr[8] = r8;
    }
    
    void frontCW ()
    {

      F[RED].rotateCW ();

      int y6, y7, y8;
      y6 = F[YELLOW].sqr[6];
      y7 = F[YELLOW].sqr[7];
      y8 = F[YELLOW].sqr[8];

      //YELLOW FACE UPDATE
      F[YELLOW].sqr[6] = F[GREEN].sqr[8];
      F[YELLOW].sqr[7] = F[GREEN].sqr[5];
      F[YELLOW].sqr[8] = F[GREEN].sqr[2];

      //GREEN FACE UPDATE
      F[GREEN].sqr[2] = F[WHITE].sqr[0];
      F[GREEN].sqr[5] = F[WHITE].sqr[1];
      F[GREEN].sqr[8] = F[WHITE].sqr[2];

      //WHITE FACE UPDATE
      F[WHITE].sqr[0] = F[BLUE].sqr[6];
      F[WHITE].sqr[1] = F[BLUE].sqr[3];
      F[WHITE].sqr[2] = F[BLUE].sqr[0];

      //BLUE FACE UPDATE
      F[BLUE].sqr[0] = y6;
      F[BLUE].sqr[3] = y7;
      F[BLUE].sqr[6] = y8;
    }

    void backCW ()
    {
      F[ORANGE].rotateCW ();

      int y0, y1, y2;
      y0 = F[YELLOW].sqr[0];
      y1 = F[YELLOW].sqr[1];
      y2 = F[YELLOW].sqr[2];

      //YELLOW FACE UPDATE
      F[YELLOW].sqr[0] = F[BLUE].sqr[2];
      F[YELLOW].sqr[1] = F[BLUE].sqr[5];
      F[YELLOW].sqr[2] = F[BLUE].sqr[8];

      //BLUE FACE UPDATE
      F[BLUE].sqr[2] = F[WHITE].sqr[8];
      F[BLUE].sqr[5] = F[WHITE].sqr[7];
      F[BLUE].sqr[8] = F[WHITE].sqr[6];

      //WHITE FACE UPDATE
      F[WHITE].sqr[6] = F[GREEN].sqr[0];
      F[WHITE].sqr[7] = F[GREEN].sqr[3];
      F[WHITE].sqr[8] = F[GREEN].sqr[6];

      //GREEN FACE UPDATE
      F[GREEN].sqr[0] = y2;
      F[GREEN].sqr[3] = y1;
      F[GREEN].sqr[6] = y0;
    }

    void upCCW ()
    {
      F[YELLOW].rotateCCW ();

      int r0, r1, r2;
      r0 = F[RED].sqr[0];
      r1 = F[RED].sqr[1];
      r2 = F[RED].sqr[2];

      //RED FACE UPDATE
      F[RED].sqr[0] = F[GREEN].sqr[0];
      F[RED].sqr[1] = F[GREEN].sqr[1];
      F[RED].sqr[2] = F[GREEN].sqr[2];

      //BLUE FACE UPDATE
      F[GREEN].sqr[0] = F[ORANGE].sqr[0];
      F[GREEN].sqr[1] = F[ORANGE].sqr[1];
      F[GREEN].sqr[2] = F[ORANGE].sqr[2];

      //ORANGE FACE UPDATE
      F[ORANGE].sqr[0] = F[BLUE].sqr[0];
      F[ORANGE].sqr[1] = F[BLUE].sqr[1];
      F[ORANGE].sqr[2] = F[BLUE].sqr[2];

      //BLUE FACE UPDATE
      F[BLUE].sqr[0] = r0;
      F[BLUE].sqr[1] = r1;
      F[BLUE].sqr[2] = r2;
    }

    void downCCW ()
    {
      F[WHITE].rotateCCW ();

      int r6, r7, r8;
      r6 = F[RED].sqr[6];
      r7 = F[RED].sqr[7];
      r8 = F[RED].sqr[8];

      //RED FACE UPDATE
      F[RED].sqr[6] = F[BLUE].sqr[6];
      F[RED].sqr[7] = F[BLUE].sqr[7];
      F[RED].sqr[8] = F[BLUE].sqr[8];

      //BLUE FACE UPDATE
      F[BLUE].sqr[6] = F[ORANGE].sqr[6];
      F[BLUE].sqr[7] = F[ORANGE].sqr[7];
      F[BLUE].sqr[8] = F[ORANGE].sqr[8];

      //ORANGE FACE UPDATE
      F[ORANGE].sqr[6] = F[GREEN].sqr[6];
      F[ORANGE].sqr[7] = F[GREEN].sqr[7];
      F[ORANGE].sqr[8] = F[GREEN].sqr[8];

      //GREEN FACE UPDATE
      F[GREEN].sqr[6] = r6;
      F[GREEN].sqr[7] = r7;
      F[GREEN].sqr[8] = r8;
    }

    void leftCCW ()
    {
      F[GREEN].rotateCCW ();

      int r0, r3, r6;
      r0 = F[RED].sqr[0];
      r3 = F[RED].sqr[3];
      r6 = F[RED].sqr[6];

      //RED FACE UPDATE
      F[RED].sqr[0] = F[WHITE].sqr[0];
      F[RED].sqr[3] = F[WHITE].sqr[3];
      F[RED].sqr[6] = F[WHITE].sqr[6];

      //WHITE FACE UPDATE
      F[WHITE].sqr[0] = F[ORANGE].sqr[8];
      F[WHITE].sqr[3] = F[ORANGE].sqr[5];
      F[WHITE].sqr[6] = F[ORANGE].sqr[2];

      //ORANGE FACE UPDATE
      F[ORANGE].sqr[2] = F[YELLOW].sqr[2];
      F[ORANGE].sqr[5] = F[YELLOW].sqr[3];
      F[ORANGE].sqr[8] = F[YELLOW].sqr[0];

      //YELLOW FACE UPDATE
      F[YELLOW].sqr[0] = r0;
      F[YELLOW].sqr[3] = r3;
      F[YELLOW].sqr[6] = r6;

    }
    
    void rightCCW ()
    {
      F[BLUE].rotateCCW ();

      int r2, r5, r8;
      r2 = F[RED].sqr[2];
      r5 = F[RED].sqr[5];
      r8 = F[RED].sqr[8];

      //RED FACE UPDATE
      F[RED].sqr[2] = F[YELLOW].sqr[2];
      F[RED].sqr[5] = F[YELLOW].sqr[5];
      F[RED].sqr[8] = F[YELLOW].sqr[8];

      //YELLOW FACE UPDATE
      F[YELLOW].sqr[2] = F[ORANGE].sqr[6];
      F[YELLOW].sqr[5] = F[ORANGE].sqr[3];
      F[YELLOW].sqr[8] = F[ORANGE].sqr[0];

      //ORANGE FACE UPDATE
      F[ORANGE].sqr[0] = F[WHITE].sqr[8];
      F[ORANGE].sqr[3] = F[WHITE].sqr[5];
      F[ORANGE].sqr[6] = F[WHITE].sqr[2];

      //WHITE FACE UPDATE
      F[WHITE].sqr[2] = r2;
      F[WHITE].sqr[5] = r5;
      F[WHITE].sqr[8] = r8;
    }
    
    void backCCW ()
    {
      F[ORANGE].rotateCCW ();

      int y0, y1, y2;
      y0 = F[YELLOW].sqr[0];
      y1 = F[YELLOW].sqr[1];
      y2 = F[YELLOW].sqr[2];

      //YELLOW FACE UPDATE
      F[YELLOW].sqr[0] = F[GREEN].sqr[6];
      F[YELLOW].sqr[1] = F[GREEN].sqr[3];
      F[YELLOW].sqr[2] = F[GREEN].sqr[0];

      //GREEN FACE UPDATE
      F[GREEN].sqr[0] = F[WHITE].sqr[6];
      F[GREEN].sqr[3] = F[WHITE].sqr[7];
      F[GREEN].sqr[6] = F[WHITE].sqr[8];

      //WHITE FACE UPDATE
      F[WHITE].sqr[6] = F[BLUE].sqr[8];
      F[WHITE].sqr[7] = F[BLUE].sqr[5];
      F[WHITE].sqr[8] = F[BLUE].sqr[2];

      //BLUE FACE UPDATE
      F[BLUE].sqr[2] = y0;
      F[BLUE].sqr[5] = y1;
      F[BLUE].sqr[8] = y2;
    }
    
    void frontCCW ()
    {
      F[RED].rotateCCW ();

      int y6, y7, y8;
      y6 = F[YELLOW].sqr[6];
      y7 = F[YELLOW].sqr[7];
      y8 = F[YELLOW].sqr[8];

      //YELLOW FACE UPDATE
      F[YELLOW].sqr[6] = F[BLUE].sqr[0];
      F[YELLOW].sqr[7] = F[BLUE].sqr[3];
      F[YELLOW].sqr[8] = F[BLUE].sqr[6];

      //BLUE FACE UPDATE
      F[BLUE].sqr[0] = F[WHITE].sqr[2];
      F[BLUE].sqr[3] = F[WHITE].sqr[1];
      F[BLUE].sqr[6] = F[WHITE].sqr[0];

      //WHITE FACE UPDATE
      F[WHITE].sqr[0] = F[GREEN].sqr[2];
      F[WHITE].sqr[1] = F[GREEN].sqr[5];
      F[WHITE].sqr[2] = F[GREEN].sqr[8];

      //GREEN FACE UPDATE
      F[GREEN].sqr[2] = y8;
      F[GREEN].sqr[5] = y7;
      F[GREEN].sqr[8] = y6;
    }
    
};

#endif
