
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<time.h>//ʱ����ʾ
#include<conio.h>
#include <windows.h>
#pragma comment(lib, "WINMM.LIB")//���ز���wav


/*������������*/
void ma_interf();
int ReadFile();
void ReadData(FILE *p);
void WriteResult (int b[] , int j);
void Search();
void quickSort();
void QuickSort(struct dataOut l[],int n);

/*�궨��*/
#define MCGETCHAR(data)  (*((char *)(data)))
#define MCGETSHORT(data)  ((unsigned short)(( ((unsigned short)(*((char *)(data))))<<8 )|( ((unsigned short)(*((char *)(data)+1)))&0x00ff )))
#define MCGETLONG(data)  ( ( ((unsigned long)MCGETSHORT((data)))<<16 )|( ((unsigned long)MCGETSHORT((char *)(data)+2))&0x0000ffff ) )
#define MCGET3BN(data)  ( ( ((unsigned long)MCGETCHAR((data)))<<16 )|( ((unsigned long)MCGETSHORT((char *)(data)+1))&0x0000ffff ) )
#define Length 655350 
#define TIME_INTERVAL 2

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
double start,end;//ʱ��

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


void Sort(dataOut data[]);   
/*************************************************************************************************/
/*********************************�˳�����********************************************************/
/*************************************************************************************************/

void exit()
{
	system("cls");
	printf("------------------------------------------------------------------------------\n");
	printf("����������������������������������������\n");
	printf("������������ ��лʹ��DreamerGroup���ӵ�ͼ! ��������������\n");
	printf("����������������������������������������\n\n");
	system("pause");
	exit(0);

	return;
}


/*************************************************************************************************/
/*********************************��ɫ����********************************************************/
/*************************************************************************************************/

void set_color1()	//�������ּ�������ɫ����
{	char ch1='3';
	//getchar(); //������ѡ����'C'�����ٰ�'�س�'����ϵͳ�����ν��䴦��Ϊ�����ַ��������ڴ˴�����'�س�'���մ������²���Ӱ�쵽������ַ����롣
	while(1)		
	{	system("cls");
		printf("\n\n\t\t\t      �������ּ�������ɫ  \n");
		printf("_______________________________________________________________________________\n\n");
		printf("\n\t\t\t        ������ɫ   ������ɫ\n");
		printf("\n\t\t\t  1 ��    ��ɫ       ��ɫ");
		printf("\n\t\t\t  2 ��    ��ɫ      ����ɫ");
		printf("\n\t\t\t  3 ��    ��ɫ       ��ɫ");
		printf("\n\t\t\t  4 ��    ��ɫ       ��ɫ");
		printf("\n\t\t\t  5 ��    ��ɫ      ����ɫ��Ĭ����ɫ��");
		printf("\n\t\t\t  6 ��    ��ɫ       ��ɫ");
		printf("\n\t\t\t  7 ��    ��ɫ       ��ɫ");
		printf("\n\t\t\t  8 ��    ��ɫ       ��ɫ");
		printf("\n\t\t\t  9 ��    ��ɫ      ����ɫ");
		printf("\n\n\t\t\t  0 ��  �������˵�\n\n");
		printf("\n\t\t\t���밴�˵�ǰ������ֻ��ַ�������ѡ��\n");
		printf("\n\t\t\t==��");
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
/*********************************������**********************************************************/
/*************************************************************************************************/


void Start(){

	time_t rawtime;
	struct tm * timeinfo;

	sndPlaySound("media\\summer.wav",SND_LOOP|SND_ASYNC);


	system("color 3E");//ϵͳ��ɫ���ģ�����������ɫ 3�� ������ɫ������ɫ E��

	int i=2;
	int k=0;
	int j=3;

	while(1)//��˸

	{
		char * star[10]={"�����������������������������������������\n",
						 "�����������������������������������������\n",
						 "�����������������������������������������\n",
						 "�����������������������������������������\n",
						 "�����������������������������������������\n",
						 "�����������������������������������������\n",
						 "�����������������������������������������\n",
						 "�����������������������������������������\n",
						 "�����������������������������������������\n",
                         "�����������������������������������������\n",
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
		printf("**************************-----���ӵ�ͼ����ϵͳ-----****************************\n");
		printf("       DDD     RRRR      EEEEEE      A          M     M     EEEEEE  RRRR\n");
		printf("       D  D    R   R     E          A  A       M M   M M    E       R   R\n");
		printf("       D   D   RRRR      EEEEE     AAAAAA     M   M M   M   EEEEE   RRRR\n");
		printf("       D  D    R   R     E        A      A   M     M     M  E       R   R\n");
		printf("       DDD     R    R    EEEEEE   A      A   M           M  EEEEEE  R    R\n");
		printf("                                                        Dreamer-Group ��������\n");
		printf("******************************-----Just Do IT!-----*****************************\n");
		printf("%s",star[i]);
		printf("%s",star[k]);
		printf("%s",star[j]);
		printf("               Dreamer Ϊ����ʱ ����ʱ�� ����ʱ�䣺%4d-%02d-%02d %02d:%02d:%02d\n",1900+timeinfo->tm_year, 1+timeinfo->tm_mon,
																		timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
		printf("                            �밴�ո񣬽���ѡ�����\n");
	

		int i,j;
		for(i=0;i<3000;i++)
			for(j=0;j<20000;j++){;}//��ʱ
		system("cls");//������ʵ����˸
	
	
	}
	
}  

/*************************************************************************************************/
/*********************************��ȡ�ļ�********************************************************/
/*************************************************************************************************/


int   ReadFile() 
{ 
	char aclinkId[4] ;							/*�Ӷ������ļ��ж�ȡ��·���*/
    char acroadnamesize[2] ;			    	/*�Ӷ������ļ��ж�ȡ��·�������ݳ���*/
    char acNodeInfo[4];
	unsigned short ustotalsize;
    unsigned long  ullinkId;
    unsigned short usroadnamesize;
	
	char actotalsize[2] ;					   /*�Ӷ������ļ��ж�ȡ��·��Ϣ���������ݳ��� */
	
	FILE *pfp = fopen( "D:\\GTBL.dat " ,  "rb+"); 
	FILE *pf2 = fopen( "D:\\�����ļ�.txt " ,  "w+"); 

	if(pfp == NULL)
	{
		printf("can not open the GTBL.dat file or there is no the file!\n");
		return 0;
	}
	system("cls");

	printf("\n\n\t\t\t\t�ļ���ȡ��.....\n");

    printf("                               ,,,,,,,\n");
	printf("                           ,NEUSOFT:'-,o,\n");
	printf("                         .NEUSOFT' '' ' -*R&b,\n");
	printf("                        'NEUSOFT`'      .oM'HM?.\n");
	printf("                      ,NEUSOFT       'NEUSOFT$$|\n");
	printf("                     .:NEUSOFT         `NEUSOFT#|\n");
	printf("                    . NEU@#SOFT       &*��NEUSOFT:\n");
	printf("                    .    SOFT       �wNEUSOFT%MMM.\n");
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
		
		data[nsizecount].dispclass= road[nsizecount].usdispclass;
		data[nsizecount].brunch=road[nsizecount].usbrunch;
		data[nsizecount].roadnameflag=road[nsizecount].usroadnameflag;
		data[nsizecount].linkid= ullinkId;
		
		fread(road[nsizecount].roadname , sizeof(char) , ustotalsize - 12 , pfp ) ;	/*���ļ��ж�ȡ��·����*/	
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
		fprintf(pf2 , "Roadname=����");
		fprintf(pf2 , "%s\t" , data[nsizecount].roadname+4);
		fprintf(pf2 , "#");
		fprintf(pf2 , " \n");

		nsizecount++;//���ݸ���
		
		
	}
	fclose(pfp); 
	fclose(pf2); 
	system("cls"); 
	printf("\n\t\t\t\t �ļ���ȡ�ɹ�\n");
	return  0; 
}
/*************************************************************************************************/
/*********************************д���ļ�********************************************************/
/*************************************************************************************************/
void WriteResult (int b[] , int j)
{
	FILE *qq;
	if((qq=fopen("D:\\searchresult.txt" , "w")) == NULL)  //�ж��ļ��Ƿ񴴽��ɹ�
		{
			printf("�����ļ�ʧ��\n");
			exit();
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
/*************************************************************************************************/
/*********************************����ж�********************************************************/
/*************************************************************************************************/
void Judge()
{
	FILE *pp;

	if((pp=fopen("D:\\GTBL.dat" , "rb")) == NULL)    //���ļ� ������pp�ļ�ָ�� �ж��ļ��Ƿ����
		{	system("cls");
			printf("\n\n\t\t\t\tthe file not exist!\n\n\t\t\t\t  ������ѡ�����\n\n");
			printf("\n\t�����Ҫ������--���ӵ�ͼ����ϵͳ.dat--����--D:\\��Ŀ¼��\n\n");

		}

}

/*************************************************************************************************/
/*********************************����ѡ��********************************************************/
/*************************************************************************************************/

void Choose()
{

	char* Choose1[13] = {"  �� ӭ �� �� �� �� ѡ �� �� ��  ",//0
						"����ѡ������Ҫ�Ĺ���",//1
						"��ȡ�ļ�",//2
						"����",//3
						"����",//4
						"�˳�",//5
						"��������ѡ��Ĺ���ǰ�����ֱ��",//6
						"���������ṩ��ѡ����ѡ��",//7
						"������������ѡ��Ĳ���ǰ�����ִ���",//8
						"����",//9
						"�������ּ�������ɫ"//10
				};	

	int k;



	printf("------------------------------------------------------------------------------\n");
	printf("����������������������������������������\n");
	printf("������������  %s  �����������\n",Choose1[0]);
	printf("����������������������������������������\n\n");
		
	printf("       %s��\n\n",Choose1[1]);
	printf("               [1]%s��\n",Choose1[2]);
	printf("               [2]%s��\n",Choose1[3]);
	printf("               [3]%s��\n",Choose1[4]);

	printf("               [4]%s��\n",Choose1[9]);
	printf("               [5]%s��\n",Choose1[10]);
	printf("               [0]%s��\n",Choose1[5]);
	printf("       %s��\n\n",Choose1[6]);
	printf("       %s��",Choose1[7]);

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

	if(1 == k)//��ȡ���ļ�
	{	
		if(mark_1!=0)
		{
			system("cls");
			printf("                                 �ļ��Ѵ�!\n");
			Choose();
			
		}


		ReadFile();
		mark_1++;			//����Ƿ�ִ�ж�ȡ�ļ�
	
		Judge();
		
	

		Choose();
	
	

		
	

	}
	else if(2 == k){//���������ܽ���
	
		system("cls"); 
		if(mark_1==0){
			printf("\n\n\t���ڽ�������ǰ��ѡ��-1-���ж�ȡ�ļ������������ݽ�������\n\n");
			Choose();
		}
		else
		{
			mark_2++;		//����Ƿ�ִ���������
			Sort(data);
		}
	}
	else if(3 == k)//����������ܽ���
	{
		system("cls"); 

		if(mark_1==0||mark_2==0){		//ͬ��
			printf("\n\n\t\t���ڽ���-����-ǰ��ѡ��-1--2-���ж�ȡ�ļ����������\n\n");
			printf("\t\t     ���������ݽ��м����������������δ����\n\n");
			Choose();
	}
	else{
		Search();
		}

	}

	
	else if(4 == k)
	{
		system("cls"); 
		if(mark_1==0||mark_2==0){		//ͬ��
			printf("\n\n\t\t���ڽ���-����-ǰ��ѡ��-1--2-���ж�ȡ�ļ����������\n\n");
			printf("\t\t            ���������ݽ��и���\n\n");
			Choose();
		}
		Update (data);//������½���
	}	
	else if(0 == k)
	{
		//if(mark_1!=0)		//�ж��Ƿ������s ��ss �Ŀռ�
				//	{
					//	free(s);		//�ͷ�s�ڴ�
					//	free(ss);		//�ͷ�ss�ڴ�
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
/*************************************�۰����****************************************************/
/*************************************************************************************************/
void BinarySearch()
{
		int sss,low,high,mid;
		printf("       ������link��ID:");
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

/*************************************************************************************************/
/*************************************˳�����****************************************************/
/*************************************************************************************************/

void sequentialSearch()

{
		    int sss,i,j;
			printf("       ������link��ID:");
			scanf("%d" , &sss);
			
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


/*************************************************************************************************/
/*********************************��������ѡ��****************************************************/
/*************************************************************************************************/


void Search(){
	char* Search1[8] = {"   �������ܽ���   ",//0
						"��ѡ�������ʽ",//1
						"��˳����ҷ�ʽ����",//2
						"���۰���ҷ�ʽ����",//3
					
						"������һ���˵�",//4
					
	
						"��������ѡ��Ĺ���ǰ�����ִ���",//5
						"���������ṩ��ѡ����ѡ��",//6
						"������������ѡ��Ĺ���ǰ�����ִ���",//7
					
	
								};

	int Method;//����

	printf("------------------------------------------------------------------------------\n");
	printf("����������������������������������������\n");
	printf("�������������� %s �����������������\n",Search1[0]);
	printf("����������������������������������������\n\n");

	printf("       %s��\n\n",Search1[1]);
	printf("               [1]%s��\n",Search1[2]);//˳��
	printf("               [2]%s��\n",Search1[3]);//�۰�

	printf("               [3]%s��\n",Search1[4]);
	printf("       %s��",Search1[5]);
 






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
						sequentialSearch();//˳�����
						printf("--------------------------------------------------------------------------\n\n");
						system("pause");
						system("cls"); 
						

				}
				Choose();
				break;
			case 2:
				{
						BinarySearch();//�۰����
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
/*****************************************ð������************************************************/
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
	 end=clock();
	 printf("\t\t��ϲ�ɹ�����!��ʱ%lf��\n",double(end-start)/CLOCKS_PER_SEC);
	 printf("\n\n\t\t����ɹ�-----��LinkID�����С�����������\n\n");
	 printf(">>>>>> >>>>>> >>>>>> >>>>>> >>>>>> ���Ե� <<<<<< <<<<<< <<<<<< <<<<<< <<<<<<");
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
/*****************************************ѡ������************************************************/
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

				
						}

				
		

	system("cls");
	end=clock();
	printf("\t\t��ϲ�ɹ�����!��ʱ%f��\n",(double)(end-start)/CLOCKS_PER_SEC);
	printf("\n\n\t\t����ɹ�-----��LinkID�����С�����������\n\n");
	printf(">>>>>> >>>>>> >>>>>> >>>>>> >>>>>> ���Ե� <<<<<< <<<<<< <<<<<< <<<<<< <<<<<<");
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
	
			//�������  ����������
}
/*************************************************************************************************/
/*****************************************��������************************************************/
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
		printf("\t\t��ϲ�ɹ�����!��ʱ%f��\n",(double)(end-start)/CLOCKS_PER_SEC);
		printf("\n\n\t\t����ɹ�-----��LinkID�����С�����������\n\n");
		printf(">>>>>> >>>>>> >>>>>> >>>>>> >>>>>> ���Ե� <<<<<< <<<<<< <<<<<< <<<<<< <<<<<<");
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
/*****************************************��������************************************************/
/*************************************************************************************************/
void quickSort()
	{
	 start=clock();
     QuickSort(data,nsizecount-2);
	 end=clock();

		printf("\t\t��ϲ�ɹ�����!��ʱ%f��\n",(double)(end-start)/CLOCKS_PER_SEC);
		printf("\n\n\t\t����ɹ�-----��LinkID�����С�����������\n\n");
		printf(">>>>>> >>>>>> >>>>>> >>>>>> >>>>>> ���Ե� <<<<<< <<<<<< <<<<<< <<<<<< <<<<<<");
	

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
		p=Q1(l,low,high);    //����һ������Ľ����Ϊ����    
        Q2(l,low,p-1); //�ݹ�������� ��low ��prvotloc-1    
        Q2(l,p+1,high); //�ݹ�������� �� prvotloc+1�� high
	}
}

void QuickSort(struct dataOut l[],int n)
{
	Q2(l,0,nsizecount-2); //��һ����Ϊ���� ���ӵ�һ���ŵ���n��
}




/*************************************************************************************************/
/*********************************������ѡ��****************************************************/
/*************************************************************************************************/
void Sort(dataOut data[])
{
	char* SortChoose[20] = {"  �����ܽ���  ",//0
							"��ѡ������ʽ",//1
							"ð������",//2
							"��������",//3
					
							"��������",//4
							"������һ���˵�",//5

							"��������ѡ��Ĺ���ǰ�����ִ���",//6
							"���������ṩ��ѡ����ѡ��",//7
							"������������ѡ�������ʽǰ�����ִ���",//8

							"       ���ڽ����������Ժ�  ...... ...... ...... ...... ...... ...... ......",//9
							"����ѡ����������Ĳ���",//10
							"����ԭ�ļ�",//11
							"���Ϊ���ļ�",//12
							"�����в���",//13
							"��������ѡ��Ĳ���ǰ�����ֱ��",//14
							"�ȽϽ���!",//15
							"�ո���˳��Ƚ�!",//16
						    "ѡ������"};//17
	

	int Type;



	printf("------------------------------------------------------------------------------\n");
	printf("����������������������������������������\n");
	printf("��������������  %s  �����������������\n",SortChoose[0]);
	printf("����������������������������������������\n\n");

    printf("       %s��\n\n",SortChoose[1]);
	printf("               [1]%s��\n",SortChoose[2]);
	printf("               [2]%s��\n",SortChoose[3]);
	printf("               [3]%s��\n",SortChoose[4]);
	printf("               [4]%s��\n",SortChoose[17]);

	printf("               [0]%s��\n",SortChoose[5]);

	printf("       %s��",SortChoose[6]);
	


	scanf("%d" , &Type);//ѡ������ؼ���
	fflush(stdin);
	while(1 != Type && 2 != Type && 3 != Type && 4 != Type )//�ж��Ƿ�������ȷ
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
		
				BubbleSort();//ð��
				break;
			case 2:
				printf("%s\n\n",SortChoose[9]);
			
				insertSort();//����
				break;
			case 3:
				printf("%s\n\n",SortChoose[9]);
			
				quickSort();//��������
				break;
			case 4:
				printf("%s\n\n",SortChoose[9]);
			
				SelectionSort();//ѡ��
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
/*****************************************����****************************************************/
/*************************************************************************************************/
void Update (dataOut data[]) 
{
	printf("\n\n\t\t\t\t�ļ������С���\n");	
	FILE *q=fopen("d:\\newfile.dat " , "wb+");   
	if((q=fopen("d:\\newfile.dat " , "wb+")) == NULL)		
	{		
		printf("�����ļ�����ʧ�ܡ���");
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
		printf("\n\n\t\t\t\t�ļ����³ɹ�\n\n\n\t\t\t�����ļ������update.dat�ļ���\n\n\n");
	Choose();					//����������
}





	
/*************************************************************************************************/
/*******************************************������************************************************/
/*************************************************************************************************/

int main(){

	Start();
	Choose();

	return 0;
}
