#include <stdio.h>
#include <stdlib.h>
#include "StructFile.h"
#include "TransferFormat.h"
#include "Formation.h"
#include "string.h"
#include "time.h"

int main()
{
    int baocuo = 0;
	struct Road *Head=NULL,*Head_Sort=NULL;
	time_t rawtime;
	struct tm * timeinfo;
	int choice = 1;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );	
    printf("\t/***************************************************/\n");
    printf("\t/***************************************************/\n");
    printf("\t/***                                             ***/\n");
    printf("\t/***����\t ��� ���  ��� ���\t�ű�ͮ\t ***/\n");
    printf("\t/***\t\t���      ��       ���\t\t ***/\n");
    printf("\t/***\t\t���     ף��      ���\t\t ***/\n");
    printf("\t/***\t\t���   ���쿪��   ���\t\t ***/\n");
    printf("\t/***������\t ���  O(��_��)O ���\t������   ***/\n");
    printf("\t/***\t\t  ���          ���\t\t ***/\n");
    printf("\t/***\t\t   ���        ���\t\t ***/\n");
    printf("\t/***\t\t    ���     ���\t\t ***/\n");
    printf("\t/***������\t      �����\t\t�λ��� \t ***/\n");
    printf("\t/***\t\t        ���\t\t\t ***/\n");
    printf("\t/***                ��ͬΪ������                 ***/\n");
    printf("\t/********************--welcome--********************/\n");
    printf("\t/***\t\t���ӵ�ͼ��Ϣͳ��ϵͳ\t\t ***/\n");
    printf("\t/***\t\t�����Ŷ� : ����� \t\t ***/\n");
    printf("\t/***\t\t����ʱ�� : %d��%d��%d��\t ***/\n",(timeinfo->tm_year+1900),(timeinfo->tm_mon+1),timeinfo->tm_mday);
    printf("\t/***\t\tʹ��ʱ�� : %dʱ%d��%d��\t ***/\n",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
    printf("\t/**************--Thank you for using--**************/\n");
    system("color 2e");
	while(choice!=0)
	{
		printf("\n\t��ӭʹ�õ��ӵ�ͼ����ϵͳ\n");
		printf("\t��ѡ���������ࣺ\n");
		printf("\t\t1.��ȡ�ļ�(C:\\GTBL.dat)\n");
		printf("\t\t2.����(��������)��������(C:\\SortGTBL.dat)\n");
		printf("\t\t3.����\n");
		printf("\t\t4.����\n");
		printf("\t\t0.�˳�\n");
		printf("\t\t��ѡ�� : ");
		scanf("%d",&choice); 
        switch(choice)
		{
		case 1://��ȡ�ļ�
			{
                int fileb[80];
                int choice_3;
                baocuo++;
                printf("\n\t��ѡ���ȡ�ķ�ʽ�� \n");
                printf("\t\t1.Ĭ�϶�ȡ�� \n");
				printf("\t\t2.�Զ����ȡ�� \n");
                printf("\t\t0.����\n");
                printf("\t����������ѡ��");
                scanf("%d",&choice_3);
                switch(choice_3)
                {
                case 1:                   
				        printf("\n\t�ļ���ȡ�У����Ժ�....\n");
				        if(LoadFile("C:\\GTBL.dat",&Head)==0)
				        {
					        printf("\t�ļ���ȡ��ɣ�\n");
                        }          
				    break;
                case 2:
  
   				        printf("\t�������ļ���ַ: ");
                        scanf("%s",fileb);
                        printf("\t��ȡ�ļ���...\n");
                        if(LoadFile(fileb,&Head)==0)
				        {
				            printf("\t�ļ���ȡ��ɣ�\n");                            
                        }
                         break;
                    
                case 0: 
                    break;
                default:
			        printf("\n\t�r(�s�n�t���q��������������1,2,0�������֣�\n");
                }
              break;

			}
                  break;
		case 2://��������
			{
                if(baocuo != 0)
                {
				int choice;
				printf("\n\t��ѡ������ķ�ʽ�� \n");
				printf("\t\t1.ð������ \n");
				printf("\t\t2.ѡ������ \n");
				printf("\t\t3.�������� \n");
                printf("\t\t0.����\n");
				printf("\t����������ѡ��");
				scanf("%d",&choice);
				LinkToArray(&Head,choice);
			
                }
                else printf("\n\t�r(�s���t)�q���Ƚ���1.��ȡ�ļ�\n");
            }
			break;
		case 3://��������
			{
				int choice=0;
				long linkId;
				int disClass;
				int brunch;
				char roadName[20];
				if((LoadFile("C:\\GTBL.dat",&Head_Sort))==0)
				{
					
					printf("\n\t��ѡ�������ʽ��\n");
					printf("\t\t1.ָ��LinkID������\n");
					printf("\t\t2.ָ������Link�б�ʾClass���� ������\n");
					printf("\t\t3.ָ����·�� ����:\n");
					printf("\t\t4.ָ����·���� ������\n");
					printf("\t\t0.����\n");
					printf("\t����������ѡ��");
					scanf("%d",&choice);
					switch(choice)
					{
					case 1:
						printf("\t������Link��ID��");
						scanf("%ld",&linkId);
						Sort_LinkID(&Head_Sort,linkId);
						break;

					case 2:
						printf("\t�����뽻��Link�б�ʾClass���ţ�");
						scanf("%d",&disClass);
						Sort_DisClass(&Head_Sort,disClass);
						break;
					case 3:
						printf("\t������Ҫ���ҵĲ�·���� ");
						scanf("%d",&brunch);
						Sort_RoadBrunch(&Head_Sort,brunch);
						break;
					case 4:
						printf("\t������Ҫ���ҵĵ�·���ƣ� ");
						scanf("%s",roadName);
						printf("%s",roadName);
						Sort_RoadName(&Head_Sort,roadName);
						break;
					case 0:
						break;
                    default:
			            printf("\n\t�r(�s�n�t���q��������������0--4֮������֣�\n");
					}
				}
				else
				{
					printf("���ȶ�ԭ���ݽ�������Ȼ��ſ��Խ��м�����\n");
				}
			}
			break;
		case 4://���²���
			{
    
				int choice_2;
                int a[80];
                printf("\t1.Ĭ��·��(ָ������)\n");
                printf("\t2.�Զ���Ŀ¼\n");
                printf("\t0.����\n");
                printf("\t��ѡ�� : ");
                scanf("%d",&choice_2);
                switch(choice_2)
                {
                case 1:
                    printf("\t��ȡ�������ļ�...\n");
                    if(LoadFile("C:\\update.dat",&Head)==0)
				    {
				        printf("\t�����ļ���ȡ��ɣ�\n");                            
                    }
                    LinkToArray_2(&Head,3);
                    break;
                case 2:
                    
                    printf("\t�������ļ���ַ: ");
                    scanf("%s",a);
                    printf("\t��ȡ�������ļ�...\n");
                    if(LoadFile(a,&Head)==0)
				    {
				        printf("\t�����ļ���ȡ��ɣ�\n");                            
                    }
                    LinkToArray_2(&Head,3);
                    break;
                case 0:
                    break;
                 default:
			        printf("\n\t�r(�s�n�t���q��������������1,2,0�������֣�\n");
                }
                //    break;			
			}
      
			break;
		case 0://�˳�����
			printf("\t��л����ʹ�ã���ӭ�´μ���ʹ�á�\n");

            printf("\t/***\t  �~�~�~�~  .   �~�~�~�~  .  �~�~�~�~  .  �~�~�~�~\t***/\n");
            printf("\t/***\t���~�~�~�~��. ���~�~�~�~��.���~�~�~�~��.���~�~�~�~��\t***/\n");
            printf("\t/***\t�~������֨~. �~�������~.�~��������~.�~�ϼһ��֨~\t***/\n");
            printf("\t/***\t���~�~�~�~��. ���~�~�~�~��.���~�~�~�~��.���~�~�~�~��\t***/\n");
            printf("\t/***\t  �~�~�~�~  .   �~�~�~�~  .  �~�~�~�~  .  �~�~�~�~\t***/\n");
            printf("\t/***\t   | | |          | | |       | | |         | | |\t***/\n");
			break;
		default:
			printf("\t�r(�s�n�t���q��������������0-4�����֣�\n");
		}
        getchar();

	}

	return 0;
}









