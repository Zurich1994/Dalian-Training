#include"Map.h"

void BinarySearch4(RoadRecord * pRoadRecord , int RoadNum)
{
	InsertSort(pRoadRecord,RoadNum);

	int i,j,m=0,g;
	int b[1000];
	char name[100];
	printf("�������·���ƣ�");
	scanf("%s",name);
	i=0;
	j=RoadNum-1;
	for(i=0;i<RoadNum;i++)	
		if(pRoadRecord[i].RoadName!=NULL && strcmp(pRoadRecord[i].RoadName,name)==0)
			b[m++]=i;
			
	if(m==0)
		printf("�޽��");

	else if(m>5){
		
			printf("�������5��������ת�浽txt�ļ�.\\data\\searchRoadName.txt��\n");
			FILE * outMap;
			outMap = fopen(".\\data\\searchRoadName.txt","r+");
			if(NULL==outMap)
				printf("wrong\n");
		
			for(g=0;g<m;g++)
			{
				fprintf(outMap, "LinkID=%-10d", pRoadRecord[b[g]].LinkID);
				fprintf(outMap, "flag=%-10d", pRoadRecord[b[g]].flag);
				fprintf(outMap, "Bruch=%-10d", pRoadRecord[b[g]].Bruch);
				fprintf(outMap, "dispclass=%-10hd\n", pRoadRecord[b[g]].dispclass);
				if(pRoadRecord[b[g]].RoadName != NULL)
				{
					fprintf(outMap, "RoadName=%s\n", pRoadRecord[b[g]].RoadName);
				}
			}

			fclose(outMap);
			outMap = NULL;
	}
	else{
		for(g=0;g<m;g++)
		{
			printf("RoadName=%s\n", pRoadRecord[b[g]].RoadName);
			printf("LinkID=%-10d", pRoadRecord[b[g]].LinkID);
			printf("flag=%-10d", pRoadRecord[b[g]].flag);
			printf("Bruch=%-10d",pRoadRecord[b[g]].Bruch);
			printf("dispclass=%-10hd\n", pRoadRecord[b[g]].dispclass);
		}
		
		
	}



}

