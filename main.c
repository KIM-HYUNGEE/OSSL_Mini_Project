#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

int count;
// function prototypes
void main_handler(char input[], Record *records[], int count);
void display_menu();

// main function
int main(){

	Record *records[MAX_RECORDS];
  
	char user_input[64] = "";
	while(strcmp(user_input, "99") != 0){
    		count = loadBooks(records);
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
    		printf("\n");
		main_handler(user_input, records, count);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void main_handler(char input[], Record *records[], int count){

	// TODO: Modify this function as you need
	if(!strcmp(input, "1"))
		registerBook(records, count);
	else if(!strcmp(input, "2"))
		purchaseBook(records, count);	
  	else if(!strcmp(input, "3"))
    		updateBook(records, count);
	else if(!strcmp(input, "99")){
    		freeBooks(records, count);
		printf("Terminating... bye!\n"); 
		// Quit - no operation (an empty statement with a semi-colon)
  	}	
  	else
		printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	// TODO: Modify this function as you need

	printf("**************************************\n");
	printf(" Online Secondhand Book Market System \n");
	printf("**************************************\n");
	printf(" 1. Register the Book\n");
	printf(" 2. Apply for the Book\n");
  	printf(" 3. Update the Book Price (Administrator Mode)\n");
	printf(" 99. Quit\n");
}



