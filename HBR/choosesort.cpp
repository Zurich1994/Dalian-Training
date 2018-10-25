#include"Map.h"
void ChooseSort(RoadRecord * pRoadRecord,int RoadNum)
{ 

     int i,j,m;
	 float time1,time2;
	 char *a;
	 unsigned long t,u;
	 unsigned short v,w;
	 bool l;
     time1=clock();
	 for(i=0;i<RoadNum-1;i++)
	 {
		 m=i;
		 for(j=i+1;j<RoadNum;j++)
			 if(pRoadRecord[j].LinkID<pRoadRecord[m].LinkID)
				 m=j;

				t=pRoadRecord[i].LinkID;
				pRoadRecord[i].LinkID=pRoadRecord[m].LinkID;
				pRoadRecord[m].LinkID=t;

			 	v=pRoadRecord[i].Bruch;
				pRoadRecord[i].Bruch=pRoadRecord[m].Bruch;
				pRoadRecord[m].Bruch=v;

				v=pRoadRecord[i].dispclass;
				pRoadRecord[i].dispclass=pRoadRecord[m].dispclass;
				pRoadRecord[m].dispclass=v;

				l=pRoadRecord[i].flag;
				pRoadRecord[i].flag=pRoadRecord[m].flag;
				pRoadRecord[m].flag=l;

				v=pRoadRecord[i].RecordSize;
				pRoadRecord[i].RecordSize=pRoadRecord[m].RecordSize;
				pRoadRecord[m].RecordSize=v;

				v=pRoadRecord[i].lengh;
				pRoadRecord[i].lengh=pRoadRecord[m].lengh;
				pRoadRecord[m].lengh=v;

				w=pRoadRecord[i].NameSize;
				pRoadRecord[i].NameSize=pRoadRecord[m].NameSize;
				pRoadRecord[j+1].NameSize=w;

				a=pRoadRecord[i].RoadName;
				pRoadRecord[i].RoadName=pRoadRecord[m].RoadName;
				pRoadRecord[m].RoadName=a;
	 }
	 time2=clock();
	 printf("sort success!\n");
         printf("ÓÃÊ±%.3fÃë\n",(time2-time1)/1000);

}