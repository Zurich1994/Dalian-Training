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
		printf("已经读取文件，不可以再次读取\n");
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
	printf("文件读取中...\n\n");
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
	printf("成功读取文件!\n");
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
	printf("\n\n\t\t是否需要生成排序后文件?\n\n\t\t1.是，并生成SortedGTBL.txt\n\n\t\t2.是，并生成SortedGTBL.dat");
	printf("\n\n\t\t3.否\n\n\t\t0.返回\n\n");
	printf("\t\t请选择:");
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
			printf("文件创建失败!\n");
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
		printf("\n\n\t\t 文件创建成功\n\n\t\t 更新的数据存放在SortedGTBL.txt 文件中\n\n\n"); 
		printf("\t\t是否还需要继续创建文件?\n\n");
		printf("\t\t1.是\n\n\t\t2.否\n\n");
		printf("\t\t请选择:");
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
			default:printf("输入错误，返回上级菜单\n");creat();break;
		}
		break;
	case 2:
		pp=fopen("SortedGTBL.dat " , "wb+");
		if(pp==NULL) 
		{
			printf("更新文件创建失败……"); 
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
		printf("\n\n\t\t 文件创建成功\n\n\t\t 更新的数据存放在SortedGTBL.dat 文件中\n\n\n"); 
		printf("\t\t是否还需要继续创建文件?\n\n");
		printf("\t\t1.是\n\n\t\t2.否\n\n");
		printf("\t\t请选择:");
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
			default:printf("输入错误，返回上级菜单\n");creat();break;
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
	printf("\n该排序一共用时:%.2fs\n",(float)(t2-t1)/1000);
	numsort++;
	creat();
	ma_interf();
}

void xzSort() 
{
	int i,j,c=0,t1,t2;
	struct roadinfor temp;
	printf("排序进度:0 %%");
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
		printf("\n该排序一共用时:%.2fs\n",(float)(t2-t1)/1000);
		numsort++;
		creat();
		ma_interf();
}

void mpSort() 
{
	int i,j,c=0,t1,t2;
	struct roadinfor temp;
	printf("排序进度:0 %%");
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
		printf("\n该排序一共用时:%.2fs\n",(float)(t2-t1)/1000);
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
	printf("\n该排序一共用时:%.2fs\n",(float)(t2-t1)/1000);
	numsort++;
	creat();
	ma_interf();
}

void ma_interf() 
{ 
		int a;
		int select;
		printf("\t     ▇▇▇▇ .    ▇▇▇▇ .   ▇▇▇▇      ▇▇▇▇\n");
		printf("\t   ◢▇▇▇▇◣  ◢▇▇▇▇◣ ◢▇▇▇▇◣  ◢▇▇▇▇◣\n");
		printf("\t   ▇欢迎使用▇. ▇欢迎使用▇ ▇欢迎使用▇  ▇欢迎使用▇\n");
		printf("\t   ◥▇▇▇▇◤ .◥▇▇▇▇◤ ◥▇▇▇▇◤  ◥▇▇▇▇◤\n");
		printf("\t     ▇▇▇▇ .    ▇▇▇▇ .   ▇▇▇▇      ▇▇▇▇\n");
		printf("\t      | | |         | | |        | | |         | | |\n");
		printf("/***********************************--Welcome--*******************************/\n"); 
		printf("/***\t\t\t\t\t\t\t\t\t   ***/\n"); 
		printf("/*** ╭︿︿︿╮  ╭︿︿︿╮    电子地图信息统计系统\t\t\t   ***/\n");
		printf("/*** {/-★★-/}  {/ ︿︿ /}     \t\t\t\t\t   ***/\n"); 
		printf("/***  ( (oo) )    ( (oo) )    \t\t王  垚 李  涛 宋志远 张芷源 于宝龙 ***/\n"); 
		printf("/***   ︶︶︶     ︶ ︶ ︶\t\t\t2013年 8 月 1 日 \t   ***/\n");
		printf("/*****************************************************************************/\n\n"); 
		printf("请选择服务的种类：\n");
		printf("\t1:读取文件(GTBL.dat)\n\t2:排序\n\t3:检索\n\t4:更新\n\t0:退出\n\t 请选择:"); 
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
						printf("请先读取文件!\n");
						ma_interf();
					}
					printf("\n\n\t 请输入检索方式:\n\n\t\t1:选择排序(较慢)\n\n\t\t2:冒泡排序(较慢)\n\n\t\t3:插入排序(推荐)\
		\n\n\t\t4:快速排序(推荐)\n\n\t\t0:返回 \n\n\t\t 请选择：");
					scanf("%d",&a);
					switch(a)
					{
						case 1 : xzSort();break;
						case 2 : mpSort();break;
						case 3 : shellSort();break;
						case 4 : quickSort();break;
						case 0 : ma_interf();break;
						default: printf("选择错误,返回上级菜单\n");
								 ma_interf();
								 break;
					}
			case 3 : 
					if(numread<=0) 
					{
						printf("请先读取文件!\n");
						ma_interf();
					}
					Search(); 
					break;
			case 4 : 
					if(numread<=0) 
					{
						printf("请先读取文件!\n");
						ma_interf();
					}
					Update(); 
					break; 
			case 0 : 
					printf("\n\n\n\t\t\t  ._________________.\n"); 
					printf("\t\t\t  | _______________ |\n");
					printf("\t\t\t  | I             I |\n"); 
					printf("\t\t\t  | I             I |\n"); 
					printf("\t\t\t  | I  谢谢使用!  I |\n"); 
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
					printf("\n\n\n\t\t\t输入信息出错，请重新选择服务种类：\n\n\n\n"); 
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
		printf("更新文件创建失败……"); 
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
	printf("\n\n\t\t\t\t 文件更新成功\n\n\n\t\t\t 更新文件存放在update.dat 文件中\n\n\n"); 
	ma_interf();  
} 

void Search() 
{ 
	int select , i=0 , j=0 , *b , c=0 , f,k; 
	char sss[20];
	printf("\n\n\t 请输入检索方式:\n\n\t\t1:指定linkID顺序检索\n\n\t\t2:指定交叉link列表示class番号检索\n\n\t\t3:指定查找岔路数检索\
		\n\n\t\t4:指定道路名称检索\n\n\t\t5:指定linkID二分检索\n\n\t\t0:返回 \n\n\t\t 请选择："); 
	scanf("%d" , &select);
	if(!(select>=0&&select<=5)) 
	{
		flushall();
		select=6;
	}
	system("cls"); 
	printf("\n\n*****--当检索到信息条数超过5条时,会把检索到的信息存放在searchresult文件中--*****\n\n");
	printf("\n********--当检索到信息条数未超过5条时,会把检索到的信息直接显示在屏幕上--********\n\n\n"); 
	if(select == 1) 
	{ 
		printf("\t 请输入link的ID:"); 
		scanf("%d" , &k); 
		system("cls"); 
		for(i=0; i<n-1;i++) 
		{ 
			if(road[i].linkid==k) 
			{
				printf("查询结果为:\n");
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
			printf("\t\t\t\t 没有匹配结果\n\n\t\t\t      请重新选择检索方式 \n");
			printf("/*****************************************************************************/\n");
			Search(); 
		} 
	}
	else if(select==2) 
	{ 
		printf("\t请输入交叉link列表示class番号:"); 
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
			printf("\t\t\t\t 没有匹配结果\n\n\t\t\t      请重新选择检索方式\n");
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
				printf("查询结果为:\n");
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
		printf("\t 请输入岔路数:");
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
			printf("\t\t\t\t 没有匹配结果\n\n\t\t\t      请重新选择检索方式\n"); 
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
				printf("查询结果为:\n");
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
		char ss_1[14]="１＝"; 
		printf("\t 请输入道路名称:"); 
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
			printf("\t\t\t\t 没有匹配结果\n\n\t\t\t      请重新选择检索方式\n");	
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
			printf("请先排序，在选择此种搜索方式!\n");
			ma_interf();
		}
		int ii=-1;
		printf("\t 请输入link的ID:"); 
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
			printf("\t\t\t\t 没有匹配结果\n\n\t\t\t      请重新选择检索方式 \n"); 
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
		printf("\n\n\t\t输入信息错误,请重新选择检索方式\n\n"); 
		Search(); 
	} 
	ma_interf(); 
}

void WriteResult (int b[] , int j) 
{ 
	FILE *qq=fopen("searchresult.txt" , "w"); 
	if(qq== NULL) 
	{ 
		printf("创建文件searchresult失败\n"); 
		exit(0); 
	} 
	int i=0 , f;  
	printf("/*****************************************************************************/\n");
	printf("\t\t\t检索到的信息超过--5--条\n\t\t 检索到的信息写入 searchresult 文件 中……\n");
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
	printf("\n\n\t\t 检索到的信息写入 searchresult文件中成功\n\n\n"); 
} 

void main()
{
	system("color E5");
	ma_interf();
}