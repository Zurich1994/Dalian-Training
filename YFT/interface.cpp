#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <time.h>
#include"ioFile.h"
#include"sort.h"
#include"search.h"
#include "structures.h"
RoadArray_t * stRL;
TreeNode_t *  pNode;

char* FilePath = PATH;
/*********************************************************************************************************
** Last version date:       2013-07-30                                                                   *
** Description:        ҳ����Ƽ�����                                                                    *
** Author:            ��ع��                                                                             *
*********************************************************************************************************/

void PrintHeadFunction()
{
	
	printf("/************************ ��ӭʹ��! Welcome to use! *************************/\n");
	printf("/*****                                                                  *****/\n");
	printf("/*****                                                                  *****/\n");
	printf("/*****                        ���ӵ�ͼ����ϵͳ                          *****/\n");
	printf("/*****                 Electronic Map Management System                 *****/\n");
    printf("/*****                                                                  *****/\n");
	printf("/*****                                                                  *****/\n");
    printf("/*****                                 ,,,,,,                           *****/\n");
	printf("/*****                         '' o#'9MMHb':'-,o,                       *****/\n");
	printf("/*****                       '.oH'':HH$' ''' ' -*R&o,                   *****/\n");
	printf("/*****                     ' dMMM*'''`'      .oM'HM?.                   *****/\n");
	printf("/*****                    ',MMM'          '''HLbd< ?&Hp                 *****/\n");
	printf("/*****                   '.:MH .''          ` MM  MM&b                  *****/\n");
	printf("/*****                  . ''*H    -        &MMMMMMMMMH:;                *****/\n");
	printf("/*****                  .    dboo        MMMMMMMMMMMM  ;.               *****/\n");
	printf("/*****                  .   dMMMMMMb      *MMMMMMMMMP  ; '              *****/\n");
	printf("/*****                   ;. MMMMMMMMMP        *MMMMMP  . '              *****/\n");
	printf("/*****                    ;;  `#MMMMM           MM6P   ;,               *****/\n");
	printf("/*****                    ';    `MMMP'           HM*`,;                 *****/\n");
	printf("/*****                      ';    :MM             .- ,                  *****/\n");
	printf("/*****                        ;.   `#?..  .       ..'                   *****/\n");
	printf("/*****                          -.   .         .-                       *****/\n");
	printf("/*****                            ''-.oo,oo.-''	                        *****/\n");
	printf("/*****                                                                  *****/\n");
	printf("/*****                                                                  *****/\n");
	printf("/*****                                                                  *****/\n");
	printf("/*****                   �汾�ţ�Version����sh*t 2.0                    *****/\n");
	printf("/*****                   �����ߣ�Developer�����й�����                  *****/\n");
	printf("/*****                   ����������ڣ�Date����2013-07-31               *****/\n");
	printf("/****************************************************************************/\n\n");

}


void ExitFunction()
{   
	printf("******************************************************************************\n");
	printf("******                               |||3|||                            ******\n");
    printf("******                              |||345|||                           ******\n");
	printf("******                ;            (��.@.@��)               ;           ******\n");
    printf("******                ;-------oOOo-----(_)-----oOOo---------;           ******\n");
    printf("******                ;������   �й������л����ʹ��!������ ;           ******\n"); 
    printf("******                ;��    ��                       ��  ��;           ******\n");
    printf("******                ;����Thank you for using the system!  ;           ******\n");
    printf("******                ;�������������������������������� ����;           ******\n");
	printf("******                ;����������Bye!      Bye!�� ����      ;           ******\n");
	printf("******                ;---------------------Oooo------------;           ******\n");
	printf("******                                                                  ******\n");                               
	printf("******************************************************************************\n");
	printf("���򼴽��ر�(Closing)......\n");
    Sleep(700);

	if(stRL->roadMsgs != NULL)
		free(stRL->roadMsgs);
	
	if(stRL != NULL)
		free(stRL);
	
	if(pNode != NULL)
		free(pNode);

	exit(0);
}


int SortHelp(int SortHelpChoose)
{
	
	int choose = SortHelpChoose;
	if(CHINESE == choose)
	{

		printf("\n---------------------------------��  ��---------------------------------------\n");
		printf("һ�������飺\n");
		printf("        ������Ϊϵͳ�е�������ѡ����棬����������ȡ������Ҫ���ļ�֮��ѡ\n");
		printf("    ������Ҫ�ķ�ʽ���ļ��е����ݽ������򣬵õ���Ӧ����������\n\n");
		printf("�������ܼ�飺\n");
		printf("    1��ѡ�������׼��������ѡ�����linkID����·������·���Ż��ߵ�·���ƶ���\n");
		printf("                     �ݽ�������\n\n");
		printf("    2��ѡ������ʽ��Ϊ���ṩ��Ĭ�Ϸ�ʽ���Զ��巽ʽ�Ͷ�������ʽЧ�ʱȽϣ�\n");
		printf("                     ��������ʽ��\n\n");
		printf("                          ��Ĭ�Ϸ�ʽ��������Ը�������ʽ�����˽⣬�Ƽ���ѡ\n");
		printf("                                      ��˷�ʽ��Ĭ���ÿ�������ķ�ʽΪ������;\n\n");
		printf("                          ���Զ��巽ʽ��Ϊ���ṩ�˿�������ð�����򡢲�����\n");
		printf("                                        ��������Ҫ������ʽ����ѡ��\n");
		printf("                                        ���������Ϊ�������������ʱ�䣻\n\n");
		printf("                          �Ƕ�������ʽЧ�ʱȽϣ��ÿ��١�ð�ݡ�����\n");
		printf("                                                  ���ַ�ʽ�����ݽ������򲢽�\n");
		printf("                                                  ����ʱ���ڿ���̨�����\n\n");
		printf("     3�����¹��ܣ�������ѡ������������ý���滻ԭ�ļ��������Ϊ���ļ����ļ���\n");
		printf("                  Ĭ��Ϊ:'sortedInfo.txt'�������ڵ�ǰ·���¡���Ҳ����ѡ�񲻶�\n");
		printf("                  ���������д���\n\n");
		printf("     4��������һ���������������к����Ĳ���������ѡ��˹��ܷ��ع���ѡ����棻\n");
		printf("------------------------------------------------------------------------------\n\n");

	}

	return 0;
}


int SearchHelp(int SearchHelpChoose)
{
	int choose = SearchHelpChoose;
	if(CHINESE == choose)
	{
		
		printf("\n---------------------------------��  ��---------------------------------------\n");
		printf("һ�������飺\n");
		printf("        ������Ϊϵͳ�еļ�������ѡ����棬����������ȡ������Ҫ���ļ�֮����\n");
		printf("    ��ؼ��ֶ��ļ��е����ݽ��м������õ���Ӧ�ļ��������\n\n");
		printf("�������ܼ�飺\n");
		printf("    1��ѡ�������׼��������ѡ������linkID����·������·���Ż��ߵ�·��������\n");
		printf("                     �Ĺؼ��ֽ��м�����\n\n");
		printf("    2��ѡ�������ʽ��Ϊ���ṩ��˳����Һ��۰����������Ҫ�Ĳ��ҷ�ʽ\n");                    
		printf("    3��������������������С�����������ڿ���̨Ϊ��������������������\n");
		printf("                 ���������������ļ�����ʽΪ�������ڵ�ǰ·���£�Ĭ���ļ���Ϊ\n");
		printf("                 'result.txt';\n\n");
		printf("    4��������һ��:�����������к����Ĳ���������ѡ��˹��ܷ��ع���ѡ�����;\n");
		printf("------------------------------------------------------------------------------\n\n");
	
	}
	return 0;
}


int OptionHelp(int OptionHelpChoose)
{
	int choose = OptionHelpChoose;
	if(CHINESE == choose)
	{
		
		printf("\n---------------------------------��  ��---------------------------------------\n");
		printf("     һ�������飺\n");
		printf("             ������Ϊϵͳ�еĹ���ѡ����棬����������ȡ������Ҫ���ļ�֮��ѡ��\n");
		printf("         ����Ҫ�Ĳ������ļ��е����ݽ��д����õ��Լ���Ҫ���������������\n");
		printf("     �������ܼ�飺\n");
		printf("         1����ȡ���ļ����ܣ������������Ѵ򿪵��ļ����б༭�Ļ��������´�\n");
		printf("         2�������ܣ����Ѵ򿪵��ļ��е����ݰ����û���Ҫ�ı�׼��������\n");
		printf("         3���������ܣ����Ѵ򿪵��ļ��е����ݰ����û���Ҫ�ı�׼���м�����������\n");
		printf("         4���˳����ܣ����������������к�����������ѡ�˹�����ʱ�˳�ϵͳ\n");
		printf("------------------------------------------------------------------------------\n\n");
	}


	return 0;
}



int SearchFace(int SearchFaceChoose)
{

	char* SearchChoose[16][1] = {"   ��ӭ����������ܽ���   ",
								"��ѡ������Ҫ�Ĺ���",
								"ָ����·���Ƽ���",
								"ָ�����Ҳ�·������",
								"ָ������Link�б�ʾclass���ż���",
								"ָ��LinkID����",
								"������һ���˵�",
								"����",
								"��������ѡ��Ĺ���ǰ�����ִ���",
								"���������ṩ��ѡ����ѡ��",
								"������������ѡ��Ĺ���ǰ�����ִ���",
								"��ѡ������Ҫ�Ĺ���",
								"��˳����ҷ�ʽ����",
								"���۰���ҷ�ʽ����",
								"��������������ʽ����",
								"����������Ҫ�����Ĺؼ���",
								};
	
	int choose = SearchFaceChoose;
	int TypeChoose;
	int MethodChoose;
	void ChooseFunction(int LanChoose);
	int SequenceSearch(RoadArray_t rdArray, int searchType , int choose);
	int BinarySearch(RoadArray_t rdArray, int searchType , int choose);
    int TreeSearch(TreeNode_t* pNode , int choose);
    
	printf("------------------------------------------------------------------------------\n");
	printf("/****************************************************************************/\n");
	printf("/************************ %s ************************/\n",SearchChoose[0][choose]);
	printf("/****************************************************************************/\n\n");
	printf("       %s��\n\n",SearchChoose[1][choose]);
	printf("               [1]%s��\n",SearchChoose[2][choose]);
	printf("               [2]%s��\n",SearchChoose[3][choose]);
	printf("               [3]%s��\n",SearchChoose[4][choose]);
	printf("               [4]%s��\n",SearchChoose[5][choose]);
	printf("               [5]%s��\n",SearchChoose[6][choose]);
	printf("               [6]%s��\n\n",SearchChoose[7][choose]);
	printf("       %s��",SearchChoose[8][choose]);
	scanf("%d" , &TypeChoose);
	fflush(stdin);
	while(1 != TypeChoose && 2 != TypeChoose && 3 != TypeChoose && 4 != TypeChoose && 5 != TypeChoose && 6 != TypeChoose)
	{
		printf("\n");
		printf("       %s!\n\n",SearchChoose[9][choose]);
		printf("       %s:",SearchChoose[10][choose]);
		scanf("%d",&TypeChoose);
		fflush(stdin);
	}

	if(5 == TypeChoose)
	{
		printf("--------------------------------------------------------------------------\n\n");
		system("pause");
		system("cls"); 
		PrintHeadFunction();
		ChooseFunction(choose);
	}
	else if(6 == TypeChoose)
	{
		SearchHelp(choose);
		fflush(stdin);
		system("pause");
		system("cls"); 
		PrintHeadFunction();
		SearchFace(choose);
	}
	else if(1 == TypeChoose)
	{
		printf("       %s��\n\n",SearchChoose[11][choose]);
		printf("               [1]%s��\n",SearchChoose[12][choose]);
		printf("               [2]%s��\n",SearchChoose[13][choose]);
		printf("               [3]%s��\n\n",SearchChoose[6][choose]);
		printf("       %s:",SearchChoose[8][choose]);
		scanf("%d" , &MethodChoose);
		fflush(stdin);

		while(1 != MethodChoose && 2 != MethodChoose && 3 != MethodChoose && 4 != MethodChoose)
		{
			printf("\n");
			printf("       %s!\n\n",SearchChoose[9][choose]);
			printf("       %s:",SearchChoose[10][choose]);
			scanf("%d" , &MethodChoose);
			fflush(stdin);
		}

		switch(MethodChoose)
		{
			case 1:
				printf("       %s��",SearchChoose[15][choose]);
				SequenceSearch(*stRL, TYPE_ID , choose); 
				printf("--------------------------------------------------------------------------\n\n");
				system("pause");
				system("cls"); 
				PrintHeadFunction();
				ChooseFunction(choose);
				break;
			case 2:
				printf("       %s��",SearchChoose[15][choose]);
				BinarySearch(*stRL, TYPE_ID , choose);
				printf("--------------------------------------------------------------------------\n\n");
				system("pause");
				system("cls"); 
				PrintHeadFunction();
				ChooseFunction(choose);
				break;
			case 3:
				printf("\n���ڽ����������Ժ�The tree is building.Please wait.��......\n\n");
				printf("       %s��",SearchChoose[15][choose]);
				readToTree(&pNode, stRL);
				TreeSearch(pNode,choose);
				printf("--------------------------------------------------------------------------\n\n");
				system("pause");
				system("cls"); 
				PrintHeadFunction();
				ChooseFunction(choose);
				break;
			case 4:
				printf("--------------------------------------------------------------------------\n\n");
				system("pause");
				system("cls"); 
				PrintHeadFunction();
				ChooseFunction(choose);
				break;
			default:
				break;
		}
	}
	else
	{
		printf("       %s��\n\n",SearchChoose[11][choose]);
		printf("               [1]%s��\n",SearchChoose[12][choose]);
		printf("               [2]%s��\n",SearchChoose[13][choose]);
		printf("               [3]%s��\n\n",SearchChoose[6][choose]);
		printf("       %s:",SearchChoose[8][choose]);
		scanf("%d" , &MethodChoose);
		fflush(stdin);

		while(1 != MethodChoose && 2 != MethodChoose && 3 != MethodChoose)
		{
			printf("\n");
			printf("       %s!\n\n",SearchChoose[9][choose]);
			printf("       %s:",SearchChoose[10][choose]);
			scanf("%d" , &MethodChoose);
			fflush(stdin);
		}

		switch(MethodChoose)
		{
			case 1:
				switch(TypeChoose)
				{
					case 2:
						printf("       %s��",SearchChoose[15][choose]);
						SequenceSearch(*stRL, TYPE_BRUNCH,choose);
						printf("--------------------------------------------------------------------------\n\n");
						system("pause");
						system("cls"); 
						PrintHeadFunction();
						ChooseFunction(choose);
						break;
					case 3:
						printf("       %s��",SearchChoose[15][choose]);
						SequenceSearch(*stRL, TYPE_CLASSNO,choose);
						printf("--------------------------------------------------------------------------\n\n");
						system("pause");
						system("cls"); 
						PrintHeadFunction();
						ChooseFunction(choose);
						break;
					case 4:
						printf("       %s��",SearchChoose[15][choose]);
						SequenceSearch(*stRL, TYPE_NAME,choose);
						printf("--------------------------------------------------------------------------\n\n");
						system("pause");
						system("cls"); 
						PrintHeadFunction();
						ChooseFunction(choose);
						break;
					default:
						break;
				}
				printf("--------------------------------------------------------------------------\n\n");
				system("pause");
				system("cls"); 
				PrintHeadFunction();
				ChooseFunction(choose);
				break;
			case 2:
				switch(TypeChoose)
				{
					case 2:
						printf("       %s��",SearchChoose[15][choose]);
						BinarySearch(*stRL, TYPE_BRUNCH,choose);
						printf("--------------------------------------------------------------------------\n\n");
						system("pause");
						system("cls"); 
						PrintHeadFunction();
						ChooseFunction(choose);
						break;
					case 3:
						printf("       %s��",SearchChoose[15][choose]);
						BinarySearch(*stRL, TYPE_CLASSNO,choose);
						printf("--------------------------------------------------------------------------\n\n");
						system("pause");
						system("cls"); 
						PrintHeadFunction();
						ChooseFunction(choose);
						break;
					case 4:
						printf("       %s��",SearchChoose[15][choose]);
						BinarySearch(*stRL, TYPE_NAME , choose);
						printf("--------------------------------------------------------------------------\n\n");
						system("pause");
						system("cls"); 
						PrintHeadFunction();
						ChooseFunction(choose);
						break;
					default:
						break;
				}
				printf("--------------------------------------------------------------------------\n\n");
				system("pause");
				system("cls"); 
				PrintHeadFunction();
				ChooseFunction(choose);
				break;
			case 3:
				printf("--------------------------------------------------------------------------\n\n");
				system("pause");
				system("cls"); 
				PrintHeadFunction();
				ChooseFunction(choose);
				break;
			default:
				break;
		}

	}

	return 0;
}


int SortFace(int SortChoose)
{
	char* SortFaceChoose[27][1] = {"  ��ӭ���������ܽ���  ",
									"��ѡ������Ҫ�Ĺ���",
									"����·�������",
									"����·������",
									"����·��������",
									"����·��������",
									"������һ���˵�",
									"����",
									"��������ѡ��Ĺ���ǰ�����ִ���",
									"���������ṩ��ѡ����ѡ��",
									"������������ѡ��Ĺ���ǰ�����ִ���",
									"��Ĭ�Ϸ�ʽ����(��������)",
									"���Զ��巽ʽ����",
									"���ַ���������ʱ��",
									"��ѡ���Զ�������ʽ",
									"��������",
									"ð������",
									"��������",
									"������",
									"ѡ������",
									"��������ѡ�������ʽǰ�����ֱ��",
									"���ڽ������������Ժ�",
									"����ѡ����������Ĳ���",
									"����ԭ�ļ�",
									"���Ϊ���ļ�",
									"�����в���",
									"��������ѡ��Ĳ���ǰ�����ֱ��",
									};
	int TypeChoose;
	void ChooseFunction(int LanChoose);
	int MethodChoose;
	int OtherMethod;
	int ResultDeal;
	int choose = SortChoose;

	printf("------------------------------------------------------------------------------\n");
	printf("/****************************************************************************/\n");
	printf("/************************* %s *************************/\n",SortFaceChoose[0][choose]);
	printf("/****************************************************************************/\n\n");

    printf("       %s��\n\n",SortFaceChoose[1][choose]);
	printf("               [1]%s��\n",SortFaceChoose[2][choose]);
	printf("               [2]%s��\n",SortFaceChoose[3][choose]);
	printf("               [3]%s��\n",SortFaceChoose[4][choose]);
	printf("               [4]%s��\n",SortFaceChoose[5][choose]);
	printf("               [5]%s��\n",SortFaceChoose[6][choose]);
	printf("               [6]%s��\n\n",SortFaceChoose[7][choose]);
	printf("       %s��",SortFaceChoose[8][choose]);
	scanf("%d" , &TypeChoose);
	fflush(stdin);

	while(1 != TypeChoose && 2 != TypeChoose && 3 != TypeChoose && 4 != TypeChoose && 5 != TypeChoose && 6 != TypeChoose)
	{
		printf("\n");
		printf("       %s!\n\n",SortFaceChoose[9][choose]);
		printf("       %s:",SortFaceChoose[10][choose]);
		scanf("%d",&TypeChoose);
		fflush(stdin);
	}

	if(5 == TypeChoose)
	{
		printf("--------------------------------------------------------------------------\n\n");
		system("pause");
		system("cls"); 
		PrintHeadFunction();
		ChooseFunction(choose);
	}
	else if(6 == TypeChoose)
	{
		SortHelp(choose);
		fflush(stdin);
		system("pause");
		system("cls"); 
		PrintHeadFunction();
		SortFace(choose);
	}
	else
	{
		printf("\n");
		printf("       %s��\n\n",SortFaceChoose[1][choose]);
		printf("               [1]%s��\n",SortFaceChoose[11][choose]);
		printf("               [2]%s��\n",SortFaceChoose[12][choose]);
		printf("               [3]%s��\n",SortFaceChoose[13][choose]);
		printf("               [4]%s��\n\n",SortFaceChoose[6][choose]);
		printf("       %s��",SortFaceChoose[8][choose]);
		scanf("%d" , &MethodChoose);
		fflush(stdin);

		while(1 != MethodChoose && 2 != MethodChoose && 3 != MethodChoose && 4 != MethodChoose)
		{
			printf("\n");
			printf("       %s!\n\n",SortFaceChoose[9][choose]);
			printf("       %s:",SortFaceChoose[10][choose]);
			scanf("%d" , &MethodChoose);
			fflush(stdin);
		}

		switch(MethodChoose)
		{
			case 1:
				printf("\n");
				printf("       %s......\n",SortFaceChoose[21][choose]);
				switch(TypeChoose)
				{
					case 1:
						TimeOfQuickSort(stRL , TYPE_ID);	
						break;
					case 2:
						TimeOfQuickSort(stRL , TYPE_BRUNCH);
						break;
					case 3:
						TimeOfQuickSort(stRL , TYPE_CLASSNO);
						break;
					case 4:
						TimeOfQuickSort(stRL , TYPE_NAME);
					default:
						break;
				}
				break;
			case 2:
				switch(TypeChoose)
				{
					case 1:
						printf("\n");
						printf("       %s��\n\n",SortFaceChoose[14][choose]);
						printf("               [1]%s��\n",SortFaceChoose[15][choose]);
						printf("               [2]%s��\n",SortFaceChoose[16][choose]);
						printf("               [3]%s��\n",SortFaceChoose[17][choose]);
						printf("               [4]%s��\n",SortFaceChoose[18][choose]);
						printf("               [5]%s��\n\n",SortFaceChoose[19][choose]);
						printf("       %s��",SortFaceChoose[20][choose]);
						scanf("%d" , &OtherMethod);
						fflush(stdin);

						while(1 != OtherMethod && 2 != OtherMethod && 3 != OtherMethod && 4 != OtherMethod && 5 != OtherMethod)
						{
							printf("\n");
							printf("       %s!\n\n",SortFaceChoose[9][choose]);
							printf("       %s:",SortFaceChoose[10][choose]);
							scanf("%d" , &OtherMethod);
							fflush(stdin);
						}

						printf("\n");
						printf("       %s......\n",SortFaceChoose[21][choose]);
						switch(OtherMethod)
						{
							case 1:
								TimeOfQuickSort(stRL , TYPE_ID);
								break;
							case 2:
								TimeOfBubbleSort(stRL , TYPE_ID);
								break;
							case 3:
								TimeOfInsertionSort(stRL , TYPE_ID);
								break;
							case 4:
								TimeOfHeapSort(stRL , TYPE_ID);
								break;
							case 5:
							    TimeOfTreeSort(&pNode,stRL);
								break;
							default:
								break;
						}
						break;
					case 2:
						printf("\n");
						printf("       %s��\n\n",SortFaceChoose[14][choose]);
						printf("               [1]%s��\n",SortFaceChoose[15][choose]);
						printf("               [2]%s��\n",SortFaceChoose[16][choose]);
						printf("               [3]%s��\n",SortFaceChoose[17][choose]);
						printf("               [4]%s��\n",SortFaceChoose[18][choose]);
						printf("       %s��",SortFaceChoose[20][choose]);
						scanf("%d" , &OtherMethod);
						fflush(stdin);

						while(1 != OtherMethod && 2 != OtherMethod && 3 != OtherMethod && 4 != OtherMethod)
						{
							printf("\n");
							printf("       %s!\n\n",SortFaceChoose[9][choose]);
							printf("       %s:",SortFaceChoose[10][choose]);
							scanf("%d" , &OtherMethod);
							fflush(stdin);
						}

						printf("\n");
						printf("       %s......\n",SortFaceChoose[21][choose]);
						switch(OtherMethod)
						{
							case 1:
								TimeOfQuickSort(stRL , TYPE_BRUNCH);
								break;
							case 2:
								TimeOfBubbleSort(stRL , TYPE_BRUNCH);
								break;
							case 3:
								TimeOfInsertionSort(stRL , TYPE_BRUNCH);
								break;
							case 4:
								TimeOfHeapSort(stRL , TYPE_BRUNCH);
								break;
							default:
								break;
						}
						break;
					case 3:
						printf("\n");
						printf("       %s��\n\n",SortFaceChoose[14][choose]);
						printf("               [1]%s��\n",SortFaceChoose[15][choose]);
						printf("               [2]%s��\n",SortFaceChoose[16][choose]);
						printf("               [3]%s��\n",SortFaceChoose[17][choose]);
						printf("               [4]%s��\n",SortFaceChoose[18][choose]);
						printf("       %s��",SortFaceChoose[20][choose]);
						scanf("%d" , &OtherMethod);
						fflush(stdin);

						while(1 != OtherMethod && 2 != OtherMethod && 3 != OtherMethod && 4 != OtherMethod)
						{
							printf("\n");
							printf("       %s!\n\n",SortFaceChoose[9][choose]);
							printf("       %s:",SortFaceChoose[10][choose]);
							scanf("%d" , &OtherMethod);
							fflush(stdin);
						}

						printf("\n");
						printf("       %s......\n",SortFaceChoose[21][choose]);
						switch(OtherMethod)
						{
							case 1:
								TimeOfQuickSort(stRL , TYPE_CLASSNO);
								break;
							case 2:
								TimeOfBubbleSort(stRL , TYPE_CLASSNO);
								break;
							case 3:
								TimeOfInsertionSort(stRL , TYPE_CLASSNO);
								break;
							case 4:
								TimeOfHeapSort(stRL , TYPE_CLASSNO);
								break;
							default:
								break;
						}
						break;
					case 4:
							printf("\n");
							printf("       %s��\n\n",SortFaceChoose[14][choose]);
							printf("               [1]%s��\n",SortFaceChoose[15][choose]);
							printf("               [2]%s��\n",SortFaceChoose[16][choose]);
							printf("               [3]%s��\n",SortFaceChoose[17][choose]);
							printf("               [4]%s��\n",SortFaceChoose[18][choose]);
							printf("       %s��",SortFaceChoose[20][choose]);
							scanf("%d" , &OtherMethod);
							fflush(stdin);

							while(1 != OtherMethod && 2 != OtherMethod && 3 != OtherMethod && 4 != OtherMethod)
							{
								printf("\n");
								printf("       %s!\n\n",SortFaceChoose[9][choose]);
								printf("       %s:",SortFaceChoose[10][choose]);
								scanf("%d" , &OtherMethod);
								fflush(stdin);
							}

							printf("\n");
							printf("       %s......\n",SortFaceChoose[21][choose]);
							switch(OtherMethod)
							{
								case 1:
									TimeOfQuickSort(stRL , TYPE_NAME);
									break;
								case 2:
									TimeOfBubbleSort(stRL , TYPE_NAME);
									break;
								case 3:
									TimeOfInsertionSort(stRL , TYPE_NAME);
									break;
								case 4:
									TimeOfHeapSort(stRL , TYPE_NAME);
									break;
								default:
									break;
							}
							break;
					default:
						break;
				}
				break;
			case 3:
				TimeComp(stRL,FilePath,(TypeChoose - 1));
				break;
			case 4:
				printf("--------------------------------------------------------------------------\n\n");
				system("pause");
				system("cls"); 
				PrintHeadFunction();
				ChooseFunction(choose);
				break;
			default:
				break;
		}
	}

	if(3 == MethodChoose)
	{
		system("pause");
		system("cls"); 
		PrintHeadFunction();
		ChooseFunction(choose);
	}
	else
	{
		printf("       %s��\n\n",SortFaceChoose[22][choose]);
		printf("               [1]%s��\n",SortFaceChoose[23][choose]);
		printf("               [2]%s��\n",SortFaceChoose[24][choose]);
		printf("               [3]%s��\n\n",SortFaceChoose[25][choose]);
		printf("       %s��",SortFaceChoose[26][choose]);
		scanf("%d" , &ResultDeal);
		fflush(stdin);

		while(1 != ResultDeal && 2 != ResultDeal && 3 != ResultDeal)
		{
			printf("\n");
			printf("       %s!\n\n",SortFaceChoose[9][choose]);
			printf("       %s:",SortFaceChoose[10][choose]);
			scanf("%d" , &ResultDeal);
			fflush(stdin);
		}

		switch(ResultDeal)
		{
			case 1:
				if(5 == OtherMethod)
				{
					
					writeFromTree("GTBL.dat", &pNode);
					printf("--------------------------------------------------------------------------\n\n");
					system("pause");
					system("cls"); 
					PrintHeadFunction();
					ChooseFunction(choose);
				}
				else
				{
					writeFromArray("GTBL.dat", stRL);
					printf("--------------------------------------------------------------------------\n\n");
					system("pause");
					system("cls"); 
					PrintHeadFunction();
					ChooseFunction(choose);
				}
			case 2:
				if(5 == OtherMethod)
				{
					writeFromTree(FILENAME, &pNode);
					printf("--------------------------------------------------------------------------\n\n");
					system("pause");
					system("cls"); 
					PrintHeadFunction();
					ChooseFunction(choose);
				}
				else
				{		
					writeFromArray(FILENAME, stRL);
					printf("--------------------------------------------------------------------------\n\n");
					system("pause");
					system("cls"); 
					PrintHeadFunction();
					ChooseFunction(choose);
				}
				break;
			case 3:
				printf("--------------------------------------------------------------------------\n\n");
				system("pause");
				system("cls"); 
				PrintHeadFunction();
				ChooseFunction(choose);
				break;
			default:
				break;
		}
	}

	return 0;
}


void ChooseFunction(int LanChoose)
{
	char* Choose[10][1] = {"  �� ӭ �� �� �� �� ѡ �� �� ��  ",
						"����ѡ������Ҫ�Ĺ���",
						"��ȡ���ļ�",
						"������",
						"��������",
						"����",
						"�˳�",
						"��������ѡ��Ĺ���ǰ�����ֱ��",
						"���������ṩ��ѡ����ѡ��",
						"������������ѡ��Ĳ���ǰ�����ִ���",
						};	

	int Language = LanChoose;
	int OptionChoose;
	int ReadFileFace(int FileFaceChoose);

	printf("------------------------------------------------------------------------------\n");
	printf("/****************************************************************************/\n");
	printf("/********************* %s ********************/\n",Choose[0][Language]);
	printf("/****************************************************************************/\n\n");
		
	printf("       %s��\n\n",Choose[1][Language]);
	printf("               [1]%s��\n",Choose[2][Language]);
	printf("               [2]%s��\n",Choose[3][Language]);
	printf("               [3]%s��\n",Choose[4][Language]);
	printf("               [4]%s��\n",Choose[5][Language]);
	printf("               [5]%s��\n\n",Choose[6][Language]);
	printf("       %s��",Choose[7][Language]);
	scanf("%d" , &OptionChoose);
	fflush(stdin);
		
	while(1 != OptionChoose && 2 != OptionChoose && 3 != OptionChoose && 4 != OptionChoose && 5 != OptionChoose)
	{
		printf("\n");
		printf("       %s!\n\n",Choose[8][Language]);
		printf("       %s:",Choose[9][Language]);
		scanf("%d",&OptionChoose);
		fflush(stdin);
	}
		
	if(1 == OptionChoose)
	{
		system("cls"); 
		PrintHeadFunction();
		ReadFileFace(Language);
	}
	else if(2 == OptionChoose)
	{
		system("cls"); 
		PrintHeadFunction();
		SortFace(Language);
	}
	else if(3 == OptionChoose)
	{
		system("cls"); 
		PrintHeadFunction();
		SearchFace(Language);
	}
	else if(4 == OptionChoose)
	{
		OptionHelp(Language);
		system("pause");
		system("cls"); 
		PrintHeadFunction();
		ChooseFunction(Language);
	}
	else
	{
		ExitFunction();
	}
}
void ReadFile(char* filename,int ReadChoose)
{
	char* ReadFileLan[10][1] ={"�������ļ�·��",
								"�Բ��𣬳�����",
								"��������ļ�·������ȷ�����ļ������ڣ�����",
								"����ѡ����һ���Ĳ���",
								"���������ļ�·��",
								"�˳�����",
								"��������ѡ��Ĳ���ǰ�����ִ���",
								"���������ṩ��ѡ����ѡ��",
								"������������ѡ��Ĳ���ǰ�����ִ���",
								"������һ���˵�",
								};
	FILE *fp; 
	int OptionChoose;
	int choose = ReadChoose;
	int ReadFileFace(int FileFaceChoose);

	printf("       %s:",ReadFileLan[0][choose]); 
	gets(filename); 

	if(0 == strcmp(filename,"") || (fp = fopen(filename , "r")) == NULL) 
	{ 
		printf("\n");
		printf("       %s��\n       %s��\n\n",ReadFileLan[1][choose],ReadFileLan[2][choose]);
		printf("       %s:\n\n",ReadFileLan[3][choose]);
		printf("               [1]%s��\n",ReadFileLan[4][choose]);
		printf("               [2]%s��\n",ReadFileLan[9][choose]);
		printf("               [3]%s��\n\n",ReadFileLan[5][choose]);
		printf("       %s:",ReadFileLan[6][choose]);
		scanf("%d" , &OptionChoose);
		fflush(stdin);

		while(1 != OptionChoose && 2 != OptionChoose && 3 != OptionChoose)
		{
			printf("\n");
			printf("       %s!\n\n",ReadFileLan[7][choose]);
			printf("       %s��",ReadFileLan[8][choose]);
			scanf("%d",&OptionChoose);
			fflush(stdin);
		}

		if(1 == OptionChoose)
		{
			ReadFile(filename,choose);
		}
		else if(2 == OptionChoose)
		{
			system("cls"); 
			PrintHeadFunction();
			ReadFileFace(choose);
		}
		else
		{
			ExitFunction();
		}
	}

	FilePath = filename;
	
	if(fp != NULL)
	{
		fclose(fp);
	}
}


int ReadFileFace(int FileFaceChoose)
{
	char* ReadFileChoose[14][1] = {"    �� ӭ �� �� �� �� �� ȡ �� ��   ",
									"��ѡ����Ҫ��ȡ���ļ�·��",
									"Ĭ��·����ȡ",
									"�Զ���·����ȡ",
									"����(Return)",
									"��������ѡ��Ĳ���ǰ�����ִ���",
									"���������ṩ��ѡ����ѡ��",
									"������������ѡ���·��ǰ�����ִ���",
									"�Բ��𣬳�����",
									"�ļ���ʧ�ܻ�����ռ䲻��",
									"����ѡ����һ���Ĳ���",
									"���������ļ�·��",
									"������һ���˵�",
									"�˳�����",
									};
	int choose = FileFaceChoose;
	int PathChoose;
	char* FileName;
	int ReadResult;
	int OptionChoose;
	int ChooseLan();

	printf("------------------------------------------------------------------------------\n");
	printf("/****************************************************************************/\n");
	printf("/******************* %s *******************/\n",ReadFileChoose[0][choose]);
	printf("/****************************************************************************/\n\n");
	printf("       %s��\n\n",ReadFileChoose[1][choose]);
	printf("               [1]%s;\n",ReadFileChoose[2][choose]);
	printf("               [2]%s;\n",ReadFileChoose[3][choose]);
	printf("               [3]%s;\n\n",ReadFileChoose[4][choose]);
	printf("       %s:",ReadFileChoose[5][choose]);
	scanf("%d",&PathChoose);
	fflush(stdin);

	while(1 != PathChoose && 2 != PathChoose && 3 != PathChoose)
	{
		printf("\n");
		printf("       %s!\n\n",ReadFileChoose[6][choose]);
		printf("       %s:",ReadFileChoose[7][choose]);
		scanf("%d",&PathChoose);
		fflush(stdin);
	}

	if(1 == PathChoose)
	{
		FilePath = PATH;                        
	    ReadResult = readToArray (FilePath, stRL); 
		if(1 == ReadResult)
		{
			printf("\n�ļ� %s ��ȡ�ɹ���Successfully read file %s��!\n", FilePath,FilePath);
			system("pause");
			system("cls"); 
			PrintHeadFunction();
			ChooseFunction(choose);
		}
		else
		{
			printf("       %s��\n       %s��\n\n",ReadFileChoose[8][choose],ReadFileChoose[9][choose]);
			printf("       %s:\n\n",ReadFileChoose[10][choose]);
			printf("               [1]%s��\n",ReadFileChoose[11][choose]);
			printf("               [2]%s��\n",ReadFileChoose[12][choose]);
			printf("               [3]%s��\n\n",ReadFileChoose[13][choose]);
			printf("       %s:",ReadFileChoose[5][choose]);
			scanf("%d" , &OptionChoose);
			fflush(stdin);

			while(1 != OptionChoose && 2 != OptionChoose && 3 != OptionChoose)
			{
				printf("\n");
				printf("       %s!\n\n",ReadFileChoose[6][choose]);
				printf("       %s��",ReadFileChoose[7][choose]);
				scanf("%d",&OptionChoose);
				fflush(stdin);
			}

			if(1 == OptionChoose)
			{
				ReadFileFace(choose);
			}
			else if(2 == OptionChoose)
			{
				ReadFileFace(choose);
			}
			else
			{
				ExitFunction();
			}
		}
	}
	else if(2 == PathChoose)
	{
		FileName = (char*)malloc(20 * sizeof(char));
        ReadFile(FileName,choose);
		
		printf("--------------------------------------------------------------------------\n\n");
		printf("\n�ļ� %s ��ȡ�ɹ���Successfully read file %s��!\n", FileName,FileName);
		system("pause");
		system("cls"); 
		PrintHeadFunction();
		ReadResult = readToArray (FilePath, stRL);

		if(1 == ReadResult)
		{
			ChooseFunction(choose);
		}
		else
		{
			printf("       %s��\n       %s��\n\n",ReadFileChoose[8][choose],ReadFileChoose[9][choose]);
			printf("       %s:\n\n",ReadFileChoose[10][choose]);
			printf("               [1]%s��\n",ReadFileChoose[11][choose]);
			printf("               [2]%s��\n\n",ReadFileChoose[13][choose]);
			printf("       %s:",ReadFileChoose[5][choose]);
			scanf("%d" , &OptionChoose);
			fflush(stdin);

			while(1 != OptionChoose && 2 != OptionChoose)
			{
				printf("\n");
				printf("       %s!\n\n",ReadFileChoose[6][choose]);
				printf("       %s��",ReadFileChoose[7][choose]);
				scanf("%d",&OptionChoose);
				fflush(stdin);
			}

			if(1 == OptionChoose)
			{
				ReadFileFace(choose);
			}
			else
			{
				ExitFunction();
			}
		}
	}
	else
	{
		system("cls"); 
		PrintHeadFunction();
		ChooseLan();
	}

	return 0;
}
int ChooseLan()
{
	int LanChoose = 0;
    fflush(stdin);
		system("cls"); 
		PrintHeadFunction();
		ReadFileFace(0);	
	return 0;
}
int main()
{   
	system("color  1A");
    stRL = (RoadArray_t*)malloc(sizeof(RoadArray_t));
	pNode = (TreeNode_t*)malloc(sizeof(TreeNode_t));
	stRL->roadMsgs = NULL;
	PrintHeadFunction();
	ChooseLan();

	return 0;
}
