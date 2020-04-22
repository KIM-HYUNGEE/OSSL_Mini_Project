#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"
#include "extras.h"
#define MAX_RECORDS 1000


int loadBooks(Record *records[]) {
  FILE* fp;
  fp = fopen("save.log", "rt");
  int i;
  for (i=0; i<MAX_RECORDS; i++) {
    records[i] = malloc(sizeof(Record));
    fscanf(fp, "%d %s %d %[^\n]s", &records[i]->price, records[i]->author, &records[i]->year, records[i]->title);
    if (feof(fp) != 0) {
      break;
    }
  }
  fclose(fp);
  return i;
}


// Function: registerBook()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void registerBook(Record *records[], int count){
	// TODO: Modify this function as you need
  
  char title[100];
  char author[100];
  int year;
  int price;
  char decide[30];

  printf("Type your Book Title> ");
  scanf("%[^\n]s", title);
  getchar();
  printf("Type your Book Author(no space)> ");
  scanf("%s", author);
  getchar();
  printf("Type your Book Publication Year> ");
  scanf("%d", &year);
  getchar();
  printf("Type your Preferred Price> ");
  scanf("%d", &price);
  getchar();
  printf("Are you sure? [y/n] ");
  scanf("%[^\n]s", decide);
  getchar();
  if (!strcmp(decide, "y")) {
    count = saveInfo(records, count, title, author, year, price);
    printf("Return...\n");
  }
  else if (!strcmp(decide, "n")) {
    printf("Return...\n\n");
  }
  else {
    printf("Unknown input: %s \n\n",decide);
    printf("Return...\n\n");
  }

}


  int saveInfo(Record *records[], int count, char title[], char author[], int year, int price) {
    records[count] = malloc(sizeof(Record));
    int i;
    for (i=0; i<100; i++) {
      records[count]->title[i] = title[i];
    }
    for (i=0; i<100; i++) {
      records[count]->author[i] = author[i];
    }
    records[count]->year = year;
    records[count]->price = price; 

    FILE *fp;
    fp = fopen("save.log","wt");
    for (i=0; i<count+1; i++) {
      fprintf(fp,"%d %s %d %s\n", records[i]->price, records[i]->author, records[i]->year, records[i]->title);
    }
    fclose(fp);
    printf("\n Registered Successfully!!\n\n");

    return count+1;
  }






// Function: purchaseBook()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void purchaseBook(Record *records[], int count){
	// TODO: Modify this function as you need

  char purInput[30] = "";

  printf("*******************\n");
  printf(" Purchase the Book \n");
  printf("*******************\n");
  printf(" 1. Print Out the Books on the Market\n");
  printf(" 2. Search the Book\n");
  printf(" 3. Arrange the List of Books\n");
  printf(" 4. Select the Book you want\n");
  printf(" 99. Return to the main menu\n");

  printf("\nSelect a menu> ");
  scanf("%[^\n]s",purInput);
  getchar();

  purchaseHandler(purInput, records, count);
}


void purchaseHandler(char input[], Record *records[], int count){
  if(!strcmp(input, "1"))
	printOut(records, count);
	else if(!strcmp(input, "2"))
		searchBook(records, count);
  	else if(!strcmp(input, "3"))
    		arrangeBook(records, count);
  	else if(!strcmp(input, "4"))
    		selectBook(records, count);
	else if(!strcmp(input, "99"))
		printf("Return to the main menu...\n\n"); 
    // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);

}


void printOut(Record *records[], int count) {
  int i;
  printf("\n Total %d books left. \n", count);
  printf("----------------------\n");
  for (i=0; i<count; i++) {
    printf("%2d. %s (%s) %d [price: %d]\n\n", i+1, records[i]->title, records[i]->author, records[i]->year, records[i]->price);
  }
  purchaseBook(records, count); // return to purchase menu
}



void selectBook(Record *records[], int count){
  int i;
  printf("\n Total %d books left. \n", count);
  printf("----------------------\n");
  for (i=0; i<count; i++) {
    printf("%2d. %s (%s) %d [price: %d]\n\n", i+1, records[i]->title, records[i]->author, records[i]->year, records[i]->price);
  }
  int numInput;
  printf("\nType the Book 'Number' you want> ");
  scanf("%d",&numInput);
  getchar();

  if (numInput > count) {
    printf("Wrong Number... Type Again...\n\n");
    selectBook(records, count);
  }
  deleteBook(records, count, numInput-1);
  printf("Application completed!!\n\n");

}


void updateBook(Record *records[], int count) {
  int updateInput;
  int updatePrice;
  int i;
  printf("\n");
  printf(" Update the Book Price \n");
  printf("-----------------------\n");
  for (i=0; i<count; i++) {
    printf("%2d. %s (%s) %d [price: %d]\n\n", i+1, records[i]->title, records[i]->author, records[i]->year, records[i]->price);
  }
  printf("Type the Book 'Number' you want to update> ");
  scanf("%d",&updateInput);
  getchar();
  printf("Type your preffered price> ");
  scanf("%d",&updatePrice);
  getchar();
  records[updateInput-1]->price = updatePrice;
  
  FILE *fp;
  fp = fopen("save.log", "wt");
  for (i=0; i<count; i++) {
    fprintf(fp,"%d %s %d %s\n", records[i]->price, records[i]->author, records[i]->year, records[i]->title);
  }
  fclose(fp);
  printf("\nUpdate Successfully!!\n\n");
}



void freeBooks(Record *records[], int count) {
  int i;
  for (i=0; i<count; i++) {
    free(records[i]);
  }
}

// TODO: Add more functions to fulfill the requirements
