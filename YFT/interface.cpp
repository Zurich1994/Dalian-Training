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
** Description:        页面设计及美化                                                                    *
** Author:            闫毓麟                                                                             *
*********************************************************************************************************/

void PrintHeadFunction()
{
	
	printf("/************************ 欢迎使用! Welcome to use! *************************/\n");
	printf("/*****                                                                  *****/\n");
	printf("/*****                                                                  *****/\n");
	printf("/*****                        电子地图管理系统                          *****/\n");
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
	printf("/*****                   版本号（Version）：sh*t 2.0                    *****/\n");
	printf("/*****                   开发者（Developer）：中国好组                  *****/\n");
	printf("/*****                   最终完成日期（Date）：2013-07-31               *****/\n");
	printf("/****************************************************************************/\n\n");

}


void ExitFunction()
{   
	printf("******************************************************************************\n");
	printf("******                               |||3|||                            ******\n");
    printf("******                              |||345|||                           ******\n");
	printf("******                ;            (　.@.@　)               ;           ******\n");
    printf("******                ;-------oOOo-----(_)-----oOOo---------;           ******\n");
    printf("******                ;　　　   中国好组感谢您的使用!　　　 ;           ******\n"); 
    printf("******                ;　    　                       　  　;           ******\n");
    printf("******                ;　　Thank you for using the system!  ;           ******\n");
    printf("******                ;　　　　　　　　　　　　　　　　 　　;           ******\n");
	printf("******                ;　　　　　Bye!      Bye!　 　　      ;           ******\n");
	printf("******                ;---------------------Oooo------------;           ******\n");
	printf("******                                                                  ******\n");                               
	printf("******************************************************************************\n");
	printf("程序即将关闭(Closing)......\n");
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

		printf("\n---------------------------------帮  助---------------------------------------\n");
		printf("一、界面简介：\n");
		printf("        本界面为系统中的排序功能选择界面，用于在您读取完所需要的文件之后选\n");
		printf("    择所需要的方式对文件中的数据进行排序，得到相应的排序结果。\n\n");
		printf("二、功能简介：\n");
		printf("    1、选择排序标准：您可以选择根据linkID、岔路数、道路番号或者道路名称对数\n");
		printf("                     据进行排序；\n\n");
		printf("    2、选择排序方式：为您提供了默认方式、自定义方式和多种排序方式效率比较，\n");
		printf("                     三种排序方式：\n\n");
		printf("                          ⑴默认方式：如果您对各种排序方式并不了解，推荐您选\n");
		printf("                                      择此方式，默认用快速排序的方式为您排序;\n\n");
		printf("                          ⑵自定义方式：为您提供了快速排序、冒泡排序、插入排\n");
		printf("                                        序三种主要的排序方式供您选择。\n");
		printf("                                        排序结束后为您输出排序所用时间；\n\n");
		printf("                          ⑶多种排序方式效率比较：用快速、冒泡、插入\n");
		printf("                                                  三种方式对数据进行排序并将\n");
		printf("                                                  所用时间在控制台输出；\n\n");
		printf("     3、更新功能：您可以选择用排序后所得结果替换原文件或者另存为新文件，文件名\n");
		printf("                  默认为:'sortedInfo.txt'，保存在当前路径下。您也可以选择不对\n");
		printf("                  排序结果进行处理；\n\n");
		printf("     4、返回上一级：如果您不想进行后续的操作，可以选择此功能返回功能选择界面；\n");
		printf("------------------------------------------------------------------------------\n\n");

	}

	return 0;
}


int SearchHelp(int SearchHelpChoose)
{
	int choose = SearchHelpChoose;
	if(CHINESE == choose)
	{
		
		printf("\n---------------------------------帮  助---------------------------------------\n");
		printf("一、界面简介：\n");
		printf("        本界面为系统中的检索功能选择界面，用于在您读取完所需要的文件之后输\n");
		printf("    入关键字对文件中的数据进行检索，得到相应的检索结果。\n\n");
		printf("二、功能简介：\n");
		printf("    1、选择检索标准：您可以选择输入linkID、岔路数、道路番号或者道路名称类型\n");
		printf("                     的关键字进行检索；\n\n");
		printf("    2、选择检索方式：为您提供了顺序查找和折半查找两种主要的查找方式\n");                    
		printf("    3、结果输出：如果检索结果小于五条，则在控制台为您输出结果，如果结果大于\n");
		printf("                 等于五条，则以文件的形式为您保存在当前路径下，默认文件名为\n");
		printf("                 'result.txt';\n\n");
		printf("    4、返回上一级:如果您不想进行后续的操作，可以选择此功能返回功能选择界面;\n");
		printf("------------------------------------------------------------------------------\n\n");
	
	}
	return 0;
}


int OptionHelp(int OptionHelpChoose)
{
	int choose = OptionHelpChoose;
	if(CHINESE == choose)
	{
		
		printf("\n---------------------------------帮  助---------------------------------------\n");
		printf("     一、界面简介：\n");
		printf("             本界面为系统中的功能选择界面，用于在您读取完所需要的文件之后选择\n");
		printf("         所需要的操作对文件中的数据进行处理，得到自己想要的排序或检索结果。\n");
		printf("     二、功能简介：\n");
		printf("         1、读取新文件功能：如果您不想对已打开的文件进行编辑的话可以重新打开\n");
		printf("         2、排序功能：对已打开的文件中的数据按照用户需要的标准进行排序\n");
		printf("         3、检索功能：对已打开的文件中的数据按照用户需要的标准进行检索并输出结果\n");
		printf("         4、退出功能：如果您不想继续进行后续操作可以选此功能随时退出系统\n");
		printf("------------------------------------------------------------------------------\n\n");
	}


	return 0;
}



int SearchFace(int SearchFaceChoose)
{

	char* SearchChoose[16][1] = {"   欢迎进入检索功能界面   ",
								"请选择所需要的功能",
								"指定道路名称检索",
								"指定查找岔路数检索",
								"指定交叉Link列表示class番号检索",
								"指定LinkID检索",
								"返回上一级菜单",
								"帮助",
								"请输入您选择的功能前的数字代号",
								"请您在所提供的选项中选择",
								"请重新输入您选择的功能前的数字代号",
								"请选择所需要的功能",
								"按顺序查找方式检索",
								"按折半查找方式检索",
								"按二叉树遍历方式检索",
								"请输入您所要检索的关键字",
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
	printf("       %s：\n\n",SearchChoose[1][choose]);
	printf("               [1]%s；\n",SearchChoose[2][choose]);
	printf("               [2]%s；\n",SearchChoose[3][choose]);
	printf("               [3]%s；\n",SearchChoose[4][choose]);
	printf("               [4]%s；\n",SearchChoose[5][choose]);
	printf("               [5]%s；\n",SearchChoose[6][choose]);
	printf("               [6]%s；\n\n",SearchChoose[7][choose]);
	printf("       %s：",SearchChoose[8][choose]);
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
		printf("       %s：\n\n",SearchChoose[11][choose]);
		printf("               [1]%s；\n",SearchChoose[12][choose]);
		printf("               [2]%s；\n",SearchChoose[13][choose]);
		printf("               [3]%s；\n\n",SearchChoose[6][choose]);
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
				printf("       %s：",SearchChoose[15][choose]);
				SequenceSearch(*stRL, TYPE_ID , choose); 
				printf("--------------------------------------------------------------------------\n\n");
				system("pause");
				system("cls"); 
				PrintHeadFunction();
				ChooseFunction(choose);
				break;
			case 2:
				printf("       %s：",SearchChoose[15][choose]);
				BinarySearch(*stRL, TYPE_ID , choose);
				printf("--------------------------------------------------------------------------\n\n");
				system("pause");
				system("cls"); 
				PrintHeadFunction();
				ChooseFunction(choose);
				break;
			case 3:
				printf("\n正在建树，请您稍后（The tree is building.Please wait.）......\n\n");
				printf("       %s：",SearchChoose[15][choose]);
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
		printf("       %s：\n\n",SearchChoose[11][choose]);
		printf("               [1]%s；\n",SearchChoose[12][choose]);
		printf("               [2]%s；\n",SearchChoose[13][choose]);
		printf("               [3]%s；\n\n",SearchChoose[6][choose]);
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
						printf("       %s：",SearchChoose[15][choose]);
						SequenceSearch(*stRL, TYPE_BRUNCH,choose);
						printf("--------------------------------------------------------------------------\n\n");
						system("pause");
						system("cls"); 
						PrintHeadFunction();
						ChooseFunction(choose);
						break;
					case 3:
						printf("       %s：",SearchChoose[15][choose]);
						SequenceSearch(*stRL, TYPE_CLASSNO,choose);
						printf("--------------------------------------------------------------------------\n\n");
						system("pause");
						system("cls"); 
						PrintHeadFunction();
						ChooseFunction(choose);
						break;
					case 4:
						printf("       %s：",SearchChoose[15][choose]);
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
						printf("       %s：",SearchChoose[15][choose]);
						BinarySearch(*stRL, TYPE_BRUNCH,choose);
						printf("--------------------------------------------------------------------------\n\n");
						system("pause");
						system("cls"); 
						PrintHeadFunction();
						ChooseFunction(choose);
						break;
					case 3:
						printf("       %s：",SearchChoose[15][choose]);
						BinarySearch(*stRL, TYPE_CLASSNO,choose);
						printf("--------------------------------------------------------------------------\n\n");
						system("pause");
						system("cls"); 
						PrintHeadFunction();
						ChooseFunction(choose);
						break;
					case 4:
						printf("       %s：",SearchChoose[15][choose]);
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
	char* SortFaceChoose[27][1] = {"  欢迎进入排序功能界面  ",
									"请选择所需要的功能",
									"按道路标号排序",
									"按岔路数排序",
									"按道路番号排序",
									"按道路名称排序",
									"返回上一级菜单",
									"帮助",
									"请输入您选择的功能前的数字代号",
									"请您在所提供的选项中选择",
									"请重新输入您选择的功能前的数字代号",
									"按默认方式排序(快速排序)",
									"按自定义方式排序",
									"多种方法排序算时间",
									"请选择自定义排序方式",
									"快速排序",
									"冒泡排序",
									"插入排序",
									"堆排序",
									"选择排序",
									"请输入所选择的排序方式前的数字标号",
									"正在进行排序，请您稍候",
									"请您选择对排序结果的操作",
									"覆盖原文件",
									"另存为新文件",
									"不进行操作",
									"请输入所选择的操作前的数字标号",
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

    printf("       %s：\n\n",SortFaceChoose[1][choose]);
	printf("               [1]%s；\n",SortFaceChoose[2][choose]);
	printf("               [2]%s；\n",SortFaceChoose[3][choose]);
	printf("               [3]%s；\n",SortFaceChoose[4][choose]);
	printf("               [4]%s；\n",SortFaceChoose[5][choose]);
	printf("               [5]%s；\n",SortFaceChoose[6][choose]);
	printf("               [6]%s；\n\n",SortFaceChoose[7][choose]);
	printf("       %s：",SortFaceChoose[8][choose]);
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
		printf("       %s：\n\n",SortFaceChoose[1][choose]);
		printf("               [1]%s；\n",SortFaceChoose[11][choose]);
		printf("               [2]%s；\n",SortFaceChoose[12][choose]);
		printf("               [3]%s；\n",SortFaceChoose[13][choose]);
		printf("               [4]%s；\n\n",SortFaceChoose[6][choose]);
		printf("       %s：",SortFaceChoose[8][choose]);
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
						printf("       %s：\n\n",SortFaceChoose[14][choose]);
						printf("               [1]%s；\n",SortFaceChoose[15][choose]);
						printf("               [2]%s；\n",SortFaceChoose[16][choose]);
						printf("               [3]%s；\n",SortFaceChoose[17][choose]);
						printf("               [4]%s；\n",SortFaceChoose[18][choose]);
						printf("               [5]%s；\n\n",SortFaceChoose[19][choose]);
						printf("       %s：",SortFaceChoose[20][choose]);
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
						printf("       %s：\n\n",SortFaceChoose[14][choose]);
						printf("               [1]%s；\n",SortFaceChoose[15][choose]);
						printf("               [2]%s；\n",SortFaceChoose[16][choose]);
						printf("               [3]%s；\n",SortFaceChoose[17][choose]);
						printf("               [4]%s；\n",SortFaceChoose[18][choose]);
						printf("       %s：",SortFaceChoose[20][choose]);
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
						printf("       %s：\n\n",SortFaceChoose[14][choose]);
						printf("               [1]%s；\n",SortFaceChoose[15][choose]);
						printf("               [2]%s；\n",SortFaceChoose[16][choose]);
						printf("               [3]%s；\n",SortFaceChoose[17][choose]);
						printf("               [4]%s；\n",SortFaceChoose[18][choose]);
						printf("       %s：",SortFaceChoose[20][choose]);
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
							printf("       %s：\n\n",SortFaceChoose[14][choose]);
							printf("               [1]%s；\n",SortFaceChoose[15][choose]);
							printf("               [2]%s；\n",SortFaceChoose[16][choose]);
							printf("               [3]%s；\n",SortFaceChoose[17][choose]);
							printf("               [4]%s；\n",SortFaceChoose[18][choose]);
							printf("       %s：",SortFaceChoose[20][choose]);
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
		printf("       %s：\n\n",SortFaceChoose[22][choose]);
		printf("               [1]%s；\n",SortFaceChoose[23][choose]);
		printf("               [2]%s；\n",SortFaceChoose[24][choose]);
		printf("               [3]%s；\n\n",SortFaceChoose[25][choose]);
		printf("       %s：",SortFaceChoose[26][choose]);
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
	char* Choose[10][1] = {"  欢 迎 进 入 功 能 选 择 界 面  ",
						"请您选择所需要的功能",
						"读取新文件",
						"排序功能",
						"检索功能",
						"帮助",
						"退出",
						"请输入所选择的功能前的数字标号",
						"请您在所提供的选项中选择",
						"请重新输入您选择的操作前的数字代号",
						};	

	int Language = LanChoose;
	int OptionChoose;
	int ReadFileFace(int FileFaceChoose);

	printf("------------------------------------------------------------------------------\n");
	printf("/****************************************************************************/\n");
	printf("/********************* %s ********************/\n",Choose[0][Language]);
	printf("/****************************************************************************/\n\n");
		
	printf("       %s：\n\n",Choose[1][Language]);
	printf("               [1]%s；\n",Choose[2][Language]);
	printf("               [2]%s；\n",Choose[3][Language]);
	printf("               [3]%s；\n",Choose[4][Language]);
	printf("               [4]%s；\n",Choose[5][Language]);
	printf("               [5]%s；\n\n",Choose[6][Language]);
	printf("       %s：",Choose[7][Language]);
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
	char* ReadFileLan[10][1] ={"请输入文件路径",
								"对不起，出错了",
								"您输入的文件路径不正确或者文件不存在，请检查",
								"请您选择下一步的操作",
								"重新输入文件路径",
								"退出程序",
								"请输入您选择的操作前的数字代号",
								"请您在所提供的选项中选择",
								"请重新输入您选择的操作前的数字代号",
								"返回上一级菜单",
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
		printf("       %s！\n       %s！\n\n",ReadFileLan[1][choose],ReadFileLan[2][choose]);
		printf("       %s:\n\n",ReadFileLan[3][choose]);
		printf("               [1]%s；\n",ReadFileLan[4][choose]);
		printf("               [2]%s；\n",ReadFileLan[9][choose]);
		printf("               [3]%s；\n\n",ReadFileLan[5][choose]);
		printf("       %s:",ReadFileLan[6][choose]);
		scanf("%d" , &OptionChoose);
		fflush(stdin);

		while(1 != OptionChoose && 2 != OptionChoose && 3 != OptionChoose)
		{
			printf("\n");
			printf("       %s!\n\n",ReadFileLan[7][choose]);
			printf("       %s：",ReadFileLan[8][choose]);
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
	char* ReadFileChoose[14][1] = {"    欢 迎 进 入 文 件 读 取 界 面   ",
									"请选择所要读取的文件路径",
									"默认路径读取",
									"自定义路径读取",
									"返回(Return)",
									"请输入您选择的操作前的数字代号",
									"请您在所提供的选项中选择",
									"请重新输入您选择的路径前的数字代号",
									"对不起，出错了",
									"文件打开失败或数组空间不足",
									"请您选择下一步的操作",
									"重新输入文件路径",
									"返回上一级菜单",
									"退出程序",
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
	printf("       %s：\n\n",ReadFileChoose[1][choose]);
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
			printf("\n文件 %s 读取成功（Successfully read file %s）!\n", FilePath,FilePath);
			system("pause");
			system("cls"); 
			PrintHeadFunction();
			ChooseFunction(choose);
		}
		else
		{
			printf("       %s！\n       %s！\n\n",ReadFileChoose[8][choose],ReadFileChoose[9][choose]);
			printf("       %s:\n\n",ReadFileChoose[10][choose]);
			printf("               [1]%s；\n",ReadFileChoose[11][choose]);
			printf("               [2]%s；\n",ReadFileChoose[12][choose]);
			printf("               [3]%s；\n\n",ReadFileChoose[13][choose]);
			printf("       %s:",ReadFileChoose[5][choose]);
			scanf("%d" , &OptionChoose);
			fflush(stdin);

			while(1 != OptionChoose && 2 != OptionChoose && 3 != OptionChoose)
			{
				printf("\n");
				printf("       %s!\n\n",ReadFileChoose[6][choose]);
				printf("       %s：",ReadFileChoose[7][choose]);
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
		printf("\n文件 %s 读取成功（Successfully read file %s）!\n", FileName,FileName);
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
			printf("       %s！\n       %s！\n\n",ReadFileChoose[8][choose],ReadFileChoose[9][choose]);
			printf("       %s:\n\n",ReadFileChoose[10][choose]);
			printf("               [1]%s；\n",ReadFileChoose[11][choose]);
			printf("               [2]%s；\n\n",ReadFileChoose[13][choose]);
			printf("       %s:",ReadFileChoose[5][choose]);
			scanf("%d" , &OptionChoose);
			fflush(stdin);

			while(1 != OptionChoose && 2 != OptionChoose)
			{
				printf("\n");
				printf("       %s!\n\n",ReadFileChoose[6][choose]);
				printf("       %s：",ReadFileChoose[7][choose]);
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
