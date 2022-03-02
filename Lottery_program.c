/* C program by Kevin Huy Trinh CS1311 March 2022

||=============================================================================||
||                                                                             ||
||  #    # ####### #     # ### #     #    ####### ######  ### #     # #     #  ||
||  #   #  #       #     #  #  ##    #       #    #     #  #  ##    # #     #  ||
||  #  #   #       #     #  #  # #   #       #    #     #  #  ##    # #     #  ||
||  ###    #####   #     #  #  #  #  #       #    ######   #  #  #  # #######  ||
||  #  #   #        #   #   #  #   # #       #    #   #    #  #   # # #     #  ||
||  #   #  #         # #    #  #    ##       #    #    #   #  #    ## #     #  ||
||  #    # #######    #    ### #     #       #    #     # ### #     # #     #  ||
||                                                                             ||                            
||=============================================================================||

* Author: Kevin Huy Trinh
* Class: CS1311 12:35pm
* Language: C
* Project Name: Lottery Program #4

* Purpose: This program generates seven unique numbers, then
* its sorts them using a sorting method called bubble sorting.
* Finally the lottery program compares all user numbers to the
* randomly generated numbers. */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* program generates 7 unique numbers */
int generateRandNumbers() {
	
	int index, num;		/* index value, rand num that's returned */

	srand(time(NULL));
    num = rand() % 50 + 1;
    
    return num;

}


/* adds a delay */
void delay(int number_of_seconds)
{
    /*Converting time into milli_seconds */
    int milli_seconds = 1000 * number_of_seconds;
  
    /* Storing start time */
    clock_t start_time = clock();
  
    /* looping till required time is not achieved */
    while (clock() < start_time + milli_seconds);
}



/* look for x in array; return 1 if found, 0 if not */
int check_for_unique(int x, int array[]) {

	int i, duplicate = 0; 	/* assume no repeat */
	
	for (i = 0; i < 7; i++) {
	
		if(x == array[i])
			 duplicate = 1;
	
	}
	
	return duplicate;

}


/* prints its given array */
void print_array7(int array[]){

	 int x;		/* index value into array */
	 
	 for (x=0; x<7; x++) {
	 
	 	 printf("   %i   ", array[x]);
	 
	 }
	 
	 printf("\n"); 	/* spacing */

}




void main(void){

	 int n = 0, count = 0, unique, temp, sorted = 1, i, matches = 0;		/* mist statistics of list */
	 int usersNumbers[7] = {0, 0, 0, 0, 0, 0, 0};							/* user's unique list */
  	 int programNumbers[7] = {0, 0, 0, 0, 0, 0, 0};							/* program's unique numbers */
  	 
  	 
	 /* gets 7 unique numbers from user */
	 printf("This program compares users littery numbers to 7 randomly lottery numbers. \n\n");
	 printf("Please enter 7 different positive integers. \n\n");
	 while (count < 7) {							
	 
	 	   printf("Type in an integer between 1 and 50: ");
	 	   scanf("%i", &n);
	 	   unique = check_for_unique(n, usersNumbers);
	 	   
	 	   if (unique == 0 && n > 0 && n < 51){
			
			  usersNumbers[count] = n;
			  count = count + 1;
			
			}
			else {
			
		       printf("%i is a duplicate or out of range. \n", n);
			
			}
	 
	 }
	 
	 printf("\n\nYour 7 unordered digits are: ");			
	 print_array7(usersNumbers);
	 
	 /* bubble sorts the user's numbers */
	 n = 7, i = 1, temp, sorted = 1;
     do {
	
	   sorted = 1;	/* assume list is sorted */
	   
	   for (i = 0; i < n - 1; i++) {	/* for each adjacent pair */
	   
	   	     if(usersNumbers[i] > usersNumbers[i+1]){	/* if first > second then swap */
			  
 		       temp = usersNumbers[i];
 		       usersNumbers[i] = usersNumbers[i+1];
 		       usersNumbers[i + 1] = temp;
 		       sorted = 0;		/* list was not yet sorted */
			  
		     }
         }
     } while (sorted == 0); /* list is not sorted yet */
	 printf("Your 7 reordered digits are: ");
	 print_array7(usersNumbers);
     
 
	 
	 
	 /* generates 7 unique random numbers */
	 count = 0;
	 while (count < 7) {							

	 	   delay(1);		/* uses delay to avoid spam */
	 	   n = generateRandNumbers();
	 	   unique = check_for_unique(n, programNumbers);
	 	   
	 	   if (unique == 0 && n > 0 && n < 51){
			
			  programNumbers[count] = n;
			  count = count + 1;
			
			}
			else {
			
		       printf("%i is a duplicate or out of range. Trying again. \n", n);
			
			}
	 
	 }
	 printf("\n\nThe 7 unordered random lottery numbers: ");
	 print_array7(programNumbers);
     
     /* sorts the programs lottery numbers */
	 n = 7, i = 1, temp, sorted = 1;
     do {
	
	   sorted = 1;	/* assume list is sorted */
	   
	   for (i = 0; i < 7 - 1; i++) {	/* for each adjacent pair */
	   
	   	     if(programNumbers[i] > programNumbers[i+1]){	/* if first > second then swap */
			  
 		       temp = programNumbers[i];
 		       programNumbers[i] = programNumbers[i+1];
 		       programNumbers[i + 1] = temp;
 		       sorted = 0;		/* list was not yet sorted */
			  
		     }
         }
     } while (sorted == 0); /* list is not sorted yet */
	 printf("The 7 reordered random lottery numbers: ");
	 print_array7(programNumbers);
	 
	 printf("\nNow getting lottery results... \n\n");
	 
	 
	 /* compares both list items at same index */
 	 for (i = 0; i < 7; i++) {
	  
	  	 if (usersNumbers[i] == programNumbers[i]) {	/* match found */
		   
		      matches = matches + 1;			/* increment matches when one is found */
		      printf("Congrats! %i matches with %i on the lottery! \n", usersNumbers[i], programNumbers[i]);
		   
		   }
         else {			/* no matches found */
		 
		 	  printf("Sorry! %i and %i are not a match. \n", usersNumbers[i], programNumbers[i]);
		 
		 }
	  
	  }
	  
	  printf("\nA total of %i of your numbers matched a number on the lottery!", matches);

}
