#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define MAX 65545

int option,sort_option;
int n=1;



 

struct roadinfor

{

         short roadsize;

         int linkid;

         short roadnamesize;

         int aclass;

         int brunch;

         int flag;

         char name[20];

}road[MAX];

 

struct tagMap_t 

{ 

         char sign_one[2]; 

         char linkid[14];

         char flag[7]; 

         char brunch[9]; 

         char dispclass[13]; 

         char Roadname[30]; 

         char sign_two[2]; 

}*s,*ss;

 

int largetolittle (unsigned int large,int byte)

{

         

         unsigned char *p=(unsigned char*)&large;

         if(byte==4)

         return(((unsigned int)*p<<24)+((unsigned int)*(p+1)<<16)+((unsigned int)*(p+2)<<8)+(unsigned int)*(p+3));

         if(byte==2)

                   return(((unsigned int)*p<<8)+(unsigned int)*(p+1));

}

 

int readfile()

{		n=1;

         int temp;

         unsigned int m=0; 

         unsigned int linkid1;          

         unsigned short int roadnamesize1;

         char nodeinfor[4]; 

         unsigned short int totalsize1; 

         unsigned int linkid2; 

         unsigned short int roadnamesize2; 

         unsigned short int totalsize2;
		 printf("读取文件... \n");

         FILE *pf1=fopen("C:\\Documents and Settings\\new\\桌面\\电子地图提供物\\GTBL.dat","rb+");

         FILE *pf2=fopen("C:\\Documents and Settings\\new\\桌面\\电子地图提供物\\file.txt","w+");
  
         if(pf1==NULL)

         {

                   printf("cannot open the GTBL.dat\n");

                   return 0;

         }

         if(pf2==NULL)

         {

                   printf("cannot open the file\n");

                   return 0;

         }

         printf("读取中...\n");

         while(fread(&totalsize1,sizeof(totalsize1),1,pf1))

         {

                   fread(&linkid1,sizeof(linkid1),1,pf1);

                   fread(&roadnamesize1,sizeof(roadnamesize1),1,pf1);

                   fread(nodeinfor,sizeof(nodeinfor),1,pf1);

                   totalsize2=largetolittle(totalsize1,2);

                   linkid2=largetolittle(linkid1,4);

                   roadnamesize2=largetolittle(roadnamesize1,2);

                   fread(road[n].name,sizeof(char),totalsize2-12,pf1);

                   road[n].roadsize=totalsize2;

                   road[n].linkid=linkid2;

                   road[n].roadnamesize=roadnamesize2;

                   temp=(int)nodeinfor[3]&255;

                   road[n].aclass=temp&15;

                   road[n].brunch=(temp&112)/16;

                   road[n].flag=(temp&128)/128;

                   fprintf(pf2,"%d\t",n); 

                   fprintf(pf2,"LinkID="); 

                   fprintf(pf2,"%d\t" ,road[n].linkid); 

                   fprintf(pf2,"flag="); 

                   fprintf(pf2,"%d\t" ,road[n].flag); 

                   fprintf(pf2,"brunch="); 

                   fprintf(pf2,"%d\t" ,road[n].brunch); 

                   fprintf(pf2,"class="); 

                   fprintf(pf2,"%-4d" ,road[n].aclass); 

                   fprintf(pf2,"Roadname="); 

                   fprintf(pf2,"%s\t" ,road[n].name+4);  

                   fprintf(pf2,"\n");

                   n++;

         }
							

         fclose(pf1);

         fclose(pf2);

         printf("成功读取文件!\n");

         return 0;

}
struct Road_REC
{
    unsigned short usRecSize;
	unsigned short usRoadNameSize;
	unsigned long ulLinkID;
	unsigned long ulStaNodeInfo;
	unsigned char *pcRoadName;
};

struct Road
{
    struct Road_REC stRoadRec;
	struct Road* pNextNode;  
};
struct PST_Road
{
    struct Road_REC* stRoadRec;
	struct PST_Road* pNextNode;  
};


signed long bubblesort(
	       
	)
{	int z,i,j;
	clock_t         start,finish;
		
    start=clock();										
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(road[i].linkid>road[j].linkid)
			{
				z=road[i].linkid;
				road[j].linkid=road[i].linkid;
				road[i].linkid=z;
			}

    finish=clock();
	printf( "\nSort OK!\n" );
   
	printf("运行时间：%4.2f\n",(double)(finish-start)/CLOCKS_PER_SEC);
	system("pause");
	return 0;
}

signed long selectsort(
		
	)
{
	clock_t         start,finish;
	
    start=clock();
	int i,j,m,z;
		for(i=0;i<n;i++)
		{
			m=i;
			for(j=i;j<n;j++)
				if(road[j].linkid<road[m].linkid)
					m=j;
				z=road[i].linkid;
				road[m].linkid=road[i].linkid;
				road[m].linkid=z;
		}


    finish=clock();
	printf( "\nSort OK!\n" );
	printf("运行时间：%4.2f\n",(double)(finish-start)/CLOCKS_PER_SEC);
	system("pause");
	return 1;
}
signed long charusort()
{
	clock_t         start,finish;

    start=clock();
	int i,j,t;
	for(i=1;i<n;i++)
	{
		t=road[i].linkid;
		j=i-1;
		while(t<road[j].linkid&&j>=0)
		{
			road[j+1].linkid=road[j].linkid;
			j--;
		}
		road[j+1].linkid=t;
	}
	


    finish=clock();
	printf( "\nSort OK!\n" );
	printf("运行时间：%4.2f\n",(double)(finish-start)/CLOCKS_PER_SEC);
	system("pause");
	return 1;
}
signed long kuai(int head,int tail)
{
	int i=head,j=tail;
	int x=road[head].linkid;
	while(i<j)
	{
		while(i<j && road[j].linkid>=x) j--;
		road[i].linkid=road[j].linkid;
		while(i<j && road[i].linkid<=x) i++;
		road[j].linkid=road[i].linkid;
	}
	road[i].linkid=x;
	if (head<i-1) kuai(head,i-1);
	if (j+1<tail) kuai(j+1,tail);return 0;
}
signed long kuaisu(int head,int tail)
{
	clock_t         start,finish;
	
    start=clock();

	kuai(head,tail-1);



	finish=clock();
	
	printf( "\nSort OK!\n" );
	
	printf("运行时间：%4.2f\n",(double)(finish-start)/CLOCKS_PER_SEC);
	
	system("pause");

	return 1;
}

signed long zhiding()
{	int link,i;
	clock_t         start,finish;
	printf("请输入Link的ID:");
	scanf("%d",&link);
	printf( "\nIt is now sorting. Please wait...\n" );
    start=clock();
	i=0;
	while(road[i].linkid!=link&&i<=n)
	i++;
	if(i<=n)
	{
		printf("*******************************************************************************\n");
		printf("roadsize=%d;#LinkID=%d;roadnamesize=%d;aclass=%d;brunch=%d;flag=%d;name=%s\n",road[i].roadsize,road[i].linkid,road[i].roadnamesize,road[i].aclass,road[i].brunch,road[i].flag,road[i].name+4);
		printf("*******************************************************************************\n");}
	else
	printf("没有查到所输入Llink:\n");

	


    finish=clock();
	printf( "\nSort OK!\n" );
	printf("运行时间：%4.2f\n",(double)(finish-start)/CLOCKS_PER_SEC);
	system("pause");
	return 1;
}
signed long jiaocha()
{	int i, class1,j=0;
	clock_t         start,finish;
	printf("请输入交叉Link列表示Class番号:");
	scanf("%d",&class1);
	printf( "\nIt is now sorting. Please wait...\n" );
    start=clock();
	
	printf("*******************************************************************************\n");
	for(i=0;i<n;i++)
		if(road[i].aclass==class1)
		{j++;printf("roadsize=%d;#LinkID=%d;roadnamesize=%d;aclass=%d;brunch=%d;flag=%d;name=%s\n",road[i].roadsize,road[i].linkid,road[i].roadnamesize,road[i].aclass,road[i].brunch,road[i].flag,road[i].name+4);}
	printf("*******************************************************************************\n");
	finish=clock();
	printf( "\nSort OK!\n" );
	printf("运行时间：%4.2f\n",(double)(finish-start)/CLOCKS_PER_SEC);
	if(j==0)printf("没有找到指定Class番号:\n");
	system("pause");
	return 1;
}
signed long chalu()	  
{	int brunch1,i,j=0;
	clock_t         start,finish;
	printf("请输入查找岔路数:");
	scanf("%d",&brunch1);
	printf( "\nIt is now sorting. Please wait..." );
    start=clock();
	
	printf("*******************************************************************************\n");
	for(i=0;i<n;i++)
		if(road[i].brunch==brunch1)
		{j++;printf("roadsize=%d;#LinkID=%d;roadnamesize=%d;aclass=%d;brunch=%d;flag=%d;name=%s\n",road[i].roadsize,road[i].linkid,road[i].roadnamesize,road[i].aclass,road[i].brunch,road[i].flag,road[i].name+4);}
	printf("*******************************************************************************\n");
	finish=clock();
	printf( "\nSort OK!\n" );
	printf("运行时间：%4.2f\n",(double)(finish-start)/CLOCKS_PER_SEC);
	if(j==0)printf("没有找到指定岔路数的道路:\n");
	system("pause");
	return 1;
}
signed long mingcheng()
{	int i,j=0,k,chang;char ming[20];
	clock_t         start,finish;
	printf("请输入道路名称:");
	scanf("%s",ming);
	chang=strlen(ming);
	printf( "\nIt is now sorting. Please wait...\n" );
    start=clock();
	
	printf("*******************************************************************************\n");
	for(i=0;i<n;i++)
	{
		for(k=0;k<chang;k++)
		if(road[i].name[k+4]!=ming[k])break;
		if(k==chang)
		{j++;printf("roadsize=%d;#LinkID=%d;roadnamesize=%d;aclass=%d;brunch=%d;flag=%d;name=%s\n",road[i].roadsize,road[i].linkid,road[i].roadnamesize,road[i].aclass,road[i].brunch,road[i].flag,road[i].name+4);}}
	printf("*******************************************************************************\n");
	finish=clock();
	printf( "\nSort OK!\n" );
	printf("运行时间：%4.2f\n",(double)(finish-start)/CLOCKS_PER_SEC);
	if(j==0)printf("没有找到指定道路名的道路:\n");
	system("pause");
	return 1;
}

int tianjia()

{
			n=1;
         int temp;

         unsigned int m=0; 

         unsigned int linkid1;          

         unsigned short int roadnamesize1;

         char nodeinfor[4]; 

         unsigned short int totalsize1; 

         unsigned int linkid2; 

         unsigned short int roadnamesize2; 

         unsigned short int totalsize2;
		 printf("读取文件... \n");

         FILE *pf1=fopen("C:\\Documents and Settings\\new\\桌面\\电子地图提供物\\GTBL.dat","rb+");

         FILE *pf2=fopen("C:\\Documents and Settings\\new\\桌面\\电子地图提供物\\file1.txt","w+");
  
         if(pf1==NULL)

         {

                   printf("cannot open the GTBL.dat\n");

                   return 0;

         }

         if(pf2==NULL)

         {

                   printf("cannot open the file\n");

                   return 0;

         }

         printf("读取中...\n");

         while(fread(&totalsize1,sizeof(totalsize1),1,pf1))

         {

                   fread(&linkid1,sizeof(linkid1),1,pf1);

                   fread(&roadnamesize1,sizeof(roadnamesize1),1,pf1);

                   fread(nodeinfor,sizeof(nodeinfor),1,pf1);

                   totalsize2=largetolittle(totalsize1,2);

                   linkid2=largetolittle(linkid1,4);

                   roadnamesize2=largetolittle(roadnamesize1,2);

                   fread(road[n].name,sizeof(char),totalsize2-12,pf1);

                   road[n].roadsize=totalsize2;

                   road[n].linkid=linkid2;

                   road[n].roadnamesize=roadnamesize2;

                   temp=(int)nodeinfor[3]&255;

                   road[n].aclass=temp&15;

                   road[n].brunch=(temp&112)/16;

                   road[n].flag=(temp&128)/128;

                   fprintf(pf2,"%d\t",n); 

                   fprintf(pf2,"LinkID="); 

                   fprintf(pf2,"%d\t" ,road[n].linkid); 

                   fprintf(pf2,"flag="); 

                   fprintf(pf2,"%d\t" ,road[n].flag); 

                   fprintf(pf2,"brunch="); 

                   fprintf(pf2,"%d\t" ,road[n].brunch); 

                   fprintf(pf2,"class="); 

                   fprintf(pf2,"%-4d" ,road[n].aclass); 

                   fprintf(pf2,"Roadname="); 

                   fprintf(pf2,"%s\t" ,road[n].name+4);  

                   fprintf(pf2,"\n");

                   n++;

         }
		 
		 fprintf(pf2,"%d\t" ,n);
		 
		 first4:

		 printf("请输入Link的ID:");
		 
		 scanf("%d",&road[n-1].linkid);
		 
		 fflush(stdin);
		 
		 for(int i=1;i<n-1;i++)
			 
			 if(road[n-1].linkid==road[i].linkid)
				 
			 {
				 printf("您输入的Linkid已存在请重新输入:\n");
			 
				goto first4;
			 }
		  
		 fprintf(pf2,"LinkID="); 

         fprintf(pf2,"%d\t" ,road[n-1].linkid);
		  
		 //fprintf(pf1,"LinkID="); 

         fprintf(pf1,"%d" ,road[n-1].linkid);  
		 
		 
		 printf("请输入flag=");
		 
		 scanf("%d",&road[n-1].flag);fflush(stdin);
		 
		 fprintf(pf2,"flag="); 

         fprintf(pf2,"%d\t" ,road[n-1].flag); 
		  
		 //fprintf(pf1,"flag="); 

         fprintf(pf1,"%d" ,road[n-1].flag); 

	     
		 printf("请输入岔路数:");
		 
		 scanf("%d",&road[n-1].brunch);fflush(stdin);
		 
		 fprintf(pf2,"brunch="); 

         fprintf(pf2,"%d\t" ,road[n-1].brunch); 
		 
		 //fprintf(pf1,"brunch="); 

         fprintf(pf1,"%d" ,road[n-1].brunch); 
		 
		 
		 printf("请输入交叉Link列表示Class番号:");
		 
		 scanf("%d",&road[n-1].aclass);fflush(stdin);

		 fprintf(pf2,"class="); 
		 
		 fprintf(pf2,"%-4d" ,road[n-1].aclass); 
		 
		// fprintf(pf1,"class="); 
		 
		 fprintf(pf1,"%d" ,road[n-1].aclass); 


		 
		 
		 printf("请输入道路名称:");
		 
		 scanf("%s",road[n-1].name+4);fflush(stdin);
		 
		 fprintf(pf2,"Roadname="); 

         fprintf(pf2,"%s\t" ,road[n].name);  
        
		// fprintf(pf1,"Roadname="); 

         fprintf(pf1,"%s" ,road[n].name);  
          
		 
		 fclose(pf1);

         fclose(pf2);

         printf("成功添加文件!\n保存在C:\\Documents and Settings\\new\\桌面\\电子地图提供物\\file.txt中\n");
		 
		 n++;

		 system("pause");

         return 0;

}



void main()
{	
   printf("              /**************************************************/\n");
  printf("              /****we are not the best, but we have tried.*******/\n");     
  printf("              /************************ Ψ **********************/\n");
  printf("              /********************** Ψ  Ψ ********************/\n");
  printf("              /********************* Ψ    Ψ *******************/\n");
  printf("              /******************** Ψ      Ψ ******************/\n"); 
  printf("              /****************** Ψ          Ψ ****************/\n");	  
  printf("              /************** Ψ        紫        Ψ ************/\n");	  
  printf("              /************ Ψ                     Ψ ***********/\n");  
  printf("              /*********** Ψ     禁         城     Ψ **********/\n");	 
  printf("              /*********** Ψ                       Ψ **********/\n");	  
  printf("              /*********** Ψ                       Ψ **********/\n");
  printf("              /*********** Ψ           Ψ          Ψ **********/\n");
  printf("              /*********** Ψ       Ψ **** Ψ      Ψ **********/\n");
  printf("              /************ Ψ   Ψ ********** Ψ   Ψ **********/\n");
  printf("              /*************** Ψ *************** Ψ ************/\n");
  printf("              /**************************************************/\n");
  printf("              /*******************************       L-wox  队   /\n");
  printf("              /*******************************      组长 吕经祥  /\n");
  printf("              /*******************************      组秘 刘春宁  /\n");
  printf("              /*******************************  技术总监 徐  畅  /\n");
  printf("              /*******************************  界面美工 王  鹤  /\n");
  printf("              /*******************************  动漫特效 刘增宇  /\n");
  printf("              /*******************************  电影特效 代芙瑛  /\n");
  printf("              /***  我们不是猛虎，我们是蜗牛，所以我们慢慢来  ***/\n");
  printf("              /**************************************************/\n");	
	int z=0;	
  
  while(1)
	{
				
  
 
  system("color 1e");

		first:
		printf("初始默认读取文件C:\\Documents and Settings\\new\\桌面\\电子地图提供物GTBL.dat");
		printf("请选择服务种类：\n");
		printf("       1.读取文件C:\\Documents and Settings\\new\\桌面\\电子地图提供物GTBL.dat\n");
		printf("       2.排序\n");
		printf("       3.检索\n");
		printf("       4.更新\n");
		printf("       0.退出\n");
		printf("       请选择：");


		scanf("%d",&option);
		fflush(stdin);
		if(option==0){printf("谢谢使用本软件。。。byebye\n");break;}
		switch(option)
		{
		case 1:readfile();break;
		case 2:
			{	first1:
				if(z==0)
				{
				printf("             请选择排序方法：\n");
				printf("             1.冒泡排序\n");
				printf("             2.选择排序\n");
				printf("             3.插入排序\n");
				printf("             4.快速排序(只能使用一次)\n");
				printf("             0.返回\n");
				printf("             请选择：");
			
				scanf("%d",&sort_option);
				fflush(stdin);
				if(sort_option==0)goto first;
				printf( "\nIt is now sorting. Please wait..." );
				switch(sort_option)
				{
				case 1 :bubblesort();break;
				case 2 :selectsort();break;
				case 3 :charusort() ;break;
				case 4 : kuaisu(0,n);z=1;break;
				default :printf("输入错误，请输入指定数字：\n");goto first1;
				}				
				}
				else
				{
				printf("             请选择排序方法：\n");
				printf("             1.冒泡排序\n");
				printf("             2.选择排序\n");
				printf("             3.插入排序\n");
				printf("             0.返回\n");
				printf("             请选择：");
			
				scanf("%d",&sort_option);
				fflush(stdin);
				if(sort_option==0)goto first;
				printf( "\nIt is now sorting. Please wait..." );
				switch(sort_option)
				{
				case 1 :bubblesort();break;
				case 2 :selectsort();break;
				case 3 :charusort() ;break;
				default :printf("输入错误，请输入指定数字：\n");goto first1;
				}
				}
			}break;	
		case 3: 
			{	first2:
				printf("             请选择检索方法：\n");
				
				printf("             1.指定LinkID检索\n");
				
				printf("             2.指定交叉Link列表示Class番号 检索\n");
				
				printf("             3.指定查找岔路数 检索\n");
				
				printf("             4.指定道路名称 检索\n");
				
				printf("             0.返回\n");
				
				printf("             请选择：");

				scanf("%d",&sort_option);
				fflush(stdin);
				if(sort_option==0)goto first;
				switch(sort_option)
				{
				case 1:zhiding();break;
				case 2:jiaocha();break;
				case 3:chalu();break;
				case 4:mingcheng();break;
				default :printf("请输入指定数字：\n");goto first2;
				}
			
			};break;
		case 4:
			{
				first3:
				
				printf("             请选择更新操作：\n");
				
				printf("             1.添加\n");
				
				printf("             0.返回\n");
				
				printf("             请选择：");
				
				scanf("%d",&sort_option);
				
				fflush(stdin);
				if(sort_option==0)goto first;
				switch(sort_option)
				{
				case 1:tianjia();break;
				default:printf("请输入指定数字：\n");goto first3;		

				
				}
			   
			   
			 };break;
		default :printf("输入错误，请输入指定数字：\n");goto first;
		}
	}
	
}