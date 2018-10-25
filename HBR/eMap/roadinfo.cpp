#include "Map.h"
void RoadInfomation(RoadRecord * pRoadRecord , int RoadNum)
{
	int i;
    for(i=0;i<RoadNum;i++)
    {
        pRoadRecord[i].flag=(bool)((pRoadRecord[i].RoadInfo & 128)>>7);
        pRoadRecord[i].Bruch=(pRoadRecord[i].RoadInfo & 112)>>4;
        pRoadRecord[i].dispclass=pRoadRecord[i].RoadInfo&15;

		if(pRoadRecord[i].RoadName != NULL)
		{
			pRoadRecord[i].lengh=pRoadRecord[i].RecordSize-12;
		}
		else
		{
			pRoadRecord[i].lengh=0;
		}
		
	}
}
