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
	printf("\t请输入新节点的编号： ");
	scanf("%ld",&roadLinkID);
	while(1)
	{	
		roadlist=*Head;
		while(roadlist->nextRoadNode!=NULL)
		{
			roadlist=roadlist->nextRoadNode;
			if(roadlist->one_Road.RoadLinkID == roadLinkID)
			{
				printf("\t输入的节点编号已经存在，请重新输入： ");
				scanf("%ld",&roadLinkID);
				break;
			}
		}
		if(roadlist->nextRoadNode==NULL)
			break;
	}
		

	srcTemp->RoadLinkID=roadLinkID;
	printf("\t请输入RoadNameFlag:");
	scanf("%u",&RoadNameFlag);
	srcTemp->RoadStaNodeInfo=SET_FLAG(srcTemp->RoadStaNodeInfo,(RoadNameFlag&0x1));
	if(1==RoadNameFlag)
	{
		printf("\t请输入RoadName:");
		scanf("%s",RoadNameBuf);
		srcTemp->RoadName=malloc(strlen(RoadNameBuf)+sizeof("1="));
		strcpy(srcTemp->RoadName,"1=");
		strcat(srcTemp->RoadName,RoadNameBuf);
		srcTemp->RoadNameSize = strlen(srcTemp->RoadName);
	}
	else
	{
		srcTemp->RoadName=malloc(sizeof("暂无名称"));
		strcpy(srcTemp->RoadName,"暂无名称");
		srcTemp->RoadNameSize = 0;
	}
	srcTemp->RoadSize = 14 + srcTemp->RoadNameSize;
	printf("\t请输入Brunch:");
	scanf("%ld",&Brunch);
	srcTemp->RoadStaNodeInfo=SET_BRUNCH(srcTemp->RoadStaNodeInfo,(Brunch&0x7));
	printf("\t请输入DisClass:");
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
	printf("\t\t添加成功！\n");
}

int EditNode(struct Road **Head)
{
	struct Road *roadlist;
	unsigned short int roadSize=0,roadNameSize=0;
	unsigned long roadLinkID=0,RoadNameFlag,Brunch,DisClass,roadStaNodeInfo;
	unsigned char RoadNameBuf[50];

	roadlist=*Head;

	printf("\t请输入要修改的信息的编号： ");
	scanf("%ld",&roadLinkID);

	while(roadlist->nextRoadNode!=NULL)
	{
		roadlist=roadlist->nextRoadNode;
		if(roadlist->one_Road.RoadLinkID == roadLinkID)
		{
			printf("\t请输入新的RoadNameFlag：");
			scanf("%u",&RoadNameFlag);
			roadStaNodeInfo=SET_FLAG(roadStaNodeInfo,(RoadNameFlag&0x1));
			if(1==RoadNameFlag)
			{
				printf("\t请输入新的RoadName: ");
				scanf("%s",RoadNameBuf);
				roadlist->one_Road.RoadName=malloc(strlen(RoadNameBuf)+sizeof("１＝"));
				strcpy(roadlist->one_Road.RoadName,"１＝");
				strcat(roadlist->one_Road.RoadName,RoadNameBuf);
				roadNameSize=strlen(roadlist->one_Road.RoadName);
			}
			else
			{
				roadlist->one_Road.RoadName=malloc(sizeof("暂无名称"));
				strcpy(roadlist->one_Road.RoadName,"暂无名称");
				roadNameSize = 0;
			}
			roadSize=14+roadNameSize;
			printf("\t请输入新的Brunch: ");
			scanf("%u",&Brunch);
			roadStaNodeInfo=SET_BRUNCH(roadStaNodeInfo,(Brunch&0x7));
			printf("\t请输入DisClass:");
			scanf("%u",&DisClass);
			roadStaNodeInfo=SET_DISPCLASS(roadStaNodeInfo,(DisClass&0xf));
			roadlist->one_Road.RoadLinkID=roadLinkID;
			roadlist->one_Road.RoadNameSize=roadNameSize;
			roadlist->one_Road.RoadSize=roadSize;
			roadlist->one_Road.RoadStaNodeInfo=roadStaNodeInfo;
			printf("\t修改成功！\n");
			return 1;
		}
	}
	printf("\t没有找到标号为%d的信息，请检查您的输入....\n",roadLinkID);
	return 0;
}

int DeleteNode(struct Road **Head)
{
	struct Road *curNode,*nexNode;
	unsigned long roadLinkId;
	//roadlist=*Head;

	curNode=*Head;
	nexNode=curNode->nextRoadNode;
	printf("\t请输入您要删除的信息的序号： ");
	scanf("%d",&roadLinkId);
	while(nexNode!=NULL)
	{
		if(nexNode->one_Road.RoadLinkID == roadLinkId)
		{
			curNode->nextRoadNode=nexNode->nextRoadNode;
			free(nexNode);
			printf("\t删除完成！");
			return 1;
		}
		curNode=nexNode;
		nexNode=nexNode->nextRoadNode;
	}
	return 0;
}

*/
