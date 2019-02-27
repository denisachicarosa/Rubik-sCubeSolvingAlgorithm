
#ifndef CROSS.H
#define CROSS.H


class Cross
{
  public:
  static bool checkCross  (Cube& C)
  {
    if (C.F[WHITE].sqr[1] == WHITE && C.F[WHITE].sqr[3] == WHITE && C.F[WHITE].sqr[5] == WHITE && C.F[WHITE].sqr[7] == WHITE)
      if (C.F[ORANGE].sqr[7] == ORANGE && C.F[BLUE].sqr[7] == BLUE && C.F[RED].sqr[7] == RED && C.F[GREEN].sqr[7] == GREEN)
        return true;
    return false;
  }
  static void solveCross (Cube& C, String& steps)
  {
    while (!checkCross(C))
        {
            solveEdge(C, steps);
        }
  }

  static void solveEdge (Cube& C, String& steps)
  {

    for (int side = 0; side < FACES; side++)
        for (int edge = 1; edge <9; edge += 2)
        {
            String moves;
            if ( C.F[side].sqr[edge] == WHITE)
            {
                //Solve edge
                switch (side)
                {
                case WHITE: // white square on the white side
                    {
                        if (edge == 1) //red side
                        {
                            switch (C.F[RED].sqr[7])
                            {
                                case ORANGE:
                                    moves += "DD";
                                    break;
                                case BLUE:
                                    moves += "DDD";
                                    break;
                                case GREEN:
                                    moves += "D";
                                    break;
                            }
                        }
                        if (edge == 3) //green side
                        {
                            switch (C.F[GREEN].sqr[7])
                            {
                                case RED:
                                    moves += "D";
                                    break;
                                case BLUE:
                                    moves += "DD";
                                    break;
                                case ORANGE:
                                    moves += "DDD";
                                    break;
                            }
                        }
                        if (edge == 5) //blue side
                        {
                            switch (C.F[BLUE].sqr[7])
                            {
                                case RED:
                                    moves += "DDD";
                                    break;
                                case ORANGE:
                                    moves += "D";
                                    break;
                                case GREEN:
                                    moves += "DD";
                                    break;
                            }
                        }
                        if (edge == 7) //orange side
                        {
                            switch (C.F[ORANGE].sqr[7])
                            {
                                case BLUE:
                                    moves += "D";
                                    break;
                                case RED:
                                    moves +="DD";
                                case GREEN:
                                    moves +="DDD";
                                    break;
                            }
                        }
                        break;
                    }
                case YELLOW: // white square on the yellow side
                    {
                        if (edge == 1) //orange side
                        {
                            switch (C.F[ORANGE].sqr[1])
                            {
                                case ORANGE:
                                    moves += "BB";
                                    break;
                                case GREEN:
                                    moves += "ULL";
                                    break;
                                case BLUE:
                                    moves += "URR";
                                    break;
                                case RED:
                                    moves += "UUFF";
                                    break;
                            }
                        }
                        if (edge == 3) //green side
                        {
                            switch (C.F[GREEN].sqr[1])
                            {
                                case GREEN:
                                    moves += "LL";
                                    break;
                                case RED:
                                    moves += "UUUFF";
                                    break;
                                case BLUE:
                                    moves += "UURR";
                                    break;
                                case ORANGE:
                                    moves += "UBB";
                                    break;
                            }
                        }
                        if (edge == 5) //blue side
                        {
                            switch (C.F[BLUE].sqr[1])
                            {
                                case BLUE:
                                    moves += "RR";
                                    break;
                                case RED:
                                    moves += "UFF";
                                    break;
                                case GREEN:
                                    moves += "UULL";
                                    break;
                                case ORANGE:
                                    moves += "UUUBB";
                            }
                        }
                        if (edge == 7) //red face
                        {
                            switch (C.F[RED].sqr[1])
                            {
                                case RED:
                                    moves += "FF";
                                    break;
                                case BLUE:
                                    moves += "UUURR";
                                    break;
                                case ORANGE:
                                    moves += "UUBB";
                                    break;
                                case GREEN:
                                    moves += "ULL";
                                    break;
                            }
                        }
                        break;
                    }
                case RED: //white square on the red side
                    {
                        if(edge == 1) //yellow side
                        {
                            switch (C.F[YELLOW].sqr[7])
                            {
                                case RED:
                                    moves += "UUURRRFR";
                                    break;
                                case BLUE:
                                    moves += "UUBBBRB";
                                    break;
                                case ORANGE:
                                    moves += "ULLLBL";
                                    break;
                                case GREEN:
                                    moves += "FFFLF";
                                    break;
                            }
                        }
                        if (edge == 3) //green side
                        {
                            switch (C.F[GREEN].sqr[5])
                            {
                                case RED:
                                    moves += "FUUURRRFR";
                                    break;
                                case BLUE:
                                    moves += "FUUBBBRBFFF";
                                    break;
                                case ORANGE:
                                    moves += "FULLLBLFFF";
                                    break;
                                case GREEN:
                                    moves += "L";
                                    break;
                            }
                        }
                        if (edge == 5) //blue side
                        {
                            switch (C.F[BLUE].sqr[3])
                            {
                                case RED :
                                    moves += "FFFUUURRRFR";
                                    break;
                                case BLUE:
                                    moves += "RRR";
                                    break;
                                case ORANGE:
                                    moves += "FFFULLLBLF";
                                    break;
                                case GREEN:
                                    moves += "FFLFF";
                                    break;
                            }
                        }
                        if (edge == 7) //white face
                        {
                            switch (C.F[WHITE].sqr[1])
                            {
                                case RED :
                                    moves += "LFLLLUUUFF";
                                    break;
                                case BLUE:
                                    moves += "FFFRRR";
                                    break;
                                case ORANGE:
                                    moves += "RRRFFFRUUUBB";
                                    break;
                                case GREEN:
                                    moves += "FL";
                                    break;

                            }
                        }
                        break;
                    }
                case ORANGE: //white square on the orange side
                   {
                        if (edge == 1) //yellow side
                        {
                            switch (C.F[YELLOW].sqr[1])
                            {
                                case RED:
                                    moves += "URRRFR";
                                    break;
                                case BLUE:
                                    moves += "BBBRB";
                                    break;
                                case ORANGE:
                                    moves += "UUULLLBL";
                                    break;
                                case GREEN:
                                    moves += "UUFFFLF";
                                    break;
                            }
                        }
                        if (edge == 3) //blue side
                        {
                            switch (C.F[BLUE].sqr[5])
                            {
                                case RED:
                                    moves += "RRRUUURUUFF";
                                    break;
                                case BLUE:
                                    moves += "R";
                                    break;
                                case ORANGE:
                                    moves += "DDDRD";
                                    break;
                                case GREEN:
                                    moves += "RRRUURLL";
                                    break;
                            }
                        }
                        if (edge == 5) //green side
                        {
                            switch ( C.F[GREEN].sqr[3])
                            {
                                case RED :
                                    moves += "DDDLLLD";
                                    break;
                                case BLUE:
                                    moves += "LUULLLRR";
                                    break;
                                case ORANGE:
                                    moves += "DLLLDDD";
                                    break;
                                case GREEN:
                                    moves += "LLL";
                                    break;
                            }
                        }
                        if (edge == 7) //white face
                        {
                            switch (C.F[WHITE].sqr[7])
                            {
                                case RED :
                                    moves += "BBBDDDLLLD";
                                    break;
                                case BLUE:
                                    moves += "BR";
                                    break;
                                case ORANGE:
                                    moves += "BRUUURRRBB";
                                    break;
                                case GREEN:
                                    moves += "BBBLLL";
                                    break;

                            }
                        }
                        break;
                   }
                case GREEN: //white square ont the green side
                    {
                        if (edge == 1) //yellow side
                        {
                            switch (C.F[YELLOW].sqr[3])
                            {
                                case RED:
                                    moves += "UUULLLULFFF";
                                    break;
                                case BLUE:
                                    moves += "FFFUUUFRRR";
                                    break;
                                case GREEN:
                                    moves += "BBBUBLLL";
                                    break;
                                case ORANGE:
                                    moves += "DLLLDDDB";
                                    break;
                            }

                        }
                        if (edge == 3) //orange side
                        {
                            switch (C.F[ORANGE].sqr[5])
                            {
                                case RED:
                                    moves += "DDBDD";
                                    break;
                                case BLUE:
                                    moves += "DBDDD";
                                    break;
                                case GREEN:
                                    moves += "BBBUUUBLL";
                                    break;
                                case ORANGE:
                                    moves += "B";
                                    break;
                            }
                        }
                        if (edge == 5) //red side
                        {
                            switch (C.F[RED].sqr[3])
                            {
                                case RED:
                                    moves += "FFF";
                                    break;
                                case BLUE:
                                    moves += "DDDFFFD";
                                    break;
                                case GREEN:
                                    moves += "DFFFDDD";
                                    break;
                                case ORANGE:
                                    moves += "DDFFFDD";
                                    break;
                            }
                        }
                        if (edge == 7) //white side
                        {
                            switch (C.F[WHITE].sqr[3])
                            {
                                case RED:
                                    moves += "LLLFFF";
                                    break;
                                case BLUE:
                                    moves += "LLLDDDFFFD";
                                    break;
                                case GREEN:
                                    moves += "LDDDBD";
                                    break;
                                case ORANGE:
                                    moves += "DLLDDDB";
                                    break;
                            }
                        }
                        break;
                    }
                case BLUE: //white square on the blue side
                    {
                        if (edge == 1) //yellow side
                        {
                            switch (C.F[YELLOW].sqr[5])
                            {
                                case RED:
                                    moves += "UFDRRRDDD";
                                    break;
                                case BLUE:
                                    moves += "FFFUFRRR";
                                    break;
                                case GREEN:
                                    moves += "UULDFFFDDD";
                                    break;
                                case ORANGE:
                                    moves += "DDDRDBBB";
                                    break;
                            }
                        }
                        if (edge == 3) //red side
                        {
                            switch (C.F[RED].sqr[5])
                            {
                                case RED:
                                    moves += "F";
                                    break;
                                case BLUE:
                                    moves += "DDDFD";
                                    break;
                                case GREEN:
                                    moves += "DFDDD";
                                    break;
                                case ORANGE:
                                    moves += "DDFDD";
                                    break;
                            }
                        }
                        if (edge == 5) //orange side
                        {
                            switch (C.F[ORANGE].sqr[3])
                            {
                                case RED:
                                    moves += "DDBBBDD";
                                    break;
                                case BLUE:
                                    moves += "DBBBDDD";
                                    break;
                                case GREEN:
                                    moves += "DDDBBBD";
                                    break;
                                case ORANGE:
                                    moves += "BBB";
                                    break;
                            }
                        }
                        if (edge == 7) //white side
                        {
                            switch (C.F[WHITE].sqr[5])
                            {
                                case RED:
                                    moves += "RF";
                                    break;
                                case BLUE:
                                    moves += "RDDDFD";
                                    break;
                                case GREEN:
                                    moves += "RFFFUFLL";
                                    break;
                                case ORANGE:
                                    moves += "DDFDD";
                                    break;
                            }
                        }
                        break;
                    }
                }
            }
            execMoves(C, moves);
            steps += moves;
        }
  }

  static void execMoves (Cube& C, String m)
    {
        for (int i = 0; i < m.length(); i++)
        {
            switch (m[i])
            {
            case 'R':
                {
                   C.rightCW();
                   break;
                }
            case 'L':
                {
                    C.leftCW();
                    break;
                }
            case 'F':
                {
                    C.frontCW();
                    break;
                }
            case 'B':
                {
                    C.backCW();
                    break;
                }
            case 'U':
                {
                    C.upCW();
                    break;
                }
            case 'D':
                {
                    C.downCW();
                    break;
                }
            }
        }
    }

};

#endif
