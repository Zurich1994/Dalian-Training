#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<WINDOWS.h>
using namespace std;
#define MAX 65535

int n=0,numread=0,numsort=0;
void ma_interf();
void Search();
void WriteResult (int b[] , int j);
void Update () ;

struct roadinfor
{
	short roadnamesize;
	short roadsize;
	int linkid;
	int aclass;
	int branch;
	int flag;
	char name[20];
	char nodeinfor[4];
}road[MAX];

int change (unsigned int number,int byte)
{
	
	unsigned char *p=(unsigned char*)&number;
	if(byte==4)
	return(((unsigned int)*p<<24)+((unsigned int)*(p+1)<<16)+((unsigned int)*(p+2)<<8)+(unsigned int)*(p+3));
	if(byte==2)
		return(((unsigned int)*p<<8)+(unsigned int)*(p+1));
}

int readfile()
{
	if(numread)
	{
		printf("�Ѿ���ȡ�ļ����������ٴζ�ȡ\n");
		ma_interf();
	}
	int temp;
	unsigned int m=0; 
	unsigned int linkid1;		 
	unsigned short int roadnamesize1;
	char nodeinfor[4]; 
	unsigned short int totalsize1; 
	unsigned int linkid2; 
	unsigned short int roadnamesize2; 
	unsigned short int totalsize2;
	FILE *pf1=fopen("GTBL.dat","rb+");
	FILE *pf2=fopen("file.txt","w+");
	if(pf1==NULL)
	{
		printf("cannot open the file\n");
		return 0;
	}
	if(pf2==NULL)
	{
		printf("cannot open the file\n");
		return 0;
	}
	printf("�ļ���ȡ��...\n\n");
	while(fread(&totalsize1,sizeof(totalsize1),1,pf1))
	{
		fread(&linkid1,sizeof(linkid1),1,pf1);
		fread(&roadnamesize1,sizeof(roadnamesize1),1,pf1);
		fread(nodeinfor,sizeof(nodeinfor),1,pf1);
		for(int i=0;i<4;i++)
			road[n].nodeinfor[i]=nodeinfor[i];
		totalsize2=change(totalsize1,2);
		linkid2=change(linkid1,4);
		roadnamesize2=change(roadnamesize1,2);
		fread(road[n].name,sizeof(char),totalsize2-12,pf1);
		road[n].roadsize=totalsize2;
		road[n].linkid=linkid2;
		road[n].roadnamesize=roadnamesize2;
		temp=(int)nodeinfor[3]&255;
		road[n].aclass=temp&15;
		road[n].branch=(temp&112)/16;
		road[n].flag=(temp&128)/128;
		fprintf(pf2,"%d\t",n+1); 
		fprintf(pf2,"LinkID="); 
		fprintf(pf2,"%d\t" ,road[n].linkid); 
		fprintf(pf2,"flag="); 
		fprintf(pf2,"%d\t" ,road[n].flag); 
		fprintf(pf2,"branch="); 
		fprintf(pf2,"%d\t" ,road[n].branch); 
		fprintf(pf2,"class="); 
		fprintf(pf2,"%d\t" ,road[n].aclass); 
		fprintf(pf2,"Roadname="); 
		fprintf(pf2,"%s\t" ,road[n].name+4);  
		fprintf(pf2," \n");
		n++;
	}
	fclose(pf1);
	fclose(pf2);
	printf("�ɹ���ȡ�ļ�!\n");
	numread++;
	ma_interf();
	return 0;
}

int creat()
{	
	
	int i,j,choose;
	unsigned int linkid;		 
	unsigned short int roadnamesize;
	char nodeinfor[4]={0}; 
	unsigned short int totalsize;
	FILE *pp,*pf3;
	printf("\n\n\t\t�Ƿ���Ҫ����������ļ�?\n\n\t\t1.�ǣ�������SortedGTBL.txt\n\n\t\t2.�ǣ�������SortedGTBL.dat");
	printf("\n\n\t\t3.��\n\n\t\t0.����\n\n");
	printf("\t\t��ѡ��:");
	scanf("%d",&choose);
	if(!(choose>=0&&choose<=2)) 
		{
			flushall();
			choose=5;
		}
	system("cls");
	switch(choose)
	{
	case 1:
		pf3=fopen("SortedGTBL.txt","w+");
		if(pf3==NULL) 
		{
			printf("�ļ�����ʧ��!\n");
			return 0;
		}  
		for(i=0;i<n;i++)
		{
			fprintf(pf3,"\t"); 
			fprintf(pf3,"LinkID="); 
			fprintf(pf3,"%d\t" ,road[i].linkid); 
			fprintf(pf3,"flag="); 
			fprintf(pf3,"%d\t" ,road[i].flag); 
			fprintf(pf3,"branch="); 
			fprintf(pf3,"%d\t" ,road[i].branch); 
			fprintf(pf3,"class="); 
			fprintf(pf3,"%d\t" ,road[i].aclass); 
			fprintf(pf3,"Roadname="); 
			fprintf(pf3,"%s\t" ,road[i].name);  
			fprintf(pf3," \n");
		}
		fclose(pf3);
		printf("\n\n\t\t �ļ������ɹ�\n\n\t\t ���µ����ݴ����SortedGTBL.txt �ļ���\n\n\n"); 
		printf("\t\t�Ƿ���Ҫ���������ļ�?\n\n");
		printf("\t\t1.��\n\n\t\t2.��\n\n");
		printf("\t\t��ѡ��:");
		scanf("%d",&j);
		if(!(j>=0&&j<=2)) 
		{
			flushall();
			j=5;
		}
		system("cls");
		switch(j)
		{
			case 1: creat();break;
			case 2: ma_interf();break;
			default:printf("������󣬷����ϼ��˵�\n");creat();break;
		}
		break;
	case 2:
		pp=fopen("SortedGTBL.dat " , "wb+");
		if(pp==NULL) 
		{
			printf("�����ļ�����ʧ�ܡ���"); 
			return 0; 
		} 
		for(i=0;i<n;i++)
		{
			totalsize=change((unsigned short int)road[i].roadsize,2);
			linkid=change((unsigned int)road[i].linkid,4);
			roadnamesize=change((unsigned short int)road[i].roadnamesize,2);
			fwrite(&totalsize,sizeof(unsigned short int),1,pp);
			fwrite(&linkid,sizeof(unsigned int),1,pp);
			fwrite(&roadnamesize,sizeof(unsigned short int),1,pp);
			fwrite(road[i].nodeinfor,1,4,pp);
			fwrite(road[i].name,road[i].roadsize-12,1,pp);
		}
		fclose(pp); 
		printf("\n\n\t\t �ļ������ɹ�\n\n\t\t ���µ����ݴ����SortedGTBL.dat �ļ���\n\n\n"); 
		printf("\t\t�Ƿ���Ҫ���������ļ�?\n\n");
		printf("\t\t1.��\n\n\t\t2.��\n\n");
		printf("\t\t��ѡ��:");
		scanf("%d",&j);
		if(!(j>=0&&j<=2)) 
		{
			flushall();
			j=5;
		}
		system("cls");
		switch(j)
		{
			case 1: creat();break;
			case 2: ma_interf();break;
			default:printf("������󣬷����ϼ��˵�\n");creat();break;
		}
		break;
	case 3:
		system("cls");
		ma_interf();
		break;
	default:
		system("cls");
		ma_interf();
		break;
	}
}

void shellSort()
{
	int d, i, j,t1,t2;
	struct roadinfor temp;
	t1=clock();
	for(d = n/2;d >= 1;d = d/2)
	{
		for(i = d; i < n;i++)
		{
			memcpy(&temp,&road[i],sizeof(struct roadinfor));
			for(j=i-d;(j >= 0) && (road[j].linkid > temp.linkid);j=j-d)	
			{
				memcpy(&road[j+d],&road[j],sizeof(struct roadinfor));
			}
			memcpy(&road[j+d],&temp,sizeof(struct roadinfor));
		}
	}
	t2=clock();
	printf("\n������һ����ʱ:%.2fs\n",(float)(t2-t1)/1000);
	numsort++;
	creat();
	ma_interf();
}

void xzSort() 
{
	int i,j,c=0,t1,t2;
	struct roadinfor temp;
	printf("�������:0 %%");
	t1=clock();
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(road[j].linkid<road[i].linkid)
			{
				memcpy(&temp,road+j,sizeof(struct roadinfor));
				memcpy(road+j,road+i,sizeof(struct roadinfor));
				memcpy(road+i,&temp,sizeof(struct roadinfor));
			}
			if(i%636==0&&j==i+1) printf("\b\b\b%02d%%",c+=1);
		}
		t2=clock();
		system("cls");
		printf("\n������һ����ʱ:%.2fs\n",(float)(t2-t1)/1000);
		numsort++;
		creat();
		ma_interf();
}

void mpSort() 
{
	int i,j,c=0,t1,t2;
	struct roadinfor temp;
	printf("�������:0 %%");
	t1=clock();
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(road[j].linkid<road[j+1].linkid)
			{
				memcpy(&temp,road+j,sizeof(struct roadinfor));
				memcpy(road+j,road+j+1,sizeof(struct roadinfor));
				memcpy(road+j+1,&temp,sizeof(struct roadinfor));
			}
			if(i%636==0&&j==0) printf("\b\b\b%02d%%",c+=1);
		}
		t2=clock();
		system("cls");
		printf("\n������һ����ʱ:%.2fs\n",(float)(t2-t1)/1000);
		numsort++;
		creat();
		ma_interf();
}

int check(const roadinfor &a,const roadinfor &b) 
{	
	if ((a.linkid < b.linkid)) return 1;
	else return 0; 
}

void quickSort()
{
	int t1,t2;
	t1=clock();
	sort(road ,road + n,check);	
	t2=clock();
	printf("\n������һ����ʱ:%.2fs\n",(float)(t2-t1)/1000);
	numsort++;
	creat();
	ma_interf();
}

void ma_interf() 
{ 
		int a;
		int select;
		printf("\t     �~�~�~�~ .    �~�~�~�~ .   �~�~�~�~      �~�~�~�~\n");
		printf("\t   ���~�~�~�~��  ���~�~�~�~�� ���~�~�~�~��  ���~�~�~�~��\n");
		printf("\t   �~��ӭʹ�è~. �~��ӭʹ�è~ �~��ӭʹ�è~  �~��ӭʹ�è~\n");
		printf("\t   ���~�~�~�~�� .���~�~�~�~�� ���~�~�~�~��  ���~�~�~�~��\n");
		printf("\t     �~�~�~�~ .    �~�~�~�~ .   �~�~�~�~      �~�~�~�~\n");
		printf("\t      | | |         | | |        | | |         | | |\n");
		printf("/***********************************--Welcome--*******************************/\n"); 
		printf("/***\t\t\t\t\t\t\t\t\t   ***/\n"); 
		printf("/*** �q����r  �q����r    ���ӵ�ͼ��Ϣͳ��ϵͳ\t\t\t   ***/\n");
		printf("/*** {/-���-/}  {/ ��� /}     \t\t\t\t\t   ***/\n"); 
		printf("/***  ( (oo) )    ( (oo) )    \t\t��  �� ��  �� ��־Զ ����Դ �ڱ��� ***/\n"); 
		printf("/***   ����     �� �� ��\t\t\t2013�� 8 �� 1 �� \t   ***/\n");
		printf("/*****************************************************************************/\n\n"); 
		printf("��ѡ���������ࣺ\n");
		printf("\t1:��ȡ�ļ�(GTBL.dat)\n\t2:����\n\t3:����\n\t4:����\n\t0:�˳�\n\t ��ѡ��:"); 
		scanf("%d" , &select); 
		system("cls"); 
		if(!(select>=0&&select<=4)) 
		{
			flushall();
			select=5;
		}
		switch(select) 
		{
			case 1 : 
					readfile(); 
					break; 
			case 2 :
					if(numread<=0) 
					{
						printf("���ȶ�ȡ�ļ�!\n");
						ma_interf();
					}
					printf("\n\n\t �����������ʽ:\n\n\t\t1:ѡ������(����)\n\n\t\t2:ð������(����)\n\n\t\t3:��������(�Ƽ�)\
		\n\n\t\t4:��������(�Ƽ�)\n\n\t\t0:���� \n\n\t\t ��ѡ��");
					scanf("%d",&a);
					switch(a)
					{
						case 1 : xzSort();break;
						case 2 : mpSort();break;
						case 3 : shellSort();break;
						case 4 : quickSort();break;
						case 0 : ma_interf();break;
						default: printf("ѡ�����,�����ϼ��˵�\n");
								 ma_interf();
								 break;
					}
			case 3 : 
					if(numread<=0) 
					{
						printf("���ȶ�ȡ�ļ�!\n");
						ma_interf();
					}
					Search(); 
					break;
			case 4 : 
					if(numread<=0) 
					{
						printf("���ȶ�ȡ�ļ�!\n");
						ma_interf();
					}
					Update(); 
					break; 
			case 0 : 
					printf("\n\n\n\t\t\t  ._________________.\n"); 
					printf("\t\t\t  | _______________ |\n");
					printf("\t\t\t  | I             I |\n"); 
					printf("\t\t\t  | I             I |\n"); 
					printf("\t\t\t  | I  ллʹ��!  I |\n"); 
					printf("\t\t\t  | I             I |\n"); 
					printf("\t\t\t  | I_____________I |\n"); 
					printf("\t\t\t  !_________________!\n"); 
					printf("\t\t\t     ._[_______]_.\n");
					printf("\t\t\t .___|___________|___.\n"); 
					printf("\t\t\t |::: ____           |\n"); 
					printf("\t\t\t |    ~~~~ [CD-ROM]  |\n"); 
					printf("\t\t\t !___________________!\n"); 
					system("pause");
					exit(0);
					break; 
			default: 
					system("cls"); 
					printf("\n\n\n\t\t\t������Ϣ����������ѡ��������ࣺ\n\n\n\n"); 
					ma_interf();					
		} 
}

void Update () 
{ 
	unsigned int m=0; 
	unsigned int linkid;		 
	unsigned short int roadnamesize;
	char nodeinfor[4]={0}; 
	unsigned short int totalsize; 
	FILE *pp;  
	char c=0;
	int i=0; 
	if((pp=fopen("newGTBL.dat " , "wb+")) == NULL) 
	{
		printf("�����ļ�����ʧ�ܡ���"); 
		exit(0); 
	} 
	for(i=0;i<n;i++)
	{
		totalsize=change((unsigned short int)road[i].roadsize,2);
		linkid=change((unsigned int)road[i].linkid,4);
		roadnamesize=change((unsigned short int)road[i].roadnamesize,2);
		fwrite(&totalsize,sizeof(unsigned short int),1,pp);
		fwrite(&linkid,sizeof(unsigned int),1,pp);
		fwrite(&roadnamesize,sizeof(unsigned short int),1,pp);
		fwrite(road[i].nodeinfor,1,4,pp);
		fwrite(road[i].name,road[i].roadsize-12,1,pp);
	}
	fclose(pp); 
	printf("\n\n\t\t\t\t �ļ����³ɹ�\n\n\n\t\t\t �����ļ������update.dat �ļ���\n\n\n"); 
	ma_interf();  
} 

void Search() 
{ 
	int select , i=0 , j=0 , *b , c=0 , f,k; 
	char sss[20];
	printf("\n\n\t �����������ʽ:\n\n\t\t1:ָ��linkID˳�����\n\n\t\t2:ָ������link�б�ʾclass���ż���\n\n\t\t3:ָ�����Ҳ�·������\
		\n\n\t\t4:ָ����·���Ƽ���\n\n\t\t5:ָ��linkID���ּ���\n\n\t\t0:���� \n\n\t\t ��ѡ��"); 
	scanf("%d" , &select);
	if(!(select>=0&&select<=5)) 
	{
		flushall();
		select=6;
	}
	system("cls"); 
	printf("\n\n*****--����������Ϣ��������5��ʱ,��Ѽ���������Ϣ�����searchresult�ļ���--*****\n\n");
	printf("\n********--����������Ϣ����δ����5��ʱ,��Ѽ���������Ϣֱ����ʾ����Ļ��--********\n\n\n"); 
	if(select == 1) 
	{ 
		printf("\t ������link��ID:"); 
		scanf("%d" , &k); 
		system("cls"); 
		for(i=0; i<n-1;i++) 
		{ 
			if(road[i].linkid==k) 
			{
				printf("��ѯ���Ϊ:\n");
				printf("/*****************************************************************************/\n");
				printf("linkid=%d flag=%d branch=%d dispclass=%d roadname=%s \n",\
				road[i].linkid,road[i].flag,road[i].branch,road[i].aclass,road[i].name+4);
				printf("/*****************************************************************************/\n\n");
				j++; 
			} 
		} 
		if(j == 0) 
		{
			printf("/*****************************************************************************/\n");
			printf("\t\t\t\t û��ƥ����\n\n\t\t\t      ������ѡ�������ʽ \n");
			printf("/*****************************************************************************/\n");
			Search(); 
		} 
	}
	else if(select==2) 
	{ 
		printf("\t�����뽻��link�б�ʾclass����:"); 
		scanf("%d",&k); 
		system("cls"); 
		for(i=0;i<n-1;i++) 
			if(road[i].aclass==k) 
				j++; 
		b=(int *)malloc(sizeof(int)*j);  
		for(i=0;i<n-1; i++) 
		{ 
			if(road[i].aclass==k) 
			{ 
				b[c]=i; 
				c++; 
			} 
		}
		if(j == 0) 
		{  
			printf("/*****************************************************************************/\n");
			printf("\t\t\t\t û��ƥ����\n\n\t\t\t      ������ѡ�������ʽ\n");
			printf("/*****************************************************************************/\n");
			Search(); 
		} 
		else if(j>5) 
		{ 
			WriteResult(b,j); 
		}
		else if (j<=5) 
		{ 
			printf("\n\n"); 
			for(i=0; i<j; i++) 
			{ 
				f=b[i];
				printf("��ѯ���Ϊ:\n");
				printf("/*****************************************************************************/\n");
				printf("linkid=%d flag=%d branch=%d dispclass=%d roadname=%s \n",\
				road[f].linkid,road[f].flag,road[f].branch,road[f].aclass,road[f].name+4);
				printf("/*****************************************************************************/\n\n");
			} 
			printf("\n\n"); 
		}
			free(b); 
	} 
	else if(select==3) 
	{ 
		j=0,c=0;
		printf("\t �������·��:");
		scanf("%d",&k); 
		system("cls");  
		for(i=0; i<n-1; i++) 
			if(road[i].branch==k)
				j++; 
		b=(int *)malloc(sizeof(int)*j);  
		for(i=0; i<n-1; i++) 
			if(road[i].branch==k)  
			{ 
				b[c]=i; 
				c++; 
			} 
		if(j == 0) 
		{
			printf("/*****************************************************************************/\n");
			printf("\t\t\t\t û��ƥ����\n\n\t\t\t      ������ѡ�������ʽ\n"); 
			printf("/*****************************************************************************/\n");
			Search();
		} 
		else if(j>5)
		{ 
			WriteResult(b,j);
		}
		else if (j<=5)  
		{
			printf("\n\n"); 
			for(i=0; i<j; i++) 
			{
				f=b[i];
				printf("��ѯ���Ϊ:\n");
				printf("/*****************************************************************************/\n");
				printf("linkid=%d flag=%d branch=%d dispclass=%d roadname=%s \n",\
				road[f].linkid,road[f].flag,road[f].branch,road[f].aclass,road[f].name+4);
				printf("/*****************************************************************************/\n\n"); 
			} 
			printf("\n\n"); 
		} 
				free(b); 
	} 
	else if(select == 4) 
	{
		char ss_1[14]="����"; 
		printf("\t �������·����:"); 
		scanf("%s" , sss);
		system("cls"); 
		strcat(ss_1 , sss); 
		for(i=0; i<n-1; i++) 
		{
			if(strcmp(ss_1 , road[i].name) == 0) 
			{ 
				j++;
			} 
		} 
		b=(int*)malloc(sizeof(int)*j); 
		for(i=0; i<n-1; i++) 
		{ 
			if(strcmp(ss_1 ,road[i].name) == 0) 
			{ 
				b[c]=i; 
				c++; 
			} 
		} 
		if(j == 0) 
		{ 
			printf("/*****************************************************************************/\n");
			printf("\t\t\t\t û��ƥ����\n\n\t\t\t      ������ѡ�������ʽ\n");	
			printf("/*****************************************************************************/\n");
			Search(); 
		} 
		else if(j>5) 
		{ 
			WriteResult(b , j); 
		} 
		else if (j<=5) 
		{
			printf("\n\n"); 
			for(i=0; i<j; i++) 
			{ 
				f=b[i]; 
				printf("\n\n roadsize=%d linkid=%d flag=%d branch=%d dispclass=%d roadname=%s roadnamesize=%d\n\n\n",\
				road[f].roadsize,road[f].linkid,road[f].flag,road[f].branch,road[f].aclass,road[f].name,road[f].roadnamesize); 
			} 
			printf("\n\n"); 
		} 
		free(b); 
		} 
	else if(select==5)
	{
		if(numsort<=0)
		{
			printf("����������ѡ�����������ʽ!\n");
			ma_interf();
		}
		int ii=-1;
		printf("\t ������link��ID:"); 
		scanf("%d" , &k); 
		system("cls"); 
		int low=0,high=n-1,mid; 
		if(road[low].linkid==k)     
			ii=low;  
		if(road[high].linkid==k)
			ii=high;
		while(low<=high)
		{
			mid=low+((high-low)/2);
			if(road[mid].linkid==k)                   
				ii=mid;          
			if(road[mid].linkid>k)             
				high=mid-1; 
			else            
				low=mid+1; 
		}     
		if(ii<0)         
		{
			printf("/*****************************************************************************/\n");
			printf("\t\t\t\t û��ƥ����\n\n\t\t\t      ������ѡ�������ʽ \n"); 
			printf("/*****************************************************************************/\n");
			Search(); 
		} 
		printf("\n\n linkid=%d flag=%d branch=%d dispclass=%d roadname=%s \n\n\n",\
		road[ii].linkid,road[ii].flag,road[ii].branch,road[ii].aclass,road[ii].name+4); 
	}
	else if(select == 0) 
	{
		system("cls"); 
		ma_interf(); 
	} 
	else 
	{ 
		system("cls"); 
		printf("\n\n\t\t������Ϣ����,������ѡ�������ʽ\n\n"); 
		Search(); 
	} 
	ma_interf(); 
}

void WriteResult (int b[] , int j) 
{ 
	FILE *qq=fopen("searchresult.txt" , "w"); 
	if(qq== NULL) 
	{ 
		printf("�����ļ�searchresultʧ��\n"); 
		exit(0); 
	} 
	int i=0 , f;  
	printf("/*****************************************************************************/\n");
	printf("\t\t\t����������Ϣ����--5--��\n\t\t ����������Ϣд�� searchresult �ļ� �С���\n");
	printf("/*****************************************************************************/\n");
	for(i=0;i<j; i++) 
	{ 
		f=b[i];
		fprintf(qq,"\t"); 
		fprintf(qq,"LinkID="); 
		fprintf(qq,"%d\t" ,road[f].linkid); 
		fprintf(qq,"flag="); 
		fprintf(qq,"%d\t" ,road[f].flag); 
		fprintf(qq,"branch="); 
		fprintf(qq,"%d\t" ,road[f].branch); 
		fprintf(qq,"class="); 
		fprintf(qq,"%d\t" ,road[f].aclass); 
		fprintf(qq,"Roadname="); 
		fprintf(qq,"%s\t" ,road[f].name+4);  
		fprintf(qq," \n"); 
	}
	fclose(qq); 
	printf("\n\n\t\t ����������Ϣд�� searchresult�ļ��гɹ�\n\n\n"); 
} 

void main()
{
	system("color E5");
	ma_interf();
}