#include "Map.h"
void SortSelect(RoadRecord * pRoadRecord,int RoadNum)
{
    int n,i,top,bot,loca,flag;
    unsigned long num;
    printf("请选择检索的方式:\n");
    printf("        1.指定linkID检索\n");
    printf("        2.指定交叉Link列表示Class番号 检索\n");
    printf("        3.指定查找岔路数 检索\n");
    printf("        4.指定道路名称 检索\n");
    printf("        0.返回\n");
    printf("请选择: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
    {
        ChooseSort(pRoadRecord,RoadNum);
        printf("请输入Link的ID: ");
        scanf("%ld",&num);
        for(i=0; i<RoadNum; i++)
        {
            if(num==pRoadRecord[i].LinkID)
            {
                printf("查询结果为:\n");
                printf("LinkId=");
                printf("%d\n", pRoadRecord[i].LinkID);
                printf("flag=");
                printf("%d\n", pRoadRecord[i].flag);
                printf("Bruch=");
                printf("%hd\n", pRoadRecord[i].Bruch);
                printf("dispclass=");
                printf("%hd\n", pRoadRecord[i].dispclass);
                if(pRoadRecord[i].RoadName != NULL)
                    printf("%s\n", pRoadRecord[i].RoadName);
                break;
            }
        }
        if(i==RoadNum)
            printf("没有匹配结果或输入错误\n");
        break;
    }
    case 2:
    {
        InsertSort(pRoadRecord,RoadNum);
        printf("请输入交叉LinkID列表示Class的番号: ");
        int i,j,m,cla;
        int f,l;
        scanf("%d",&cla);
        i=0;
        j=RoadNum-1;
        m=(i+j)/2;

        while(cla!=(pRoadRecord[m].dispclass) &&i<=j)
        {

            if((pRoadRecord[m].dispclass)>cla)
                j=m-1;
            if((pRoadRecord[m].dispclass)<cla)
                i=m+1;
            m=(i+j)/2;
        }

        if(i<=j)
        {
            printf("结果大于5条，将其转存到txt文件.\\data\\searchdispclass.txt中\n");
            FILE * outMap;
            outMap = fopen(".\\data\\searchdispclass.txt","r+");
            if(NULL==outMap)
                printf("wrong\n");
            f=m;
            l=m;
            for(int k=m;; k++)
            {
                if(pRoadRecord[k].dispclass==cla)
                    l++;
                else break;
            }
            for(k=m;; k--)
            {
                if(pRoadRecord[k].dispclass==cla)
                    f--;
                else break;
            }

            for( k=f+1; k<l; k++)
            {
                fprintf(outMap, "LinkID=%-10d", pRoadRecord[k].LinkID);
                fprintf(outMap, "flag=%-10d", pRoadRecord[k].flag);
                fprintf(outMap, "Bruch=%-10d", pRoadRecord[k].Bruch);
                fprintf(outMap, "dispclass=%-10hd", pRoadRecord[k].dispclass);
                if(pRoadRecord[k].RoadName != NULL)
                {
                    fprintf(outMap, "RoadName=%s\n", pRoadRecord[k].RoadName);
                }
            }

            fclose(outMap);
            outMap = NULL;
        }
        else printf("无结果!\n");
    break;
    }
case 3:
    {
        BinarySearch3(pRoadRecord,RoadNum);
        break;
    }



    case 4:
     {
         BinarySearch4(pRoadRecord,RoadNum);
         break;
     }
     case 0:
     {

         break;
     }
}

}










































