#include "search.h"
#include "structures.h"
#include "sort.h"
#include "ioFile.h"
/*********************************************************************************************************
** FileName:                search.h                                                                     *
** Last version date:       2013-07-30                                                                   *
** Description:      Algorithms for binary searching, 2-tree searching and sequence searching            *                                     *
** Author:           周璋 闫毓麟                                                                         *
*********************************************************************************************************/
char* menuArr[11][2] = { "查找中，请稍后......", 
                       "没有找到合适的记录!", 
					   "结果总共 ", 
					   "条", 
					   "道路编号: ", 
					   "道路名称: ", 
					   "岔路数: ", 
					   "番号: ", 
					   "总共花费时间: ", 
					   "记录将被保存到result.txt中", 
					   "不能写入文件，请确保其处于可写状态", 
						};
/*********************************************************************************************************
** FileName:                  BinarySearch                                                               *
** Last version date:       2013-07-30                                                                   *
** Description:      折半查找法                                                                          *                                     
** Author:           周璋 闫毓麟                                                                         *
*********************************************************************************************************/
int BinarySearch(RoadArray_t rdArray, const int searchType, int choose)
{
    double totalTime = 0.0;
	RoadArray_t outArr = {0};
	outArr.roadMsgs = (RoadMsg_t*)malloc(sizeof(RoadMsg_t) * rdArray.length); 
	clock_t endTime; // 结束时间
	clock_t startTime = clock(); // 开始时间
	int result;
	switch(searchType)
	{
        
	case TYPE_ID:
		{
			char idStr[5];
			int id;
			
			scanf("%s", idStr);
			fflush(stdin); // 清除缓存区

			for(int i = 0; i < 5 && idStr[i] != '\0'; i++)
			{
                if(isdigit(idStr[i])== 0)
                {
                    printf("Invalid input!\n");
                    return UNSUCCESS;
                }
            }
			id = atoi(idStr);
			
			
            int left = 0;
            int right = rdArray.length - 1;
            int mid = (left + right) / 2;
             
            printf("%s", menuArr[0][choose]);
			QSort(&rdArray, searchType);  //记录排序第一
			
			
			while(left <= right)
            {
		
                if(rdArray.roadMsgs[mid].linkID == id)
                {
					
                    memcpy(&(outArr.roadMsgs[outArr.length]), 
						&(rdArray.roadMsgs[mid]), sizeof(rdArray.roadMsgs[mid]));
                    outArr.length++;

				
                    for(left = mid - 1; left >= 0 && rdArray.roadMsgs[left].linkID == id; left--)
                    {
                        memcpy(&(outArr.roadMsgs[outArr.length]), 
							&(rdArray.roadMsgs[left]), sizeof(rdArray.roadMsgs[left]));
                        outArr.length++;
                    }
					
                    for(right = mid + 1; right < rdArray.length && rdArray.roadMsgs[right].linkID == id; right++)
                    {
                        memcpy(&(outArr.roadMsgs[outArr.length]), 
							&(rdArray.roadMsgs[right]), sizeof(rdArray.roadMsgs[right]));
                        outArr.length++;
                    }
                    break;
                }

                else if(rdArray.roadMsgs[mid].linkID  > id)
                    right = (left + right)/2 - 1;
                else
                    left = (left + right)/2 + 1;
                mid = (left + right) / 2;
            }
			
			break;
		} 
		
        
	case TYPE_BRUNCH:
		{
			char brcStr[5];
			int brunch;
			scanf("%s", brcStr);
			fflush(stdin); 

			
			for(int i = 0; i < 5 && brcStr[i] != '\0'; i++)
			{
                if(isdigit(brcStr[i])== 0)
                {
                    printf("Invalid input!\n");
                    return UNSUCCESS;
                }
            }
			brunch = atoi(brcStr);
			
			
            int left = 0;
            int right = rdArray.length - 1;
            int mid = (left + right) / 2;
			printf("%s", menuArr[0][choose]);
			QSort(&rdArray, searchType);  
            
           
			while(left <= right) 
            {
                if(rdArray.roadMsgs[mid].brunch == brunch)
                {
				
                    memcpy(&(outArr.roadMsgs[outArr.length]), 
						&(rdArray.roadMsgs[mid]), sizeof(rdArray.roadMsgs[mid]));
                    outArr.length++;

					
                    for(left = mid - 1; left >= 0 && rdArray.roadMsgs[left].brunch == brunch; left--)
                    {
                        memcpy(&(outArr.roadMsgs[outArr.length]), 
						&(rdArray.roadMsgs[left]), sizeof(rdArray.roadMsgs[left]));
                        outArr.length++;
                    }

                    for(right = mid + 1; right < rdArray.length && rdArray.roadMsgs[right].brunch == brunch; right++)
                    {
                        memcpy(&(outArr.roadMsgs[outArr.length]), 
						&(rdArray.roadMsgs[right]), sizeof(rdArray.roadMsgs[right]));
                        outArr.length++;
                    }
                    break;
                }
				
                else if(rdArray.roadMsgs[mid].brunch  > brunch)
                    right = (left + right)/2 - 1;
                else
                    left = (left + right)/2 + 1;
                mid = (left + right) / 2;
            } 
            
			break;
		} 
		
        
	case TYPE_CLASSNO:
		{
			char noStr[5];
			int classNo;
			scanf("%s", noStr);
			fflush(stdin); 
			
		
			for(int i = 0; i < 5 && noStr[i] != '\0'; i++)
			{
                if(isdigit(noStr[i])== 0)
                {
                    printf("Invalid input!\n");
                    return UNSUCCESS;
                }
            }

			classNo = atoi(noStr);
			int left = 0;
            int right = rdArray.length - 1;
            int mid = (left + right) / 2;
			printf("%s", menuArr[0][choose]);
			QSort(&rdArray, searchType);  

           
			while(left <= right) 
            {
                if(rdArray.roadMsgs[mid].dispclass == classNo)
                {

				
                    memcpy(&(outArr.roadMsgs[outArr.length]), 
						&(rdArray.roadMsgs[mid]), sizeof(rdArray.roadMsgs[mid]));
                    outArr.length++;
					
				
                    for(left = mid - 1; left >= 0 && rdArray.roadMsgs[left].dispclass == classNo; left--)
                    {
                        memcpy(&(outArr.roadMsgs[outArr.length]), 
						&(rdArray.roadMsgs[left]), sizeof(rdArray.roadMsgs[left]));
                        outArr.length++;
                    }
                    for(right = mid + 1; right < rdArray.length && rdArray.roadMsgs[right].dispclass == classNo; right++)
                    {
                        memcpy(&(outArr.roadMsgs[outArr.length]), 
						&(rdArray.roadMsgs[right]), sizeof(rdArray.roadMsgs[right]));
                        outArr.length++;
                    }
                    break;
                }

                else if(rdArray.roadMsgs[mid].dispclass  > classNo)
                    right = mid - 1;
                else
                    left = (left + right)/2 + 1;
                mid = (left + right) / 2;
            } 
            
			break;
		} 
		
	case TYPE_NAME:
		{
			char nameIn[ROADNAME_SIZE];
			char cIn = ' ';
			int count = 0;
			scanf("%s", nameIn);

  
      	
            
			int left = 0;
            int right = rdArray.length - 1;
            int mid = (left + right) / 2;
			printf("%s", menuArr[0][choose]);

			
            QSort(&rdArray, searchType); 

			while(left <= right) 
            {
			   
                if(strcmp(rdArray.roadMsgs[mid].roadname + 4,nameIn) == 0)
                {
				
                    memcpy(&(outArr.roadMsgs[outArr.length]), 
						&(rdArray.roadMsgs[mid]), sizeof(rdArray.roadMsgs[mid]));
                    outArr.length++;
					

				
                    for(left = mid - 1; 
					(left >= 0) && strcmp(rdArray.roadMsgs[left].roadname + 4, nameIn) == 0; 
					left--)
                    {
                        memcpy(&(outArr.roadMsgs[outArr.length]), 
						    &(rdArray.roadMsgs[left]), sizeof(rdArray.roadMsgs[left]));
                        outArr.length++;
                    }
                    
                    for(right = mid + 1; 
					(right < rdArray.length) && (strcmp(rdArray.roadMsgs[right].roadname + 4,nameIn) == 0); 
					right++)
                    {
                       memcpy(&(outArr.roadMsgs[outArr.length]), 
						  &(rdArray.roadMsgs[right]), sizeof(rdArray.roadMsgs[right]));
                        outArr.length++;
                    }
                    break;
                }

                else if(strcmp(rdArray.roadMsgs[mid].roadname + 4,nameIn) > 0)
				{
					
                    right = mid - 1;
				}
                else
				{
                    left = mid + 1;
				}
                mid = (left + right) / 2;
            } 
			break;
		} 
		
	default:
		break;
		
		
	} // 结束 switch 循环
	
	endTime = clock();
	totalTime = (double)(endTime - startTime)/CLOCKS_PER_SEC;

	if(0 == outArr.length)
	{
		free(outArr.roadMsgs);
		printf("%s\n", menuArr[1][choose]);
		return 0; 
	}
	
	else if(5 >= outArr.length)
	{
        printf("%s%d%s\n", menuArr[2][choose], outArr.length, menuArr[3][choose]);
        printf("-------------------------------\n");
		for(int i = 0; i < outArr.length; i++)
		{
			printf("%s%d\n", menuArr[4][choose], outArr.roadMsgs[i].linkID);
			
			if(outArr.roadMsgs[i].roadnameflag == 0)
				printf("%sNo name\n", menuArr[5][choose]);
			else
				printf("%s%s\n", menuArr[5][choose],outArr.roadMsgs[i].roadname + 4);
			printf("%s%d\n", menuArr[6][choose], outArr.roadMsgs[i].brunch);
			printf("%s%d\n", menuArr[7][choose], outArr.roadMsgs[i].dispclass);
			printf("-------------------------------\n");
			
		}
		printf("%s%lf sec\n",menuArr[8][choose] ,totalTime);
		free(outArr.roadMsgs);
		return SUCCESS;
	}
	
	else 
	{ 
        printf("%s%d%s\n", menuArr[2][choose], outArr.length, menuArr[3][choose]);
        printf("%s%lf sec\n",menuArr[8][choose] ,totalTime);
		result =  writeresult(RESULT_FILENAME, &outArr); 
		free(outArr.roadMsgs);
		if(result == SUCCESS)
		{
			printf("%s\n", menuArr[9][choose]);
		}
		else
		{
			printf("%s\n", menuArr[10][choose]);
		}
		return result;
	}
} 
/*********************************************************************************************************
** FileName:                sequencesearch                                                               *
** Last version date:       2013-07-30                                                                   *
** Description:      顺序法查找                                                                          *                                     
** Author:           周璋 闫毓麟                                                                         *
*********************************************************************************************************/

int SequenceSearch(const RoadArray_t rdArray, const int searchType, int choose)
{
	RoadArray_t outArr = {0}; 
	outArr.roadMsgs = (RoadMsg_t*)malloc(sizeof(RoadMsg_t) * INFO_SIZE);
	clock_t endTime;
	clock_t startTime = clock();
	double totalTime = 0.0;
	int result = 0;
	
	switch(searchType)
	{
	case TYPE_ID:
		{
			char idStr[5];
			int id;
			
			scanf("%s", idStr);
			fflush(stdin); 

		
			for(int i = 0; i < 5 && idStr[i] != '\0'; i++)
			{
                if(isdigit(idStr[i])== 0)
                {
                    printf("Invalid input!\n");
                    return UNSUCCESS;
                }
            }
			id = atoi(idStr);
			
			
			for(i = 0; i < rdArray.length; i++)
			{
				if(rdArray.roadMsgs[i].linkID == id)
				{
					memcpy(&(outArr.roadMsgs[outArr.length]), &(rdArray.roadMsgs[i]), sizeof(rdArray.roadMsgs[i]));
					outArr.length++;
				}
			}
			
			
			break;
		} 
				
	case TYPE_BRUNCH:
		{
			char brcStr[5];
			int brunch;
			scanf("%s", brcStr);
			fflush(stdin); 

          
			for(int i = 0; i < 5 && brcStr[i] != '\0'; i++)
			{
                if(isdigit(brcStr[i])== 0)
                {
                    printf("Invalid input!\n");
                    return UNSUCCESS;
                }
            }
			brunch = atoi(brcStr);
			
			for(i = 0; i < rdArray.length; i++)
			{
				if(rdArray.roadMsgs[i].brunch == brunch)
				{
					memcpy(&(outArr.roadMsgs[outArr.length]), &(rdArray.roadMsgs[i]), sizeof(rdArray.roadMsgs[i]));
					outArr.length++;
				}
			}
			
			break;
		} 
		
	case TYPE_CLASSNO:
		{
			char noStr[5];
			int classNo;
			scanf("%s", noStr);
			fflush(stdin); 
			
		
			for(int i = 0; i < 5 && noStr[i] != '\0'; i++)
			{
                if(isdigit(noStr[i])== 0)
                {
                    printf("Invalid input!\n");
                    return UNSUCCESS;
                }
            }
			classNo = atoi(noStr);
			
			for(i = 0; i < rdArray.length; i++)
			{
				if(rdArray.roadMsgs[i].dispclass == classNo)
				{
					memcpy(&(outArr.roadMsgs[outArr.length]), &(rdArray.roadMsgs[i]), sizeof(rdArray.roadMsgs[i]));
					outArr.length++;
				}
			}
			break;
		} 
		
	case TYPE_NAME:
		{
			char nameIn[ROADNAME_SIZE];
			char cIn = ' ';
			int count = 0;
			scanf("%s", nameIn);
			fflush(stdin); 

		

			for(int i = 0; i < rdArray.length; i++)
			{
				if(strcmp(nameIn, (rdArray.roadMsgs[i].roadname + 4)) == 0)
				{
					memcpy(&(outArr.roadMsgs[outArr.length]), &(rdArray.roadMsgs[i]), sizeof(rdArray.roadMsgs[i]));
					outArr.length++;
				}
			}
			
			break;
		} 
		
	default:
		break;
	} // 结束 switch 循环
	
	endTime = clock();
	totalTime =(double)(endTime - startTime)/ CLOCKS_PER_SEC;
	if(0 == outArr.length)
	{
		free(outArr.roadMsgs);
		printf("%s\n", menuArr[1][choose]);
		return 0; 
	}
	
	else if(5 >= outArr.length)
	{
        printf("%s%d%s\n", menuArr[2][choose], outArr.length, menuArr[3][choose]);
        printf("-------------------------------\n");
		for(int i = 0; i < outArr.length; i++)
		{
			printf("%s%d\n", menuArr[4][choose], outArr.roadMsgs[i].linkID);
			
			if(outArr.roadMsgs[i].roadnameflag == 0)
				printf("%sNo name\n", menuArr[5][choose]);
			else
				printf("%s%s\n", menuArr[5][choose],outArr.roadMsgs[i].roadname + 4);
			printf("%s%d\n", menuArr[6][choose], outArr.roadMsgs[i].brunch);
			printf("%s%d\n", menuArr[7][choose], outArr.roadMsgs[i].dispclass);
			printf("-------------------------------\n");
			
		}
		printf("%s%lf sec\n",menuArr[8][choose] ,totalTime);
		free(outArr.roadMsgs);
		return SUCCESS;
	}
	
	else 
	{ 
        printf("%s%d%s\n", menuArr[2][choose], outArr.length, menuArr[3][choose]);
        printf("%s%lf sec\n",menuArr[8][choose] ,totalTime);
		result =  writeresult(RESULT_FILENAME, &outArr); 
		free(outArr.roadMsgs);
		if(result == SUCCESS)
		{
			printf("%s\n", menuArr[9][choose]);
		}
		else
		{
			printf("%s\n", menuArr[10][choose]);
		}
		return result;
	}
} // 端续列搜索


int TreeSearch(TreeNode_t* pNode, int choose)
{
	
    RoadArray_t outArr = {0}; 
	outArr.roadMsgs = (RoadMsg_t*)malloc(sizeof(RoadMsg_t) * INFO_SIZE);
	clock_t endTime;
	clock_t startTime = clock();
	double totalTime = 0.0;
	TreeNode_t* pCurrent = NULL; 
	int result = 0;
	
	char idStr[5];
	int id;
	
	scanf("%s", idStr);
	fflush(stdin); 

	for(int i = 0; i < 5 && idStr[i] != '\0'; i++)
	{
		if(isdigit(idStr[i])== 0)
		{
			printf("Invalid input!\n");
			return UNSUCCESS;
		}
	}
	id = atoi(idStr);
	
	
	for(pCurrent = pNode; pCurrent != NULL;)
	{
		if((pCurrent->data)->linkID == id)
		{
			memcpy(&(outArr.roadMsgs[outArr.length]), pCurrent->data, sizeof(*(pCurrent->data)));
			outArr.length++;
			break;
		}
		
		else if((pCurrent->data)->linkID > id)
		{
			pCurrent = pCurrent->leftChild;
		}
		
		else
		{
			pCurrent = pCurrent->rightChild;
		}
	}
	
		
	endTime = clock();
	totalTime =(double)(endTime - startTime)/ CLOCKS_PER_SEC;
	if(0 == outArr.length)
	{
		free(outArr.roadMsgs);
		printf("%s\n", menuArr[1][choose]);
		return 0; 
	}
	
	else
	{
        printf("%s%d%s\n", menuArr[2][choose], outArr.length, menuArr[3][choose]);
        printf("-------------------------------\n");
		for(int i = 0; i < outArr.length; i++)
		{
			printf("%s%d\n", menuArr[4][choose], outArr.roadMsgs[i].linkID);
			
			if(outArr.roadMsgs[i].roadnameflag == 0)
				printf("%sNo name\n", menuArr[5][choose]);
			else
				printf("%s%s\n", menuArr[5][choose],outArr.roadMsgs[i].roadname + 4);
			printf("%s%d\n", menuArr[6][choose], outArr.roadMsgs[i].brunch);
			printf("%s%d\n", menuArr[7][choose], outArr.roadMsgs[i].dispclass);
			printf("-------------------------------\n");
			
		}
		printf("%s%lf sec\n",menuArr[8][choose] ,totalTime);
		free(outArr.roadMsgs);
		return SUCCESS;
	}
	
	
} 
