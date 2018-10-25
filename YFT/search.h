#ifndef _SEARCH_H_
#define _SEARCH_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <time.h>
#include "structures.h"

int BinarySearch(RoadArray_t rdArray, const int, int);
int SequenceSearch(const RoadArray_t, const int, int);
int TreeSearch(TreeNode_t* , int);

#endif
