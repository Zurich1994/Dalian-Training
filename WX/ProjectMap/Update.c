#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Formation.h"
#include "StructFile.h"
#include "TransferFormat.h"



extern int count;
/*
void AddNode(struct Road **Head)
{
	struct Road *roadlist,*newNode;
	struct Road_Info *srcTemp;
	unsigned short int roadSize=0,roadNameSize=0;
	unsigned long roadLinkID=0,RoadNameFlag,Brunch,DisClass;
	unsigned char RoadNameBuf[50];
	srcTemp=malloc(sizeof(struct Road_Info));
	memset(srcTemp,0,sizeof(struct Road_Info));	
	printf("\t�������½ڵ�ı�ţ� ");
	scanf("%ld",&roadLinkID);
	while(1)
	{	
		roadlist=*Head;
		while(roadlist->nextRoadNode!=NULL)
		{
			roadlist=roadlist->nextRoadNode;
			if(roadlist->one_Road.RoadLinkID == roadLinkID)
			{
				printf("\t����Ľڵ����Ѿ����ڣ����������룺 ");
				scanf("%ld",&roadLinkID);
				break;
			}
		}
		if(roadlist->nextRoadNode==NULL)
			break;
	}
		

	srcTemp->RoadLinkID=roadLinkID;
	printf("\t������RoadNameFlag:");
	scanf("%u",&RoadNameFlag);
	srcTemp->RoadStaNodeInfo=SET_FLAG(srcTemp->RoadStaNodeInfo,(RoadNameFlag&0x1));
	if(1==RoadNameFlag)
	{
		printf("\t������RoadName:");
		scanf("%s",RoadNameBuf);
		srcTemp->RoadName=malloc(strlen(RoadNameBuf)+sizeof("1="));
		strcpy(srcTemp->RoadName,"1=");
		strcat(srcTemp->RoadName,RoadNameBuf);
		srcTemp->RoadNameSize = strlen(srcTemp->RoadName);
	}
	else
	{
		srcTemp->RoadName=malloc(sizeof("��������"));
		strcpy(srcTemp->RoadName,"��������");
		srcTemp->RoadNameSize = 0;
	}
	srcTemp->RoadSize = 14 + srcTemp->RoadNameSize;
	printf("\t������Brunch:");
	scanf("%ld",&Brunch);
	srcTemp->RoadStaNodeInfo=SET_BRUNCH(srcTemp->RoadStaNodeInfo,(Brunch&0x7));
	printf("\t������DisClass:");
	scanf("%ld",&DisClass);
	srcTemp->RoadStaNodeInfo=SET_DISPCLASS(srcTemp->RoadStaNodeInfo,(DisClass&0xf));
   
	newNode = malloc(sizeof(struct Road));
	memset(newNode,0,sizeof(struct Road));
	newNode->one_Road.RoadLinkID=srcTemp->RoadLinkID;
	newNode->one_Road.RoadName=srcTemp->RoadName;
	newNode->one_Road.RoadNameSize=srcTemp->RoadNameSize;
	newNode->one_Road.RoadSize=srcTemp->RoadSize;
	newNode->one_Road.RoadStaNodeInfo=srcTemp->RoadStaNodeInfo;
	//printf("%d\n",newNode->one_Road.)
	roadlist=*Head;
	newNode->nextRoadNode=roadlist->nextRoadNode;
	roadlist->nextRoadNode=newNode;
	newNode=NULL;
	printf("\t\t��ӳɹ���\n");
}

int EditNode(struct Road **Head)
{
	struct Road *roadlist;
	unsigned short int roadSize=0,roadNameSize=0;
	unsigned long roadLinkID=0,RoadNameFlag,Brunch,DisClass,roadStaNodeInfo;
	unsigned char RoadNameBuf[50];

	roadlist=*Head;

	printf("\t������Ҫ�޸ĵ���Ϣ�ı�ţ� ");
	scanf("%ld",&roadLinkID);

	while(roadlist->nextRoadNode!=NULL)
	{
		roadlist=roadlist->nextRoadNode;
		if(roadlist->one_Road.RoadLinkID == roadLinkID)
		{
			printf("\t�������µ�RoadNameFlag��");
			scanf("%u",&RoadNameFlag);
			roadStaNodeInfo=SET_FLAG(roadStaNodeInfo,(RoadNameFlag&0x1));
			if(1==RoadNameFlag)
			{
				printf("\t�������µ�RoadName: ");
				scanf("%s",RoadNameBuf);
				roadlist->one_Road.RoadName=malloc(strlen(RoadNameBuf)+sizeof("����"));
				strcpy(roadlist->one_Road.RoadName,"����");
				strcat(roadlist->one_Road.RoadName,RoadNameBuf);
				roadNameSize=strlen(roadlist->one_Road.RoadName);
			}
			else
			{
				roadlist->one_Road.RoadName=malloc(sizeof("��������"));
				strcpy(roadlist->one_Road.RoadName,"��������");
				roadNameSize = 0;
			}
			roadSize=14+roadNameSize;
			printf("\t�������µ�Brunch: ");
			scanf("%u",&Brunch);
			roadStaNodeInfo=SET_BRUNCH(roadStaNodeInfo,(Brunch&0x7));
			printf("\t������DisClass:");
			scanf("%u",&DisClass);
			roadStaNodeInfo=SET_DISPCLASS(roadStaNodeInfo,(DisClass&0xf));
			roadlist->one_Road.RoadLinkID=roadLinkID;
			roadlist->one_Road.RoadNameSize=roadNameSize;
			roadlist->one_Road.RoadSize=roadSize;
			roadlist->one_Road.RoadStaNodeInfo=roadStaNodeInfo;
			printf("\t�޸ĳɹ���\n");
			return 1;
		}
	}
	printf("\tû���ҵ����Ϊ%d����Ϣ��������������....\n",roadLinkID);
	return 0;
}

int DeleteNode(struct Road **Head)
{
	struct Road *curNode,*nexNode;
	unsigned long roadLinkId;
	//roadlist=*Head;

	curNode=*Head;
	nexNode=curNode->nextRoadNode;
	printf("\t��������Ҫɾ������Ϣ����ţ� ");
	scanf("%d",&roadLinkId);
	while(nexNode!=NULL)
	{
		if(nexNode->one_Road.RoadLinkID == roadLinkId)
		{
			curNode->nextRoadNode=nexNode->nextRoadNode;
			free(nexNode);
			printf("\tɾ����ɣ�");
			return 1;
		}
		curNode=nexNode;
		nexNode=nexNode->nextRoadNode;
	}
	return 0;
}

*/
