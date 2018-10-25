#include"Map.h"

void BubbleSort(RoadRecord * pRoadRecord,int RoadNum)
{
	int i,j;
	double time1,time2;
	char *a;
	unsigned long t,u;
	unsigned short v,w;
	bool l;
	printf("sorting...\n");
	time1=clock();
	
	for(i=0;i<RoadNum-1;i++)
		for(j=0;j<RoadNum-1-i;j++)
 			if(pRoadRecord[j].Bruch>pRoadRecord[j+1].Bruch){
				v=pRoadRecord[j].Bruch;
				pRoadRecord[j].Bruch=pRoadRecord[j+1].Bruch;
				pRoadRecord[j+1].Bruch=v;

				v=pRoadRecord[j].dispclass;
				pRoadRecord[j].dispclass=pRoadRecord[j+1].dispclass;
				pRoadRecord[j+1].dispclass=v;

				v=pRoadRecord[j].lengh;
				pRoadRecord[j].lengh=pRoadRecord[j+1].lengh;
				pRoadRecord[j+1].lengh=v;

				l=pRoadRecord[j].flag;
				pRoadRecord[j].flag=pRoadRecord[j+1].flag;
				pRoadRecord[j+1].flag=l;

				u=pRoadRecord[j].LinkID;
				pRoadRecord[j].LinkID=pRoadRecord[j+1].LinkID;
				pRoadRecord[j+1].LinkID=u;

				v=pRoadRecord[j].RecordSize;
				pRoadRecord[j].RecordSize=pRoadRecord[j+1].RecordSize;
				pRoadRecord[j+1].RecordSize=u;

				w=pRoadRecord[j].NameSize;
				pRoadRecord[j].NameSize=pRoadRecord[j+1].NameSize;
				pRoadRecord[j+1].NameSize=w;

				a=pRoadRecord[j].RoadName;
				pRoadRecord[j].RoadName=pRoadRecord[j+1].RoadName;
				pRoadRecord[j+1].RoadName=a;
			}

	time2=clock();
	printf("sort success!\n");

	printf("”√ ±%.3f√Î\n",(time2-time1)/1000);
}
	
