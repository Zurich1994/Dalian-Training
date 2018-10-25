#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <windows.h>
#include <Mmsystem.h>
#include <winbase.h>

#pragma comment(lib,"winmm.lib")
using namespace std;

void fprint();
bool fs=false;
struct link{
	unsigned short size;
	unsigned int linkid;
	unsigned short size_name;
	unsigned int node;
	unsigned int Class;
	unsigned int branch;
	unsigned int Flag;
	char name[30];
};
link k,*a;
void print(){
	char i=6;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i);
	
	printf("      ************              *       *              *           * * * * \n");
	printf("     *      N      *           * *     * *           *   *         *      * \n");
	printf("    *       |       *         *   *   *   *        * * * * *       * * * * \n");
	printf("   *        |        *       *     * *     *     *           *     *\n");
	printf("  *W   -----|-----   E*     *       *       *   *             *    *\n");
	printf("   *        |        *\n");
	printf("    *       |       *                       制作团队:\n");
	printf("     *      S      *                                 sound of the silencing\n");
	printf("      *************                         制作日期:\n"); 
	printf("                                                        2013.07.30\n");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i);
}

short reverse_short(short a)
{
	union {
		short i;
		char c[2];
	} u, r;	
	u.i = a;
	r.c[0] = u.c[1];
	r.c[1] = u.c[0];	
	return r.i;
}
int reverse_int(int a)
{
	union {
		int i;
		char c[4];
	} u, r;	
	u.i = a;
	r.c[0] = u.c[3];
	r.c[1] = u.c[2];
	r.c[2] = u.c[1];
	r.c[3] = u.c[0];
	return r.i;
}
int i=0;
char s[100]="C:\\Documents and Settings\\new\\桌面\\赵天华.cpp\\电子地图提供物\\GTBL.dat";

void fileopen()
{
	i=0;
	FILE *stream;
	printf("是否更新读入文件地址Y/N: ");
	char ch;
	flushall();
	scanf("%c",&ch);
	if(ch=='Y')
	{
		printf("请输入文件地址：");
		scanf("%s",s);
	}
	printf("loading...\n");	
	if( (stream = fopen( s, "rb+" )) == NULL )
	{
		printf("打开文件失败请重新读入文件\n");
		return;
	}
	unsigned int trash;
	link b;
	int sum=1;
	while(fread(&b.size,sizeof(short),1,stream))
	{
		b.size=reverse_short(b.size);
		fseek(stream,b.size-2,SEEK_CUR);
		sum++;
	}
	free(a);
	a = (link *)malloc(sum*sizeof(link));
	rewind(stream);
	while(fread(&a[i].size,sizeof(short),1,stream))
	{
		a[i].size=reverse_short(a[i].size);
		fread(&a[i].linkid,sizeof(int),1,stream);
		a[i].linkid=reverse_int(a[i].linkid);
		fread(&a[i].size_name,sizeof(short),1,stream);
		a[i].size_name=reverse_short(a[i].size_name);
		fread(&trash,sizeof(int),1,stream);
		trash=reverse_int(trash);
		a[i].Flag=(trash>>7)&1;
		a[i].branch=(trash>>4)&7;
		a[i].Class=trash&15;
		if(a[i].size-12 !=0)
		{
			fread(a[i].name,sizeof(char),a[i].size-12,stream);	
		}else
		{
			strcpy(a[i].name,"no name");		
		}
		i++;	
	}
	fclose( stream );
	printf("success!\n");
}
void fileupdate()
{
	printf("loading...\n");	
	FILE *stream;
	if( (stream = fopen( "C:\\Documents and Settings\\new\\桌面\\GTBL.dat", "wb+" )) == NULL )
	{
		printf("打开文件失败\n");
		exit( 0 );	
	}
	unsigned int trash;
	int j=0;
	while(j<i)
	{
		int size=a[j].size;
		a[j].size=reverse_short(a[j].size);
		fwrite(&a[j].size,sizeof(short),1,stream);
		a[j].linkid=reverse_int(a[j].linkid);
		fwrite(&a[j].linkid,sizeof(int),1,stream);
		a[j].size_name=reverse_short(a[j].size_name);
		fwrite(&a[j].size_name,sizeof(short),1,stream);
		trash=0;
		trash=trash|(a[j].Class&15);
		trash=trash|((a[j].branch&7)<<4);
		trash=trash|((a[j].Flag&1)<<7);
		trash=reverse_int(trash);
		fwrite(&trash,sizeof(int),1,stream);
		if(a[j].Flag)
		{
			fwrite(a[j].name,sizeof(char),size-12,stream);	
		}
		j++;
	}
	fclose( stream );
	printf("success!\n");
}
void paopao_linkid(link *a, int n)
{ 
	link t;
	int i, j;
	bool flag=true;
	for(i=0;i<n&&flag;i++)
	{
		flag=false;
		for(j=0;j<n-i-1;j++)
			if(a[j].linkid>a[j+1].linkid)
			{   
				memcpy(&t, &a[j], sizeof(link)); 
				memcpy(&a[j], &a[j+1], sizeof(link)); 
				memcpy(&a[j+1], &t, sizeof(link));
				flag=true;
			}
	}
}

void paopao_name(link *a, int n)
{ 
	
	
	link t;
	int i, j;
	bool flag=true;
	for(i=0;i<n&&flag;i++)
	{
		flag=false;
		for(j=0;j<n-i-1;j++)
			if(strcmp(a[j].name,a[j+1].name)==1)
			{   
				memcpy(&t, &a[j], sizeof(link)); 
				memcpy(&a[j], &a[j+1], sizeof(link)); 
				memcpy(&a[j+1], &t, sizeof(link));
				flag=true;
			}
	}
			
}
void paopao_class(link *a, int n)
{
	link t;
	int i, j;
	bool flag=true;
	for(i=0;i<n&&flag;i++)
	{
		flag=false;
		for(j=0;j<n-i-1;j++)
			if(a[j].Class>a[j+1].Class)
			{   
				memcpy(&t, &a[j], sizeof(link)); 
				memcpy(&a[j], &a[j+1], sizeof(link)); 
				memcpy(&a[j+1], &t, sizeof(link));
				flag=true;
			}
	}
}

void paopao_branch(link *a, int n)
{
	link t;
	int i, j;
	bool flag=true;
	for(i=0;i<n&&flag;i++)
	{
		flag=false;
		for(j=0;j<n-i-1;j++)
			if(a[j].branch>a[j+1].branch)
			{   
				memcpy(&t, &a[j], sizeof(link)); 
				memcpy(&a[j], &a[j+1], sizeof(link)); 
				memcpy(&a[j+1], &t, sizeof(link));
				flag=true;
			}	
	}
}

void xuanze_linkid(link *a,int n)
{
	int i,j,m;
	link t;
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
		if(a[j].linkid<a[m].linkid)
			m=j;
			memcpy(&t,&a[i],sizeof(link));
			memcpy(&a[i],&a[m],sizeof(link));
			memcpy(&a[m],&t,sizeof(link));
	}
}
void xuanze_name(link *a,int n)
{
	int i,j,m;
	link t;
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
			if(strcmp(a[j].name,a[m].name)==-1)
				m=j;
			memcpy(&t,&a[i],sizeof(link));
			memcpy(&a[i],&a[m],sizeof(link));
			memcpy(&a[m],&t,sizeof(link));
	}
}

void xuanze_Class(link *a,int n)
{
	int i,j,m;
	link t;
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
			if(a[j].Class<a[m].Class)
				m=j;
			memcpy(&t,&a[i],sizeof(link));
			memcpy(&a[i],&a[m],sizeof(link));
			memcpy(&a[m],&t,sizeof(link));
	}
}

void xuanze_branch(link *a,int n)
{
	int i,j,m;
	link t;
	for(i=0;i<n-1;i++)
	{
		m=i;
		for(j=i+1;j<n;j++)
			if(a[j].branch<a[m].branch)
				m=j;
			memcpy(&t,&a[i],sizeof(link));
			memcpy(&a[i],&a[m],sizeof(link));
			memcpy(&a[m],&t,sizeof(link));
	}
}


void charu_linkid(link *a,int n)
{
	int i,j;
	link temp;
	for(i=1;i<n;i++)
	{
		memcpy(&temp,&a[i],sizeof(link));
		j=i-1;
		while(j>=0&&temp.linkid<a[j].linkid)
		{
			memcpy(&a[j+1],&a[j],sizeof(link));
			j--;
		}
		memcpy(&a[j+1],&temp,sizeof(link));
	}
}	
void charu_name(link *a,int n)
{
	int i,j;
	link temp;
	for(i=1;i<n;i++)
	{
		memcpy(&temp,&a[i],sizeof(link));
		j=i-1;
		while(j>=0&&(strcmp(temp.name,a[j].name)==-1))
		{
			memcpy(&a[j+1],&a[j],sizeof(link));
			j--;
		}
		memcpy(&a[j+1],&temp,sizeof(link));
	}
}	

void charu_Class(link *a,int n)
{
	int i,j;
	link temp;
	for(i=1;i<n;i++)
	{
		memcpy(&temp,&a[i],sizeof(link));
		j=i-1;
		while(j>=0&&temp.Class<a[j].Class)
		{
			memcpy(&a[j+1],&a[j],sizeof(link));
			j--;
		}
		memcpy(&a[j+1],&temp,sizeof(link));
	}
}

void charu_branch(link *a,int n)
{
	int i,j;
	link temp;
	for(i=1;i<n;i++)
	{
		memcpy(&temp,&a[i],sizeof(link));
		j=i-1;
		while(j>=0&&temp.branch<a[j].branch)
		{
			memcpy(&a[j+1],&a[j],sizeof(link));
			j--;
		}
		memcpy(&a[j+1],&temp,sizeof(link));
	}
}
int comp_name(link a,link b)
{
	return strcmp(a.name,b.name)==-1;
}		
void quicksort_name(link *a,int n)
{
	sort(a,a+n,comp_name);
}
int comp_linkid(link a,link b)
{
	return a.linkid<b.linkid;
}
void quicksort_linkid(link *a,int n)
{
     sort(a,a+n,comp_linkid);
}


int comp_Class(link a,link b)
{
	return a.Class<b.Class;
}
void quicksort_Class(link *a,int n)
{
	sort(a,a+n,comp_Class);
}


int comp_branch(link a,link b)
{
	return a.branch<b.branch;
}
void quicksort_branch(link *a,int n)
{
	sort(a,a+n,comp_branch);
}


void list1(int b)
{
	int e;
	printf("                     1.冒泡排序\n");
	printf("                     2.选择排序\n");
	printf("                     3.插入排序\n");
	printf("                     4.快速排序\n");
	printf("                     0.返回\n");
	printf("                     请选择：");
	scanf("%d",&e);
	printf("loading...\n");
	printf("********************************************************************************");
	DWORD time_start,time_end;
	time_start=timeGetTime();
	switch(e)
	{
	case 0:return ;
	case 1:switch(b)
		   {
				case 1:paopao_linkid(a,i);break;
				case 2:paopao_class(a,i);break;
				case 3:paopao_branch(a,i);break;
				case 4:paopao_name(a,i);break;
		   }
			break;
	case 2:switch(b)
		   {
				case 1:xuanze_linkid(a,i);break;
				case 2:xuanze_Class(a,i);break;
				case 3:xuanze_branch(a,i);break;
				case 4:xuanze_name(a,i);break;
		   }
			break;
	case 3:switch(b)
		   {
				case 1:charu_linkid(a,i);break;
				case 2:charu_Class(a,i);break;
				case 3:charu_branch(a,i);break;
				case 4:charu_name(a,i);break;
		   }
			break;
	case 4:switch(b)
		   {
				case 1:quicksort_linkid(a,i);break;
				case 2:quicksort_Class(a,i);break;
				case 3:quicksort_branch(a,i);break;
				case 4:quicksort_name(a,i);break;
		   }
			break;
	default:printf("输入错误\n");
	}
	
	time_end=timeGetTime();
	float time=time_end-time_start;
	printf("共用时%.3f秒\n",time/1000);
	printf("排序成功\n");	
} 
void list()
{
	int b;
	printf("请选择排序的方式:\n");
	printf("                 1.按linkID排序\n");
	printf("                 2.按交叉Link列表示Class番号 排序\n");
	printf("                 3.按查找岔路数 排序\n");
	printf("                 4.按道路名称　排序\n");
	printf("                 0.返回\n");
	printf("                 请选择：");
	scanf("%d",&b);
	switch(b){
	case 0:return;
	case 1:list1(b);break;
	case 2:list1(b);break;
	case 3:list1(b);break;
	case 4:list1(b);break;
	default:printf("输入错误\n");
	}
	fprint();
}
void shunxu_linkid(link *a,int k_linkid,int n)
{
	bool *p=(bool *)calloc(n,sizeof(bool));
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		if(a[i].linkid==k_linkid)
		{
			p[i]=1;
			sum++;
		}
	}	
	if(sum>0)	
	{
		printf("find it!\n");
		printf("共找到 %d条符合条件的数据\n",sum);
		if(sum<=5)
		{
			for(i=0;i<n;i++)
				if(p[i])
				{
					printf("这是第%d个数据:\n",i+1);
					printf("linkid = %d;flag = %d;branch = %d;Class = %d;roadname = %s\n",a[i].linkid,a[i].Flag,a[i].branch,a[i].Class,a[i].name);
				}
		}
		else 
		{
			printf("由于检索结果数据量大于5，结果已保存到C:\\findings.txt中\n");
			FILE *fp;
			if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
			{
				printf("打开文件失败\n");
				return ;
				
			}
			int j=0;
			for(;j<i;j++)
			if(p[j])
				{
					fprintf(fp,"linkid: ");
					fprintf(fp,"%d",a[j].linkid);
					fprintf(fp,"Class: ");
					fprintf(fp,"%d",a[j].Class);
					fprintf(fp,"branch: ");
					fprintf(fp,"%d",a[j].branch);
					fprintf(fp,"name: ");
					fprintf(fp,"%s\n",a[j].name);
				}
			fclose(fp);
		}
	}
	else 
		printf("sorry,not found\n");
	free(p);
	return ;
}

void shunxu_Class(link *a,int k_linkClass,int n)
{
	bool *p=(bool *)calloc(n,sizeof(bool));
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		if(a[i].Class==k_linkClass)
		{
			p[i]=1;
			sum++;
		}
	}	
	if(sum>0)	
	{
		printf("find it!\n");
		printf("共找到 %d条符合条件的数据\n",sum);
		if(sum<=5)
		{
			for(i=0;i<n;i++)
				if(p[i])
				{
					printf("这是第%d个数据:\n",i+1);
					printf("linkid = %d;flag = %d;branch = %d;Class = %d;roadname = %s\n",a[i].linkid,a[i].Flag,a[i].branch,a[i].Class,a[i].name);
				}
		}
		else 
		{
			printf("由于检索结果数据量大于5，结果已保存到C:\\findings.txt中\n");
			FILE *fp;
			if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
			{
				printf("打开文件失败\n");
				return ;
				
			}
			int j=0;
			for(;j<i;j++)
				if(p[j])
				{
					fprintf(fp,"linkid: ");
					fprintf(fp,"%d",a[j].linkid);
					fprintf(fp,"Class: ");
					fprintf(fp,"%d",a[j].Class);
					fprintf(fp,"branch: ");
					fprintf(fp,"%d",a[j].branch);
					fprintf(fp,"name: ");
					fprintf(fp,"%s\n",a[j].name);
				}
				fclose(fp);
		}
	}
	else 
		printf("sorry,not found\n");
	free(p);
	return ;
}


void shunxu_branch(link *a,int k_linkbranch,int n)
{
	bool *p=(bool *)calloc(n,sizeof(bool));
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		if(a[i].branch==k_linkbranch)
		{
			p[i]=1;
			sum++;
		}
	}	
	if(sum>0)	
	{
		printf("find it!\n");
		printf("共找到 %d条符合条件的数据\n",sum);
		if(sum<=5)
		{
			for(i=0;i<n;i++)
				if(p[i])
				{
					printf("这是第%d个数据:\n",i+1);
					printf("linkid = %d;flag = %d;branch = %d;Class = %d;roadname = %s\n",a[i].linkid,a[i].Flag,a[i].branch,a[i].Class,a[i].name);
				}
		}
		else 
		{
			printf("由于检索结果数据量大于5，结果已保存到C:\\findings.txt中\n");
			FILE *fp;
			if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
			{
				printf("打开文件失败\n");
				return ;
				
			}
			int j=0;
			for(;j<i;j++)
				if(p[j])
				{
					fprintf(fp,"linkid: ");
					fprintf(fp,"%d",a[j].linkid);
					fprintf(fp,"Class: ");
					fprintf(fp,"%d",a[j].Class);
					fprintf(fp,"branch: ");
					fprintf(fp,"%d",a[j].branch);
					fprintf(fp,"name: ");
					fprintf(fp,"%s\n",a[j].name);
				}
				fclose(fp);
		}	
	}
	else 
		printf("sorry,not found\n");
	free(p);
	return ;
}

void shunxu_name(link *a,char *k_name,int n)
{
	bool *p=(bool *)calloc(n,sizeof(bool));
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		if (strcmp(a[i].name,k_name)==0)
		{
			p[i]=1;
			sum++;
		}
	}	
	if(sum>0)	
	{
		printf("find it!\n");
		printf("共找到 %d条符合条件的数据\n",sum);
		if(sum<=5)
		{
			for(i=0;i<n;i++)
				if(p[i])
				{
					printf("这是第%d个数据:\n",i+1);
					printf("linkid = %d;flag = %d;branch = %d;Class = %d;roadname = %s\n",a[i].linkid,a[i].Flag,a[i].branch,a[i].Class,a[i].name);
				}
		}
		else 
		{
			printf("由于检索结果数据量大于5，结果已保存到C:\\findings.txt中\n");
			FILE *fp;
			if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
			{
				printf("打开文件失败\n");
				return ;
			}
			int j=0;
			for(;j<i;j++)
				if(p[j])
				{
					fprintf(fp,"linkid: ");
					fprintf(fp,"%d",a[j].linkid);
					fprintf(fp,"Class: ");
					fprintf(fp,"%d",a[j].Class);
					fprintf(fp,"branch: ");
					fprintf(fp,"%d",a[j].branch);
					fprintf(fp,"name: ");
					fprintf(fp,"%s\n",a[j].name);
				}
				fclose(fp);
		}
	}
	else 
		printf("sorry,not found\n");
	free(p);
	return ;
}

int Search_linkid_left(link a[],int n,int b)//返回等于b的第一个
{
	if(n==0)
		return -1;
	int low = 0;
	int high = n-1;
	int last = -1;
	while (low<=high)
	{
		int mid = low +(high-low)/2;
		if (a[mid].linkid==b)
		{
			last = mid;
			high = mid -1;
		}
		else if(a[mid].linkid>b)
			high = mid -1;
		else
			low = mid +1;
	}
	
	return last;
	
}
int Search_linkid_right(link a[],int n,int b)//大于b的第一个数
{
	if(n<=0)
		return -1;
	int last = -1;
	int low = 0;
	int high = n-1;
	while (low<=high)
	{
		int mid = low +(high - low)/2;
		if(a[mid].linkid>b)
		{
			last = mid;
			high = mid -1;
		}
		else if (a[mid].linkid<=b)
		{
			low =mid +1;
		}
	}
	
	return last;
}

void zheban_linkid(link *a,int k_linkid,int n)
{
	quicksort_linkid(a,i);
	int left,right;
	left=Search_linkid_left(a,n,k_linkid);
	right=Search_linkid_right(a,n,k_linkid);
	if (left!=-1)
	{	
		if(right==-1)right=n;
		int sum=right-left;
		printf("find it!\n");
		printf("共找到 %d条符合条件的数据\n",sum);
		if(sum<=5)
		{
			int i;
			for(i=left;i<right;i++)
			{
				printf("这是第%d个数据:\n",i+1);
				printf("linkid = %d;flag = %d;branch = %d;Class = %d;roadname = %s\n",a[i].linkid,a[i].Flag,a[i].branch,a[i].Class,a[i].name);
			}
		}
		else 
		{
			printf("由于检索结果数据量大于5，结果已保存到C:\findings.txt中\n");
			FILE *fp;
			if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
			{
				exit( 0 );
				printf("打开文件失败\n");
			}
			for(i=left;i<right;i++)
			{
				fprintf(fp,"linkid: ");
				fprintf(fp,"%d",a[i].linkid);
				fprintf(fp,"Class: ");
				fprintf(fp,"%d",a[i].Class);
				fprintf(fp,"branch: ");
				fprintf(fp,"%d",a[i].branch);
				fprintf(fp,"name: ");
				fprintf(fp,"%s\n",a[i].name);
			}
			fclose(fp);
		}	
	}
	else
		printf("sorry,not found\n");

}


int Search_left_Class(link a[],int n,int b)//返回等于b的第一个
{
	if(n==0)
		return -1;
	int low = 0;
	int high = n-1;
	int last = -1;
	while (low<=high)
	{
		int mid = low +(high-low)/2;
		if (a[mid].Class==b)
		{
			last = mid;
			high = mid -1;
		}
		else if(a[mid].Class>b)
			high = mid -1;
		else
			low = mid +1;
	}
	
	return last;
	
}
int Search_right_Class(link a[],int n,int b)//大于b的第一个数
{
	if(n<=0)
		return -1;
	int last = -1;
	int low = 0;
	int high = n-1;
	while (low<=high)
	{
		int mid = low +(high - low)/2;
		if(a[mid].Class>b)
		{
			last = mid;
			high = mid -1;
		}
		else if (a[mid].Class<=b)
		{
			low =mid +1;
		}
	}
	
	return last;
}

void zheban_Class(link *a,int k_linkClass,int n)
{
	quicksort_Class(a,i);
	int left,right;
	left=Search_left_Class(a,n,k_linkClass);
	right=Search_right_Class(a,n,k_linkClass);
	if (left!=-1)
	{	
		if(right==-1)right=n;
		int sum=right-left;
		printf("find it!\n");
		printf("共找到 %d条符合条件的数据\n",sum);
		if(sum<=5)
		{
			int i;
			for(i=left;i<right;i++)
			{
				printf("这是第%d个数据:\n",i+1);
				printf("linkid = %d;flag = %d;branch = %d;Class = %d;roadname = %s\n",a[i].linkid,a[i].Flag,a[i].branch,a[i].Class,a[i].name);
			}
		}
		else 
		{
			printf("由于检索结果数据量大于5，结果已保存到C:\findings.txt中\n");
			FILE *fp;
			if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
			{
				exit( 0 );
				printf("打开文件失败\n");
			}
			for(i=left;i<right;i++)
			{
				fprintf(fp,"linkid: ");
				fprintf(fp,"%d",a[i].linkid);
				fprintf(fp,"Class: ");
				fprintf(fp,"%d",a[i].Class);
				fprintf(fp,"branch: ");
				fprintf(fp,"%d",a[i].branch);
				fprintf(fp,"name: ");
				fprintf(fp,"%s\n",a[i].name);
			}
			fclose(fp);
		}	
	}
	else
		printf("sorry,not found\n");

}

int Search_left_branch(link a[],int n,int b)//返回等于b的第一个
{
	if(n==0)
		return -1;
	int low = 0;
	int high = n-1;
	int last = -1;
	while (low<=high)
	{
		int mid = low +(high-low)/2;
		if (a[mid].branch==b)
		{
			last = mid;
			high = mid -1;
		}
		else if(a[mid].branch>b)
			high = mid -1;
		else
			low = mid +1;
	}
	
	return last;
}
int Search_right_branch(link a[],int n,int b)//大于b的第一个数
{
	if(n<=0)
		return -1;
	int last = -1;
	int low = 0;
	int high = n-1;
	while (low<=high)
	{
		int mid = low +(high - low)/2;
		if(a[mid].branch>b)
		{
			last = mid;
			high = mid -1;
		}
		else if (a[mid].branch<=b)
		{
			low =mid +1;
		}
	}
	
	return last;
}
void zheban_branch(link *a,int k_linkbranch,int n)
{
	quicksort_branch(a,i);
	int left,right;
	left=Search_left_branch(a,n,k_linkbranch);
	right=Search_right_branch(a,n,k_linkbranch);
	if (left!=-1)
	{	
		if(right==-1)right=n;
		int sum=right-left;
		printf("find it!\n");
		printf("共找到 %d条符合条件的数据\n",sum);
		if(sum<=5)
		{
			int i;
			for(i=left;i<right;i++)
			{
				printf("这是第%d个数据:\n",i+1);
				printf("linkid = %d;flag = %d;branch = %d;Class = %d;roadname = %s\n",a[i].linkid,a[i].Flag,a[i].branch,a[i].Class,a[i].name);
			}
		}
		else 
		{
			printf("由于检索结果数据量大于5，结果已保存到C:\\findings.txt中\n");
			FILE *fp;
			if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
			{
				exit( 0 );
				printf("打开文件失败\n");
			}
			for(i=left;i<right;i++)
			{
				fprintf(fp,"linkid: ");
				fprintf(fp,"%d",a[i].linkid);
				fprintf(fp,"Class: ");
				fprintf(fp,"%d",a[i].Class);
				fprintf(fp,"branch: ");
				fprintf(fp,"%d",a[i].branch);
				fprintf(fp,"name: ");
				fprintf(fp,"%s\n",a[i].name);
			}
			fclose(fp);
		}	
	}
	else
		printf("sorry,not found\n");
}
int Search_name_left(link a[],int n,char *b)//返回等于b的第一个
{
	if(n==0)
		return -1;
	int low = 0;
	int high = n-1;
	int last = -1;
	while (low<=high)
	{
		int mid = low +(high-low)/2;
		if (strcmp(a[mid].name,b)==0)
		{
			last = mid;
			high = mid -1;
		}
		else if (strcmp(a[mid].name,b)==1)
			high = mid -1;
		else
			low = mid +1;
	}
	
	return last;
	
}
int Search_name_right(link a[],int n,char *b)//大于b的第一个数
{
	if(n<=0)
		return -1;
	int last = -1;
	int low = 0;
	int high = n-1;
	while (low<=high)
	{
		int mid = low +(high - low)/2;
		if(strcmp(a[mid].name,b)==1)
		{
			last = mid;
			high = mid -1;
		}
		else if (strcmp(a[mid].name,b)==-1||strcmp(a[mid].name,b)==0)
		{
			low =mid +1;
		}
	}
	
	return last;
}

void zheban_name(link *a,char *k_name,int n)
{
	quicksort_name(a,i);
	int left,right;
	left=Search_name_left(a,n,k_name);
	right=Search_name_right(a,n,k_name);
	if (left!=-1)
	{	
		if(right==-1)right=n;
		int sum=right-left;
		printf("find it!\n");
		printf("共找到 %d条符合条件的数据\n",sum);
		if(sum<=5)
		{
			int i;
			for(i=left;i<right;i++)
			{
				printf("这是第%d个数据:\n",i+1);
				printf("linkid = %d;flag = %d;branch = %d;Class = %d;roadname = %s\n",a[i].linkid,a[i].Flag,a[i].branch,a[i].Class,a[i].name);
			}
		}
		else 
		{
			printf("由于检索结果数据量大于5，结果已保存到C:\findings.txt中\n");
			FILE *fp;
			if( (fp = fopen( "C:\\findings.txt", "w" )) == NULL )
			{
				exit( 0 );
				printf("打开文件失败\n");
			}
			for(i=left;i<right;i++)
			{
				fprintf(fp,"linkid: ");
				fprintf(fp,"%d",a[i].linkid);
				fprintf(fp,"Class: ");
				fprintf(fp,"%d",a[i].Class);
				fprintf(fp,"branch: ");
				fprintf(fp,"%d",a[i].branch);
				fprintf(fp,"name: ");
				fprintf(fp,"%s\n",a[i].name);
			}
			fclose(fp);
		}	
	}
	else
		printf("sorry,not found\n");
	
}
void list2(int c)
{
	int d;
	printf("                 1.顺序检索\n");
	printf("                 2.折半检索\n");
	printf("请选择: ");
	scanf("%d",&d);
	printf("loading...\n");
	printf("********************************************************************************");
	printf("查询结果为：\n");
	switch(d)
	{
	case 1:switch(c)
		   {
				case 1:shunxu_linkid(a,k.linkid,i);break;
				case 2:shunxu_Class(a,k.Class,i);break;
				case 3:shunxu_branch(a,k.branch,i);break;
				case 4:shunxu_name(a,k.name,i);break;
		   }break;
	case 2:switch(c)
		   {
				case 1:zheban_linkid(a,k.linkid,i);break;
				case 2:zheban_Class(a,k.Class,i);break;
				case 3:zheban_branch(a,k.branch,i);break;
				case 4:zheban_name(a,k.name,i);break;
		   }break;
	default:printf("输入错误\n");
	}
	printf("********************************************************************************\n");
}
void search()
{
	int c;
	printf(" 请选择检索的方式:\n");
	printf("                 1.指定linkID检索\n");
	printf("                 2.指定交叉Link列表示Class番号 检索\n");
	printf("                 3.指定查找岔路数 检索\n");
	printf("                 4.指定道路名称　检索\n");
	printf("                 0.返回\n");
	printf("                 请选择: ");
	scanf("%d",&c);
	switch(c)
	{
	case 0:return;
	case 1:
		printf("请输入需要检索linkid的信息: ");scanf("%d",&k.linkid);list2(c);break;
	case 2:
		printf("请输入需要检索Class的信息: ");scanf("%d",&k.Class);list2(c);break;
	case 3:
		printf("请输入需要检索branch的信息: ");scanf("%d",&k.branch);list2(c);break;
	case 4:
		printf("请输入需要检索roadname的信息: ");getchar();gets(k.name);list2(c);break;	
	default:printf("输入错误\n");
	}
}

void fprint(){
	FILE *fp;
	if( (fp = fopen( "C:\\text.txt", "w" )) == NULL )
	{
		exit( 0 );
		printf("打开文件失败\n");
	}
	int j=0;
	for(;j<i;j++)
	{
		fprintf(fp,"linkid: ");
		fprintf(fp,"%d;",a[j].linkid);
		fprintf(fp,"roadflag: ");
		fprintf(fp,"%d;",a[j].Flag);
		fprintf(fp,"Class: ");
		fprintf(fp,"%d;",a[j].Class);
		fprintf(fp,"branch: ");
		fprintf(fp,"%d;",a[j].branch);
		fprintf(fp,"roadname: ");
		fprintf(fp,"%s\n",a[j].name);
	}
	printf("文件输出在：C:\\text.txt\n");
	printf("********************************************************************************");
	fclose(fp);
}
void bye_bye()
{
printf("                 .- <O> -.                   ,-------.  \n");
printf("                /_-\\'''/-_\\                  |,-----.|   \n");
printf("               |/  o) (o  \\|                /,'-----'.\\   \n");
printf("                \\   ._.   /                {_/(') (')\\_}  \n");
printf("                ,>-_,,,_-<.                  '.  _   .'   \n");
printf("                /    .   \\                   /'-___-'\\   \n");
printf("               (_)   .   (_)                /         \\  \n");
printf("                \\  -- -- /                 (_)_______(_) \n");
printf("                 \\ ____ /                    \\_______/   \n");
printf("                        bye  bye        欢迎下次使用\n");
}

void main()
{
print();
	system("COLOR  1F");
		Sleep(150);
		system("COLOR  2F");
		Sleep(150);
		system("COLOR  3F");
		Sleep(150);
		system("COLOR  AF");
		Sleep(150);
		system("COLOR  BF");
		Sleep(150);
		system("COLOR  CF");
		Sleep(150);
		system("COLOR  DF");
		Sleep(150);
		system("COLOR  EF");
		Sleep(150);
		system("COLOR  FF");
		Sleep(150);
		system("COLOR  7F");
		Sleep(150);
		system("COLOR  0F");
	int a1;
	
	while(1)
	{
		printf("请选择服务的种类：\n");
		printf("         1.读取文件(%s)\n",s);
		printf("         2.排序并输出排序结果(C:\\text.txt)\n");
		printf("         3.检索\n");
		printf("         4.更新\n");
		printf("         0.退出\n");
		printf("         请选择：");
		
		scanf("%d",&a1);
		int flag=0;
		if(a1==0||a1==1||a1==2||a1==3||a1==4)
		{
			if(a1!=1&&!fs&&a1!=0)
				printf("请您先读入文件\n");
			else{
			
				switch(a1){
				case 0:flag=1;bye_bye();break;
				case 1:fileopen() ;fs=true;printf("共读入%d条信息\n",i);break;
				case 2: list();break;
				case 3: search();break;
				case 4:fileupdate();break;
				default:printf("输入错误\n");
				}
			}
		}
		else printf("输入错误,请重新输入\n");
		if(flag)break;
		flushall();
	}
}