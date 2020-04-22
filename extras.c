#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extras.h"
#include "base.h"
#define MAX_RECORDS 1000


// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Leave a brief information about the function
// int defragment(Record records[]){
	// TODO: Modify this function as you need
	// printf("defragment(): this function needs to be implemented\n\n");
	// return 0;	// TODO: return 1 if defragment succeed; return 0 otherwise 
// }


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
// void display_stats(Record records[]){
// 	// TODO: Modify this function as you need
// 	printf("display_stats(): this function needs to be implemented\n\n"); // TODO: Remove this line
// }


void searchBook(Record *records[], int count) {
  char searchInput[30];
  printf("*****************\n");
  printf(" Search the Book \n");
  printf("*****************\n");
  printf(" 1. Book Title\n");
  printf(" 2. Author Name\n");
  printf(" 3. Book Publication Year\n");
  printf(" 99. Return to the purchase menu\n");

  printf("\nSelect a menu> ");
  scanf("%[^\n]s",searchInput);
  getchar();

  searchHandler(searchInput, records, count);

}


void searchHandler(char input[], Record *records[], int count) {
  if(!strcmp(input, "1"))
		bookTitle(records, count);
	else if(!strcmp(input, "2"))
		authorName(records, count);
  else if(!strcmp(input, "3"))
    publicationYear(records, count);
	else if(!strcmp(input, "99")){
		printf("Return to the purchase menu...\n\n"); 
    purchaseBook(records, count);
    // Quit - no operation (an empty statement with a semi-colon)
  }
	else {
		printf("Unknown menu: %s \n\n", input);
    searchBook(records, count);
  }
}

void bookTitle(Record *records[], int count) {
  char title[100];
  printf("Type the title of preffered book> ");
  scanf("%[^\n]s",title);
  getchar();
  printf("\n");
  printf("***************\n");
  printf(" Search Result \n");
  printf("***************\n");
  int i;
  int check = 0;
  int order = 1;
  for (i=0; i<count; i++) {
    if (strstr(records[i]->title,title) != NULL) {
      check = 1;
      printf("%2d. %s (%s) %d [price: %d]\n", order++, records[i]->title, records[i]->author, records[i]->year, records[i]->price);
    }
  }
  if (check == 0) printf(" No Result!! \n");
  printf("\n");
  purchaseBook(records, count);
  
}

void authorName(Record *records[], int count) {
  char author[100];
  printf("Type the author of preffered book> ");
  scanf("%[^\n]s",author);
  getchar();
  printf("\n");
  printf("***************\n");
  printf(" Search Result \n");
  printf("***************\n");
  int i;
  int check = 0;
  int order = 1;
  for (i=0; i<count; i++) {
    if (strstr(records[i]->author,author) != NULL) {
      check = 1;
      printf("%2d. %s (%s) %d [price: %d]\n", order++, records[i]->title, records[i]->author, records[i]->year, records[i]->price);
    }
  }
  if (check == 0) printf(" No Result!! \n");
  printf("\n");
  purchaseBook(records, count);
  
}

void publicationYear(Record *records[], int count) {
  int year;
  printf("Type the publication year of preffered book> ");
  scanf("%d",&year);
  printf("\n");
  printf("***************\n");
  printf(" Search Result \n");
  printf("***************\n");
  int i;
  int check = 0;
  int order = 1;
  for (i=0; i<count; i++) {
    if (records[i]->year == year) {
      check = 1;
      printf("%2d. %s (%s) %d [price: %d]\n", order++, records[i]->title, records[i]->author, records[i]->year, records[i]->price);
    }
  }
  if (check == 0) printf(" No Result!! \n");
  printf("\n");
  purchaseBook(records, count);
  
}






void arrangeBook(Record *records[], int count){
  char arrangeInput[30];
  printf("******************\n");
  printf(" Arrange the Book \n");
  printf("******************\n");
  printf(" 1. Low Price Order\n");
  printf(" 2. High Price Order\n");
  printf(" 3. Publication Year Order\n");

  printf("\nSelect a menu> ");
  scanf("%[^\n]s", arrangeInput);
  getchar();
  arrangeHandler(arrangeInput, records, count);
}

void arrangeHandler(char input[], Record *records[], int count){
  if(!strcmp(input, "1"))
    arrangeLow(records, count);
  else if(!strcmp(input, "2"))
    arrangeHigh(records, count);
  else if(!strcmp(input, "3"))
    arrangeYear(records, count);
  else if(!strcmp(input, "99")){
    printf("Return to the purchase menu...\n\n"); 
    purchaseBook(records, count);
    // Quit - no operation (an empty statement with a semi-colon)
  }
  else {
    printf("Unknown menu: %s \n\n", input);
    arrangeBook(records, count);
  }
}

void arrangeLow(Record *records[], int count){
  Record *temp[MAX_RECORDS];
  int tempCount = loadBooks(temp);

  Record *arr;
  int i, j, k;
  int order = 1;

  for (int i = 1; i < count; i++) {
    arr = malloc(sizeof(Record));
    arr->price = temp[i]->price;
    
    int j = i - 1;

    while (j >= 0 && arr->price < temp[j]->price) {
      temp[j + 1]->price = temp[j]->price;
      j = j - 1;
    }
    temp[j + 1]->price = arr->price;
  }
  
  printf("\n Arrange by Low Price \n");
  printf("----------------------\n");


  for (i=0; i<count; i++) {
    for (j=0; j<count; j++) {
      if (temp[i]->price == temp[i+1]->price) break;

      if (temp[i]->price == records[j]->price) {
        printf("%2d. %s (%s) %d [price: %d]\n\n", order++, records[j]->title, records[j]->author, records[j]->year, records[j]->price);
      }
    }
  }

  purchaseBook(records, count);
}

void arrangeHigh(Record *records[], int count){
  Record *temp[MAX_RECORDS];
  int tempCount = loadBooks(temp);

  Record *arr;
  int i, j, k;
  int order = 1;

  for (int i = 1; i < count; i++) {
    arr = malloc(sizeof(Record));
    arr->price = temp[i]->price;
    
    int j = i - 1;

    while (j >= 0 && arr->price > temp[j]->price) {
      temp[j + 1]->price = temp[j]->price;
      j = j - 1;
    }
    temp[j + 1]->price = arr->price;
  }
  
  printf("\n Arrange by High Price \n");
  printf("----------------------\n");


  for (i=0; i<count; i++) {
    for (j=0; j<count; j++) {
      if (temp[i]->price == temp[i+1]->price) break;

      if (temp[i]->price == records[j]->price) {
        printf("%2d. %s (%s) %d [price: %d]\n\n", order++, records[j]->title, records[j]->author, records[j]->year, records[j]->price);
      }
    }
  }

  purchaseBook(records, count);
}


void arrangeYear(Record *records[], int count){
  Record *temp[MAX_RECORDS];
  int tempCount = loadBooks(temp);

  Record *arr;
  int i, j, k;
  int order = 1;

  for (int i = 1; i < count; i++) {
    arr = malloc(sizeof(Record));
    arr->year = temp[i]->year;
    
    int j = i - 1;

    while (j >= 0 && arr->year > temp[j]->year) {
      temp[j + 1]->year = temp[j]->year;
      j = j - 1;
    }
    temp[j + 1]->year = arr->year;
  }
  
  printf("\n Arrange by Publication Year \n");
  printf("----------------------\n");


  for (i=0; i<count; i++) {
    for (j=0; j<count; j++) {
      if (temp[i]->year == temp[i+1]->year) break;

      if (temp[i]->year == records[j]->year) {
        printf("%2d. %s (%s) %d [price: %d]\n\n", order++, records[j]->title, records[j]->author, records[j]->year, records[j]->price);
      }
    }
  }

  purchaseBook(records, count);
}



void deleteBook(Record *records[], int count, int input){

  FILE *fp;
  fp = fopen("save.log","wt");
  int i;
  for (i=0; i<count; i++) {
    if (i == input) continue;
    fprintf(fp,"%d %s %d %s\n", records[i]->price, records[i]->author, records[i]->year, records[i]->title);
  }

  fclose(fp);
}






// TODO: Add more functions to fulfill the optional requirements
