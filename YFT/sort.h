#ifndef _SORT_H_
#define _SORT_H_

#include "structures.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <time.h>
void QSort (RoadArray_t* , int);
RoadArray_t* QuickSort (RoadArray_t* , int);
RoadArray_t* BubbleSort (RoadArray_t* , int);
RoadArray_t* InsertionSort(RoadArray_t* ,int);
RoadArray_t* HeapSort(RoadArray_t* ,int);
void TimeOfQuickSort(RoadArray_t* , int);
void TimeOfBubbleSort(RoadArray_t* , int);
void TimeOfInsertionSort(RoadArray_t* , int);
void TimeOfHeapSort(RoadArray_t* , int);
void TimeOfTreeSort(TreeNode_Point* , RoadArray_t*);
void TimeComp(RoadArray_t* , char *, int);

#endif
