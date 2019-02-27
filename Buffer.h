#ifndef BUFFER_H
#define BUFFER_H

#define WHITE 0       //down
#define YELLOW 1      //up
#define RED 2         //front
#define GREEN 3       //left
#define BLUE 4        //right
#define ORANGE 5      //back

#define CENTER 4
#define FACES 6
#define SQ_NB 9 


//folosesc functia asta sa convertesc din caractere in numere la citire
short chToNb (char ch)
{
    return (short)(ch - '0');
}

//folosesc functia asta sa afisez caractere cand afisez fetele 
char shToCh(short number) //short to ch ~ pentru afisare
{
    switch (number)
    {
        case WHITE:
            return 'W';
            break;

        case YELLOW:
            return 'Y';
            break;

        case RED:
            return 'R';
            break;

        case GREEN:
            return 'G';
            break;

        case BLUE:
            return 'B';
            break;

        case ORANGE:
            return 'O';
            break;
    
        default:
            return '-';
            break;
    }
}


class ReadingBuffer
{
    short size;
    short poz;
    short buff[20];
public:
    void init(int sz)
    {
        size = sz;
        poz = 0;
    }

    bool filled()
    {
        return (poz == size || poz == 19);
    }

    void readData()
    {
        if( !filled() && Serial.available() )
        {
            buff[poz++] = chToNb(Serial.read());
            int x; 
            x=poz-1;
            Serial.println(buff[x]);
        }
    }

    short* getBuffer()
    {
        return buff;
    }

    void reset()
    {
        poz = 0;
    }


};

#endif
