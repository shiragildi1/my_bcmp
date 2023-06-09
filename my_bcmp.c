#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 512
#define EOS '\0'
int my_bcmp(const void *b1, const void *b2,int len);
/*The main function uses the function below and returns whether the parts are the same or not.*/
int main()
{
	int result;
	int tempLength;/*Integer temporary variable*/
	int tempIndex1;/*Integer temporary variable*/
	int tempIndex2;/*Integer temporary variable*/
	double length;
        double index1;
	double index2;
	char *str;
	char c;
	void *b1;
	void *b2;
        /*Maloc and Caloc capture the characters by adding a cell each time the user enters a character*/
        str = (char*)malloc(sizeof(char));
        if(str == NULL)
	{
		printf("no alocation.\n");
		return 1;
	}
        *str = EOS;
        
        printf("pleas enter a number of bitim that do you want to comper- length:\n");
	scanf("%lf",&length);
/***************************cheking for the length*******************************************/ 
	if(length!=0)
	{
		if(!isdigit(length) && (int)length==0)/*Checking whether it is a number.*/
	 {
		printf("ERRORE-1- you entered a wrong length to check-not a number!!😡");
		return 0;
	 }

	}
	if(length!=(int)length) /*Checking whether it is an integer*/
	{
		  printf("ERRORE-2- you entered a wrong length to check-not an intiger!!");
		  return 0;
	}
	if(length<0)/*Checking whether the entered number is negative*/
	{
		 printf("ERRORE-3- you entered a wrong length to check-negetive number!!");
		 return 0;
	}
	
	
	
/*************************************************************************************/

 
	printf("pleas enter a index1 :\n");
	scanf("%lf",&index1);
/*****************************cheking for the index1*********************************/ 
	if(index1!=0)
	{
		if(!isdigit(index1) && (int)index1==0)/*Checking whether it is a number*/
	 {
		printf("ERRORE-4- you entered a wrong index1 to check-not a number!!😡");
		return 0;
	 }

	}
	if(index1!=(int)index1)/*Checking whether it is an integer.*/ 
	{
		  printf("ERRORE-5- you entered a wrong index1 to check-not an intiger!!");/*Checking whether the index1 is incomplete.*/
		  return 0;
	}
	if(index1<0)/*Checking whether the entered number is negative.*/
	{
		 printf("ERRORE-6- you entered a wrong index1 to check-negetive number!!");
		 return 0;
	}
/**************************************************************************************/
	printf("pleas enter a index2 : \n");
	scanf("%lf",&index2);

/***********************************cheking for the index2*******************************/ 
	if(index2!=0)
	{
		if(!isdigit(index2) && (int)index2==0)/*Checking whether it is a number*/
	 {
		printf("ERRORE-7- you entered a wrong index2 to check-not a number!!😡");
		return 0;
	 }

	}
	if(index2!=(int)index2)/*Checking whether it is an integer.*/  
	{
		  printf("ERRORE-8- you entered a wrong index2 to check-not an intiger!!");/*Checking whether the index2 is incomplete.*/
		  return 0;
	}
	if(index2<0)/*Checking whether the entered number is negative*/
	{
		 printf("ERRORE-9- you entered a wrong index2 to check-negetive number!!");
		 return 0;
	}
/*************************************************************************************************/
        printf("Hi!\npleas enter your string:\n");
        getchar();
	while((c=getchar())!=EOF)
	{
    
		char *temp = (char*)realloc(str,strlen(str)+2*sizeof(char));
		if(temp==NULL)
		{
			return 1;
		}
		str = temp;
		*(str+strlen(str)+1) = EOS;
		*(str+strlen(str)) = c;
               
	}
/**************************cheking for the string*****************************************************/ 
        /*Checks whether there is an exception to the string*/
        if(strlen(str)>MAX)
	{
		printf("ERRORE-10-the string is not iligal😡.\n");
		return 0;
	}
	/*Checks whether there is an exception to the string by index1*/   
	if((index1+length)>(strlen(str)))
	{
		printf("ERRORE-11- you Inserting a length that exceeds the string. from your index😡.\n");
		return 0;
	}
	
        /*Checks whether there is an exception to the string by index2*/ 
	if((index2+length)>(strlen(str)))
	{
		printf("ERRORE-12- youInserting a length that exceeds the string. from your index😡.\n");
		return 0; 
	}
/****************************************************************************************************/
	tempLength=(int)length;
	tempIndex1=(int)index1;
	tempIndex2=(int)index2;

        printf("\n");
        printf("the length is: %d\n",(int)length); 
	printf("the index1 is: %d\n",(int)index1);
	printf("the index2 is: %d\n",(int)index2);
        printf("the string is: %s",str);

	b1= &str[tempIndex1]; 
	b2= &str[tempIndex2]; 

        

        
	
/*into result goes what the function returns zero or 1.*/
	result = my_bcmp(b1,b2,tempLength);
	if(result == 0)/*this of sucsoude*/
	{
		printf("success!!!!!!!😃 😃 😃 😃 😃 😃 Well done!!!!!!!!Both sections are equal.\n");
	}
	else/*this of faile*/
	{
		printf("failure!!!!!!!😭 😭 😭 😭 😭 😭 try again next time!!!!!!!!!Both sections are not equal.\n");
	}



	return 0;
}

/*This function compares the length of bytes from pointer B1 with the length of bytes from pointer B2 and returns 0 if it is found that the two memory segments contain the same content and some other value that differs from 0.*/
int my_bcmp(const void *b1, const void *b2,int len)
{
	 char *v1=(char*)b1;/*Conversion to other voters since these are fixed type voters*/
	 char *v2=(char*)b2;/*Conversion to other voters since these are fixed type voters*/
	 int i;
 

   

	for(i=0; i<len;i++)
	{
		if((*(v1+i))!=(*(v2+i)))
		{
			return -1;
		}
		
		
	}

	   return 0;
}







  
