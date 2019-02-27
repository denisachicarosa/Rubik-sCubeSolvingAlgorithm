#ifndef   EDGES .H
#define   EDGES .H



class Edges
{
public:
    static bool checkEdges (Cube& C)
    {
        if (C.F[RED].sqr[3] != RED || C.F[RED].sqr[5] != RED)
            return false;
        else if (C.F[GREEN].sqr[3] != GREEN || C.F[GREEN].sqr[5] != GREEN)
            return false;
        else if (C.F[BLUE].sqr[3] != BLUE || C.F[BLUE].sqr[5] != BLUE)
            return false;
        else if (C.F[ORANGE].sqr[3] != ORANGE || C.F[ORANGE].sqr[5] != ORANGE)
            return false;
        else return true;
    }

    static void solveEdges (Cube& C, String& steps)
    {
        while (!checkEdges(C))
        {
            solveEdge(C, steps);
        }
    }

    static void solveEdge (Cube& C, String& steps)
    {
        String moves;
        if (C.F[YELLOW].sqr[1] != YELLOW && C.F[ORANGE].sqr[1] != YELLOW)
        {
            if (C.F[YELLOW].sqr[1] == RED)
            {
                if (C.F[ORANGE].sqr[1] == GREEN)
                    moves += "FUUUFFFLFFFLLLF";
                else if (C.F[ORANGE].sqr[1] == BLUE)
                    moves += "FFFUFRRRFRFFF";
            }
            else if (C.F[YELLOW].sqr[1] == GREEN)
            {
                if (C.F[ORANGE].sqr[1] == ORANGE)
                    moves += "ULUUULLLBLLLBBBL";
                else if (C.F[ORANGE].sqr[1] == RED)
                    moves += "ULLLULFFFLFLLL";
            }
            else if (C.F[YELLOW].sqr[1] == BLUE)
            {
                if (C.F[ORANGE].sqr[1] == RED)
                    moves += "UUURUUURRRFRRRFFFR";
                else if (C.F[ORANGE].sqr[1] == ORANGE)
                    moves += "UUURRRURBBBRBRRR";
            }
            else if (C.F[YELLOW].sqr[1] == ORANGE)
            {
                if (C.F[ORANGE].sqr[1] == GREEN)
                    moves += "UUBBBUBLLLBLBBB";
                else if (C.F[ORANGE].sqr[1] == BLUE)
                    moves += "UUBUUUBBBRBBBRRRB";
            }
        }
        else if (C.F[YELLOW].sqr[3] != YELLOW && C.F[GREEN].sqr[1] != YELLOW)
        {
            if (C.F[YELLOW].sqr[3] == RED)
            {
                if (C.F[GREEN].sqr[1] == GREEN)
                    moves += "UFUUUFFFLFFFLLLF";
                else if (C.F[GREEN].sqr[1] == BLUE)
                    moves += "UFFFUFRRRFRFFF";
            }
            else if (C.F[YELLOW].sqr[3] == GREEN)
            {
                if (C.F[GREEN].sqr[1] == ORANGE)
                    moves += "UULUUULLLBLLLBBBL";
                else if (C.F[GREEN].sqr[1] == RED)
                    moves += "UULLLULFFFLFLLL";
            }
            else if (C.F[YELLOW].sqr[3] == BLUE)
            {
                if (C.F[GREEN].sqr[1] == RED)
                    moves += "RUUURRRFRRRFFFR";
                else if (C.F[GREEN].sqr[1] == ORANGE)
                    moves += "RRRURBBBRBRRR";
            }
            else if (C.F[YELLOW].sqr[3] == ORANGE)
            {
                if (C.F[GREEN].sqr[1] == GREEN)
                    moves += "UUUBBBUBLLLBLBBB";
                else if (C.F[GREEN].sqr[1] == BLUE)
                    moves += "UUUBUUUBBBRBBBRRRB";
            }
        }
        else if (C.F[YELLOW].sqr[7] != YELLOW && C.F[RED].sqr[1] != YELLOW)
        {
              if (C.F[YELLOW].sqr[7] == RED)
            {
                if (C.F[RED].sqr[1] == GREEN)
                    moves += "UUFUUUFFFLFFFLLLF";
                else if (C.F[RED].sqr[1] == BLUE)
                    moves += "UUFFFUFRRRFRFFF";
            }
            else if (C.F[YELLOW].sqr[7] == GREEN)
            {
                if (C.F[RED].sqr[1] == ORANGE)
                    moves += "UUULUUULLLBLLLBBBL";
                else if (C.F[RED].sqr[1] == RED)
                    moves += "UUULLLULFFFLFLLL";
            }
            else if (C.F[YELLOW].sqr[7] == BLUE)
            {
                if (C.F[RED].sqr[1] == RED)
                    moves += "URUUURRRFRRRFFFR";
                else if (C.F[RED].sqr[1] == ORANGE)
                    moves += "URRRURBBBRBRRR";
            }
            else if (C.F[YELLOW].sqr[7] == ORANGE)
            {
                if (C.F[RED].sqr[1] == GREEN)
                    moves += "BBBUBLLLBLBBB";
                else if (C.F[RED].sqr[1] == BLUE)
                    moves += "BUUUBBBRBBBRRRB";
            }
        }
        else if (C.F[YELLOW].sqr[5] != YELLOW && C.F[BLUE].sqr[1] != YELLOW)
        {
            if (C.F[YELLOW].sqr[5] == RED)
            {
                if (C.F[BLUE].sqr[1] == GREEN)
                    moves += "UUUFUUUFFFLFFFLLLF";
                else if (C.F[BLUE].sqr[1] == BLUE)
                    moves += "UUUFFFUFRRRFRFFF";
            }
            else if (C.F[YELLOW].sqr[5] == GREEN)
            {
                if (C.F[BLUE].sqr[1] == ORANGE)
                    moves += "LUUULLLBLLLBBBL";
                else if (C.F[BLUE].sqr[1] == RED)
                    moves += "LLLULFFFLFLLL";
            }
            else if (C.F[YELLOW].sqr[5] == BLUE)
            {
                if (C.F[BLUE].sqr[1] == RED)
                    moves += "UURUUURRRFRRRFFFR";
                else if (C.F[BLUE].sqr[1] == ORANGE)
                    moves += "UURRRURBBBRBRRR";
            }
            else if (C.F[YELLOW].sqr[5] == ORANGE)
            {
                if (C.F[BLUE].sqr[1] == GREEN)
                    moves += "UBBBUBLLLBLBBB";
                else if (C.F[BLUE].sqr[1] == BLUE)
                    moves += "UBUUUBBBRBBBRRRB";
            }
        }

        else if (C.F[RED].sqr[3] != RED || C.F[GREEN].sqr[5] != GREEN)
            moves += "LLLULFFFLFLLL";
        else if (C.F[RED].sqr[5] != RED || C.F[BLUE].sqr[3] != BLUE)
            moves += "RUUURRRFRRRFFFR";
        else if (C.F[GREEN].sqr[3] != GREEN || C.F[ORANGE].sqr[5] != ORANGE)
            moves += "BBBUBLLLBLBBB";
        else if (C.F[ORANGE].sqr[3] != ORANGE || C.F[BLUE].sqr[5] != BLUE)
            moves += "RRRURBBBRBRRR";

        steps += moves;
        Cross::execMoves(C, moves);
    }
};

#endif
