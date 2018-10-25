
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<time.h>//时间显示
#include<conio.h>
#include <windows.h>
#pragma comment(lib, "WINMM.LIB")//加载播放wav


/*函数声明部分*/
void ma_interf();
int ReadFile();
void ReadData(FILE *p);
void WriteResult (int b[] , int j);
void Search();
void quickSort();
void QuickSort(struct dataOut l[],int n);

/*宏定义*/
#define MCGETCHAR(data)  (*((char *)(data)))
#define MCGETSHORT(data)  ((unsigned short)(( ((unsigned short)(*((char *)(data))))<<8 )|( ((unsigned short)(*((char *)(data)+1)))&0x00ff )))
#define MCGETLONG(data)  ( ( ((unsigned long)MCGETSHORT((data)))<<16 )|( ((unsigned long)MCGETSHORT((char *)(data)+2))&0x0000ffff ) )
#define MCGET3BN(data)  ( ( ((unsigned long)MCGETCHAR((data)))<<16 )|( ((unsigned long)MCGETSHORT((char *)(data)+1))&0x0000ffff ) )
#define Length 655350 
#define TIME_INTERVAL 2

int nsizecount = 2 ;
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
double start,end;//时间

struct dataOut
{   long linkid;
	int  dispclass;
	int  brunch;
	int  roadnameflag;
	char roadname[50];
	short totalsize;
	short roadnamesize;
}data[Length];
void SortData(dataOut data[]);
void Update (dataOut data[]); 		 /*存储道路信息的数组*/ 


void Sort(dataOut data[]);   
/*************************************************************************************************/
/*********************************退出界面********************************************************/
/*************************************************************************************************/

void exit()
{
	system("cls");
	printf("------------------------------------------------------------------------------\n");
	printf("¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤\n");
	printf("☆☆☆☆☆☆☆☆☆☆☆ 感谢使用DreamerGroup电子地图! ☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
	printf("¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤\n\n");
	system("pause");
	exit(0);

	return;
}


/*************************************************************************************************/
/*********************************颜色设置********************************************************/
/*************************************************************************************************/

void set_color1()	//设置文字及背景颜色函数
{	char ch1='3';
	//getchar(); //因在主选单按'C'键，再按'回车'键，系统会依次将其处理为两个字符，所以在此处将其'回车'吸收处理。以致不会影响到后面的字符输入。
	while(1)		
	{	system("cls");
		printf("\n\n\t\t\t      设置文字及背景颜色  \n");
		printf("_______________________________________________________________________________\n\n");
		printf("\n\t\t\t        文字颜色   背景颜色\n");
		printf("\n\t\t\t  1 ─    白色       绿色");
		printf("\n\t\t\t  2 ─    白色      湖蓝色");
		printf("\n\t\t\t  3 ─    白色       蓝色");
		printf("\n\t\t\t  4 —    白色       紫色");
		printf("\n\t\t\t  5 —    黄色      湖蓝色（默认颜色）");
		printf("\n\t\t\t  6 ─    黄色       蓝色");
		printf("\n\t\t\t  7 —    白色       红色");
		printf("\n\t\t\t  8 ─    白色       黑色");
		printf("\n\t\t\t  9 —    黑色      湖蓝色");
		printf("\n\n\t\t\t  0 —  返回主菜单\n\n");
		printf("\n\t\t\t（请按菜单前面的数字或字符键进行选择）\n");
		printf("\n\t\t\t==〉");
		ch1=getchar();
		switch(ch1)
		{	case '1':	system("color 2f");	break;	
			case '2':	system("color 3f");	break;
			case '3':	system("color 1f");	break;
			case '4':	system("color 5f");	break;
			case '5':	system("color 3e");	break;
			case '6':	system("color 1e");	break;
			case '7':	system("color 4f");	break;
			case '8':	system("color 07");	break;
			case '9':	system("color 30");	break;
			case '0':	goto loop_set_color1;	//break;
		}
	}
loop_set_color1:	;
}

/*************************************************************************************************/
/*********************************主界面**********************************************************/
/*************************************************************************************************/


void Start(){

	time_t rawtime;
	struct tm * timeinfo;

	sndPlaySound("media\\summer.wav",SND_LOOP|SND_ASYNC);


	system("color 3E");//系统颜色更改：背景（湖蓝色 3） 字体颜色（淡黄色 E）

	int i=2;
	int k=0;
	int j=3;

	while(1)//闪烁

	{
		char * star[10]={"☆★★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★★☆\n",
						 "☆☆☆★★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★★☆☆☆\n",
						 "☆☆☆☆☆★★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★★☆☆☆☆☆\n",
						 "☆☆☆☆☆☆☆★★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★★☆☆☆☆☆☆☆\n",
						 "☆☆☆☆☆☆☆☆☆★★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★★☆☆☆☆☆☆☆☆☆\n",
						 "☆☆☆☆☆☆☆☆☆☆☆★★☆☆☆☆☆☆☆☆☆☆☆☆☆☆★★☆☆☆☆☆☆☆☆☆☆☆\n",
						 "☆☆☆☆☆☆☆☆☆☆☆☆☆★★☆☆☆☆☆☆☆☆☆☆★★☆☆☆☆☆☆☆☆☆☆☆☆☆\n",
						 "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★★☆☆☆☆☆☆★★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n",
						 "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★★☆☆★★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n",
                         "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n",
											};
		k++;
		k=k%10;
		i++;
		i=i%10;
		j++;
		j=j%10;

		time ( &rawtime );
		timeinfo = localtime ( &rawtime );
		if(GetAsyncKeyState(' ')){		
			break;
		}
	
	
		printf("%s",star[k]);
		printf("%s",star[j]);
		printf("%s",star[i]);
		printf("**************************-----电子地图管理系统-----****************************\n");
		printf("       DDD     RRRR      EEEEEE      A          M     M     EEEEEE  RRRR\n");
		printf("       D  D    R   R     E          A  A       M M   M M    E       R   R\n");
		printf("       D   D   RRRR      EEEEE     AAAAAA     M   M M   M   EEEEE   RRRR\n");
		printf("       D  D    R   R     E        A      A   M     M     M  E       R   R\n");
		printf("       DDD     R    R    EEEEEE   A      A   M           M  EEEEEE  R    R\n");
		printf("                                                        Dreamer-Group 倾力制作\n");
		printf("******************************-----Just Do IT!-----*****************************\n");
		printf("%s",star[i]);
		printf("%s",star[k]);
		printf("%s",star[j]);
		printf("               Dreamer 为您报时 现在时刻 东软时间：%4d-%02d-%02d %02d:%02d:%02d\n",1900+timeinfo->tm_year, 1+timeinfo->tm_mon,
																		timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
		printf("                            请按空格，进入选择界面\n");
	

		int i,j;
		for(i=0;i<3000;i++)
			for(j=0;j<20000;j++){;}//延时
		system("cls");//清屏，实现闪烁
	
	
	}
	
}  

/*************************************************************************************************/
/*********************************读取文件********************************************************/
/*************************************************************************************************/


int   ReadFile() 
{ 
	char aclinkId[4] ;							/*从二进制文件中读取道路编号*/
    char acroadnamesize[2] ;			    	/*从二进制文件中读取道路名称数据长度*/
    char acNodeInfo[4];
	unsigned short ustotalsize;
    unsigned long  ullinkId;
    unsigned short usroadnamesize;
	
	char actotalsize[2] ;					   /*从二进制文件中读取道路信息的总体数据长度 */
	
	FILE *pfp = fopen( "D:\\GTBL.dat " ,  "rb+"); 
	FILE *pf2 = fopen( "D:\\解析文件.txt " ,  "w+"); 

	if(pfp == NULL)
	{
		printf("can not open the GTBL.dat file or there is no the file!\n");
		return 0;
	}
	system("cls");

	printf("\n\n\t\t\t\t文件读取中.....\n");

    printf("                               ,,,,,,,\n");
	printf("                           ,NEUSOFT:'-,o,\n");
	printf("                         .NEUSOFT' '' ' -*R&b,\n");
	printf("                        'NEUSOFT`'      .oM'HM?.\n");
	printf("                      ,NEUSOFT       'NEUSOFT$$|\n");
	printf("                     .:NEUSOFT         `NEUSOFT#|\n");
	printf("                    . NEU@#SOFT       &*⊙NEUSOFT:\n");
	printf("                    .    SOFT       ╳NEUSOFT%MMM.\n");
	printf("                    .   NEU$$SOFT     *^&NEUSOFT*.\n");
	printf("                    .    NEUSOFT         *SOFT** .\n");
	printf("                         `NEUSOFT           SOFT,\n");
	printf("                     '    `SOFT            NUE`,\n");
	printf("                      '    :NEU            .- ,\n");
	printf("                       '.   `#?..  .       ..'\n");
	printf("                          -.   .         .-\n");
	printf("                            ''-.oo,oo.-''");



	while(fread(actotalsize , sizeof(actotalsize) , 1 , pfp) == 1)    
	{
        fread( aclinkId , sizeof(aclinkId) , 1 , pfp ) ;				/*读取占用4字节的linkId字符*/      
		fread( acroadnamesize , sizeof(acroadnamesize) , 1 , pfp ) ;	/*读取占用2字节的roadnamesize字符串*/	 
		fread( acNodeInfo , sizeof(acNodeInfo) , 1 , pfp ) ;   
		
		ustotalsize = MCGETSHORT(actotalsize) ;							/*调用宏函数 ， 将字符串信息转化为数值类型*/
		ullinkId = MCGETLONG(aclinkId) ;
		usroadnamesize = MCGETSHORT(acroadnamesize) ;
		
		/*赋值 ：将数值信息传到结构体中*/ 
		road[nsizecount].ussize = ustotalsize ;
		road[nsizecount].ullinkId = ullinkId ;
		road[nsizecount].usroadnamesize= usroadnamesize ;
		
		m[nsizecount]=(int)acNodeInfo[3]&255;
		road[nsizecount].usdispclass=m[nsizecount]&15;
		road[nsizecount].usbrunch=(m[nsizecount]&112)/16;
		road[nsizecount].usroadnameflag=(m[nsizecount]&128)/128;
		
		data[nsizecount].dispclass= road[nsizecount].usdispclass;
		data[nsizecount].brunch=road[nsizecount].usbrunch;
		data[nsizecount].roadnameflag=road[nsizecount].usroadnameflag;
		data[nsizecount].linkid= ullinkId;
		
		fread(road[nsizecount].roadname , sizeof(char) , ustotalsize - 12 , pfp ) ;	/*从文件中读取道路名称*/	
		strcpy(data[nsizecount].roadname,road[nsizecount].roadname+4);

		fprintf(pf2 , "#\t");
		fprintf(pf2 , "LinkID=");
		fprintf(pf2 , "%d\t" , data[nsizecount].linkid);
		fprintf(pf2 , "flag=");
		fprintf(pf2 , "%d\t" , data[nsizecount].roadnameflag);
		fprintf(pf2 , "brunch=");
		fprintf(pf2 , "%d\t" , data[nsizecount].brunch);
		fprintf(pf2 , "dispclass=");
		fprintf(pf2 , "%d\t" , data[nsizecount].dispclass);
		fprintf(pf2 , "Roadname=１＝");
		fprintf(pf2 , "%s\t" , data[nsizecount].roadname+4);
		fprintf(pf2 , "#");
		fprintf(pf2 , " \n");

		nsizecount++;//数据个数
		
		
	}
	fclose(pfp); 
	fclose(pf2); 
	system("cls"); 
	printf("\n\t\t\t\t 文件读取成功\n");
	return  0; 
}
/*************************************************************************************************/
/*********************************写入文件********************************************************/
/*************************************************************************************************/
void WriteResult (int b[] , int j)
{
	FILE *qq;
	if((qq=fopen("D:\\searchresult.txt" , "w")) == NULL)  //判断文件是否创建成功
		{
			printf("创建文件失败\n");
			exit();
		}
	int i=0 , f;		//  i 为循环控制变量  f 记录传入数组在不同的i下 b[i]  的值
	printf("\n\n\t\t\t检索到的信息超过--5--条\n\n\n\t\t检索到的信息写入searchresult文件中……\n");
	for(i=0; i<j; i++)
		{
			f=b[i];
			fprintf(qq , "#\t");				
			fprintf(qq , "%d\t" , data[f].linkid);		// 检索到的道路信息写入文件中
			fprintf(qq , "%d\t" , data[f].roadnameflag);			// 检索到的道路信息写入文件中
			fprintf(qq , "%d\t" , data[f].brunch);		// 检索到的道路信息写入文件中
			fprintf(qq , "%d\t" , data[f].dispclass);		// 检索到的道路信息写入文件中
			fprintf(qq , "%s\t" , data[f].roadname);		// 检索到的道路信息写入文件中
			fprintf(qq , "#");
			fprintf(qq , "\n");
		}
	fclose(qq);						//关闭指针qq
	printf("\n\n\t\t检索到的信息写入searchresult文件中成功\n\n\n");	
}
/*************************************************************************************************/
/*********************************检查判断********************************************************/
/*************************************************************************************************/
void Judge()
{
	FILE *pp;

	if((pp=fopen("D:\\GTBL.dat" , "rb")) == NULL)    //打开文件 并返回pp文件指针 判断文件是否存在
		{	system("cls");
			printf("\n\n\t\t\t\tthe file not exist!\n\n\t\t\t\t  请重新选择服务：\n\n");
			printf("\n\t请把需要解析的--电子地图管理系统.dat--放入--D:\\根目录下\n\n");

		}

}

/*************************************************************************************************/
/*********************************功能选择********************************************************/
/*************************************************************************************************/

void Choose()
{

	char* Choose1[13] = {"  欢 迎 进 入 功 能 选 择 界 面  ",//0
						"请您选择所需要的功能",//1
						"读取文件",//2
						"排序",//3
						"检索",//4
						"退出",//5
						"请输入所选择的功能前的数字标号",//6
						"请您在所提供的选项中选择",//7
						"请重新输入您选择的操作前的数字代号",//8
						"更新",//9
						"设置文字及背景颜色"//10
				};	

	int k;



	printf("------------------------------------------------------------------------------\n");
	printf("¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤\n");
	printf("☆☆☆☆☆☆☆☆☆☆☆  %s  ☆☆☆☆☆☆☆☆☆☆\n",Choose1[0]);
	printf("¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤\n\n");
		
	printf("       %s：\n\n",Choose1[1]);
	printf("               [1]%s；\n",Choose1[2]);
	printf("               [2]%s；\n",Choose1[3]);
	printf("               [3]%s；\n",Choose1[4]);

	printf("               [4]%s；\n",Choose1[9]);
	printf("               [5]%s；\n",Choose1[10]);
	printf("               [0]%s；\n",Choose1[5]);
	printf("       %s；\n\n",Choose1[6]);
	printf("       %s：",Choose1[7]);

	scanf("%d" , &k);
	fflush(stdin);

	while(1 != k && 2 != k && 3 != k && 4 != k &&  0 != k && 5 != k)
	{
		printf("\n");
		printf("       %s!\n\n",Choose1[7]);
		printf("       %s:",Choose1[8]);
		scanf("%d",&k);
		fflush(stdin);
	}

	if(1 == k)//读取新文件
	{	
		if(mark_1!=0)
		{
			system("cls");
			printf("                                 文件已打开!\n");
			Choose();
			
		}


		ReadFile();
		mark_1++;			//标记是否执行读取文件
	
		Judge();
		
	

		Choose();
	
	

		
	

	}
	else if(2 == k){//进入排序功能界面
	
		system("cls"); 
		if(mark_1==0){
			printf("\n\n\t请在进行排序前先选择-1-进行读取文件，否则无数据进行排序\n\n");
			Choose();
		}
		else
		{
			mark_2++;		//标记是否执行排序操作
			Sort(data);
		}
	}
	else if(3 == k)//进入检索功能界面
	{
		system("cls"); 

		if(mark_1==0||mark_2==0){		//同上
			printf("\n\n\t\t请在进行-检索-前先选择-1--2-进行读取文件和排序操作\n\n");
			printf("\t\t     否则无数据进行检索或检索到的数据未排序\n\n");
			Choose();
	}
	else{
		Search();
		}

	}

	
	else if(4 == k)
	{
		system("cls"); 
		if(mark_1==0||mark_2==0){		//同上
			printf("\n\n\t\t请在进行-更新-前先选择-1--2-进行读取文件和排序操作\n\n");
			printf("\t\t            否则无数据进行更新\n\n");
			Choose();
		}
		Update (data);//进入更新界面
	}	
	else if(0 == k)
	{
		//if(mark_1!=0)		//判断是否打开申请s 和ss 的空间
				//	{
					//	free(s);		//释放s内存
					//	free(ss);		//释放ss内存
					//}
		exit();
		
	}
	else if(5 == k)
	{
		set_color1();
		system("cls"); 
		Choose();
	}
	else
	{
		exit();
	}
	return;
}


/*************************************************************************************************/
/*************************************折半查找****************************************************/
/*************************************************************************************************/
void BinarySearch()
{
		int sss,low,high,mid;
		printf("       请输入link的ID:");
	    scanf("%d",&sss);
			low=0;
    		high=nsizecount-3;
	    	mid=(low+high)/2;
		    while(sss!=data[mid].linkid&&low<=high){
		    if(sss<data[mid].linkid) high=mid-1;
		    if(sss>data[mid].linkid) low=mid+1;
		    mid=(low+high)/2;
			}
	    	if(low<=high)
	    	printf("\n\n  Linkid=%d flag=%d brunch=%d dispclass=%d roadname=%s\n\n\n" , data[mid].linkid , data[mid].roadnameflag , data[mid].brunch , data[mid].dispclass , 
								data[mid].roadname);
		    else{
		     	printf("\n\n\t\t\t\t没有匹配结果\n\n\t\t\t    请重新选择检索方式\n");
					flushall();
					Search();
			}
        

	}

/*************************************************************************************************/
/*************************************顺序查找****************************************************/
/*************************************************************************************************/

void sequentialSearch()

{
		    int sss,i,j;
			printf("       请输入link的ID:");
			scanf("%d" , &sss);
			
 			    for(i=0; i<(nsizecount-2); i++)
				{
					if(sss==data[i].linkid)    //比较字符串是否一致
						{
							printf("\n\n  Linkid=%d flag=%d brunch=%d dispclass=%d roadname=%s\n\n\n" , data[i].linkid , data[i].roadnameflag , data[i].brunch , data[i].dispclass , 
								data[i].roadname);
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


/*************************************************************************************************/
/*********************************检索功能选择****************************************************/
/*************************************************************************************************/


void Search(){
	char* Search1[8] = {"   检索功能界面   ",//0
						"请选择检索方式",//1
						"按顺序查找方式检索",//2
						"按折半查找方式检索",//3
					
						"返回上一级菜单",//4
					
	
						"请输入您选择的功能前的数字代号",//5
						"请您在所提供的选项中选择",//6
						"请重新输入您选择的功能前的数字代号",//7
					
	
								};

	int Method;//方法

	printf("------------------------------------------------------------------------------\n");
	printf("¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤\n");
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆ %s ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n",Search1[0]);
	printf("¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤\n\n");

	printf("       %s：\n\n",Search1[1]);
	printf("               [1]%s；\n",Search1[2]);//顺序
	printf("               [2]%s；\n",Search1[3]);//折半

	printf("               [3]%s；\n",Search1[4]);
	printf("       %s：",Search1[5]);
 






		scanf("%d" , &Method);
		fflush(stdin);

		while(1 != Method && 2 != Method && 3 != Method  )
		{
			printf("\n");
			printf("       %s!\n\n",Search1[6]);
			printf("       %s:",Search1[7]);
			scanf("%d" , &Method);
			fflush(stdin);
		}

		
		switch(Method)
		{

			case 1:
				{
						sequentialSearch();//顺序查找
						printf("--------------------------------------------------------------------------\n\n");
						system("pause");
						system("cls"); 
						

				}
				Choose();
				break;
			case 2:
				{
						BinarySearch();//折半查找
						printf("--------------------------------------------------------------------------\n\n");
						system("pause");
						system("cls"); 
				}
				Choose();
				break;
		

			case 3:
				printf("--------------------------------------------------------------------------\n\n");
				system("pause");
				system("cls"); 
				Choose();
				break;
			default:
				break;
		}

}



/*************************************************************************************************/
/*****************************************冒泡排序************************************************/
/*************************************************************************************************/
void BubbleSort()
	{
	 int t,i,j;
	 char temp[50];
	 start=clock();
	 for(i=0; i<(nsizecount-3); i++)
	 {
		   for(j=0;j<(nsizecount-3-i);j++)	 
	    	if(data[j].linkid>data[j+1].linkid)
			{
				t =data[j].linkid;				        //交换s[i]和s[j]中linkid的信息
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
	 end=clock();
	 printf("\t\t恭喜成功排序!用时%lf秒\n",double(end-start)/CLOCKS_PER_SEC);
	 printf("\n\n\t\t排序成功-----按LinkID编号由小到大排列完成\n\n");
	 printf(">>>>>> >>>>>> >>>>>> >>>>>> >>>>>> 请稍等 <<<<<< <<<<<< <<<<<< <<<<<< <<<<<<");
	 FILE *pp=fopen("d:\\newfile.dat " , "wb+");
	  int pTemp=0;
 	 while(pTemp<nsizecount-2)
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
		system("cls");
		
	 Choose();
	}
/*************************************************************************************************/
/*****************************************选择排序************************************************/
/*************************************************************************************************/
void SelectionSort()
	{
		 int t,i,k,j;
		 char temp[50];
		 start=clock();
		 for(i=0; i<(nsizecount-3); i++)
		 {
			k=i;
			 for(j=i+1; j<(nsizecount-2); j++)
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

				
						}

				
		

	system("cls");
	end=clock();
	printf("\t\t恭喜成功排序!用时%f秒\n",(double)(end-start)/CLOCKS_PER_SEC);
	printf("\n\n\t\t排序成功-----按LinkID编号由小到大排列完成\n\n");
	printf(">>>>>> >>>>>> >>>>>> >>>>>> >>>>>> 请稍等 <<<<<< <<<<<< <<<<<< <<<<<< <<<<<<");
	 FILE *pp=fopen("d:\\newfile.dat " , "wb+");
	  int pTemp=0;
 	 while(pTemp<nsizecount-2)
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
		system("cls");
		Choose();
	
			//排序完成  返回主界面
}
/*************************************************************************************************/
/*****************************************插入排序************************************************/
/*************************************************************************************************/
void insertSort()
{
	  int n1,n2,n3,n4,i,j;
	   char temp[50];		
	   start=clock();	
	   for(i=0; i<(nsizecount-2); i++)
			{
              n1=data[i].linkid;
			  n2=data[i].roadnameflag;				
			  n3= data[i].brunch;	
			  n4=data[i].dispclass;
			  strcpy(temp , data[i].roadname);
			  j=i-1;
			  while(n1<data[j].linkid &&j>=0)
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
		end=clock();
		printf("\t\t恭喜成功排序!用时%f秒\n",(double)(end-start)/CLOCKS_PER_SEC);
		printf("\n\n\t\t排序成功-----按LinkID编号由小到大排列完成\n\n");
		printf(">>>>>> >>>>>> >>>>>> >>>>>> >>>>>> 请稍等 <<<<<< <<<<<< <<<<<< <<<<<< <<<<<<");
	    FILE *pp=fopen("d:\\newfile.dat " , "wb+");
	  int pTemp=0;
 	 while(pTemp<nsizecount-2)
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
		system("cls");
		Choose();
	}

/*************************************************************************************************/
/*****************************************快速排序************************************************/
/*************************************************************************************************/
void quickSort()
	{
	 start=clock();
     QuickSort(data,nsizecount-2);
	 end=clock();

		printf("\t\t恭喜成功排序!用时%f秒\n",(double)(end-start)/CLOCKS_PER_SEC);
		printf("\n\n\t\t排序成功-----按LinkID编号由小到大排列完成\n\n");
		printf(">>>>>> >>>>>> >>>>>> >>>>>> >>>>>> 请稍等 <<<<<< <<<<<< <<<<<< <<<<<< <<<<<<");
	

	 FILE *pp=fopen("d:\\newfile.dat " , "wb+");
	  int pTemp=0;
 	 while(pTemp<nsizecount-2)
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
		
		system("cls");
		Choose();
	

	}
int Q1(struct dataOut l[],int low,int high)
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
void Q2(struct dataOut l[],int low,int high)
{
	int p;
	if(low<high)
	{     
		p=Q1(l,low,high);    //将第一次排序的结果作为枢轴    
        Q2(l,low,p-1); //递归调用排序 由low 到prvotloc-1    
        Q2(l,p+1,high); //递归调用排序 由 prvotloc+1到 high
	}
}

void QuickSort(struct dataOut l[],int n)
{
	Q2(l,0,nsizecount-2); //第一个作为枢轴 ，从第一个排到第n个
}




/*************************************************************************************************/
/*********************************排序功能选择****************************************************/
/*************************************************************************************************/
void Sort(dataOut data[])
{
	char* SortChoose[20] = {"  排序功能界面  ",//0
							"请选择排序方式",//1
							"冒泡排序",//2
							"插入排序",//3
					
							"快速排序",//4
							"返回上一级菜单",//5

							"请输入您选择的功能前的数字代号",//6
							"请您在所提供的选项中选择",//7
							"请重新输入您选择的排序方式前的数字代号",//8

							"       正在进行排序，请稍候  ...... ...... ...... ...... ...... ...... ......",//9
							"请您选择对排序结果的操作",//10
							"覆盖原文件",//11
							"另存为新文件",//12
							"不进行操作",//13
							"请输入所选择的操作前的数字标号",//14
							"比较结束!",//15
							"空格键退出比较!",//16
						    "选择排序"};//17
	

	int Type;



	printf("------------------------------------------------------------------------------\n");
	printf("¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤\n");
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆  %s  ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n",SortChoose[0]);
	printf("¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤☆¤\n\n");

    printf("       %s：\n\n",SortChoose[1]);
	printf("               [1]%s；\n",SortChoose[2]);
	printf("               [2]%s；\n",SortChoose[3]);
	printf("               [3]%s；\n",SortChoose[4]);
	printf("               [4]%s；\n",SortChoose[17]);

	printf("               [0]%s；\n",SortChoose[5]);

	printf("       %s：",SortChoose[6]);
	


	scanf("%d" , &Type);//选择排序关键字
	fflush(stdin);
	while(1 != Type && 2 != Type && 3 != Type && 4 != Type )//判断是否输入正确
	{
		printf("\n");
		printf("       %s!\n\n",SortChoose[7]);
		printf("       %s:",SortChoose[8]);
		scanf("%d",&Type);
		fflush(stdin);
	}



	switch(Type)
		{
			case 1:
				printf("%s\n\n",SortChoose[9]);
		
				BubbleSort();//冒泡
				break;
			case 2:
				printf("%s\n\n",SortChoose[9]);
			
				insertSort();//插入
				break;
			case 3:
				printf("%s\n\n",SortChoose[9]);
			
				quickSort();//快速排序
				break;
			case 4:
				printf("%s\n\n",SortChoose[9]);
			
				SelectionSort();//选择
				break;
			case 0:
				printf("--------------------------------------------------------------------------\n\n");
				system("pause");
				system("cls"); 
				Choose();
			default:
				break;
		}
	
	


		system("pause");
	
		Choose();


}

/*************************************************************************************************/
/*****************************************更新****************************************************/
/*************************************************************************************************/
void Update (dataOut data[]) 
{
	printf("\n\n\t\t\t\t文件更新中……\n");	
	FILE *q=fopen("d:\\newfile.dat " , "wb+");   
	if((q=fopen("d:\\newfile.dat " , "wb+")) == NULL)		
	{		
		printf("更新文件创建失败……");
			exit();
		}
	
    int pTemp=0;
	while(pTemp<nsizecount-2)
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
		printf("\n\n\t\t\t\t文件更新成功\n\n\n\t\t\t更新文件存放在update.dat文件中\n\n\n");
	Choose();					//返回主界面
}





	
/*************************************************************************************************/
/*******************************************主函数************************************************/
/*************************************************************************************************/

int main(){

	Start();
	Choose();

	return 0;
}
