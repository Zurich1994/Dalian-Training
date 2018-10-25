/**************************************************************************************
*	Filename:tagMap_tDo.cpp															  *	  
*	Created:																          * 
*	Author:													                          *
**************************************************************************************/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<iostream>
#include<algorithm>
#include<conio.h>
/*函数声明部分*/
void ma_interf();
int ReadFile();
void WriteResult (int b[] , int j);
void Search();

/*宏定义*/
#define MCGETCHAR(data)  (*((char *)(data)))
#define MCGETSHORT(data)  ((unsigned short)(( ((unsigned short)(*((char *)(data))))<<8 )|( ((unsigned short)(*((char *)(data)+1)))&0x00ff )))
#define MCGETLONG(data)  ( ( ((unsigned long)MCGETSHORT((data)))<<16 )|( ((unsigned long)MCGETSHORT((char *)(data)+2))&0x0000ffff ) )
#define MCGET3BN(data)  ( ( ((unsigned long)MCGETCHAR((data)))<<16 )|( ((unsigned long)MCGETSHORT((char *)(data)+1))&0x0000ffff ) )
#define Length 655350 

int size = 2 ;
int m[Length];
/*定义结构体类型及变量*/
struct  RoadRecord
{
	short ussize;
	long  ullinkId;
	short usroadnamesize;
	int   usdispclass;
	int   usbrunch;
	int   usroadnameflag;
	char  roadname[20];
}road[Length];
int mark_1=0,mark_2=0;    //标记程序是否运行读取文件和排序操作

struct dataOut
{   long linkid;
	int  dispclass;
	int  brunch;
	int  roadnameflag;
    char roadname[20];
	short  totalsize;
	short roadnamesize;
}data[Length];
void SortData(dataOut data[]);
void Update (dataOut data[]); 
void clockii();

					 /*存储道路信息的数组*/      

/**************************************************************************************
*	Functionname:ReadFile															  *
*	Function Description:读取二进制文件，并将其解析在文本文档里						  *
*	Date:2013/7/31																      * 
**************************************************************************************/

int   ReadFile() 
{ 
	
	char aclinkId[4] ;							/*从二进制文件中读取道路编号*/
    char acroadnamesize[2] ;			    	/*从二进制文件中读取道路名称数据长度*/
    char acNodeInfo[4];
	
	unsigned short ustotalsize;
    unsigned long  ullinkId;
    unsigned short usroadnamesize;
	
	char actotalsize[2] ;					   /*从二进制文件中读取道路信息的总体数据长度 */
	
	FILE *pfp = fopen( "e:\\电子地图提供物\\GTBL.dat " ,  "rb+");  
    printf("读入文件...\n读取中...\n");
	if(pfp == NULL)
	{
		printf("can not open the GTBL.dat file or there is no the file!\n");
		return 0;
	}
	while(fread(actotalsize , sizeof(actotalsize) , 1 , pfp) == 1)    
	{
        fread( aclinkId , sizeof(aclinkId) , 1 , pfp ) ;				/*读取占用4字节的linkId字符*/      
		fread( acroadnamesize , sizeof(acroadnamesize) , 1 , pfp ) ;	/*读取占用2字节的roadnamesize字符串*/	 
		fread( acNodeInfo , sizeof(acNodeInfo) , 1 , pfp ) ;   
		
		ustotalsize = MCGETSHORT(actotalsize) ;							/*调用宏函数 ， 将字符串信息转化为数值类型*/
		ullinkId = MCGETLONG(aclinkId) ;
		usroadnamesize = MCGETSHORT(acroadnamesize) ;
		
		/*赋值 ：将数值信息传到结构体中*/ 
		road[size].ussize = ustotalsize ;
		road[size].ullinkId = ullinkId ;
		road[size].usroadnamesize= usroadnamesize ;
		
		m[size]=(int)acNodeInfo[3]&255;
		road[size].usdispclass=m[size]&15;
		road[size].usbrunch=(m[size]&112)/16;
		road[size].usroadnameflag=(m[size]&128)/128;
		
		data[size].roadnamesize=road[size].usroadnamesize;
		data[size].totalsize = road[size].ussize;
		data[size].dispclass= road[size].usdispclass;
		data[size].brunch=road[size].usbrunch;
		data[size].roadnameflag=road[size].usroadnameflag;
		data[size].linkid= ullinkId;
		fread(road[size].roadname , sizeof(char) , ustotalsize - 12 , pfp ) ;	/*从文件中读取道路名称*/	
		strcpy(data[size].roadname,road[size].roadname+4);
		
		size++;
		
		
	}
	fclose(pfp);  

	return  0; 
}

/**************************************************************************************
*	Functionname:Search																  *
*	Function Description:检索信息部分，可按不同的类型进行检索				     	  *
*	Date:2013/7/31																      * 
**************************************************************************************/
void Search()
{
	int  select , i=0 , j=0 , *b , c=0 , f,p;  //select 标记选择需要运行的分支  i 循环控制  j标记检索到信息的条数  
	//b 数组指针 用来存放检索到的信息的下标 c 用来存放数组b的下标  f 标记数组b的值
	printf("\n\n\t请输入检索方式:\n\n\t\t1:顺序查找\n\n\t\t2:折半查找\n\n\t\t0:返回\n\n\t\t请选择：");
	scanf("%d" , &select);
	//system("cls");
	printf("\n\n>>>>>>>>--当检索到信息条数超过5条时 , 会把检索到的信息存放在searchresult文件中--<<<<<<<<<<<<<\n\n");
	printf("\n><><><><><>--当检索到信息条数未超过5条时 , 会把检索到的信息直接显示在屏幕上--<><><><><><><>\n\n\n");
	if(select==1)
	{
	   printf("\n\n\t请输入检索方式:\n\n\t\t1:指定linkID 检索\n\n\t\t2:指定交叉link列表示class番号 检索\n\n\t\t3:指定查找岔路数 检索\n\n\t\t0:返回\n\n\t\t请选择：");	
		scanf("%d",&p);
		if(p == 1)
		{
		  int sss;
			printf("\t请输入link的ID:");
			scanf("%d", &sss);
				for(i=0; i<(size-2); i++)
				{
					if(sss ==data[i].linkid)    
						{
							printf("\n\n   Linkid=%d flag=%d brunch=%d dispclass=%d roadname=%s \n\n\n" ,data[i].linkid , data[i].roadnameflag , data[i].brunch , 
								data[i].dispclass , data[i].roadname );
							j++;
						}
				}
			    if(j == 0)
				{
					printf("\n\n\t\t\t\t没有匹配结果\n\n\t\t\t    请重新选择检索方式\n");
					flushall();
					Search();
				}
		}
	   else if(p == 2)
			{
				int sss;
				printf("\t请输入交叉link列表示class番号:");
				scanf("%d" , &sss);
				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].dispclass)				
							{
								j++;
							}
					}
				b=(int *)malloc(sizeof(int)*j);				//动态申请数组b的存储空间

				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].dispclass)			
							{
								b[c]=i;
								c++;
							}
					}
					if(j == 0)
						{
							printf("\n\n\t\t\t\t没有匹配结果\n\n\t\t\t    请重新选择检索方式\n");
							flushall();
							Search();
						}
						else if(j>5)
							{
								WriteResult(b  ,  j);	
							}
						else if (j<=5)								//判断检索到得条数是否超过5条
						{
							printf("\n\n");
							for(i=0; i<j; i++)
								{
									f=b[i];
									printf("\n\n   Linkid=%d flag=%d brunch=%d dispclass=%d roadname=%s \n\n\n" ,data[i].linkid , data[i].roadnameflag , data[i].brunch , 
								           data[i].dispclass , data[i].roadname );

								}
							printf("\n\n");
						}
				free(b);
			}
	   else if(p == 3)
			{
				int sss;
				printf("\t请输入岔路数:");
				scanf("%d" ,&sss);
				//system("cls");				//连接字符串
				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].brunch)			//比较字符串是否一致
							{
								j++;
							}
					}
				b=(int *)malloc(sizeof(int)*j);							//动态申请数组b的存储空间

				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].brunch)			//比较字符串是否一致
							{
								b[c]=i;
								c++;
							}
					}
						if(j == 0)
							{
								printf("\n\n\t\t\t\t没有匹配结果\n\n\t\t\t    请重新选择检索方式\n");
								flushall();
								Search();
							}
						else if(j>5)
							{
								WriteResult(b  ,  j);	
							}
						else if (j<=5)							//判断检索到得条数是否超过5条
						{
							printf("\n\n");
							for(i=0; i<j; i++)
								{
									f=b[i];
									printf("\n\n   Linkid=%d flag=%d brunch=%d dispclass=%d roadname=%s \n\n\n" ,data[i].linkid , data[i].roadnameflag , data[i].brunch , 
								           data[i].dispclass , data[i].roadname );

								}
							printf("\n\n");
						}
				free(b);
			}
	  
	  else if(p == 0)
		{
		//	system("cls");
			ma_interf();clockii();
		}	
	  else							// 输入不在0到4之间给出提示信息 重新返回检索函数
		{
			//system("cls");
			printf("\n\n\t\t输入信息错误，请重新选择检索方式\n\n");
			flushall();
			Search();
		}
   }
   else if(select==2)
  {
    printf("\n\n\t请输入检索方式:\n\n\t\t1:指定linkID 检索\n\n\t\t2:指定交叉link列表示class番号 检索\n\n\t\t3:指定查找岔路数 检索\n\n\t\t0:返回\n\n\t\t请选择：");	
	   scanf("%d",&p);
		if(p == 1)
		{
		  int sss,m;
			printf("\t请输入link的ID:");
			scanf("%d" , &sss);
			i=0;j=size-3;
			m=(i+j)/2;
            while(sss!=data[m].linkid&&i<=j)
			{
				if(data[m].linkid>sss)
					j=m-1;
				if(data[m].linkid<sss)
					i=m+1;
				m=(i+j)/2;
			}
			if(i<=j)
			  printf("\n\n   Linkid=%d flag=%d brunch=%d dispclass=%d roadname=%s \n\n\n" ,data[m].linkid , data[m].roadnameflag , data[m].brunch , 
					data[m].dispclass , data[m].roadname );
			else
			{    
				printf("\n\n\t\t\t\t没有匹配结果\n\n\t\t\t    请重新选择检索方式\n");
				flushall();	
				Search();
			}
		}
	   else if(p == 2)
			{
				int sss;
				printf("\t请输入交叉link列表示class番号:");
				scanf("%d" , &sss);
				//system("cls");				//连接字符串
				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].dispclass)			//比较字符串是否一致	
							{
								j++;
							}
					}
				b=(int *)malloc(sizeof(int)*j);				//动态申请数组b的存储空间

				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].dispclass)			//比较字符串是否一致
							{
								b[c]=i;
								c++;
							}
					}
					if(j == 0)
						{
							printf("\n\n\t\t\t\t没有匹配结果\n\n\t\t\t    请重新选择检索方式\n");
							flushall();
							Search();
						}
						else if(j>5)
							{
								WriteResult(b  ,  j);	
							}
						else if (j<=5)								//判断检索到得条数是否超过5条
						{
							printf("\n\n");
							for(i=0; i<j; i++)
								{
									f=b[i];
									printf("\n\n   Linkid=%d flag=%d brunch=%d dispclass=%d roadname=%s \n\n\n" ,data[i].linkid , data[i].roadnameflag , data[i].brunch , 
								           data[i].dispclass , data[i].roadname );

								}
							printf("\n\n");
						}
				free(b);
			}
	   else if(p == 3)
			{
				int sss;
				printf("\t请输入岔路数:");
				scanf("%d" ,&sss);
				//system("cls");				//连接字符串
				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].brunch)			//比较字符串是否一致
							{
								j++;
							}
					}
				b=(int *)malloc(sizeof(int)*j);							//动态申请数组b的存储空间

				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].brunch)			//比较字符串是否一致
							{
								b[c]=i;
								c++;
							}
					}
						if(j == 0)
							{
								printf("\n\n\t\t\t\t没有匹配结果\n\n\t\t\t    请重新选择检索方式\n");
								flushall();
								Search();
							}
						else if(j>5)
							{
								WriteResult(b  ,  j);	
							}
						else if (j<=5)							//判断检索到得条数是否超过5条
						{
							printf("\n\n");
							for(i=0; i<j; i++)
								{
									f=b[i];
									printf("\n\n   Linkid=%d flag=%d brunch=%d dispclass=%d roadname=%s \n\n\n" ,data[i].linkid , data[i].roadnameflag , data[i].brunch , 
								           data[i].dispclass , data[i].roadname );

								}
							printf("\n\n");
						}
				free(b);
			}
	  else if(p == 0)
		{
		//	system("cls");
			ma_interf();
			clockii();
		}	
	  else							// 输入不在0到4之间给出提示信息 重新返回检索函数
		{
			//system("cls");
			printf("\n\n\t\t输入信息错误，请重新选择检索方式\n\n");
			flushall();
			Search();
		}
   }
   else if(select == 0)
		{
		//	system("cls");
			ma_interf();
			clockii();
		}	
   else							// 输入不在0到4之间给出提示信息 重新返回检索函数
		{
			//system("cls");
			printf("\n\n\t\t输入信息错误，请重新选择检索方式\n\n");
			flushall();
			Search();
		}	 
       ma_interf();	
	   clockii();// 执行结束 返回主界面
}

/**************************************************************************************
*	Functionname: WriteResult														  *
*	Function Description:检索信息，当超过5条时，就将信息写入一个文档中				  *
*	Date:2013/7/31																      * 
**************************************************************************************/

void WriteResult (int b[] , int j)
{
	FILE *qq;
	if((qq=fopen("e:\\searchresult.txt" , "w")) == NULL)  //判断文件是否创建成功
		{
			printf("创建文件失败\n");
			exit(0);
		}
	int i=0 , f;		//  i 为循环控制变量  f 记录传入数组在不同的i下 b[i]  的值
	printf("\n\n\t\t\t检索到的信息超过--5--条\n\n\n\t检索到的信息写入searchresult文件中……\n");
	for(i=0; i<j; i++)
		{
			f=b[i];
			fprintf(qq , "#\t");				
			fprintf(qq , "linkid=%d\t" , data[f].linkid);		// 检索到的道路信息写入文件中
			fprintf(qq , "roadnameflag=%d\t" , data[f].roadnameflag);			// 检索到的道路信息写入文件中
			fprintf(qq , "brunch=%d\t" , data[f].brunch);		// 检索到的道路信息写入文件中
			fprintf(qq , "dispclass=%d\t" , data[f].dispclass);		// 检索到的道路信息写入文件中
			fprintf(qq , "roadname=%s\t" , data[f].roadname);		// 检索到的道路信息写入文件中
			fprintf(qq , "#");
			fprintf(qq , "\n");
		}
	fclose(qq);						//关闭指针qq
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n\n\t\t检索到的信息写入searchresult文件中成功\n\n\n");	
	printf("------------------------------------------------------------------------------\n");
}
/**************************************************************************************
*	Functionname:Judge 													        	  *
*	Function Description:判断解析出来的文件是否存在									  *
*	Date:2013/7/31																      * 
**************************************************************************************/
void Judge()
{
	FILE *pp;

	if((pp=fopen("e:\\电子地图提供物\\GTBL.dat" , "rb")) == NULL)    //打开文件 并返回pp文件指针 判断文件是否存在
		{
			printf("\n\n\t\t\t\tthe file not exist!\n\n\t\t\t\t  请重新选择服务：\n\n");
		}
	else
		{
		printf("文件读取成功!\nSuccess!\n");	
		}
}
void ma_interf()
{
	int select;			//select 控制在主界面是选择需要执行的函数		
	printf("请选择服务的种类：\n");	
	printf("\t1:读取文件\n\t2:排序并输出结果\n\t3:检索\n\t4:更新\n\t0:退出\n\t请选择:");
	scanf("%d" , &select);
	clockii();
	switch(select)
		{
			case 1 :
				ReadFile();
				mark_1=1;
				Judge();//标记是否执行读取文件
				ma_interf();
				clockii();
				break;
		   case 2 :
				if(mark_1!=1)
					{
						printf("\n\n\t请在进行排序前先选择-1-进行读取文件，否则无数据进行排序\n\n");
						ma_interf();clockii();
					}
				else if(mark_1==1)
					{
						mark_2=1;		//标记是否执行排序操作
						SortData(data);
					}
				break;
			case 3 :
				if(mark_1==0||mark_2==0)		//判断是否执行 读取文件  和排序道路信息
					{
						printf("\n\n\t\t请在进行-检索-前先选择-1--2-进行读取文件和排序操作\n\n");
						printf("\t\t     否则无数据进行检索或检索到的数据未排序\n\n");
						ma_interf();
						clockii();
					}
				else
					{
						Search();
					}
				break;
			case 4 :
				if(mark_1==0||mark_2==0)		//判断是否执行 读取文件  和排序道路信息
					{
						printf("\n\n\t\t请在进行-更新-前先选择-1--2-进行读取文件和排序操作\n\n");
						printf("\t\t   否则无数据进行更新或更新到得数据未排序\n\n");
						ma_interf();
						clockii();
					}
				else
					{
						Update(data);
						break;
					}
			case 0 :
				exit(0);
				break;
			default:flushall();
			printf("\n\n\n\t\t\t输入信息出错，请重新选择服务种类：\n\n\n\n");
			ma_interf();	
			clockii();//执行结束 返回主界面
		}
}
/**************************************************************************************
*	Functionname: SortData  														  *
*	Function Description:对读取出来的文件信息进行排序并将排序结果显示在屏幕上		  *
*	Date:2013/7/31																      * 
**************************************************************************************/
int qsort1(struct dataOut l[],int low,int high)
{
	int m=l[low].linkid ;
    l[0].linkid =l[low].linkid ;
     while (low<high)
	 {     
		 while (low<high&&l[high].linkid >=m)     
			     --high;   
          l[low].linkid =l[high].linkid ;   
          l[low].roadnameflag =l[high].roadnameflag ;
		  l[low].brunch =l[high].brunch ;
		  l[low].dispclass =l[high].dispclass;
		  strcpy(l[low].roadname , l[high].roadname);
		  while (low<high&&l[low].linkid <=m)      
			     ++low;  
          l[high].linkid =l[low].linkid ;   
          l[high].roadnameflag =l[low].roadnameflag ;
		  l[high].brunch =l[low].brunch ;
		  l[high].dispclass =l[low].dispclass;
		  strcpy(l[high].roadname , l[low].roadname);
	 }
	 l[low].linkid =l[0].linkid ;   
     l[low].roadnameflag =l[0].roadnameflag ;
     l[low].brunch =l[0].brunch ;
	 l[low].dispclass =l[0].dispclass;
	 strcpy(l[low].roadname , l[0].roadname);
	 return low;
}
void qsort2(struct dataOut l[],int low,int high)
{
	int p;
	if(low<high)
	{     
		p=qsort1(l,low,high);    //将第一次排序的结果作为枢轴    
        qsort2(l,low,p-1); //递归调用排序 由low 到prvotloc-1    
        qsort2(l,p+1,high); //递归调用排序 由 prvotloc+1到 high
	}
}
void quicksort(struct dataOut l[],int n)
{
	qsort2(l,1,n); //第一个作为枢轴 ，从第一个排到第n个
}
void SortData(dataOut data[])
{
	using namespace std;
	int  select, i=0 , k=0 , j=0 ,  n=7;  
	char temp[50];
	double t1,t2;
	//i k 为循环控制变量  n 记录linkid的长度  m 标记成功排序的个数  
	printf("\n\n\t请输入排序方式:\n\n\t\t1:选择排序\n\n\t\t2:冒泡排序\n\n\t\t3:插入排序\n\n\t\t4:快排\n\n\t\t0:返回\n\n\t\t请选择：");
	scanf("%d" , &select);
	clockii();
	printf("\n\n\t\t\t排序进中…………请等待!…………\n\n\t\t");
    if(select == 1)
		{
		 int t;
		 char temp[50];
		 t1=clock();
		 for(i=0; i<(size-3); i++)
		 {
			k=i;
			 for(j=i+1; j<(size-2); j++)
					if(data[j].linkid<data[k].linkid )		// 判断linkid的长度是否为n
							k=j;
							t =data[k].linkid;				//交换s[i]和s[j]中linkid的信息
							data[k].linkid = data[i].linkid;		
							data[i].linkid = t;				
	
							t =data[k].roadnameflag;				//交换s[i]和s[j]中flag的信息
							data[k].roadnameflag = data[i].roadnameflag;			
							data[i].roadnameflag = t;				

							t = data[k].brunch;				//交换s[i]和s[j]中brunch的信息
							data[k].brunch =data[i].brunch;		
							data[i].brunch = t;

							t= data[k].dispclass;			//交换s[i]和s[j]中dispclass的信息
							data[k].dispclass = data[i].dispclass;
							data[i].dispclass = t;

							strcpy(temp , data[k].roadname);			//交换s[i]和s[j]中Roadname的信息
							strcpy(data[k].roadname , data[i].roadname);
							strcpy(data[i].roadname , temp);

									//记录已排序成功道路信息的个数
		 }
		 t2=clock();
		 printf("共用了%lf毫秒\n",t2-t1);
         printf("\n\n\t\t排序成功-----\n\n");
		 	printf("请等候....\n正将文件存入新的二进制文件中..\n");
	FILE *q = fopen( "e:\\排序文件GTBL.dat " ,  "wb+");
	
	int pTemp=0;
	while(pTemp<size-2)
	{
		fwrite(&data[pTemp].totalsize,sizeof(data[pTemp].totalsize),1,q);
		fwrite(&data[pTemp].linkid,sizeof(data[pTemp].linkid),1,q);
		fwrite(&data[pTemp].roadnamesize,sizeof(data[pTemp].roadnamesize),1,q);
        m[pTemp]=m[pTemp]&255;
		fwrite(&m[pTemp],sizeof(m[pTemp]),1,q);
		fwrite(data[pTemp].roadname , sizeof(char) , data[pTemp].totalsize - 12 , q ) ;   
		pTemp=pTemp++;
	}
		fclose(q);
		printf("已将排序结果存入新的二进制文件中!\n");
	
		 ma_interf();
		 clockii();
	}
	else if(select == 2)
	{
	 int t;
	 t1=clock();
	 for(i=0; i<(size-3); i++)
	 {
		   for(j=0;j<(size-3-i);j++)	 
	    	if(data[j].linkid>data[j+1].linkid)
			{
				t =data[j].linkid;				//交换s[i]和s[j]中linkid的信息
			    data[j].linkid = data[j+1].linkid;		
			    data[j+1].linkid = t;				
	
			    t =data[j].roadnameflag;				//交换s[i]和s[j]中flag的信息
			    data[j].roadnameflag = data[j+1].roadnameflag;			
			    data[j+1].roadnameflag = t;				

			    t = data[j].brunch;				//交换s[i]和s[j]中brunch的信息
			    data[j].brunch =data[j+1].brunch;		
			     data[j+1].brunch = t;

			    t= data[j].dispclass;			//交换s[i]和s[j]中dispclass的信息
			    data[j].dispclass = data[j+1].dispclass;
			    data[j+1].dispclass = t;

			    strcpy(temp , data[j].roadname);			//交换s[i]和s[j]中Roadname的信息
			    strcpy(data[j].roadname , data[j+1].roadname);
			    strcpy(data[j+1].roadname , temp);
			}
	 } 
	 t2=clock();
	 printf("共用了%lf毫秒\n",t2-t1);
	 printf("\n\n\t\t排序成功-----\n\n");
	 	printf("请等候....\n正将文件存入新的二进制文件中..\n");
	FILE *q = fopen( "e:\\排序文件GTBL.dat " ,  "wb+");
	
	int pTemp=0;
	while(pTemp<size-2)
	{
		fwrite(&data[pTemp].totalsize,sizeof(data[pTemp].totalsize),1,q);
		fwrite(&data[pTemp].linkid,sizeof(data[pTemp].linkid),1,q);
		fwrite(&data[pTemp].roadnamesize,sizeof(data[pTemp].roadnamesize),1,q);
        m[pTemp]=m[pTemp]&255;
		fwrite(&m[pTemp],sizeof(m[pTemp]),1,q);
		fwrite(data[pTemp].roadname , sizeof(char) , data[pTemp].totalsize - 12 , q ) ;   
		pTemp=pTemp++;
	}
		fclose(q);
		printf("已将排序结果存入新的二进制文件中!\n");
	
	 ma_interf();
	 clockii();
	}
	else if(select == 3)
	{
	  int n1,n2,n3,n4;
	   char temp[50];		
	   t1=clock();	
	   for(i=1; i<(size-2); i++)
		{
              n1=data[i].linkid;
			  n2=data[i].roadnameflag;				
			  n3= data[i].brunch;	
			  n4=data[i].dispclass;
			  strcpy(temp , data[i].roadname);
			  j=i-1;
			  while(t1<data[j].linkid &&j>=0)
			  {
				  data[j+1].linkid=data[j].linkid;
                  data[j+1].roadnameflag = data[j].roadnameflag;
                  data[j+1].brunch =data[j].brunch;
                  data[j+1].dispclass = data[j].dispclass;
                  strcpy(data[j+1].roadname , data[j].roadname);
				  j--;
			  }
			  data[j+1].linkid = n1;
			  data[j+1].roadnameflag = n2;
              data[j+1].brunch = n3;
                  data[j+1].dispclass = n4;
                  strcpy(data[j+1].roadname , temp);
          }
		t2=clock();
		printf("共用了%lf毫秒\n",t2-t1);
	    printf("\n\n\t\t排序成功-----\n\n");
			printf("请等候....\n正将文件存入新的二进制文件中..\n");
	FILE *q = fopen( "e:\\排序文件GTBL.dat " ,  "wb+");
	
	int pTemp=0;
	while(pTemp<size-2)
	{
		fwrite(&data[pTemp].totalsize,sizeof(data[pTemp].totalsize),1,q);
		fwrite(&data[pTemp].linkid,sizeof(data[pTemp].linkid),1,q);
		fwrite(&data[pTemp].roadnamesize,sizeof(data[pTemp].roadnamesize),1,q);
        m[pTemp]=m[pTemp]&255;
		fwrite(&m[pTemp],sizeof(m[pTemp]),1,q);
		fwrite(data[pTemp].roadname , sizeof(char) , data[pTemp].totalsize - 12 , q ) ;   
		pTemp=pTemp++;
	}
		fclose(q);
		printf("已将排序结果存入新的二进制文件中!\n");
	 
		ma_interf();
		

	}
	else if(select == 4)
	{
	 t1=clock();
	 quicksort(data,size-2);
	 t2=clock();
	 printf("共用了%lf毫秒\n",t2-t1);
	printf("\n\n\t\t排序成功-----\n\n");
	printf("请等候....\n正将文件存入新的二进制文件中..\n");
	FILE *q = fopen( "e:\\排序文件GTBL.dat " ,  "wb+");
	
	int pTemp=0;
	while(pTemp<size-2)
	{
		fwrite(&data[pTemp].totalsize,sizeof(data[pTemp].totalsize),1,q);
		fwrite(&data[pTemp].linkid,sizeof(data[pTemp].linkid),1,q);
		fwrite(&data[pTemp].roadnamesize,sizeof(data[pTemp].roadnamesize),1,q);
        m[pTemp]=m[pTemp]&255;
		fwrite(&m[pTemp],sizeof(m[pTemp]),1,q);
		fwrite(data[pTemp].roadname , sizeof(char) , data[pTemp].totalsize - 12 , q ) ;   
		pTemp=pTemp++;
	}
		fclose(q);
		printf("已将排序结果存入新的二进制文件中!\n");
	 ma_interf();
	}
	else if(select == 0)
		{
		//	system("cls");
			ma_interf();
		}	
	else							// 输入不在0到4之间给出提示信息 重新返回检索函数
		{
			//system("cls");
		    flushall();
			printf("\n\n\t\t输入信息错误，请重新选择检索方式\n\n");
			
	}
   ma_interf();			//排序完成  返回主界面
}

/**************************************************************************************
*	Functionname:Update														          *
*	Function Description:对数据进行更新，并将更新后的结果存入新的文件中				  *
*	Date:2013/7/31																      * 
**************************************************************************************/

void Update (dataOut data[]) 
{
	printf("\n\n\t\t\t\t文件更新中……\n");	
	FILE *pp;   
	if((pp=fopen("e:\\newfile.dat " , "wb+")) == NULL)		
	{		
		printf("更新文件创建失败……");
			exit(0);
		}
	
    int pTemp=0;
	while(pTemp<size-2)
	{
		fwrite(&data[pTemp].totalsize,sizeof(data[pTemp].totalsize),1,pp);
		fwrite(&data[pTemp].linkid,sizeof(data[pTemp].linkid),1,pp);
		fwrite(&data[pTemp].roadnamesize,sizeof(data[pTemp].roadnamesize),1,pp);
        m[pTemp]=m[pTemp]&255;
		fwrite(&m[pTemp],sizeof(m[pTemp]),1,pp);
		fwrite(data[pTemp].roadname , sizeof(char) , data[pTemp].totalsize - 12 , pp ) ;   
		pTemp=pTemp++;
	}
		fclose(pp);
		printf("\n\n\t\t\t\t文件更新成功\n\n\n\t\t\t更新文件存放在newfile.dat文件中\n\n\n");
	ma_interf();					//返回主界面
}

void clockii()
{
	char *wday[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
	time_t timep;
	struct tm *p;
	time(&timep);
	p=gmtime(&timep);
	printf("%d年%d月%d日\t",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
	printf("%s %d:%d\n",wday[p->tm_wday],p->tm_hour+8,p->tm_min);
}

void main()
{

printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c w e l c o m e !  !  ! !!%c %c %c %c %c %c %c %c %c %c %c %c %c\n",1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
printf("    组长：王钊        * * *       * * * * *         * * * *\n");
printf("    组员：赵一豪    *       *     *         *     *\n");
printf("          付越     *         *    *          *   *\n");
printf("          由楚天  *               *         *     *\n");
printf("          张宇    *               * * * * *         * * * *\n");
printf("          吴金程  *       * * *   *                         *\n");
printf(" 组名：精英设计室  *         *    *       2013年7月31号     *\n");
printf("                    *       *     *                         *\n");
printf("                      * * *       *                * * * * *\n");
system("color 8F"); 
                                                             

	clockii();	
	ma_interf();				//进入主界面
}


