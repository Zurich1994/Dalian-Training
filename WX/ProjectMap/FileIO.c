
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"
#include "StructFile.h"
#include "TransferFormat.h"

int count;
int CreateLink(FILE *fp,struct Road **roadlist);
void sort_swap(struct Road_Info *array,int a,int b);
int sort_quicksort(struct Road_Info *array,int l,int r);
void FILEIO_ArrayTo2DAT(struct Road_Info *array,char *filepath,int nodeNum);
void FILEIO_ArrayTo2TXT(struct Road_Info *array,char *filepath,int nodeNum);



int LoadFile(unsigned char *filepath,struct Road **roadlist)
{
	FILE *fp;
	if((fp=fopen(filepath,"rb+"))==NULL)
	{
		printf("Can not open.....\n");
		exit(0);
	}	
	count=CreateLink(fp,roadlist);
	return 0;
}

int CreateLink(FILE *fp,struct Road **roadlist)
{
	long nodeNum = 0;
	struct Road *Head,*CurNode,*NexNode;
	unsigned short int roadSize = 0,roadNameSize = 0;
	unsigned long roadLinkID = 0,roadInfo = 0;
	unsigned char roadInfoBuff[50];
	Head = NULL;
	CurNode = NULL;
	NexNode = NULL;
	Head = malloc(sizeof(struct Road));
	NexNode = Head;
	
	while(1)
	{
		CurNode =malloc(sizeof(struct Road));
		
		fread(&roadSize,sizeof(short int),1,fp);
		roadSize =M_CHG_INT16(roadSize);
		CurNode->one_Road.RoadSize=roadSize;
		
		fread(&roadLinkID,sizeof(long),1,fp);
		roadLinkID=M_CHG_INT32(roadLinkID);
		CurNode->one_Road.RoadLinkID=roadLinkID;
		
		fread(&roadNameSize,sizeof(short int),1,fp);
		roadNameSize =M_CHG_INT16(roadNameSize);
		CurNode->one_Road.RoadNameSize =roadNameSize;
		
		fread(&roadInfo,sizeof(long),1,fp);
		roadInfo=M_CHG_INT32(roadInfo);
		CurNode->one_Road.RoadStaNodeInfo =roadInfo;
		
		
		if(feof(fp))
			break;
		
		if(GET_FLAG(roadInfo) == 1)
		{
			CurNode->one_Road.RoadName =malloc(roadNameSize+2);
			fread(roadInfoBuff,roadNameSize+2,1,fp);
			strcpy(CurNode->one_Road.RoadName ,roadInfoBuff);
		}
		else
		{
			CurNode->one_Road.RoadName =malloc(sizeof("暂无名称"));
			strcpy(CurNode->one_Road.RoadName ,"暂无名称");
		}
		CurNode->nextRoadNode = NULL;
		NexNode->nextRoadNode = CurNode;
		NexNode = CurNode;
		nodeNum++;
	}
	*roadlist = Head;
	return nodeNum;
}





void LinkToArray(struct Road **RoadList,int choice)
{
	
	long arraysize;
	struct Road *Head;
	struct Road_Info *Road = NULL;
	int index = 0;
	int i = 0;
	int j = 0;
	clock_t start,finish;
	struct Road_Info RoadTemp;
	arraysize =count*(sizeof(struct Road));
	Road =(struct Road_Info*)malloc(arraysize);
	Head =*RoadList;
	while(Head->nextRoadNode != NULL)
	{
		Head =Head->nextRoadNode ; 
		Road[index].RoadLinkID =Head->one_Road.RoadLinkID ;
		Road[index].RoadNameSize =Head->one_Road.RoadNameSize ;
		Road[index].RoadSize =Head->one_Road.RoadSize ;
		Road[index].RoadStaNodeInfo =Head->one_Road.RoadStaNodeInfo ;
		if(GET_FLAG(Road[index] .RoadStaNodeInfo ) == 1)
		{
			Road[index].RoadName =malloc(Road[index].RoadNameSize +2);
			strcpy(Road[index] .RoadName,Head->one_Road.RoadName );
		}
		else
		{
			Road[index].RoadName =malloc(sizeof("暂无名称"));
			strcpy(Road[index].RoadName ,"暂无名称");
		}
		index++;
	}
	if(choice == 1)
	{
		start = clock();
        printf("\t\t时间较长,请您耐心等待>>(=^ ^=)<<\n");
       
		for(i = 0;i < index;i++)
		{
			for(j = 0;j < index-1;j++)
			{
				if(Road[j].RoadLinkID > Road[j+1].RoadLinkID )
				{
					memcpy(&RoadTemp,&Road[j],sizeof(struct Road_Info));
					memcpy(&Road[j],&Road[j+1],sizeof(struct Road_Info));
					memcpy(&Road[j+1],&RoadTemp,sizeof(struct Road_Info));
					memset(&RoadTemp,0,sizeof(struct Road_Info));
				}	
			}       
			if(i % 900 == 0)
			{
				printf(".");
			}
            
		} //printf("\t\t\t\t\t\t\t\t100%%");
		finish=clock();
		printf("\n\tO(∩_∩)O哈哈~排序成功,运行时间：\n\t\t\t%4.2fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	}
	if(choice == 2)
	{ 
        printf("\t\t时间不长,请您耐心等待>>(=^ ^=)<<\n");
		start = clock();
		for(i = 0;i < index;i++)
		{
			for(j = i+1;j < index;j++)
			{
				if(Road[j].RoadLinkID < Road[i].RoadLinkID )
				{
					memcpy(&RoadTemp,&Road[j],sizeof(struct Road_Info));
					memcpy(&Road[j],&Road[i],sizeof(struct Road_Info));
					memcpy(&Road[i],&RoadTemp,sizeof(struct Road_Info));
					memset(&RoadTemp,0,sizeof(struct Road_Info));
				}	
			}
           
			if(i % 1000 == 0)
			{
				printf(".");
			}
		}
		finish = clock();
		printf("\n\tO(∩_∩)O哈哈~排序成功,运行时间：\n\t\t\t%4.2fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	}
	if(choice == 3)
	{
		start = clock();
		sort_quicksort(Road,0,count-1);
		finish = clock();
		printf("\tO(∩_∩)O哈哈~排序成功,运行时间：\n\t\t\t%4.2fs\n",(double)(finish-start)/CLOCKS_PER_SEC);
	}

	FILEIO_ArrayTo2DAT(Road,"c:\\SortGTBL.dat",count);
	printf("\to(≧v≦)o~~好棒嘔文件保存完成！\n\n");
	FILEIO_ArrayTo2TXT(Road,"c:\\SortGTBL.txt",count);

}

int sort_quicksort(struct Road_Info *array,int l,int r)
{
	int i = 0,j = 0;
	int iDatasize = 0;
	struct Road_Info pivot;

	if(l >= r)
		return 0;
	i = l-1;
	j = r+1;
	iDatasize =sizeof(struct Road_Info);
	memset( &pivot, 0, iDatasize );
    memcpy( &pivot, &array[(l+r)/2], iDatasize );

	while(1)
	{
		do
		{
			i = i+1;
		}while(array[i].RoadLinkID <pivot.RoadLinkID );
		do
		{
			j = j-1;
		}while(array[j].RoadLinkID >pivot.RoadLinkID );
        if(i >= j)break;
		sort_swap(array,i,j);
        
	}
	sort_quicksort(array,l,j);
    sort_quicksort(array,j+1,r);
	return 0;
}

void sort_swap(struct Road_Info *array,int a,int b)
{
	int iDataSize = 0;
    struct Road_Info stExchgLnk;
	
	iDataSize = sizeof(struct Road_Info);
	memset( &stExchgLnk, 0, iDataSize );	
	memcpy( &stExchgLnk, &array[a], iDataSize );	
	memcpy( &array[a],&array[b], iDataSize );
	memcpy(&array[b], &stExchgLnk, iDataSize );
}


void FILEIO_ArrayTo2DAT(struct Road_Info *array,char *filepath,int nodeNum)
{
	unsigned short int roadSize = 0,roadNameSize = 0;
	unsigned long roadLinkID = 0,roadInfo = 0;
	int i = 0;
	FILE *fp;
	if((fp =fopen(filepath,"wb+")) ==NULL)
	{
		printf("File Open Failed!\n");
		exit(0);
	}
	for(i = 0;i < nodeNum;i++)
	{
		roadSize =M_CHG_INT16(array[i].RoadSize );
		fwrite(&roadSize,sizeof(unsigned short int),1,fp);

		roadLinkID =M_CHG_INT32(array[i].RoadLinkID );
		fwrite(&roadLinkID,sizeof(unsigned long),1,fp);

		roadNameSize =M_CHG_INT16(array[i].RoadNameSize );
		fwrite(&roadNameSize,sizeof(unsigned short int),1,fp);

		roadInfo =M_CHG_INT32(array[i].RoadStaNodeInfo );
		fwrite(&roadInfo,sizeof(unsigned long),1,fp);
		if(1 == GET_FLAG(array[i].RoadStaNodeInfo))
		{
			fwrite(array[i].RoadName ,array[i].RoadNameSize +2,1,fp);
		}
		else
		{

		}
	}
	fclose(fp);
}

void FILEIO_ArrayTo2TXT(struct Road_Info *array,char *filepath,int nodeNum)
{
	int iCounter = 0;
	FILE *fp;
	if((fp =fopen(filepath,"w+")) == NULL)
	{
		printf("File Open Failed!\n");
		exit(0);
	}
	fprintf(fp,"linkid         roadnameflag   brunch         dispclass      roadname\n");
    for(iCounter = 0;iCounter < nodeNum;iCounter++)
	{
		if(GET_FLAG(array[iCounter].RoadStaNodeInfo ) == 1)
			fprintf(fp,"%-15u%-25u%-19u%-19u%s\n",array[iCounter].RoadLinkID ,
            GET_FLAG(array[iCounter].RoadStaNodeInfo ),GET_BRUNCH(array[iCounter].RoadStaNodeInfo ),
            GET_DISPCLASS(array[iCounter].RoadStaNodeInfo ),array[iCounter].RoadName +4);
		else
            fprintf(fp,"%-15u%-25u%-19u%-19u%s\n",array[iCounter].RoadLinkID ,
            GET_FLAG(array[iCounter].RoadStaNodeInfo ),GET_BRUNCH(array[iCounter].RoadStaNodeInfo ),
            GET_DISPCLASS(array[iCounter].RoadStaNodeInfo ),array[iCounter].RoadName );
	}
	fclose(fp);
}

void FILEIO_LinkTo2TXT(struct Road **array,char *pfilepath)
{
	struct Road *head;
	FILE *pfile;
	head =(*array)->nextRoadNode ;
	

	pfile =fopen(pfilepath,"w+");
	fprintf(pfile,"linkid         roadnameflag   brunch         dispclass      roadname\n");
    while(NULL!=head)
	{
		if(1==GET_FLAG(head->one_Road.RoadStaNodeInfo))
			fprintf(pfile,"%-15u%-25u%-19u%-19u%s\n",head->one_Road.RoadLinkID,
            GET_FLAG(head->one_Road .RoadStaNodeInfo ),GET_BRUNCH(head->one_Road .RoadStaNodeInfo ),
            GET_DISPCLASS(head->one_Road .RoadStaNodeInfo ),head->one_Road .RoadName +4);
		else
            fprintf(pfile,"%-15u%-25u%-19u%-19u%s\n",head->one_Road.RoadLinkID,
            GET_FLAG(head->one_Road .RoadStaNodeInfo ),GET_BRUNCH(head->one_Road .RoadStaNodeInfo ),
            GET_DISPCLASS(head->one_Road .RoadStaNodeInfo ),head->one_Road .RoadName );
		head=head->nextRoadNode ;
	}
	fclose(pfile);
}


void FILEIO_LinkTo2DAT(struct Road **array,char *pfilepath)
{
	unsigned short int roadSize = 0,roadNameSize = 0;
	unsigned long roadLinkID = 0,roadInfo =0;
	struct Road *head;
	FILE *pfile;
	head=(*array)->nextRoadNode ;
	
	
	pfile=fopen(pfilepath,"wb+");
	while(NULL!=head)
	{
		roadSize =M_CHG_INT16(head->one_Road.RoadSize );
		fwrite(&roadSize,sizeof(unsigned short int),1,pfile);
        
		roadLinkID =M_CHG_INT32(head->one_Road .RoadLinkID );
        fwrite(&roadLinkID,sizeof(unsigned long),1,pfile);
        
		roadNameSize=M_CHG_INT16(head->one_Road .RoadNameSize );
		fwrite(&roadNameSize,sizeof(unsigned short int),1,pfile);
		
        roadInfo=M_CHG_INT32(head->one_Road .RoadStaNodeInfo );
		fwrite(&roadInfo,sizeof(unsigned long),1,pfile);
		if(1==GET_FLAG(head->one_Road .RoadStaNodeInfo ))
		{
			fwrite(head->one_Road .RoadName ,head->one_Road .RoadNameSize +2,1,pfile);
		}
		else
		{

		}
		head=head->nextRoadNode ;
	}
	fclose(pfile);
	fclose(pfile);
}


void LinkToArray_2(struct Road **RoadList,int choice)
{
	
	long arraysize;
	struct Road *Head;
	struct Road_Info *Road=NULL;
	int index=0;
	int i=0;
	int j=0;
	struct Road_Info RoadTemp;
	arraysize=count*(sizeof(struct Road));
	Road=(struct Road_Info*)malloc(arraysize);
	Head=*RoadList;
	while(Head->nextRoadNode!=NULL)
	{
		Head=Head->nextRoadNode;
		Road[index].RoadLinkID =Head->one_Road .RoadLinkID ;
		Road[index].RoadNameSize =Head->one_Road .RoadNameSize ;
		Road[index].RoadSize =Head->one_Road .RoadSize ;
		Road[index].RoadStaNodeInfo =Head->one_Road .RoadStaNodeInfo ;
		if(1==GET_FLAG(Road[index] .RoadStaNodeInfo ))
		{
			Road[index].RoadName=malloc(Road[index].RoadNameSize+2);
			strcpy(Road[index] .RoadName ,Head->one_Road .RoadName );
		}
		else
		{
			Road[index].RoadName=malloc(sizeof("暂无名称"));
			strcpy(Road[index].RoadName,"暂无名称");
		}
		index++;
	}
	if(choice == 3)
	{

		sort_quicksort(Road,0,count-1);

	}

	FILEIO_ArrayTo2DAT(Road,"C:\\updata.dat",count);
	FILEIO_ArrayTo2TXT(Road,"C:\\updata.txt",count);
    FILEIO_ArrayTo2TXT(Road,"C:\\updata.txt",count);
}
