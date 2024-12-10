#include <stdlib.h>
#include "BinarySearch.h"

Point *BinarySearch(Point PointList[], int Size, double Target)
{
    int Left, Right, Mid;
    Left = 0;
    Right = Size - 1;

    while(Left <= Right)
    {
        Mid = (Left + Right) / 2;

        if(Target == PointList[Mid].point)
        {
            return &(PointList[Mid]);
        }
        else if(Target > PointList[Mid].point)
            Left = Mid + 1;
        else
            Right = Mid - 1;
    }

    return NULL;
}