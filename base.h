#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"


// function prototypes
int loadBooks (Record *records[]); // Create

void registerBook(Record *records[], int count);
  int saveInfo(Record *records[], int count, char title[], char author[], int year, int price); // Create


void purchaseBook(Record *records[], int count);
  void purchaseHandler(char input[], Record *records[], int count);


// save.log 파일에 리포트 형식으로 저장 (Read)
void printOut(Record *records[], int count); // Read


void selectBook(Record *records[], int count);


void updateBook(Record *records[], int count); // Update


void freeBooks(Record *records[], int count);


#endif
