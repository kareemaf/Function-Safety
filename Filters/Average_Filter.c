#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pool.h"



float Average_Filter(int *Array , int Size);



int main ()
{
	int array[5]={11,2,1,4,20};
	int Size = sizeof(array)/sizeof(array[0]) ; 
	
	float Average_Value ;
	
	Average_Value = Average_Filter(array,Size);
	
	printf("Average Value = %f" ,Average_Value);
	
}

float Average_Filter(int *Array , int Size)
{
	int Sum ;
	float Local_Average; 
	for(int i=0 ; i<Size ; i++)
	{
		Sum += Array[i];
	}
	Local_Average = Sum / Size ;
	
	return Local_Average ;
}