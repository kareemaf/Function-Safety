#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int Consective_Filter(int *Array , int Size);


int main()
{
	int array[30] = {1,2,5,4,3,5,7,7,7,7,7,7,7,3,2,2,1,4,6,6,6,6,6,6,6,6,3,3,3};
	
	int Size = sizeof(array)/sizeof(array[0]) ;
	
	int Return_Value = Consective_Filter(array,Size);
	
	printf("Return_Value = %d" , Return_Value) ;
}


int Consective_Filter(int *Array , int Size)
{
	int Counter = 0 , Count = 0 , Index ;
	
	for(int i=0 ; i<Size ; i++)
	{
		if(Array[i]==Array[i+1])
		{
			Counter++ ;
			if(Count<Counter)
			{
				Index = Array[i] ; 
				Count = Counter ;
			}
		}
		else
		{		
			Counter = 0 ;
		}
	}
	return Index ;
}