#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pool.h"


/**/
typedef struct 
{
	int    Data;
	double Inversion;
	
}Data_Pool_t;



/*global Array data_type it "Data_Pool_t" ,it is have critical variable of system*/
Data_Pool_t  Array_Pool[3] = {0} ;




/**/
int main ()
{
	
	int Temp_SensorValue      = 40 , Temp_Addres      = 0  ; //Variable of Temprither ,store in address 0
	int Ultrsonic_SensorValue = 3  , Ultrsonic_Addres = 1  ; //Variable of Ultrsonic  ,store in address 1
	int LDR_SensorValue       = 15 , LDR_Addres       = 2  ; //Variable of LDR        ,store in address 2
    int Read_Value ;
	
	/*Call Write function to store data in Data_pool*/
	Write(Temp_SensorValue 		, Temp_Addres);
	Write(Ultrsonic_SensorValue , Ultrsonic_Addres);
	Write(LDR_SensorValue 		, LDR_Addres);
	
	/*call Read_Value function to read data from Data_Pool*/
	Read_Value = Read_From_Pool(1);
	
	/*Print Return value from data_pool*/
	printf("Read_Value = %d\n",Read_Value);
}



/********************************************************************************************************/
/********************************************************************************************************/

/* Write function to take two paramiters , first  paramiter it is a value will writeing in data_pool 
                                           Second paramiter it is a address of value*/
void Write (int First_Val ,int Addres_IN_POOL)
{
							   // pow function to get inversion of number
	double local_Inversion  =  pow(First_Val,-1) ;
	Write_In_Pool(Addres_IN_POOL,First_Val,local_Inversion);
}



/********************************************************************************************************/
/********************************************************************************************************/


/*Function called in write function*/
void Write_In_Pool (int Addresinpool,int Copy_Val,double Copy_Inversion)
{
							   // pow function to get inversion of number
	double local_Inversion  =  pow(Copy_Val,-1) ;
	if(local_Inversion == Copy_Inversion)
	{
		Array_Pool[Addresinpool].Data 	    = Copy_Val ;
		Array_Pool[Addresinpool].Inversion  = Copy_Inversion ;
	}
	else
	{
		printf("Error Inversion\n");
	}
}


/********************************************************************************************************/
/********************************************************************************************************/

/*Read function take one paramiter it is a address of variable we will read it*/
int Read_From_Pool(int Addres_IN_POOL)
{
	int Local_Value , INDEX ;
	double local_Inversion  ;
    Local_Value   = Array_Pool[Addres_IN_POOL].Data 	;
	local_Inversion = pow(Local_Value,-1) ; 
	
	if(local_Inversion == Array_Pool[Addres_IN_POOL].Inversion)
	{
		 INDEX = Local_Value ;
	}
	else
	{
		printf("Error Inversion\n");
	}
	
	return INDEX ;
}