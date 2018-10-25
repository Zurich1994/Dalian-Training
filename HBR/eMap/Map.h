#ifndef _Map_h_
#define _Map_h_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<malloc.h>
#include<iostream>
#include<windows.h>

typedef char   INT1;
typedef unsigned char UCHAR1;
typedef unsigned short UINT1;
typedef unsigned long ULONG1;
 
#define MC_GET_CHAR(__data__)  (*((char *)(__data__)))
#define MC_GET_SHORT(__data__)  ((UINT1)(( ((UINT1)(*((char *)(__data__))))<<8 )|( ((UINT1)(*((char *)(__data__)+1)))&0x00ff )))
#define MC_GET_LONG(__data__)  ( ( ((ULONG1)MC_GET_SHORT((__data__)))<<16 )|( ((ULONG1)MC_GET_SHORT((char *)(__data__)+2))&0x0000ffff ) )
#define MC_GET_3BN(__data__)  ( ( ((ULONG1)MC_GET_CHAR((__data__)))<<16 )|( ((ULONG1)MC_GET_SHORT((char *)(__data__)+1))&0x0000ffff ) )

#define MC_GEt_Class(__data__) (ULONG)((__data__.RoadInfo) & 0x000000ff)

typedef struct
{
	unsigned short RecordSize;
	unsigned long LinkID;
	unsigned short NameSize;
	unsigned long RoadInfo;
	bool flag;
	unsigned short Bruch;
	unsigned short dispclass;
	char * RoadName;
	unsigned short lengh;
}RoadRecord;

void FileRead(char * filename1, char * filename2);
void FileWrite(char * filename);

int QuickSort(RoadRecord *pRoadRecord, int left, int right);
void BubbleSort(RoadRecord * pRoadRecord,int RoadNum);
void InsertSort(RoadRecord * pRoadRecord,int RoadNum);
void ChooseSort(RoadRecord * pRoadRecord,int RoadNum);
void BinarySearch3(RoadRecord * pRoadRecord , int RoadNum);
void BinarySearch4(RoadRecord * pRoadRecord , int RoadNum);
void RoadInfomation(RoadRecord * pRoadRecord , int RoadNum);
void SortSelect(RoadRecord * pRoadRecord,int RoadNum);
int QuickSortTime(RoadRecord *pRoadRecord,int left,int right);
#endif