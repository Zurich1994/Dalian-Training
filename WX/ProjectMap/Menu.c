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
    printf("\t/***王鑫\t ☆☆ ☆☆  ☆☆ ☆☆\t张宝彤\t ***/\n");
    printf("\t/***\t\t★★      ★       ★★\t\t ***/\n");
    printf("\t/***\t\t☆☆     祝你      ☆☆\t\t ***/\n");
    printf("\t/***\t\t★★   天天开心   ★★\t\t ***/\n");
    printf("\t/***连天奇\t ☆☆  O(∩_∩)O ☆☆\t塔怀明   ***/\n");
    printf("\t/***\t\t  ★★          ★★\t\t ***/\n");
    printf("\t/***\t\t   ☆☆        ☆☆\t\t ***/\n");
    printf("\t/***\t\t    ★★     ★★\t\t ***/\n");
    printf("\t/***那晓旭\t      ☆☆☆☆\t\t宋华兵 \t ***/\n");
    printf("\t/***\t\t        ☆☆\t\t\t ***/\n");
    printf("\t/***                共同为您制作                 ***/\n");
    printf("\t/********************--welcome--********************/\n");
    printf("\t/***\t\t电子地图信息统计系统\t\t ***/\n");
    printf("\t/***\t\t制作团队 : 麒麟队 \t\t ***/\n");
    printf("\t/***\t\t日期时间 : %d年%d月%d日\t ***/\n",(timeinfo->tm_year+1900),(timeinfo->tm_mon+1),timeinfo->tm_mday);
    printf("\t/***\t\t使用时间 : %d时%d分%d秒\t ***/\n",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
    printf("\t/**************--Thank you for using--**************/\n");
    system("color 2e");
	while(choice!=0)
	{
		printf("\n\t欢迎使用电子地图管理系统\n");
		printf("\t请选择服务的种类：\n");
		printf("\t\t1.读取文件(C:\\GTBL.dat)\n");
		printf("\t\t2.排序(快速排序)并输出结果(C:\\SortGTBL.dat)\n");
		printf("\t\t3.检索\n");
		printf("\t\t4.更新\n");
		printf("\t\t0.退出\n");
		printf("\t\t请选择 : ");
		scanf("%d",&choice); 
        switch(choice)
		{
		case 1://读取文件
			{
                int fileb[80];
                int choice_3;
                baocuo++;
                printf("\n\t请选择读取的方式： \n");
                printf("\t\t1.默认读取： \n");
				printf("\t\t2.自定义读取： \n");
                printf("\t\t0.返回\n");
                printf("\t请输入您的选择：");
                scanf("%d",&choice_3);
                switch(choice_3)
                {
                case 1:                   
				        printf("\n\t文件读取中，请稍后....\n");
				        if(LoadFile("C:\\GTBL.dat",&Head)==0)
				        {
					        printf("\t文件读取完成！\n");
                        }          
				    break;
                case 2:
  
   				        printf("\t请输入文件地址: ");
                        scanf("%s",fileb);
                        printf("\t读取文件中...\n");
                        if(LoadFile(fileb,&Head)==0)
				        {
				            printf("\t文件读取完成！\n");                            
                        }
                         break;
                    
                case 0: 
                    break;
                default:
			        printf("\n\t╮(╯﹏╰）╭输入有误，请输入1,2,0三个数字！\n");
                }
              break;

			}
                  break;
		case 2://进行排序
			{
                if(baocuo != 0)
                {
				int choice;
				printf("\n\t请选择排序的方式： \n");
				printf("\t\t1.冒泡排序： \n");
				printf("\t\t2.选择排序： \n");
				printf("\t\t3.快速排序： \n");
                printf("\t\t0.返回\n");
				printf("\t请输入您的选择：");
				scanf("%d",&choice);
				LinkToArray(&Head,choice);
			
                }
                else printf("\n\t╮(╯▽╰)╭请先进行1.读取文件\n");
            }
			break;
		case 3://检索操作
			{
				int choice=0;
				long linkId;
				int disClass;
				int brunch;
				char roadName[20];
				if((LoadFile("C:\\GTBL.dat",&Head_Sort))==0)
				{
					
					printf("\n\t请选择检索方式：\n");
					printf("\t\t1.指定LinkID检索：\n");
					printf("\t\t2.指定交叉Link列表示Class番号 检索：\n");
					printf("\t\t3.指定岔路数 检索:\n");
					printf("\t\t4.指定道路名称 检索：\n");
					printf("\t\t0.返回\n");
					printf("\t请输入您的选择：");
					scanf("%d",&choice);
					switch(choice)
					{
					case 1:
						printf("\t请输入Link的ID：");
						scanf("%ld",&linkId);
						Sort_LinkID(&Head_Sort,linkId);
						break;

					case 2:
						printf("\t请输入交叉Link列表示Class番号：");
						scanf("%d",&disClass);
						Sort_DisClass(&Head_Sort,disClass);
						break;
					case 3:
						printf("\t请输入要查找的岔路数： ");
						scanf("%d",&brunch);
						Sort_RoadBrunch(&Head_Sort,brunch);
						break;
					case 4:
						printf("\t请输入要查找的道路名称： ");
						scanf("%s",roadName);
						printf("%s",roadName);
						Sort_RoadName(&Head_Sort,roadName);
						break;
					case 0:
						break;
                    default:
			            printf("\n\t╮(╯﹏╰）╭输入有误，请输入0--4之间的数字！\n");
					}
				}
				else
				{
					printf("请先对原数据进行排序，然后才可以进行检索！\n");
				}
			}
			break;
		case 4://更新操作
			{
    
				int choice_2;
                int a[80];
                printf("\t1.默认路径(指定名称)\n");
                printf("\t2.自定义目录\n");
                printf("\t0.返回\n");
                printf("\t请选择 : ");
                scanf("%d",&choice_2);
                switch(choice_2)
                {
                case 1:
                    printf("\t读取待更新文件...\n");
                    if(LoadFile("C:\\update.dat",&Head)==0)
				    {
				        printf("\t更新文件读取完成！\n");                            
                    }
                    LinkToArray_2(&Head,3);
                    break;
                case 2:
                    
                    printf("\t请输入文件地址: ");
                    scanf("%s",a);
                    printf("\t读取待更新文件...\n");
                    if(LoadFile(a,&Head)==0)
				    {
				        printf("\t更新文件读取完成！\n");                            
                    }
                    LinkToArray_2(&Head,3);
                    break;
                case 0:
                    break;
                 default:
			        printf("\n\t╮(╯﹏╰）╭输入有误，请输入1,2,0三个数字！\n");
                }
                //    break;			
			}
      
			break;
		case 0://退出程序
			printf("\t感谢您的使用，欢迎下次继续使用。\n");

            printf("\t/***\t  ▇▇▇▇  .   ▇▇▇▇  .  ▇▇▇▇  .  ▇▇▇▇\t***/\n");
            printf("\t/***\t◢▇▇▇▇◣. ◢▇▇▇▇◣.◢▇▇▇▇◣.◢▇▇▇▇◣\t***/\n");
            printf("\t/***\t▇天天快乐▇. ▇生活愉快▇.▇吉祥如意▇.▇合家欢乐▇\t***/\n");
            printf("\t/***\t◥▇▇▇▇◤. ◥▇▇▇▇◤.◥▇▇▇▇◤.◥▇▇▇▇◤\t***/\n");
            printf("\t/***\t  ▇▇▇▇  .   ▇▇▇▇  .  ▇▇▇▇  .  ▇▇▇▇\t***/\n");
            printf("\t/***\t   | | |          | | |       | | |         | | |\t***/\n");
			break;
		default:
			printf("\t╮(╯﹏╰）╭输入有误，请输入0-4的数字！\n");
		}
        getchar();

	}

	return 0;
}









