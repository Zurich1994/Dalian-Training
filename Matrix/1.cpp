/**************************************************************************************
*	Filename:tagMap_tDo.cpp																  *
*																  * 
*	Author:.. �ڿ͵۹�												  *
**************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<time.h>
#include<conio.h>

/*������������*/
void ma_interf();
int ReadFile();
void ReadData(FILE *p);
void WriteResult (int b[] , int j);
void Search();

/*�궨��*/
#define MCGETCHAR(data)  (*((char *)(data)))
#define MCGETSHORT(data)  ((unsigned short)(( ((unsigned short)(*((char *)(data))))<<8 )|( ((unsigned short)(*((char *)(data)+1)))&0x00ff )))
#define MCGETLONG(data)  ( ( ((unsigned long)MCGETSHORT((data)))<<16 )|( ((unsigned long)MCGETSHORT((char *)(data)+2))&0x0000ffff ) )
#define MCGET3BN(data)  ( ( ((unsigned long)MCGETCHAR((data)))<<16 )|( ((unsigned long)MCGETSHORT((char *)(data)+1))&0x0000ffff ) )
#define Length 655350 
#define TIME_INTERVAL 120

int nsizecount = 2 ;
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

void clockii()
{
 char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);
    printf("����ʱ����%d��%d��%d��\t", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
    printf("%s %d:%d\n", wday[p->tm_wday], p->tm_hour+8, p->tm_min);
}

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
void Update (dataOut data[]); 		 /*�洢��·��Ϣ������*/      

/**************************************************************************************
*	Functionname:ReadFile															  *
*	Function Description:��ȡ�������ļ���������������ı��ĵ���						  *
*															      * 
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
	
	FILE *pfp = fopen( "E:\\GTBL.dat" ,  "rb+"); 

	if(pfp == NULL)
	{
		printf("can not open the ���ӵ�ͼ����ϵͳ.dat file or there is no the file!\n");
		return 0;
	}

	printf("\n\n�ļ���ȡ��%c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n",26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26);

	while(fread(actotalsize , sizeof(actotalsize) , 1 , pfp) == 1)    
	{
        fread( aclinkId , sizeof(aclinkId) , 1 , pfp ) ;				/*��ȡռ��4�ֽڵ�linkId�ַ�*/      
		fread( acroadnamesize , sizeof(acroadnamesize) , 1 , pfp ) ;	/*��ȡռ��2�ֽڵ�roadnamesize�ַ���*/	 
		fread( acNodeInfo , sizeof(acNodeInfo) , 1 , pfp ) ;   
		
		ustotalsize = MCGETSHORT(actotalsize) ;							/*���ú꺯�� �� ���ַ�����Ϣת��Ϊ��ֵ����*/
		ullinkId = MCGETLONG(aclinkId) ;
		usroadnamesize = MCGETSHORT(acroadnamesize) ;
		
		/*��ֵ ������ֵ��Ϣ�����ṹ����*/ 
		road[nsizecount].ussize = ustotalsize ;
		road[nsizecount].ullinkId = ullinkId ;
		road[nsizecount].usroadnamesize= usroadnamesize ;
		
		m[nsizecount]=(int)acNodeInfo[3]&255;
		road[nsizecount].usdispclass=m[nsizecount]&15;
		road[nsizecount].usbrunch=(m[nsizecount]&112)/16;
		road[nsizecount].usroadnameflag=(m[nsizecount]&128)/128;
		
        data[nsizecount].roadnamesize=road[nsizecount].usroadnamesize;
		data[nsizecount].totalsize=road[nsizecount].ussize;
		data[nsizecount].dispclass= road[nsizecount].usdispclass;
		data[nsizecount].brunch=road[nsizecount].usbrunch;
		data[nsizecount].roadnameflag=road[nsizecount].usroadnameflag;
		data[nsizecount].linkid= ullinkId;
		
		fread(road[nsizecount].roadname , sizeof(char) , ustotalsize - 12 , pfp ) ;	/*���ļ��ж�ȡ��·����*/	
		strcpy(data[nsizecount].roadname,road[nsizecount].roadname+4);

		nsizecount++;//���ݸ���
		
		
	}
	fclose(pfp); 
	printf("\n\t\t\t\t �ļ���ȡ�ɹ�\n");
	return  0; 
}

/**************************************************************************************
*	Functionname:Search																  *
*	Function Description:������Ϣ���֣��ɰ���ͬ�����ͽ��м���				     	  *
*																      * 
**************************************************************************************/

void Search()
{
	int  select , i=0 , j=0 , *b , c=0 , f,d,low,high,mid;  //select ���ѡ����Ҫ���еķ�֧  i ѭ������  j��Ǽ�������Ϣ������  
	//b ����ָ�� ������ż���������Ϣ���±� c �����������b���±�  f �������b��ֵ
	

	printf("\n\n\t�����������ʽ:\n\n\t\t1:ָ��linkID ����\n\n\t\t2:ָ������link�б�ʾclass���� ����\n\n\t\t3:ָ�����Ҳ�·�� ����\n\n\t\t0:����\n\n\t\t��ѡ��");
	scanf("%d" , &select);
   system("cls");
	printf("\n\n*****--����������Ϣ��������5��ʱ , ��Ѽ���������Ϣ�����searchresult�ļ���--*****\n\n");
	printf("\n********--����������Ϣ����δ����5��ʱ , ��Ѽ���������Ϣֱ����ʾ����Ļ��--********\n\n\n");
	if(select == 1)
		{
		printf("\n\t1.˳�����\n\n\t2.�۰����\n\n\t0.����\n\t��������ҷ���:");
		scanf("%d",&d);
		if(d==1){
		    int sss;
			printf("\t������link��ID:");
			scanf("%d" , &sss);
				system("cls");
 			    for(i=0; i<(nsizecount-2); i++)
				{
					if(sss==data[i].linkid)    //�Ƚ��ַ����Ƿ�һ��
						{
							printf("\n\n  Linkid=%d flag=%d brunch=%d dispclass=%d roadname=%s\n\n\n" , data[i].linkid , data[i].roadnameflag , data[i].brunch , data[i].dispclass , 
								data[i].roadname);
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
		if(d==2){
		int sss;
		printf("\t������link��ID:");
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
		     	printf("\n\n\t\t\t\tû��ƥ����\n\n\t\t\t    ������ѡ�������ʽ\n");
					flushall();
					Search();
			}
        

	}
        if(d==0){
			system("cls");flushall();
		Search();
		}

	}
		
	else if(select == 2)
	{        
		        int sss;
				printf("\t�����뽻��link�б�ʾclass����:");
                 flushall();
				scanf("%d" , &sss);
				system("cls");
		     	for(i=0; i<(nsizecount-2); i++)
					{
						if(sss==data[i].dispclass)			//�Ƚ��ַ����Ƿ�һ��	
							{
								j++;
							}
					}
				b=(int *)malloc(sizeof(int)*j);				//��̬��������b�Ĵ洢�ռ�

				for(i=0; i<(nsizecount-2); i++)
					{
						if(sss==data[i].dispclass)			//�Ƚ��ַ����Ƿ�һ��
							{
								b[c]=i;
								c++;
							}
					}
					if(j == 0)
						{
							printf("\n\n\t\t\t\tû��ƥ����\n\n\t\t\t    ������ѡ�������ʽ\n");
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
									printf(" Linkid=%d flag=%d brunch=%d dispclass=%d roadname=%s\n\n\n" , data[i].linkid , data[i].roadnameflag , data[i].brunch , data[i].dispclass , 
								data[i].roadname);
								}
							printf("\n\n");
						}
				free(b);
			}
	else if(select == 3)
			{
				int sss;
				printf("\t�������·��:");
				scanf("%d" , &sss);
				flushall();
				system("cls");
				for(i=0; i<(nsizecount-2); i++)
					{
						if(sss==data[i].brunch)			//�Ƚ��ַ����Ƿ�һ��
							{
								j++;
							}
					}
				b=(int *)malloc(sizeof(int)*j);							//��̬��������b�Ĵ洢�ռ�

				for(i=0; i<(nsizecount-2); i++)
					{
						if(sss==data[i].brunch)			//�Ƚ��ַ����Ƿ�һ��
							{
								b[c]=i;
								c++;
							}
					}
						if(j == 0)
							{
								printf("\n\n\t\t\t\tû��ƥ����\n\n\t\t\t    ������ѡ�������ʽ\n");
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
										printf(" Linkid=%d flag=%d brunch=%d dispclass=%d roadname=%s\n\n\n" , data[i].linkid , data[i].roadnameflag , data[i].brunch , data[i].dispclass , 
								data[i].roadname+4);
								}
							printf("\n\n");
						}
				free(b);
			}

	else if(select == 0)
		{
			system("cls");
			ma_interf();
		}	
/*	else							// ���벻��0��4֮�������ʾ��Ϣ ���·��ؼ�������
		{
 		system("cls");
			printf("\n\n\t\t������Ϣ����������ѡ�������ʽ\n\n");
				flushall();
			Search();
		}*/
	ma_interf();					// ִ�н��� ����������
}

/**************************************************************************************
*	Functionname: WriteResult														  *
*	Function Description:������Ϣ��������5��ʱ���ͽ���Ϣд��һ���ĵ���				  *
																      * 
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
	printf("\n\n\t\t\t����������Ϣ����--5--��\n\n\n\t\t����������Ϣд��searchresult�ļ��С���\n");
	for(i=0; i<j; i++)
		{
			f=b[i];
			fprintf(qq , "#\t");				
			fprintf(qq , "%d\t" , data[f].linkid);		// �������ĵ�·��Ϣд���ļ���
			fprintf(qq , "%d\t" , data[f].roadnameflag);			// �������ĵ�·��Ϣд���ļ���
			fprintf(qq , "%d\t" , data[f].brunch);		// �������ĵ�·��Ϣд���ļ���
			fprintf(qq , "%d\t" , data[f].dispclass);		// �������ĵ�·��Ϣд���ļ���
			fprintf(qq , "%s\t" , data[f].roadname);		// �������ĵ�·��Ϣд���ļ���
			fprintf(qq , "#");
			fprintf(qq , "\n");
		}
	fclose(qq);						//�ر�ָ��qq
	printf("\n\n\t\t����������Ϣд��searchresult�ļ��гɹ�\n\n\n");	
}
/**************************************************************************************
*	Functionname:Judge 													        	  *
*	Function Description:�жϽ����������ļ��Ƿ����									  *
*																      * 
**************************************************************************************/
void Judge()
{
	FILE *pp;

	if((pp=fopen("E:\\GTBL.dat" , "rb")) == NULL)    //���ļ� ������pp�ļ�ָ�� �ж��ļ��Ƿ����
		{
			printf("\n\n\t\t\t\tthe file not exist!\n\n\t\t\t\t  ������ѡ�����\n\n");
			printf("\n\t�����Ҫ������--���ӵ�ͼ����ϵͳ.dat--����--e:\\��Ŀ¼����--��\n\n");

		}

}
void ma_interf()
{
	int select;			//select ��������������ѡ����Ҫִ�еĺ���			//���������ļ����ļ�ָ��

	printf("��ѡ���������ࣺ\n");
	printf("\t1:��ȡ�ļ�(e:���ӵ�ͼ����ϵͳGTBL.dat)\n\t2:����������\n\t3:����\n\t4:����\n\t0:�˳�\n\t��ѡ��:");
	scanf("%d" , &select);
		system("cls");
		clockii();
	switch(select)
		{
			case 1 :

				ReadFile();				
				mark_1=1;
				Judge();
				ma_interf();
				break;
			case 2 :
				if(mark_1!=1)
					{
						printf("\n\n\t���ڽ�������ǰ��ѡ��-1-���ж�ȡ�ļ������������ݽ�������\n\n");
						ma_interf();
					}
				else if(mark_1==1)
					{
						mark_2++;//����Ƿ�ִ���������
                         		
						SortData(data);
					}
				break;
			case 3 :
				if(mark_1==0||mark_2==0)		//�ж��Ƿ�ִ�� ��ȡ�ļ�  �������·��Ϣ
					{
						printf("\n\n\t\t���ڽ���-����-ǰ��ѡ��-1--2-���ж�ȡ�ļ����������\n\n");
						printf("\t\t     ���������ݽ��м����������������δ����\n\n");
						ma_interf();
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
					}
				else
					{
						Update(data);
						break;
					}
			case 0 :
				printf("�����ˣ��Ǿ�byebye��!\n%c",1);
				system("pause");
				exit(0);
				break;
			default:
			printf("\n\n\n\t\t\t������Ϣ����������ѡ��������ࣺ\n\n\n\n");
			ma_interf();			//ִ�н��� ����������
		}
}

/**************************************************************************************
*	Functionname: SortData  														  *
*	Function Description:�Զ�ȡ�������ļ���Ϣ�������򲢽���������ʾ����Ļ��		  *
*															      * 
**************************************************************************************/
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
		p=Q1(l,low,high);    //����һ������Ľ����Ϊ����    
        Q2(l,low,p-1); //�ݹ�������� ��low ��prvotloc-1    
        Q2(l,p+1,high); //�ݹ�������� �� prvotloc+1�� high
	}
}
void quicksort(struct dataOut l[],int n)
{
	Q2(l,1,n); //��һ����Ϊ���� ���ӵ�һ���ŵ���n��
}

void SortData(dataOut data[])
{
	//using namespace std;
	int  select, i=0 , k=0 , j=0 ,  n=7;  
	char temp[50];
	double t1,t2;
	//i k Ϊѭ�����Ʊ���  n ��¼linkid�ĳ���  m ��ǳɹ�����ĸ���  
	printf("\n\n\t����������ʽ:\n\n\t\t1:ѡ������\n\n\t\t2:ð������\n\n\t\t3:��������\n\n\t\t4:����\n\n\t\t5:����\n\n\t\t0:����\n\n\t\t��ѡ��");
	scanf("%d" , &select);
		system("cls");
		clockii();
	printf("\n\n����������������������������Ŭ��Ϊ�����������С��������Ȼ����!����������������\n^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^LOADING^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.\n\n\t\t������ɺ��Զ���LinkID�����С������ʾ���е�·��Ϣ\n\n");
//system("cls");
    if(select == 1)//ѡ������
		{
		 int t;
		 char temp[50];
		 t1=clock();
		 for(i=0; i<(nsizecount-3); i++)
		 {
			k=i;
			 for(j=i+1; j<(nsizecount-2); j++)
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
		/* for(i=0;i<(nsizecount-2);i++)
		{
			printf("    %d      \n" , data[i].linkid );
		}*/
		 t2=clock();
		 printf("��ѡ���ѡ�����������ˣ�������%lf���룬����ȫ�������û�.\n\n\n\n\t\t\t\t��Ҳ����̬��%c\n\n\n\n",t2-t1,1);
		 printf("~~~~~~~~~~~~~~~~~~~~~~~loading>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	     FILE *pp=fopen("e:\\SORTGTBL.dat " , "wb+");
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
		printf("��������������£�\n");
		 ma_interf();
	}
	else if(select == 2)//ð������
	{
	 int t;
	 t1=clock();
	 for(i=0; i<(nsizecount-3); i++)
	 {
		   for(j=0;j<(nsizecount-3-i);j++)	 
	    	if(data[j].linkid>data[j+1].linkid)
			{
				t =data[j].linkid;				        //����s[i]��s[j]��linkid����Ϣ
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
	 printf("��ѡ���ð�����������ˣ�������%lf���룬����ȫ���ĳ��û����ٶ�һ��,ϴϴ˯�ɡ�\n\n\n\t\t\t\t����Ŭ����%c\n\n\n\n",t2-t1,2);
	 printf("~~~~~~~~~~~~~~~~~~~~~~~~loading>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	 FILE *pp=fopen("e:\\SORTGTBL.dat " , "wb+");
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
		printf("�໣��ļ������Ѹ㶨��\n");
	 ma_interf();
	}
	else if(select == 3)//��������
	{
	  int n1,n2,n3,n4;
	   char temp[50];		
	   t1=clock();	
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
		t2=clock();
		printf("��ѡ��Ĳ������������ˣ�������%lf���룬����ȫ�������û���\n\n\n\t\t\t\t�ٶ��Ѿ�ͦ����,͵���ְ�^.^\n\n\n\n",t2-t1);
		printf("~~~~~~~~~~~~~~~~~~~~loading>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	    FILE *pp=fopen("e:\\SORTGTBL.dat " , "wb+");
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
		printf("����ļ����������£�\n");
		ma_interf();
	}
	else if(select == 4)//����
	{
	 t1=clock();
     quicksort(data,nsizecount-2);
	  t2=clock();
	 printf("��ѡ��Ŀ������������ˣ�������%lf���룬��ɱ��ȫ���϶��û��ˡ�\n\n\n\t\t\t\t�������Ĥ��%c%c\n\n\n",t2-t1,26,26);
	 printf("~~~~~~~~~~~~~~~~~~~~~loading>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	 FILE *pp=fopen("e:\\SORTGTBL.dat " , "wb+");
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
		printf("�������ļ���������������\n");
	 ma_interf();		
	}
	else if(select == 5)//����
	{
	  
	  t1=clock();
       quicksort(data,nsizecount-2);
	  t2=clock();
	  printf("��ѡ��Ķ����������ˣ�������%lf���룬��ɱ��ȫ�������û���\n\n\n\t\t\t\t�ϵ۰���%c%c\n\n\n\n",t2-t1,26,26);
	  printf("~~~~~~~~~~~~~~~~~~~loading>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	  FILE *pp=fopen("e:\\SORTGTBL.dat " , "wb+");
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
		printf("�������ļ������ˣ�\n");
		ma_interf();
	}
	else if(select == 0)
		{
system("cls");
			ma_interf();
		}	
	else							// ���벻��0��4֮�������ʾ��Ϣ ���·��ؼ�������
		{
			//system("cls");
			printf("\n\n\t\t������Ϣ����������ѡ�������ʽ\n\n");
			
		}
//	ma_interf();		// ִ�н��� ��������
system("cls");

	printf("\n\n\t\t����㶨��-----��LinkID�����С������ʾ���\n\n\n");
	ma_interf();			//�������  ����������
}


/**************************************************************************************
*	Functionname:Update														          *
*	Function Description:�����ݽ��и��£��������º�Ľ�������µ��ļ���				  *
*																	      * 
**************************************************************************************/

void Update (dataOut data[]) 
{
	printf("\n\n\t\t\t\t�ļ������С���\n");	
	FILE *q=fopen("e:\\newfile.dat " , "wb+");   
	if((q=fopen("e:\\newfile.dat " , "wb+")) == NULL)		
	{		
		printf("�����ļ�����ʧ�ܡ���");
			exit(0);
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
		printf("\n\n\t\t\t\t�ļ����³ɹ�\n\n\n\t\t\t�����ļ������newfile.dat�ļ���\n\n\n");
	ma_interf();					//����������
}


void main()
{int i,j;
long c;
char str[150]="*********>>>>>>>>>>>>The Matrix Product. You are the one!>>>>\n\n\n\n";
int l=strlen(str);
char sleft[150];
char sright[150];
int scrwidth=158;
system("color 2F");//������ɫΪblue������Ϊaqua
clockii();
	for(i=0;i<=scrwidth;i++)
	{
		if(i<=scrwidth-l)

			c=clock();
			
			else
			{
				c=clock();
				strcpy(sleft,str);
			 	strcpy(sright,str+3-(i-(scrwidth-3)));
				*(sleft+2-(i-(scrwidth-2)))=NULL;
				for(j=0;j<i;j++)
				{
					printf(" ");
				}
			 	printf("%s \r",sleft);
			 	printf("%s \r",sright);
				
				while(clock()-c<=TIME_INTERVAL);
			}
		}
system("cls");



	printf("/~.<~.~<~.~<~.~<~.~<~.~<~.~<~.~<~.~<~.~welcome!~.~>~.~>~.~>~.~>~.~>~.~>~.~>~.\n");
    printf("                     * *             * *            * *\n");
	printf("                   *     *         *     *        *     *\n");
    printf("                 *          *   *          *   *          *\n");
    printf("               *              *              * ����Ȼ       *\n");
	printf("              *               %c               *    �� ��     *\n",2);
    printf("              *           ��ӭ����ʹ��         *      ������  *\n");
    printf("              *                                *       ��ï�� *\n");
    printf("               *       ����Ϊ���߳Ϸ���       *       �ܲ��� *\n");
	printf("                *                            * ������       *\n");
	printf("                 *  We are ready and eager *              *\n");
	printf("                   *                     *              *\n");
	printf("                     *  to serve you.  *              *\n");
	printf("                       *      %c     *   *          *\n",1);
	printf("                         *         *      *       *\n");
	printf("                              *               * \n");  


	system("color 1E");//������ɫΪaqua������Ϊlightwhite
    clockii();
	ma_interf();				//����������



	
}
