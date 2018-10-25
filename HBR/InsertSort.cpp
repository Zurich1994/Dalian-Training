#include "Map.h"


void InsertSort(RoadRecord * pRoadRecord,int RoadNum){

	int i,j;
	char *a;
	bool u;
	unsigned long z;
	unsigned short v,w,x,y,q;
	float time1,time2;
	time1=clock();
	
	for(i=1;i<RoadNum;i++){
		u=pRoadRecord[i].flag;
		x=pRoadRecord[i].dispclass;
		y=pRoadRecord[i].Bruch;
		q=pRoadRecord[i].lengh;
		v=pRoadRecord[i].RecordSize;
		w=pRoadRecord[i].NameSize;	
		a=pRoadRecord[i].RoadName;	
		z=pRoadRecord[i].LinkID;
		j=i-1;
		
		while( x<pRoadRecord[j].dispclass && j>=0)
		{
			
				pRoadRecord[j+1].LinkID=pRoadRecord[j].LinkID;
				pRoadRecord[j+1].flag=pRoadRecord[j].flag;
				pRoadRecord[j+1].dispclass=pRoadRecord[j].dispclass;
				pRoadRecord[j+1].Bruch=pRoadRecord[j].Bruch;
				pRoadRecord[j+1].lengh=pRoadRecord[j].lengh;
				pRoadRecord[j+1].RecordSize=pRoadRecord[j].RecordSize;
				pRoadRecord[j+1].NameSize=pRoadRecord[j].NameSize;
				pRoadRecord[j+1].RoadName=pRoadRecord[j].RoadName;
				j--;
		}
		
		pRoadRecord[j+1].RecordSize=v;
		pRoadRecord[j+1].NameSize=w;
		pRoadRecord[j+1].RoadName=a;
		pRoadRecord[j+1].LinkID=z;
		pRoadRecord[j+1].dispclass=x;
		pRoadRecord[j+1].flag=u;
		pRoadRecord[j+1].Bruch=y;
		pRoadRecord[j+1].lengh=q;
	
	}
	time2=clock();
	printf("sort success!\n");
	printf("”√ ±%.3f√Î\n",(time2-time1)/1000);
}

