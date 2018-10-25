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
/*������������*/
void ma_interf();
int ReadFile();
void WriteResult (int b[] , int j);
void Search();

/*�궨��*/
#define MCGETCHAR(data)  (*((char *)(data)))
#define MCGETSHORT(data)  ((unsigned short)(( ((unsigned short)(*((char *)(data))))<<8 )|( ((unsigned short)(*((char *)(data)+1)))&0x00ff )))
#define MCGETLONG(data)  ( ( ((unsigned long)MCGETSHORT((data)))<<16 )|( ((unsigned long)MCGETSHORT((char *)(data)+2))&0x0000ffff ) )
#define MCGET3BN(data)  ( ( ((unsigned long)MCGETCHAR((data)))<<16 )|( ((unsigned long)MCGETSHORT((char *)(data)+1))&0x0000ffff ) )
#define Length 655350 

int size = 2 ;
int m[Length];
/*����ṹ�����ͼ�����*/
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
int mark_1=0,mark_2=0;    //��ǳ����Ƿ����ж�ȡ�ļ����������

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

					 /*�洢��·��Ϣ������*/      

/**************************************************************************************
*	Functionname:ReadFile															  *
*	Function Description:��ȡ�������ļ���������������ı��ĵ���						  *
*	Date:2013/7/31																      * 
**************************************************************************************/

int   ReadFile() 
{ 
	
	char aclinkId[4] ;							/*�Ӷ������ļ��ж�ȡ��·���*/
    char acroadnamesize[2] ;			    	/*�Ӷ������ļ��ж�ȡ��·�������ݳ���*/
    char acNodeInfo[4];
	
	unsigned short ustotalsize;
    unsigned long  ullinkId;
    unsigned short usroadnamesize;
	
	char actotalsize[2] ;					   /*�Ӷ������ļ��ж�ȡ��·��Ϣ���������ݳ��� */
	
	FILE *pfp = fopen( "e:\\���ӵ�ͼ�ṩ��\\GTBL.dat " ,  "rb+");  
    printf("�����ļ�...\n��ȡ��...\n");
	if(pfp == NULL)
	{
		printf("can not open the GTBL.dat file or there is no the file!\n");
		return 0;
	}
	while(fread(actotalsize , sizeof(actotalsize) , 1 , pfp) == 1)    
	{
        fread( aclinkId , sizeof(aclinkId) , 1 , pfp ) ;				/*��ȡռ��4�ֽڵ�linkId�ַ�*/      
		fread( acroadnamesize , sizeof(acroadnamesize) , 1 , pfp ) ;	/*��ȡռ��2�ֽڵ�roadnamesize�ַ���*/	 
		fread( acNodeInfo , sizeof(acNodeInfo) , 1 , pfp ) ;   
		
		ustotalsize = MCGETSHORT(actotalsize) ;							/*���ú꺯�� �� ���ַ�����Ϣת��Ϊ��ֵ����*/
		ullinkId = MCGETLONG(aclinkId) ;
		usroadnamesize = MCGETSHORT(acroadnamesize) ;
		
		/*��ֵ ������ֵ��Ϣ�����ṹ����*/ 
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
		fread(road[size].roadname , sizeof(char) , ustotalsize - 12 , pfp ) ;	/*���ļ��ж�ȡ��·����*/	
		strcpy(data[size].roadname,road[size].roadname+4);
		
		size++;
		
		
	}
	fclose(pfp);  

	return  0; 
}

/**************************************************************************************
*	Functionname:Search																  *
*	Function Description:������Ϣ���֣��ɰ���ͬ�����ͽ��м���				     	  *
*	Date:2013/7/31																      * 
**************************************************************************************/
void Search()
{
	int  select , i=0 , j=0 , *b , c=0 , f,p;  //select ���ѡ����Ҫ���еķ�֧  i ѭ������  j��Ǽ�������Ϣ������  
	//b ����ָ�� ������ż���������Ϣ���±� c �����������b���±�  f �������b��ֵ
	printf("\n\n\t�����������ʽ:\n\n\t\t1:˳�����\n\n\t\t2:�۰����\n\n\t\t0:����\n\n\t\t��ѡ��");
	scanf("%d" , &select);
	//system("cls");
	printf("\n\n>>>>>>>>--����������Ϣ��������5��ʱ , ��Ѽ���������Ϣ�����searchresult�ļ���--<<<<<<<<<<<<<\n\n");
	printf("\n><><><><><>--����������Ϣ����δ����5��ʱ , ��Ѽ���������Ϣֱ����ʾ����Ļ��--<><><><><><><>\n\n\n");
	if(select==1)
	{
	   printf("\n\n\t�����������ʽ:\n\n\t\t1:ָ��linkID ����\n\n\t\t2:ָ������link�б�ʾclass���� ����\n\n\t\t3:ָ�����Ҳ�·�� ����\n\n\t\t0:����\n\n\t\t��ѡ��");	
		scanf("%d",&p);
		if(p == 1)
		{
		  int sss;
			printf("\t������link��ID:");
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
					printf("\n\n\t\t\t\tû��ƥ����\n\n\t\t\t    ������ѡ�������ʽ\n");
					flushall();
					Search();
				}
		}
	   else if(p == 2)
			{
				int sss;
				printf("\t�����뽻��link�б�ʾclass����:");
				scanf("%d" , &sss);
				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].dispclass)				
							{
								j++;
							}
					}
				b=(int *)malloc(sizeof(int)*j);				//��̬��������b�Ĵ洢�ռ�

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
							printf("\n\n\t\t\t\tû��ƥ����\n\n\t\t\t    ������ѡ�������ʽ\n");
							flushall();
							Search();
						}
						else if(j>5)
							{
								WriteResult(b  ,  j);	
							}
						else if (j<=5)								//�жϼ������������Ƿ񳬹�5��
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
				printf("\t�������·��:");
				scanf("%d" ,&sss);
				//system("cls");				//�����ַ���
				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].brunch)			//�Ƚ��ַ����Ƿ�һ��
							{
								j++;
							}
					}
				b=(int *)malloc(sizeof(int)*j);							//��̬��������b�Ĵ洢�ռ�

				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].brunch)			//�Ƚ��ַ����Ƿ�һ��
							{
								b[c]=i;
								c++;
							}
					}
						if(j == 0)
							{
								printf("\n\n\t\t\t\tû��ƥ����\n\n\t\t\t    ������ѡ�������ʽ\n");
								flushall();
								Search();
							}
						else if(j>5)
							{
								WriteResult(b  ,  j);	
							}
						else if (j<=5)							//�жϼ������������Ƿ񳬹�5��
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
	  else							// ���벻��0��4֮�������ʾ��Ϣ ���·��ؼ�������
		{
			//system("cls");
			printf("\n\n\t\t������Ϣ����������ѡ�������ʽ\n\n");
			flushall();
			Search();
		}
   }
   else if(select==2)
  {
    printf("\n\n\t�����������ʽ:\n\n\t\t1:ָ��linkID ����\n\n\t\t2:ָ������link�б�ʾclass���� ����\n\n\t\t3:ָ�����Ҳ�·�� ����\n\n\t\t0:����\n\n\t\t��ѡ��");	
	   scanf("%d",&p);
		if(p == 1)
		{
		  int sss,m;
			printf("\t������link��ID:");
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
				printf("\n\n\t\t\t\tû��ƥ����\n\n\t\t\t    ������ѡ�������ʽ\n");
				flushall();	
				Search();
			}
		}
	   else if(p == 2)
			{
				int sss;
				printf("\t�����뽻��link�б�ʾclass����:");
				scanf("%d" , &sss);
				//system("cls");				//�����ַ���
				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].dispclass)			//�Ƚ��ַ����Ƿ�һ��	
							{
								j++;
							}
					}
				b=(int *)malloc(sizeof(int)*j);				//��̬��������b�Ĵ洢�ռ�

				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].dispclass)			//�Ƚ��ַ����Ƿ�һ��
							{
								b[c]=i;
								c++;
							}
					}
					if(j == 0)
						{
							printf("\n\n\t\t\t\tû��ƥ����\n\n\t\t\t    ������ѡ�������ʽ\n");
							flushall();
							Search();
						}
						else if(j>5)
							{
								WriteResult(b  ,  j);	
							}
						else if (j<=5)								//�жϼ������������Ƿ񳬹�5��
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
				printf("\t�������·��:");
				scanf("%d" ,&sss);
				//system("cls");				//�����ַ���
				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].brunch)			//�Ƚ��ַ����Ƿ�һ��
							{
								j++;
							}
					}
				b=(int *)malloc(sizeof(int)*j);							//��̬��������b�Ĵ洢�ռ�

				for(i=0; i<(size-2); i++)
					{
						if(sss == data[i].brunch)			//�Ƚ��ַ����Ƿ�һ��
							{
								b[c]=i;
								c++;
							}
					}
						if(j == 0)
							{
								printf("\n\n\t\t\t\tû��ƥ����\n\n\t\t\t    ������ѡ�������ʽ\n");
								flushall();
								Search();
							}
						else if(j>5)
							{
								WriteResult(b  ,  j);	
							}
						else if (j<=5)							//�жϼ������������Ƿ񳬹�5��
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
	  else							// ���벻��0��4֮�������ʾ��Ϣ ���·��ؼ�������
		{
			//system("cls");
			printf("\n\n\t\t������Ϣ����������ѡ�������ʽ\n\n");
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
   else							// ���벻��0��4֮�������ʾ��Ϣ ���·��ؼ�������
		{
			//system("cls");
			printf("\n\n\t\t������Ϣ����������ѡ�������ʽ\n\n");
			flushall();
			Search();
		}	 
       ma_interf();	
	   clockii();// ִ�н��� ����������
}

/**************************************************************************************
*	Functionname: WriteResult														  *
*	Function Description:������Ϣ��������5��ʱ���ͽ���Ϣд��һ���ĵ���				  *
*	Date:2013/7/31																      * 
**************************************************************************************/

void WriteResult (int b[] , int j)
{
	FILE *qq;
	if((qq=fopen("e:\\searchresult.txt" , "w")) == NULL)  //�ж��ļ��Ƿ񴴽��ɹ�
		{
			printf("�����ļ�ʧ��\n");
			exit(0);
		}
	int i=0 , f;		//  i Ϊѭ�����Ʊ���  f ��¼���������ڲ�ͬ��i�� b[i]  ��ֵ
	printf("\n\n\t\t\t����������Ϣ����--5--��\n\n\n\t����������Ϣд��searchresult�ļ��С���\n");
	for(i=0; i<j; i++)
		{
			f=b[i];
			fprintf(qq , "#\t");				
			fprintf(qq , "linkid=%d\t" , data[f].linkid);		// �������ĵ�·��Ϣд���ļ���
			fprintf(qq , "roadnameflag=%d\t" , data[f].roadnameflag);			// �������ĵ�·��Ϣд���ļ���
			fprintf(qq , "brunch=%d\t" , data[f].brunch);		// �������ĵ�·��Ϣд���ļ���
			fprintf(qq , "dispclass=%d\t" , data[f].dispclass);		// �������ĵ�·��Ϣд���ļ���
			fprintf(qq , "roadname=%s\t" , data[f].roadname);		// �������ĵ�·��Ϣд���ļ���
			fprintf(qq , "#");
			fprintf(qq , "\n");
		}
	fclose(qq);						//�ر�ָ��qq
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n\n\t\t����������Ϣд��searchresult�ļ��гɹ�\n\n\n");	
	printf("------------------------------------------------------------------------------\n");
}
/**************************************************************************************
*	Functionname:Judge 													        	  *
*	Function Description:�жϽ����������ļ��Ƿ����									  *
*	Date:2013/7/31																      * 
**************************************************************************************/
void Judge()
{
	FILE *pp;

	if((pp=fopen("e:\\���ӵ�ͼ�ṩ��\\GTBL.dat" , "rb")) == NULL)    //���ļ� ������pp�ļ�ָ�� �ж��ļ��Ƿ����
		{
			printf("\n\n\t\t\t\tthe file not exist!\n\n\t\t\t\t  ������ѡ�����\n\n");
		}
	else
		{
		printf("�ļ���ȡ�ɹ�!\nSuccess!\n");	
		}
}
void ma_interf()
{
	int select;			//select ��������������ѡ����Ҫִ�еĺ���		
	printf("��ѡ���������ࣺ\n");	
	printf("\t1:��ȡ�ļ�\n\t2:����������\n\t3:����\n\t4:����\n\t0:�˳�\n\t��ѡ��:");
	scanf("%d" , &select);
	clockii();
	switch(select)
		{
			case 1 :
				ReadFile();
				mark_1=1;
				Judge();//����Ƿ�ִ�ж�ȡ�ļ�
				ma_interf();
				clockii();
				break;
		   case 2 :
				if(mark_1!=1)
					{
						printf("\n\n\t���ڽ�������ǰ��ѡ��-1-���ж�ȡ�ļ������������ݽ�������\n\n");
						ma_interf();clockii();
					}
				else if(mark_1==1)
					{
						mark_2=1;		//����Ƿ�ִ���������
						SortData(data);
					}
				break;
			case 3 :
				if(mark_1==0||mark_2==0)		//�ж��Ƿ�ִ�� ��ȡ�ļ�  �������·��Ϣ
					{
						printf("\n\n\t\t���ڽ���-����-ǰ��ѡ��-1--2-���ж�ȡ�ļ����������\n\n");
						printf("\t\t     ���������ݽ��м����������������δ����\n\n");
						ma_interf();
						clockii();
					}
				else
					{
						Search();
					}
				break;
			case 4 :
				if(mark_1==0||mark_2==0)		//�ж��Ƿ�ִ�� ��ȡ�ļ�  �������·��Ϣ
					{
						printf("\n\n\t\t���ڽ���-����-ǰ��ѡ��-1--2-���ж�ȡ�ļ����������\n\n");
						printf("\t\t   ���������ݽ��и��»���µ�������δ����\n\n");
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
			printf("\n\n\n\t\t\t������Ϣ����������ѡ��������ࣺ\n\n\n\n");
			ma_interf();	
			clockii();//ִ�н��� ����������
		}
}
/**************************************************************************************
*	Functionname: SortData  														  *
*	Function Description:�Զ�ȡ�������ļ���Ϣ�������򲢽���������ʾ����Ļ��		  *
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
		p=qsort1(l,low,high);    //����һ������Ľ����Ϊ����    
        qsort2(l,low,p-1); //�ݹ�������� ��low ��prvotloc-1    
        qsort2(l,p+1,high); //�ݹ�������� �� prvotloc+1�� high
	}
}
void quicksort(struct dataOut l[],int n)
{
	qsort2(l,1,n); //��һ����Ϊ���� ���ӵ�һ���ŵ���n��
}
void SortData(dataOut data[])
{
	using namespace std;
	int  select, i=0 , k=0 , j=0 ,  n=7;  
	char temp[50];
	double t1,t2;
	//i k Ϊѭ�����Ʊ���  n ��¼linkid�ĳ���  m ��ǳɹ�����ĸ���  
	printf("\n\n\t����������ʽ:\n\n\t\t1:ѡ������\n\n\t\t2:ð������\n\n\t\t3:��������\n\n\t\t4:����\n\n\t\t0:����\n\n\t\t��ѡ��");
	scanf("%d" , &select);
	clockii();
	printf("\n\n\t\t\t������С���������ȴ�!��������\n\n\t\t");
    if(select == 1)
		{
		 int t;
		 char temp[50];
		 t1=clock();
		 for(i=0; i<(size-3); i++)
		 {
			k=i;
			 for(j=i+1; j<(size-2); j++)
					if(data[j].linkid<data[k].linkid )		// �ж�linkid�ĳ����Ƿ�Ϊn
							k=j;
							t =data[k].linkid;				//����s[i]��s[j]��linkid����Ϣ
							data[k].linkid = data[i].linkid;		
							data[i].linkid = t;				
	
							t =data[k].roadnameflag;				//����s[i]��s[j]��flag����Ϣ
							data[k].roadnameflag = data[i].roadnameflag;			
							data[i].roadnameflag = t;				

							t = data[k].brunch;				//����s[i]��s[j]��brunch����Ϣ
							data[k].brunch =data[i].brunch;		
							data[i].brunch = t;

							t= data[k].dispclass;			//����s[i]��s[j]��dispclass����Ϣ
							data[k].dispclass = data[i].dispclass;
							data[i].dispclass = t;

							strcpy(temp , data[k].roadname);			//����s[i]��s[j]��Roadname����Ϣ
							strcpy(data[k].roadname , data[i].roadname);
							strcpy(data[i].roadname , temp);

									//��¼������ɹ���·��Ϣ�ĸ���
		 }
		 t2=clock();
		 printf("������%lf����\n",t2-t1);
         printf("\n\n\t\t����ɹ�-----\n\n");
		 	printf("��Ⱥ�....\n�����ļ������µĶ������ļ���..\n");
	FILE *q = fopen( "e:\\�����ļ�GTBL.dat " ,  "wb+");
	
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
		printf("�ѽ������������µĶ������ļ���!\n");
	
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
				t =data[j].linkid;				//����s[i]��s[j]��linkid����Ϣ
			    data[j].linkid = data[j+1].linkid;		
			    data[j+1].linkid = t;				
	
			    t =data[j].roadnameflag;				//����s[i]��s[j]��flag����Ϣ
			    data[j].roadnameflag = data[j+1].roadnameflag;			
			    data[j+1].roadnameflag = t;				

			    t = data[j].brunch;				//����s[i]��s[j]��brunch����Ϣ
			    data[j].brunch =data[j+1].brunch;		
			     data[j+1].brunch = t;

			    t= data[j].dispclass;			//����s[i]��s[j]��dispclass����Ϣ
			    data[j].dispclass = data[j+1].dispclass;
			    data[j+1].dispclass = t;

			    strcpy(temp , data[j].roadname);			//����s[i]��s[j]��Roadname����Ϣ
			    strcpy(data[j].roadname , data[j+1].roadname);
			    strcpy(data[j+1].roadname , temp);
			}
	 } 
	 t2=clock();
	 printf("������%lf����\n",t2-t1);
	 printf("\n\n\t\t����ɹ�-----\n\n");
	 	printf("��Ⱥ�....\n�����ļ������µĶ������ļ���..\n");
	FILE *q = fopen( "e:\\�����ļ�GTBL.dat " ,  "wb+");
	
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
		printf("�ѽ������������µĶ������ļ���!\n");
	
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
		printf("������%lf����\n",t2-t1);
	    printf("\n\n\t\t����ɹ�-----\n\n");
			printf("��Ⱥ�....\n�����ļ������µĶ������ļ���..\n");
	FILE *q = fopen( "e:\\�����ļ�GTBL.dat " ,  "wb+");
	
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
		printf("�ѽ������������µĶ������ļ���!\n");
	 
		ma_interf();
		

	}
	else if(select == 4)
	{
	 t1=clock();
	 quicksort(data,size-2);
	 t2=clock();
	 printf("������%lf����\n",t2-t1);
	printf("\n\n\t\t����ɹ�-----\n\n");
	printf("��Ⱥ�....\n�����ļ������µĶ������ļ���..\n");
	FILE *q = fopen( "e:\\�����ļ�GTBL.dat " ,  "wb+");
	
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
		printf("�ѽ������������µĶ������ļ���!\n");
	 ma_interf();
	}
	else if(select == 0)
		{
		//	system("cls");
			ma_interf();
		}	
	else							// ���벻��0��4֮�������ʾ��Ϣ ���·��ؼ�������
		{
			//system("cls");
		    flushall();
			printf("\n\n\t\t������Ϣ����������ѡ�������ʽ\n\n");
			
	}
   ma_interf();			//�������  ����������
}

/**************************************************************************************
*	Functionname:Update														          *
*	Function Description:�����ݽ��и��£��������º�Ľ�������µ��ļ���				  *
*	Date:2013/7/31																      * 
**************************************************************************************/

void Update (dataOut data[]) 
{
	printf("\n\n\t\t\t\t�ļ������С���\n");	
	FILE *pp;   
	if((pp=fopen("e:\\newfile.dat " , "wb+")) == NULL)		
	{		
		printf("�����ļ�����ʧ�ܡ���");
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
		printf("\n\n\t\t\t\t�ļ����³ɹ�\n\n\n\t\t\t�����ļ������newfile.dat�ļ���\n\n\n");
	ma_interf();					//����������
}

void clockii()
{
	char *wday[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
	time_t timep;
	struct tm *p;
	time(&timep);
	p=gmtime(&timep);
	printf("%d��%d��%d��\t",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
	printf("%s %d:%d\n",wday[p->tm_wday],p->tm_hour+8,p->tm_min);
}

void main()
{

printf("%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c w e l c o m e !  !  ! !!%c %c %c %c %c %c %c %c %c %c %c %c %c\n",1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1);
printf("    �鳤������        * * *       * * * * *         * * * *\n");
printf("    ��Ա����һ��    *       *     *         *     *\n");
printf("          ��Խ     *         *    *          *   *\n");
printf("          �ɳ���  *               *         *     *\n");
printf("          ����    *               * * * * *         * * * *\n");
printf("          ����  *       * * *   *                         *\n");
printf(" ��������Ӣ�����  *         *    *       2013��7��31��     *\n");
printf("                    *       *     *                         *\n");
printf("                      * * *       *                * * * * *\n");
system("color 8F"); 
                                                             

	clockii();	
	ma_interf();				//����������
}


