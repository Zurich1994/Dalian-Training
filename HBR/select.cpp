#include "Map.h"
void SortSelect(RoadRecord * pRoadRecord,int RoadNum)
{
    int n,i,top,bot,loca,flag;
    unsigned long num;
    printf("��ѡ������ķ�ʽ:\n");
    printf("        1.ָ��linkID����\n");
    printf("        2.ָ������Link�б�ʾClass���� ����\n");
    printf("        3.ָ�����Ҳ�·�� ����\n");
    printf("        4.ָ����·���� ����\n");
    printf("        0.����\n");
    printf("��ѡ��: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
    {
        ChooseSort(pRoadRecord,RoadNum);
        printf("������Link��ID: ");
        scanf("%ld",&num);
        for(i=0; i<RoadNum; i++)
        {
            if(num==pRoadRecord[i].LinkID)
            {
                printf("��ѯ���Ϊ:\n");
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
            printf("û��ƥ�������������\n");
        break;
    }
    case 2:
    {
        InsertSort(pRoadRecord,RoadNum);
        printf("�����뽻��LinkID�б�ʾClass�ķ���: ");
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
            printf("�������5��������ת�浽txt�ļ�.\\data\\searchdispclass.txt��\n");
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
        else printf("�޽��!\n");
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










































