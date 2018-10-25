#include"emap.h"
#include<cstdlib>
#include<cstring>

extern Road *roads;
// 保存所有道路的数组
extern int roadsSize;
// 道路数量

Road queryByLinkID(const unsigned int linkID){
	for (int i=0;i<roadsSize;i++)
		if (roads[i].linkID==linkID)
			return roads[i];
	return nullRoad; 
}

Road queryByLinkIDBinary(const unsigned int linkID){
	int i=0,j=roadsSize-1;
	Road x;
	int m;
	while (i<j){
		m=(i+j)>>1;
		x=roads[m];
		if (x.linkID>=linkID) j=m;
		else i=m+1;
	}
	if(roads[i].linkID==linkID) return roads[i];
	else return nullRoad;
}

struct Road* queryByDispClass(const unsigned int dispClass,int * n)
{ 
	int i,j=0;struct Road *p;
	for(i=0;i<roadsSize;i++)
	{
		if(roads[i].dispClass==dispClass)
			j++;	
	}
    p=(struct Road*)malloc(sizeof(struct Road)*j);
	int k=0;
	for(i=0;i<roadsSize;i++)
	{
		if(roads[i].dispClass==dispClass)
		{
			p[k]=roads[i];
			k++;
		}
	}
	*n=j;
    return p;
}

struct Road* queryByName(char * const name,int * n)
{  
	int i,j=0;struct Road *p;
	for(i=0;i<roadsSize;i++)
	{
		if(strcmp(roads[i].name,name)==0)
			j++;	
	}
    p=(struct Road*)malloc(sizeof(struct Road)*j);
    int k=0;
    *n=j;
	for(i=0;i<roadsSize;i++)
	{
		if(strcmp(roads[i].name,name)==0)
		{
			p[k]=roads[i];
			k++;
		}
	}
	return p;
}

struct Road* queryByBranch(int const branch,int *n){
	int i,c=0;
	for(i=0;i<roadsSize;i++){
		if(roads[i].branch==branch)
			c++;  
	}
	*n=c;
	struct Road*p=(struct Road*)malloc(sizeof(struct Road)*c);
	int k=0;
	for(i=0;i<roadsSize;i++){
		if(roads[i].branch==branch){
			p[k]=roads[i];
			k++;
		}                      
	}
	return p;
} 

