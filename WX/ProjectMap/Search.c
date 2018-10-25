#include <stdio.h>
#include <stdlib.h>
#include "StructFile.h"
#include "TransferFormat.h"
#include "string.h"

int Sort_LinkID(struct Road **Head,long linkID)
{
	struct Road *roadlist;
	roadlist=*Head;	
	while(roadlist->nextRoadNode != NULL)
	{
	
			roadlist=roadlist->nextRoadNode;
		if(roadlist->one_Road.RoadLinkID == linkID)
		{
			printf("��ѯ���Ϊ��\n");
			printf("*************************************************************************\n");
			if(1==GET_FLAG(roadlist->one_Road.RoadStaNodeInfo))
			{
				printf("#linkid=%u;roadnameflag=%u;bruch=%u;dispclass=%u;roadname=%s#\n",roadlist->one_Road.RoadLinkID,GET_FLAG(roadlist->one_Road.RoadStaNodeInfo),GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo),GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo),roadlist->one_Road.RoadName);
			}
			else
			{
				printf("#linkid=%u;roadnameflag=%u;bruch=%u;dispclass=%u;��������#\n",roadlist->one_Road.RoadLinkID,GET_FLAG(roadlist->one_Road.RoadStaNodeInfo),GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo),GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo));	
			}
			printf("*************************************************************************\n");
			printf("�����������....\n");            
			getchar();
			return 0;
		}
        
	}

	printf("\tû���ҵ�ƥ������������\n");
	printf("�����������....\n");
	getchar();
	getchar();
	system("CLS");
	return 0;
}
void Sort_RoadName(struct Road **Head,char name[20])
{
	char linkID[20]="\0";
	char disClassNo[20]="\0";
	char roadFlag[5]="\0";
	char roadBrunch[20]="\0";
	FILE *fp;
	struct Road *roadlist;
	int count=0;
	roadlist=*Head;
	
	printf("��ѯ���Ϊ��\n");
	while(roadlist->nextRoadNode != NULL)
	{
		roadlist=roadlist->nextRoadNode ;
		if((strcmp(roadlist->one_Road .RoadName ,name))==0)
		{
			count++;
		}
	}
	printf("%d\n",count);
	if(count <= 5)
	{
		roadlist=*Head;
		printf("*************************************************************************\n");
		while(roadlist->nextRoadNode != NULL)
		{
			roadlist=roadlist->nextRoadNode ;
			if((strcmp(roadlist->one_Road .RoadName ,name))==0)
			{
				if(1==GET_FLAG(roadlist->one_Road .RoadStaNodeInfo ))
				{
					printf("#linkid=%u;roadnameflag=%u;bruch=%u;dispclass=%u;roadname=%s#\n",
                        roadlist->one_Road.RoadLinkID,GET_FLAG(roadlist->one_Road.RoadStaNodeInfo),
                        GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo),
                        GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo),roadlist->one_Road.RoadName);
				}
				else
				{
					printf("#linkid=%u;roadnameflag=%u;bruch=%u;dispclass=%u;��������#\n",
                        roadlist->one_Road.RoadLinkID,GET_FLAG(roadlist->one_Road.RoadStaNodeInfo),
                        GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo),
                        GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo));	
				}
			}
		}
		printf("*************************************************************************\n");
	}
	else if(count >5)
	{		
		printf("*************************************************************************\n");
		printf("��Ŀ����5�������ݽ��������ı��ļ� ./data/����/Sort_RoadName.txt ��\n");
		printf("*************************************************************************\n");
		roadlist=*Head;
		if((fp=fopen("C:\\Sort_RoadName.txt","w"))==NULL)
		{
			exit(0);
		}
		fputs("LinkID\tDisClass\tRoadNameFlag\tBrunch\tRoadName\n",fp);
		printf("Here!");
		while(roadlist->nextRoadNode != NULL)
		{
			roadlist=roadlist->nextRoadNode;
			if((strcmp(roadlist->one_Road.RoadName,name))==0)
			{
				if(1==GET_FLAG(roadlist->one_Road.RoadStaNodeInfo))
				{
					sprintf(linkID,"%ld",roadlist->one_Road.RoadLinkID);
					fputs(linkID,fp);
					fputs("\t",fp);
					sprintf(disClassNo,"%d",GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo));
					fputs(disClassNo,fp);
					fputs("\t",fp);
					sprintf(roadFlag,"%d",GET_FLAG(roadlist->one_Road.RoadStaNodeInfo));
					fputs(roadFlag,fp);
					fputs("\t\t",fp);
					sprintf(roadBrunch,"%d",GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo));
					fputs(roadBrunch,fp);
					fputs("\t",fp);
					fputs(roadlist->one_Road.RoadName,fp);
					fputs("\n",fp);
				}
				else
				{
					sprintf(linkID,"%ld",roadlist->one_Road.RoadLinkID);
					fputs(linkID,fp);
					fputs("\t",fp);
					sprintf(disClassNo,"%d",GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo));
					fputs(disClassNo,fp);
					fputs("\t",fp);
					sprintf(roadFlag,"%d",GET_FLAG(roadlist->one_Road.RoadStaNodeInfo));
					fputs(roadFlag,fp);
					fputs("\t\t",fp);
					sprintf(roadBrunch,"%d",GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo));
					fputs(roadBrunch,fp);
					fputs("\t",fp);
					fputs("��������",fp);
					fputs("\n",fp);
				}
			}
		}
		fclose(fp);
	}
}
void Sort_RoadBrunch(struct Road **Head,int flag)
{
	char linkID[20]="\0";
	char disClassNo[20]="\0";
	char roadFlag[5]="\0";
	char roadBrunch[20]="\0";
	FILE *fp;
	struct Road *roadlist;
	int count=0;
	roadlist=*Head;
	
	printf("��ѯ���Ϊ��\n");
	while(roadlist->nextRoadNode != NULL)
	{
		roadlist=roadlist->nextRoadNode;
		if(GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo) == flag)
		{
			count++;
		}
	}
	printf("%d\n",count);
	if(count <= 5)
	{
		roadlist=*Head;
		printf("*************************************************************************\n");
		while(roadlist->nextRoadNode != NULL)
		{
			roadlist=roadlist->nextRoadNode;
			if(GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo) == flag)
			{
				if(1==GET_FLAG(roadlist->one_Road.RoadStaNodeInfo))
				{
					printf("#linkid=%u;roadnameflag=%u;bruch=%u;dispclass=%u;roadname=%s#\n",
                        roadlist->one_Road.RoadLinkID,GET_FLAG(roadlist->one_Road.RoadStaNodeInfo),
                        GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo),
                        GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo),roadlist->one_Road.RoadName);
				}
				else
				{
					printf("#linkid=%u;roadnameflag=%u;bruch=%u;dispclass=%u;��������#\n",
                        roadlist->one_Road.RoadLinkID,GET_FLAG(roadlist->one_Road.RoadStaNodeInfo),
                        GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo),
                        GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo));	
				}
			}
		}
		printf("*************************************************************************\n");
	}
	else if(count >5)
	{
		
		printf("*************************************************************************\n");
		printf("��Ŀ����5�������ݽ��������ı��ļ� ./data/����/Sort_RoadBrunch.txt ��\n");
		printf("*************************************************************************\n");
		roadlist=*Head;
		if((fp=fopen("C:\\Sort_RoadBrunch.txt","w"))==NULL)
		{
			exit(0);
		}
		fputs("LinkID\tDisClass\tRoadNameFlag\tBrunch\tRoadName\n",fp);
		printf("Here!");
		while(roadlist->nextRoadNode != NULL)
		{
			roadlist=roadlist->nextRoadNode;
			if(GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo) == flag)
			{
				if(1==GET_FLAG(roadlist->one_Road.RoadStaNodeInfo))
				{
					sprintf(linkID,"%ld",roadlist->one_Road.RoadLinkID);
					fputs(linkID,fp);
					fputs("\t",fp);
					sprintf(disClassNo,"%d",GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo));
					fputs(disClassNo,fp);
					fputs("\t",fp);
					sprintf(roadFlag,"%d",GET_FLAG(roadlist->one_Road.RoadStaNodeInfo));
					fputs(roadFlag,fp);
					fputs("\t\t",fp);
					sprintf(roadBrunch,"%d",GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo));
					fputs(roadBrunch,fp);
					fputs("\t",fp);
					fputs(roadlist->one_Road.RoadName,fp);
					fputs("\n",fp);
				}
				else
				{
					sprintf(linkID,"%ld",roadlist->one_Road.RoadLinkID);
					fputs(linkID,fp);
					fputs("\t",fp);
					sprintf(disClassNo,"%d",GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo));
					fputs(disClassNo,fp);
					fputs("\t",fp);
					sprintf(roadFlag,"%d",GET_FLAG(roadlist->one_Road.RoadStaNodeInfo));
					fputs(roadFlag,fp);
					fputs("\t\t",fp);
					sprintf(roadBrunch,"%d",GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo));
					fputs(roadBrunch,fp);
					fputs("\t",fp);
					fputs("��������",fp);
					fputs("\n",fp);
				}
			}
		}
		fclose(fp);
	}
}
void Sort_DisClass(struct Road **Head,int disClass)
{
	char linkID[20]="\0";
	char disClassNo[20]="\0";
	char roadFlag[5]="\0";
 	char roadBrunch[20]="\0";
	FILE *fp;
	struct Road *roadlist;
	int count=0;
	roadlist=*Head;
	 
	printf("��ѯ���Ϊ��\n");
	while(roadlist->nextRoadNode != NULL)
	{
		roadlist=roadlist->nextRoadNode;
		if(GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo) == disClass)
		{
			count++;
		}
	}
	if(count <= 5)
	{
		roadlist=*Head;
		printf("*************************************************************************\n");
		while(roadlist->nextRoadNode != NULL)
		{
			roadlist=roadlist->nextRoadNode;
			if(GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo) == disClass)
			{
				if(1==GET_FLAG(roadlist->one_Road.RoadStaNodeInfo))
				{
					printf("#linkid=%u;roadnameflag=%u;bruch=%u;dispclass=%u;roadname=%s#\n",
                        roadlist->one_Road.RoadLinkID,GET_FLAG(roadlist->one_Road.RoadStaNodeInfo),
                        GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo),
                        GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo),roadlist->one_Road.RoadName);
				}
				else
				{
					printf("#linkid=%u;roadnameflag=%u;bruch=%u;dispclass=%u;��������#\n",
                        roadlist->one_Road.RoadLinkID,GET_FLAG(roadlist->one_Road.RoadStaNodeInfo),
                        GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo),
                        GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo));	
				}
			}
		}
		printf("*************************************************************************\n");
	}
	else if(count >5)
	{
		
		printf("*************************************************************************\n");
		printf("��Ŀ����5�������ݽ��������ı��ļ� C:\\Sort_DisClass.txt ��\n");
		printf("*************************************************************************\n");
		roadlist=*Head;
		if((fp=fopen("C:\\Sort_DisClass.txt","w"))==NULL)
		{
			exit(0);
		}
		fputs("LinkID\tDisClass\tRoadNameFlag\tBrunch\tRoadName\n",fp);
		while(roadlist->nextRoadNode != NULL)
		{
			roadlist=roadlist->nextRoadNode;
			if(GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo) == disClass)
			{
				if(1==GET_FLAG(roadlist->one_Road.RoadStaNodeInfo))
				{
					sprintf(linkID,"%ld",roadlist->one_Road.RoadLinkID);
					fputs(linkID,fp);
					fputs("\t",fp);
					sprintf(disClassNo,"%d",GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo));
					fputs(disClassNo,fp);
					fputs("\t",fp);
					sprintf(roadFlag,"%d",GET_FLAG(roadlist->one_Road.RoadStaNodeInfo));
					fputs(roadFlag,fp);
					fputs("\t\t",fp);
					sprintf(roadBrunch,"%d",GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo));
					fputs(roadBrunch,fp);
					fputs("\t",fp);
					fputs(roadlist->one_Road.RoadName,fp);
					fputs("\n",fp);
				}
				else
 				{
					sprintf(linkID,"%ld",roadlist->one_Road.RoadLinkID);
					fputs(linkID,fp);
					fputs("\t",fp);
					sprintf(disClassNo,"%d",GET_DISPCLASS(roadlist->one_Road.RoadStaNodeInfo));
					fputs(disClassNo,fp);
					fputs("\t",fp);
					sprintf(roadFlag,"%d",GET_FLAG(roadlist->one_Road.RoadStaNodeInfo));
					fputs(roadFlag,fp);
					fputs("\t\t",fp);
					sprintf(roadBrunch,"%d",GET_BRUNCH(roadlist->one_Road.RoadStaNodeInfo));
					fputs(roadBrunch,fp);
					fputs("\t",fp);
					fputs("��������",fp);
					fputs("\n",fp);
				}
			}
		}
		fclose(fp);
	}
}

