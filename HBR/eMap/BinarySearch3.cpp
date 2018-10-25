#include"Map.h"

void BinarySearch3(RoadRecord * pRoadRecord , int RoadNum)
{
	BubbleSort(pRoadRecord,RoadNum);
	int i,j,m,Bruch;
	int f,l;
	printf("请输入Link的Bruch(岔道数)数量：");
	scanf("%d",&Bruch);
	i=0;
	j=RoadNum-1;
	m=(i+j)/2;
	
	while(Bruch!=(pRoadRecord[m].Bruch) &&i<=j){

		if((pRoadRecord[m].Bruch)>Bruch)
				 j=m-1;
        if((pRoadRecord[m].Bruch)<Bruch)
				 i=m+1;
				m=(i+j)/2;
	}

	if(i<=j)
	{
		printf("结果大于5条，将其转存到txt文件.\\data\\searchBruch.txt中\n");
		FILE * outMap;
		outMap = fopen(".\\data\\searchBruch.txt","r+");
		if(NULL==outMap)
			printf("wrong\n");
		f=m;
		l=m;
		for(int k=m;;k++)
		{
			if(pRoadRecord[k].Bruch==Bruch)
				l++;
			else break;
		}
		for(k=m;;k--)
		{
			if(pRoadRecord[k].Bruch==Bruch)
				f--;
			else break;
		}

		for( k=f+1;k<l;k++)
		{
			fprintf(outMap, "LinkID=%-10d", pRoadRecord[k].LinkID);
			fprintf(outMap, "flag=%-10d", pRoadRecord[k].flag);
			fprintf(outMap, "Bruch=%-10d", pRoadRecord[k].Bruch);
			fprintf(outMap, "dispclass=%-10hd\n", pRoadRecord[k].dispclass);
			if(pRoadRecord[k].RoadName != NULL)
			{
				fprintf(outMap, "RoadName=%s\n", pRoadRecord[k].RoadName);
			}
		}

		fclose(outMap);
		outMap = NULL;
	}
	else printf("无结果!\n");
}
