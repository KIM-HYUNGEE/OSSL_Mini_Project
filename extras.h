#ifndef _EXTRAS_H_
#define _EXTRAS_H_

#include "record.h"

// function prototypes
// int defragment(Record[]);
// void display_stats(Record[]);

//new func by SJc
void advanced_search(Record *records[], int count);

// search system (일부 검색도 가능)
void searchBook(Record *records[], int count);
  void searchHandler(char input[], Record *records[], int count);
    void bookTitle(Record *records[], int count); // 검색
    void authorName(Record *records[], int count); // 검색
    void publicationYear(Record *records[], int count); // 검색


// arrange system (낮은 가격순, 높은 가격순, 출판연도순)
void arrangeBook(Record *records[], int count);
  void arrangeHandler(char input[], Record *records[], int count);
    void arrangeLow(Record *records[], int count); // 정렬(extra)
    void arrangeHigh(Record *records[], int count); // 정렬(extra)
    void arrangeYear(Record *records[], int count); // 정렬(extra)


void deleteBook(Record *records[], int count, int input); 
// Delete & 앞으로 밀기(file)


#endif
