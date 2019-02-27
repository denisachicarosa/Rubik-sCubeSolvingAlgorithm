#ifndef   LASTLAYERPERMUTATION .H
#define   LASTLAYERPERMUTATION .H


class LastLayerPermutation
{
public:
    static bool checkCorners (Cube& C)
    {
        if (C.F[RED].sqr[0] == RED && C.F[RED].sqr[2] == RED && C.F[GREEN].sqr[0] == GREEN && C.F[GREEN].sqr[2] == GREEN && C.F[BLUE].sqr[0] == BLUE && C.F[BLUE].sqr[2] == BLUE && C.F[ORANGE].sqr[0] == ORANGE && C.F[ORANGE].sqr[2] == ORANGE)
            return true;
        return false;
    }
    static int getState (Cube& C)
    {
        if (C.F[RED].sqr[0] == C.F[RED].sqr[2])
            return 1;
        else if (C.F[GREEN].sqr[0] == C.F[GREEN].sqr[2])
            return 2;
        else if (C.F[BLUE].sqr[0] == C.F[BLUE].sqr[2])
            return 3;
        else if (C.F[ORANGE].sqr[0] == C.F[ORANGE].sqr[2])
            return 4;
        else return 0;
    }

    static bool permute (Cube& C, String& steps)
    {
        if (checkCorners(C))
            return true;
        else
        {
            String moves = "U";
            Cross::execMoves(C,moves);
            steps += moves;
            if (checkCorners(C)) return true;
            else
            {
                Cross::execMoves(C,moves);
                steps += moves;

                if (checkCorners(C)) return true;
                else
                {
                    Cross::execMoves(C,moves);
                    steps += moves;

                    if (checkCorners(C)) return true;
                    else
                    {
                        Cross::execMoves(C,moves);
                        steps += moves;

                        return false;
                    }
                }
            }
        }
    }

    static void solveLastLayerCorners (Cube& C, String& steps)
    {
        while (!permute(C,steps))
        {
            int state = getState(C);
            String moves;
            switch (state)
            {
                case 1:
                {
                 moves += "RBBBRFFRRRBRFFRR";
                 break;
                }
                case 2:
                {
                 moves += "UUURBBBRFFRRRBRFFRR";
                 break;
                }
                case 3:
                {
                 moves += "URBBBRFFRRRBRFFRR";
                 break;
                }
                case 4:
                {
                 moves += "UURBBBRFFRRRBRFFRR";
                 break;
                }
                case 0:
                {
                 moves += "RBBBRFFRRRBRFFRR";
                 break;
                }
            }

            steps += moves;
            Cross::execMoves(C, moves);
        }
    }

    static int findSolvedFace (Cube& C)
    {
        if (C.F[RED].sqr[0] == C.F[RED].sqr[1] && C.F[RED].sqr[1] == C.F[RED].sqr[2])
            return 1;
        else if (C.F[GREEN].sqr[0] == C.F[GREEN].sqr[1] && C.F[GREEN].sqr[1] == C.F[GREEN].sqr[2])
            return 2;
        else if (C.F[BLUE].sqr[0] == C.F[BLUE].sqr[1] && C.F[BLUE].sqr[1] == C.F[BLUE].sqr[2])
            return 3;
        else if (C.F[ORANGE].sqr[0] == C.F[ORANGE].sqr[1] && C.F[ORANGE].sqr[1] == C.F[ORANGE].sqr[2])
            return 4;
        else return 0;
    }

    static bool checkAll (Cube& C)
    {
        int i;
        for (i = 0; i < 6; i++)
            if (C.F[i].sqr[0] != C.F[i].sqr[1] || C.F[i].sqr[1] != C.F[i].sqr[2])
            return false;
        return true;
    }

    static int checkCase (Cube& C)
    {
        if (C.F[ORANGE].sqr[0] == C.F[ORANGE].sqr[1] && C.F[ORANGE].sqr[0] == C.F[ORANGE].sqr[3])
            return 0;
        if (C.F[GREEN].sqr[0] == C.F[GREEN].sqr[1] && C.F[GREEN].sqr[0] == C.F[GREEN].sqr[3])
            return 1;
        if (C.F[RED].sqr[0] == C.F[RED].sqr[1] && C.F[RED].sqr[0] == C.F[RED].sqr[3])
            return 2;
        if (C.F[BLUE].sqr[0] == C.F[BLUE].sqr[1] && C.F[BLUE].sqr[0] == C.F[BLUE].sqr[3])
            return 3;
        return 4;
    }

    static void solveLayer (Cube& C, String& steps)
    {
        while (!checkAll(C))
        {
            int state;
            String moves;
            state = checkCase(C);
            switch (state)
            {
                case 0:
                {
                    moves += "RUUURURURUUURRRUUURR";
                    break;
                }
                case 1:
                {
                    moves += "URUUURURURUUURRRUUURR";
                    break;
                }
                case 2:
                {
                    moves += "UURUUURURURUUURRRUUURR";
                    break;
                }
                case 3:
                {
                    moves += "UUURUUURURURUUURRRUUURR";
                    break;
                }
                case 4:
                {
                    moves += "RUUURURURUUURRRUUURR";
                    break;
                }
            }
        Cross::execMoves(C, moves);
        steps += moves;
        }
        while (C.F[RED].sqr[0] != RED )
        {
            String moves;
            moves += "U";
            steps += moves;
            Cross::execMoves(C,moves);
        }

    }
};



#endif
