#include <stdio.h> 
#include <string.h> 
#include "insertionSort.h"

int main( void ) 
{ 
    int DataSet[] = {6, 4, 2, 3, 1, 5}; 
		int ExpectData[] ={1,2,3,4,5,6};
    int Length = sizeof DataSet / sizeof DataSet[0];     
    int i = 0; 
 
    InsertionSort(DataSet, Length); 
 
    for ( i=0; i<Length; i++ ) 
    { 
				//EXPECT_EQ(ExpectData[i] , DataSet[i]);
        printf("%d ", DataSet[i]); 
    } 
 
    printf("\n"); 
 
    return 0; 
}