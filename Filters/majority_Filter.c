#include<stdio.h>
#include<stdlib.h>

int findMostFrequentElement(int A[], int n)
{
	
    for (int i = 0; i < n; i++)    //Sort the array
    {    
        int temp;
        for (int j = i+1; j < n; j++) 
        {     
           if(A[i] > A[j]) 
           {    
               temp = A[i];    
               A[i] = A[j];    
               A[j] = temp;    
           }     
        }     
    }        
	
    //find the most occuring element
    int max_count = 1, res = A[0], count = 1; 
    for (int i = 1; i < n; i++) 
	{ 
        if (A[i] == A[i - 1]) 
            count++; 
        else { 
            if (count > max_count) 
			{ 
                max_count = count; 
                res = A[i - 1]; 
            } 
            count = 1; 
        } 
    }   
    // If last element is most frequent 
    if (count > max_count) 
    { 
        max_count = count; 
        res = A[n - 1]; 
    }   
    return res; //return the most repeatinng  element
	
}
//Driver Program
void main()
{
    int array[] = {0,2,2,1,0,0,2,2};
	int size = sizeof(array)/sizeof(array[0]);   
  
    int maxElement = findMostFrequentElement(array, size);    //Function call
    printf("Maximum Repeating Element : %d",maxElement);   //Prints the most occuring element 
    
}

