#ifndef YELLOWFACE.H
#define YELLOWFACE.H

class YellowFace
{
public:
    static bool checkCross (Cube& C)
    {
        if (C.F[YELLOW].sqr[1] == YELLOW && C.F[YELLOW].sqr[3] == YELLOW && C.F[YELLOW].sqr[5] == YELLOW && C.F[YELLOW].sqr[7] == YELLOW)
            return true;
        return false;
    }

    static int getStateCross (Cube& C)
    {
        if (C.F[YELLOW].sqr[1] == YELLOW && C.F[YELLOW].sqr[3] == YELLOW)
            return 1;
        else if (C.F[YELLOW].sqr[3] == YELLOW && C.F[YELLOW].sqr[5] == YELLOW)
            return 2;
        else if (C.F[YELLOW].sqr[1] == YELLOW && C.F[YELLOW].sqr[5] == YELLOW)
            return 3;
        else if (C.F[YELLOW].sqr[5] == YELLOW && C.F[YELLOW].sqr[7] == YELLOW)
            return 4;
        else if (C.F[YELLOW].sqr[3] == YELLOW && C.F[YELLOW].sqr[7] == YELLOW)
            return 5;
        else if (C.F[YELLOW].sqr[1] == YELLOW && C.F[YELLOW].sqr[7] == YELLOW)
            return 6;
        else return 0;
    }

    static void solveYellowCross (Cube& C, String& steps)
    {
        while (!checkCross(C))
        {
            String moves;
            int state = getStateCross(C);
            switch (state)
            {
                case 1:
                {
                    moves += "FURUUURRRFFF";
                    break;
                }
                case 2:
                {
                    moves += "FRURRRUUUFFF";
                    break;
                }

                case 3:
                {
                    moves += "UUUFURUUURRRFFF";
                    break;
                }
                case 4:
                {
                    moves += "UUFURUUURRRFFF";
                    break;
                }
                case 5:
                {
                    moves += "UFURUUURRRFFF";
                    break;
                }
                case 6:
                {
                    moves += "UFRURRRUUUFFF";
                    break;
                }
                case 0:
                {
                     moves += "FRURRRUUUFFF";
                     break;
                }
            }

            steps += moves;
            Cross::execMoves(C, moves);
        }
    }

    static bool checkCorners (Cube& C)
    {
        if (C.F[YELLOW].sqr[0] == YELLOW && C.F[YELLOW].sqr[2] == YELLOW && C.F[YELLOW].sqr[6] == YELLOW && C.F[YELLOW].sqr[8] == YELLOW)
            return true;
        return false;
    }

    static int getCornerState (Cube& C)
    {
        if (C.F[YELLOW].sqr[8] == YELLOW)
            return 0;
        else if (C.F[RED].sqr[2] == YELLOW)
            return 1;
        else if (C.F[BLUE].sqr[0] == YELLOW)
            return 2;
    }

    static void solveCorners(Cube& C, String& steps)
    {
        while (!checkCorners(C))
        {
            int state = getCornerState(C);
            String moves;
            switch (state)
            {
                case 0:
                {
                    moves += "U";
                    break;
                }
                case 1:
                {
                    moves += "RRRDRDDDRRRDRDDD";
                    break;
                }
                case 2:
                {
                    moves += "DRRRDDDRDRRRDDDR";
                    break;
                }
            }
            steps += moves;
            Cross::execMoves (C, moves);
        }
    }
};

#endif
