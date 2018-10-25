#include<cstdio>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib, "winmm.lib") 

#include"emap.h"

extern Road *roads;
// 保存所有道路的数组
extern int roadsSize;
// 道路数量
extern bool sorted;
// 已排序 

const char sortIcon[]=
"\n" "\n"
"　　　　　　　　　↑　　　　　┄┄┄┄┄┄┄┄┄┄┄　←╮\n"
"　　　　　　　　　┆　╭─→　┄┄┄┄┄┄┄┄┄┄┄　　│\n"
"　　　　　　　　　┆　│╭→　┄┄┄┄┄┄┄┄┄┄┄　　│\n"
"　　　　　　　　　┆　││　　┄┄┄┄┄┄┄┄┄┄┄　←╯\n"
"　　　　　　　　　┆　╰┼→　┄┄┄┄┄┄┄┄┄┄┄\n"
"　　　　　　　　　┆　　│　　┄┄┄┄┄┄┄┄┄┄┄　←╮\n"
"　　　　　　　　　┆　　│　　┄┄┄┄┄┄┄┄┄┄┄　←╯\n"
"　　　　　　　　　↓　　╰→　┄┄┄┄┄┄┄┄┄┄┄ \n"
"\n""\n";

/* 实现部分 */
int bubbleSort(){
	system("cls");
	puts(sortIcon);
	int i,j;
	DWORD time1=timeGetTime();
    for(i=0;i<roadsSize-1;i++)
	{
		bool flag=true;
		if (i%100==0 || i==roadsSize-2){
	    	printf("正在排序中，请稍侯");
	    	int k;
	    	for (k=0;k<i/100%5;k++) printf(".");
	    	for (k=0;k<5-i/100%5;k++) printf(" ");
	    	printf("%7.2f%%\r",(float)i*100/roadsSize); _flushall();
	    }
		for(j=0;j<roadsSize-1-i;j++)
		{
			if(roads[j].linkID>roads[j+1].linkID)
			{
				flag=false;
				swap(roads[j],roads[j+1]);
			}
		}
		if (flag) break;
	}
	printf("\r排序完毕！                          \n");
	DWORD time2=timeGetTime();
	sorted=true;
    return time2-time1;
}

int selectionSort(){
	system("cls");
	puts(sortIcon);
	int i,j,m;
	DWORD time1=timeGetTime();
    for(i=0;i<roadsSize-1;i++){
    	if (i%100==0 || i==roadsSize-2){
	    	printf("正在排序中，请稍侯");
	    	int k;
	    	for (k=0;k<i/100%5;k++) printf(".");
	    	for (k=0;k<5-i/100%5;k++) printf(" ");
	    	printf("%7.2f%%\r",(float)i*100/roadsSize); _flushall();
	    }
		m=i;
		for(j=i+1;j<roadsSize;j++)
			if(roads[j].linkID<roads[m].linkID)
               m=j;
			swap(roads[i],roads[m]);
	}
	printf("\r排序完毕！                      \n");
	DWORD time2=timeGetTime();
	sorted=true;
    return time2-time1;
}

int insertionSort(){
	system("cls");
	puts(sortIcon);
	int i,j;
	Road t;
	DWORD time1=timeGetTime();
	for(i=1;i<roadsSize;i++){
		if (i%100==0 || i==roadsSize-2){
	    	printf("正在排序中，请稍侯");
	    	int k;
	    	for (k=0;k<i/100%5;k++) printf(".");
	    	for (k=0;k<5-i/100%5;k++) printf(" ");
	    	printf("%7.2f%%\r",(float)i*100/roadsSize); _flushall();
	    }
		t=roads[i];
		for(j=i-1;roads[j].linkID>t.linkID&&j>=0;j--)
			roads[j+1]=roads[j];
		roads[j+1]=t;
	}
	printf("\r排序完毕！                      \n");
	DWORD time2=timeGetTime();
	sorted=true;
    return time2-time1;	 
}
void quickSort(int left,int right){
	int i=left,j=right;
	Road m=roads[(left+right)>>1];
	if (i%100==0 || i==roadsSize){
	    	printf("正在排序中，请稍侯");
	    	int k;
	    	for (k=0;k<i/100%5;k++) printf(".");
	    	for (k=0;k<5-i/100%5;k++) printf(" ");
	    	printf("%7.2f%%\r",100-((float)i*100/roadsSize)); _flushall();
	    }
	while (i<=j){
		while(roads[i].linkID<m.linkID) i++;
		while(roads[j].linkID>m.linkID) j--;
		if (i<=j){
			swap(roads[i],roads[j]);
			i++;
			j--;
		}
	}
	if (i<right) quickSort(i,right);
	if (left<j) quickSort(left,j);
}
int quickSort(){
	system("cls");
	puts(sortIcon);
	DWORD time1=timeGetTime();
	quickSort(0,roadsSize-1);
	printf("\r排序完毕！                      \n");
	DWORD time2=timeGetTime();
	sorted=true;
    return time2-time1;	
}

