#include "Map.h"

int QuickSort(RoadRecord *pRoadRecord,int left,int right){  
	int p = (left + right)/2;   
	char *a;
	bool u;
	unsigned short v,w,x,y,q;  
	int key = pRoadRecord[p].LinkID;  
		u=pRoadRecord[p].flag;
		x=pRoadRecord[p].dispclass;
		y=pRoadRecord[p].Bruch;
		q=pRoadRecord[p].lengh;
		v=pRoadRecord[p].RecordSize;
		w=pRoadRecord[p].NameSize;	
		a=pRoadRecord[p].RoadName;	
	
	for(int i = left,j = right; i < j;){      
		
		while(!(key < pRoadRecord[i].LinkID || p < i))           
			i++;    
		
			if(i < p){  
				
				pRoadRecord[p].LinkID= pRoadRecord[i].LinkID;    
			
				pRoadRecord[p].flag=pRoadRecord[i].flag;
				pRoadRecord[p].dispclass=pRoadRecord[i].dispclass;
				pRoadRecord[p].Bruch=pRoadRecord[i].Bruch;
				pRoadRecord[p].lengh=pRoadRecord[i].lengh;
				pRoadRecord[p].RecordSize=pRoadRecord[i].RecordSize;
				pRoadRecord[p].NameSize=pRoadRecord[i].NameSize;
				pRoadRecord[p].RoadName=pRoadRecord[i].RoadName;
				p = i;
			} 
			
		while(j>0 && !(j < p || pRoadRecord[j].LinkID < key))           
			j--;  
		
			if(p < j){             
				pRoadRecord[p].LinkID = pRoadRecord[j].LinkID;  	
				pRoadRecord[p].flag=pRoadRecord[j].flag;
				pRoadRecord[p].dispclass=pRoadRecord[j].dispclass;
				pRoadRecord[p].Bruch=pRoadRecord[j].Bruch;
				pRoadRecord[p].lengh=pRoadRecord[j].lengh;
				pRoadRecord[p].RecordSize=pRoadRecord[j].RecordSize;
				pRoadRecord[p].NameSize=pRoadRecord[j].NameSize;
				pRoadRecord[p].RoadName=pRoadRecord[j].RoadName;           
				p = j;       
			}     
	}  
	pRoadRecord[p].LinkID = key;  	
		pRoadRecord[p].RecordSize=v;
		pRoadRecord[p].NameSize=w;
		pRoadRecord[p].RoadName=a;
		pRoadRecord[p].dispclass=x;
		pRoadRecord[p].flag=u;
		pRoadRecord[p].lengh=q;
		pRoadRecord[p].Bruch=y;    
	if(p - left > 1)          
		QuickSort(pRoadRecord,left,p-1);    
	if(right - p > 1)        
		QuickSort(pRoadRecord,p + 1, right); 
	return 0;
} 
int QuickSortTime(RoadRecord *pRoadRecord,int left,int right){

	double time1,time2;
	time1=clock();

	QuickSort(pRoadRecord,left,right);

	time2=clock();

	printf("”√ ±%.3f√Î\n",(time2-time1)/1000);
		return 0;

} 
