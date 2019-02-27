#ifndef CORNERS.H
#define CORNERS.H


class Corners
{
public:
    static void solveCorners (Cube& C, String& steps)
    {
        while (checkWhiteCorners(C) == false)
        {
            if (C.F[RED].sqr[8] == WHITE || C.F[WHITE].sqr[2] == WHITE || C.F[BLUE].sqr[6] == WHITE)
            {
                String moves;
                while (C.F[RED].sqr[2] == WHITE || C.F[YELLOW].sqr[8] == WHITE || C.F[BLUE].sqr[0] == WHITE)
                    {
                        C.upCW();
                        steps += "U";
                    }
                moves += "RURRR";
                steps += moves;
                Cross::execMoves(C, moves);
            }
            if (C.F[RED].sqr[6] == WHITE || C.F[WHITE].sqr[0] == WHITE || C.F[GREEN].sqr[8] == WHITE)
            {
                String moves;
                while (C.F[RED].sqr[0] == WHITE || C.F[YELLOW].sqr[6] == WHITE || C.F[GREEN].sqr[2] == WHITE)
                    {
                        C.upCW();
                        steps += "U";
                    }
                moves += "FUFFF";
                steps += moves;
                Cross::execMoves(C, moves);
            }
            if (C.F[BLUE].sqr[8] == WHITE || C.F[WHITE].sqr[8] == WHITE || C.F[ORANGE].sqr[6] == WHITE)
            {
                String moves;
                while (C.F[BLUE].sqr[2] == WHITE || C.F[ORANGE].sqr[0] == WHITE || C.F[YELLOW].sqr[2] == WHITE)
                    {
                        C.upCW();
                        steps += "U";
                    }
                moves += "BUBBB";
                steps += moves;
                Cross::execMoves(C, moves);
            }
            if (C.F[ORANGE].sqr[8] == WHITE || C.F[WHITE].sqr[6] == WHITE || C.F[GREEN].sqr[6] == WHITE)
            {
                String moves;
                while (C.F[ORANGE].sqr[2] == WHITE || C.F[YELLOW].sqr[0] == WHITE || C.F[GREEN].sqr[0] == WHITE)
                    {
                        C.upCW();
                        steps += "U";
                    }
                moves += "LULLL";
                steps += moves;
                Cross::execMoves(C, moves);
            }

        }

        while (checkBottom(C) == false)
        {
            String moves;
            if (C.F[YELLOW].sqr[8] == WHITE)
            {
                switch(C.F[RED].sqr[2])
                {
                case BLUE:
                    {
                        moves += "RUURRRUUURURRR";
                        break;
                    }
                case ORANGE:
                    {
                        moves += "UUUBUUBBBUUUBUBBB";
                        break;
                    }
                case GREEN:
                    {
                        moves += "UULUULLLUUULULLL";

                        break;
                    }
                case RED:
                    {
                        moves += "UFUUFFFUUUFUFFF";
                        break;
                    }
                }

            }
            else if (C.F[RED].sqr[2] == WHITE)
            {
                switch (C.F[YELLOW].sqr[8])
                {
                    case GREEN:
                    {
                     moves += "ULLLUUUL";
                     break;
                    }
                    case RED:
                    {
                     moves += "FFFUUUF";
                     break;
                    }
                    case BLUE:
                    {
                     moves += "UUURRRUUUR";
                     break;
                    }
                    case ORANGE:
                    {
                     moves += "UUBBBUUUB";
                     break;
                    }
                }
            }
            else if (C.F[BLUE].sqr[0] == WHITE)
            {
                switch(C.F[RED].sqr[2])
                {
                    case ORANGE:
                    {
                     moves += "UULULLL";
                     break;
                    }
                    case GREEN:
                    {
                     moves += "UFUFFF";
                     break;
                    }
                    case RED:
                    {
                     moves += "RURRR";
                     break;
                    }
                    case BLUE:
                    {
                     moves += "UUUBUBBB";
                     break;
                    }
                }
            }
            else
            {
                moves += "U";
            }
            steps += moves;
            Cross::execMoves(C, moves);
        }

    }

    static bool checkBottom (Cube& C)
    {
        if (C.F[WHITE].sqr[0] == WHITE && C.F[WHITE].sqr[2] == WHITE && C.F[WHITE].sqr[6] == WHITE && C.F[WHITE].sqr[8] == WHITE)
        {
          if (C.F[RED].sqr[6] == RED && C.F[RED].sqr[8] == RED && C.F[GREEN].sqr[6] == GREEN && C.F[GREEN].sqr[8] == GREEN && C.F[BLUE].sqr[6] == BLUE && C.F[BLUE].sqr[8] == BLUE &&C.F[ORANGE].sqr[6] == ORANGE && C.F[ORANGE].sqr[8] == ORANGE )
            return true;
        }
        return false;
    }

    static bool checkWhiteCorners (Cube& C)
    {
        if (!checkBottom(C))
        if (C.F[RED].sqr[6] == WHITE || C.F[RED].sqr[8] == WHITE || C.F[BLUE].sqr[6] == WHITE || C.F[BLUE].sqr[8] == WHITE || C.F[GREEN].sqr[6] == WHITE || C.F[GREEN].sqr[8] == WHITE || C.F[ORANGE].sqr[6] == WHITE || C.F[ORANGE].sqr[8] == WHITE)
        return false;
        else
          if (C.F[WHITE].sqr[0] == WHITE || C.F[WHITE].sqr[2] == WHITE || C.F[WHITE].sqr[6] == WHITE ||C.F[WHITE].sqr[8] == WHITE)
            return false;
          else  return true;
        return true;
    }

};

#endif
