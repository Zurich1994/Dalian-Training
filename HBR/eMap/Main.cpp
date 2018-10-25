#include "Map.h"
using namespace std;

void start2()
{
    int i,a;
    for(i=0;;i++)
    {
		i=i%7;
        switch(i)
        {
            case 0:cout<<"★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★"<<endl;
                   cout<<"☆★☆☆☆☆☆　┏━　　　┏━━━━┓　┓┏　┏　┏━━━━┓☆☆☆☆☆★☆"<<endl;
                   cout<<"☆☆★☆☆☆☆┏┣━━━┓　　　┏━┛┏┣┣━┣┓┃┣━━┓┃☆☆☆☆★☆☆"<<endl;
                   cout<<"☆☆☆★☆☆☆┃┃　　　┃　　　╰╮　　┃┃　┃┃┃╯━┏╯┃☆☆☆★☆☆☆"<<endl;
                   cout<<"☆☆☆☆★☆☆┣┣━━━┫┗━━━┣┛　┃┃　┃┃┃━┳╯━┃☆☆★☆☆☆☆"<<endl;
                   cout<<"☆☆☆☆☆★☆┗┣━━━╯　　　　┃　　┃┃　┃╯┃┗━━╮┃☆★☆☆☆☆☆"<<endl;
                   cout<<"☆☆☆☆☆☆★  ╰━━━┛╰━━━┛　╰┻╰━━┛┗━━━━╯★☆☆☆☆☆☆"<<endl;

                   break;
            case 1:
                   cout<<"☆★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★☆"<<endl;
                   cout<<"☆☆★☆☆☆☆　┏━　　　┏━━━━┓　┓┏　┏　┏━━━━┓☆☆☆☆★☆☆"<<endl;
                   cout<<"☆☆☆★☆☆☆┏┣━━━┓　　　┏━┛┏┣┣━┣┓┃┣━━┓┃☆☆☆★☆☆☆"<<endl;
                   cout<<"☆☆☆☆★☆☆┃┃　　　┃　　　╰╮　　┃┃　┃┃┃╯━┏╯┃☆☆★☆☆☆☆"<<endl;
                   cout<<"☆☆☆☆☆★☆┣┣━━━┫┗━━━┣┛　┃┃　┃┃┃━┳╯━┃☆★☆☆☆☆☆"<<endl;
                   cout<<"☆☆☆☆☆☆★┗┣━━━╯　　　　┃　　┃┃　┃╯┃┗━━╮┃★☆☆☆☆☆☆"<<endl;
                   cout<<"★☆☆☆☆☆☆  ╰━━━┛╰━━━┛　╰┻╰━━┛┗━━━━╯☆☆☆☆☆☆★"<<endl;
                   break;
            case 2:
                   cout<<"☆☆★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★☆☆"<<endl;
                   cout<<"☆☆☆★☆☆☆　┏━　　　┏━━━━┓　┓┏　┏　┏━━━━┓☆☆☆★☆☆☆"<<endl;
                   cout<<"☆☆☆☆★☆☆┏┣━━━┓　　　┏━┛┏┣┣━┣┓┃┣━━┓┃☆☆★☆☆☆☆"<<endl;
                   cout<<"☆☆☆☆☆★☆┃┃　　　┃　　　╰╮　　┃┃　┃┃┃╯━┏╯┃☆★☆☆☆☆☆"<<endl;
                   cout<<"☆☆☆☆☆☆★┣┣━━━┫┗━━━┣┛　┃┃　┃┃┃━┳╯━┃★☆☆☆☆☆☆"<<endl;
                   cout<<"★☆☆☆☆☆☆┗┣━━━╯　　　　┃　　┃┃　┃╯┃┗━━╮┃☆☆☆☆☆☆★"<<endl;
                   cout<<"☆★☆☆☆☆☆  ╰━━━┛╰━━━┛　╰┻╰━━┛┗━━━━╯☆☆☆☆☆★☆"<<endl;
                   break;
            case 3:
                   cout<<"☆☆☆★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★☆☆☆"<<endl;
                   cout<<"☆☆☆☆★☆☆　┏━　　　┏━━━━┓　┓┏　┏　┏━━━━┓☆☆★☆☆☆☆"<<endl;
                   cout<<"☆☆☆☆☆★☆┏┣━━━┓　　　┏━┛┏┣┣━┣┓┃┣━━┓┃☆★☆☆☆☆☆"<<endl;
                   cout<<"☆☆☆☆☆☆★┃┃　　　┃　　　╰╮　　┃┃　┃┃┃╯━┏╯┃★☆☆☆☆☆☆"<<endl;
                   cout<<"★☆☆☆☆☆☆┣┣━━━┫┗━━━┣┛　┃┃　┃┃┃━┳╯━┃☆☆☆☆☆☆★"<<endl;
                   cout<<"☆★☆☆☆☆☆┗┣━━━╯　　　　┃　　┃┃　┃╯┃┗━━╮┃☆☆☆☆☆★☆"<<endl;
                   cout<<"☆☆★☆☆☆☆  ╰━━━┛╰━━━┛　╰┻╰━━┛┗━━━━╯☆☆☆☆★☆☆"<<endl;
                   break;
            case 4:
                   cout<<"☆☆☆☆★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★☆☆☆☆"<<endl;
                   cout<<"☆☆☆☆☆★☆　┏━　　　┏━━━━┓　┓┏　┏　┏━━━━┓☆★☆☆☆☆☆"<<endl;
                   cout<<"☆☆☆☆☆☆★┏┣━━━┓　　　┏━┛┏┣┣━┣┓┃┣━━┓┃★☆☆☆☆☆☆"<<endl;
                   cout<<"★☆☆☆☆☆☆┃┃　　　┃　　　╰╮　　┃┃　┃┃┃╯━┏╯┃☆☆☆☆☆☆★"<<endl;
                   cout<<"☆★☆☆☆☆☆┣┣━━━┫┗━━━┣┛　┃┃　┃┃┃━┳╯━┃☆☆☆☆☆★☆"<<endl;
                   cout<<"☆☆★☆☆☆☆┗┣━━━╯　　　　┃　　┃┃　┃╯┃┗━━╮┃☆☆☆☆★☆☆"<<endl;
                   cout<<"☆☆☆★☆☆☆  ╰━━━┛╰━━━┛　╰┻╰━━┛┗━━━━╯☆☆☆★☆☆☆"<<endl;
                   break;
            case 5:
                   cout<<"☆☆☆☆☆★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★☆☆☆☆☆"<<endl;
                   cout<<"☆☆☆☆☆☆★　┏━　　　┏━━━━┓　┓┏　┏　┏━━━━┓★☆☆☆☆☆☆"<<endl;
                   cout<<"★☆☆☆☆☆☆┏┣━━━┓　　　┏━┛┏┣┣━┣┓┃┣━━┓┃☆☆☆☆☆☆★"<<endl;
                   cout<<"☆★☆☆☆☆☆┃┃　　　┃　　　╰╮　　┃┃　┃┃┃╯━┏╯┃☆☆☆☆☆★☆"<<endl;
                   cout<<"☆☆★☆☆☆☆┣┣━━━┫┗━━━┣┛　┃┃　┃┃┃━┳╯━┃☆☆☆☆★☆☆"<<endl;
                   cout<<"☆☆☆★☆☆☆┗┣━━━╯　　　　┃　　┃┃　┃╯┃┗━━╮┃☆☆☆★☆☆☆"<<endl;
                   cout<<"☆☆☆☆★☆☆  ╰━━━┛╰━━━┛　╰┻╰━━┛┗━━━━╯☆☆★☆☆☆☆"<<endl;
                   break;
            case 6:
                   cout<<"☆☆☆☆☆☆★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★☆☆☆☆☆☆"<<endl;
                   cout<<"★☆☆☆☆☆☆　┏━　　　┏━━━━┓　┓┏　┏　┏━━━━┓☆☆☆☆☆☆★"<<endl;
                   cout<<"☆★☆☆☆☆☆┏┣━━━┓　　　┏━┛┏┣┣━┣┓┃┣━━┓┃☆☆☆☆☆★☆"<<endl;
                   cout<<"☆☆★☆☆☆☆┃┃　　　┃　　　╰╮　　┃┃　┃┃┃╯━┏╯┃☆☆☆☆★☆☆"<<endl;
                   cout<<"☆☆☆★☆☆☆┣┣━━━┫┗━━━┣┛　┃┃　┃┃┃━┳╯━┃☆☆☆★☆☆☆"<<endl;
                   cout<<"☆☆☆☆★☆☆┗┣━━━╯　　　　┃　　┃┃　┃╯┃┗━━╮┃☆☆★☆☆☆☆"<<endl;
                   cout<<"☆☆☆☆☆★☆  ╰━━━┛╰━━━┛　╰┻╰━━┛┗━━━━╯☆★☆☆☆☆☆"<<endl;
                   break;
        }
        cout<<"☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"<<endl;
		cout<<"____________________________________________________________________________"<<endl;
		cout<<"                          --Dream of Miracle  出品--                        "<<endl;
		cout<<"                             --按空格键继续--                                  "<<endl;
		if(GetAsyncKeyState(' ')) {break;}
        system("cls");
		}
cout<<endl;
}
void start1()
{
	system("cls");    
	cout<<"★☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆★"<<endl;
        cout<<"☆★☆☆☆☆☆　┏━　　　┏━━━━┓　┓┏　┏　┏━━━━┓☆☆☆☆☆★☆"<<endl;
        cout<<"☆☆★☆☆☆☆┏┣━━━┓　　　┏━┛┏┣┣━┣┓┃┣━━┓┃☆☆☆☆★☆☆"<<endl;
        cout<<"☆☆☆★☆☆☆┃┃　　　┃　　　╰╮　　┃┃　┃┃┃╯━┏╯┃☆☆☆★☆☆☆"<<endl;
        cout<<"☆☆☆☆★☆☆┣┣━━━┫┗━━━┣┛　┃┃　┃┃┃━┳╯━┃☆☆★☆☆☆☆"<<endl;
        cout<<"☆☆☆☆☆★☆┗┣━━━╯　　　　┃　　┃┃　┃╯┃┗━━╮┃☆★☆☆☆☆☆"<<endl;
        cout<<"☆☆☆☆☆☆★  ╰━━━┛╰━━━┛　╰┻╰━━┛┗━━━━╯★☆☆☆☆☆☆"<<endl;
		cout<<"☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆"<<endl;
		cout<<"____________________________________________________________________________"<<endl;
		cout<<"                          --Dream of Miracle  出品--                        "<<endl;
		
}
void begin1()
{
    cout<<endl;
    cout<<"请选择服务的种类："<<endl;
    cout<<"         1:读取文件"<<endl;
    cout<<"         2:排序"<<endl;
    cout<<"         3:检索"<<endl;
    cout<<"         4:更新"<<endl;
    cout<<"         0:退出"<<endl;
    cout<<"  请选择：";
}
RoadRecord * pRoadRecord;
int RoadNum;

void FileRead(char * filename1, char * filename2)/////////////////////////////////////////////////////////////
{
	cout<<"读取文件。。。"<<endl;
	cout<<"读取中。。。"<<endl;
	int i;
	UINT1 Size=0;
	FILE * inMap;
	FILE * outMap;
	RoadNum=0;
	inMap = fopen(filename1,"rb");
	if(NULL==inMap)
		{cout<<"源文件不存在！"<<endl;
        cout<<"请手动输入文件的路径："<<endl;}
    else cout<<"    文件读取成功！"<<endl<<"    Success!"<<endl;

	outMap = fopen(filename2,"r+");
	if(NULL==outMap)
	{
		printf("out.txt不存在！\n");
	}
		

	for(RoadNum = 0; fread(&Size, 1, 2, inMap) > 0; RoadNum++)
	{
		Size = MC_GET_SHORT(&Size);
		fseek(inMap, Size - 2, SEEK_CUR);
	}

	pRoadRecord = (RoadRecord *)malloc(sizeof(RoadRecord)*RoadNum);
	fseek(inMap, 0, SEEK_SET);

	for(i=0; i<RoadNum; ++i)
	{
		fread(&pRoadRecord[i].RecordSize, 1, 2, inMap);
		fread(&pRoadRecord[i].LinkID, 1, 4, inMap);
		fread(&pRoadRecord[i].NameSize, 1, 2, inMap);
		fread(&pRoadRecord[i].RoadInfo, 1, 4, inMap);

		pRoadRecord[i].RecordSize = MC_GET_SHORT(&pRoadRecord[i].RecordSize);
		pRoadRecord[i].LinkID = MC_GET_LONG(&pRoadRecord[i].LinkID);
		pRoadRecord[i].NameSize = MC_GET_SHORT(&pRoadRecord[i].NameSize);
		pRoadRecord[i].RoadInfo = MC_GET_LONG(&pRoadRecord[i].RoadInfo);

		if(pRoadRecord[i].RecordSize!=0x0c && pRoadRecord[i].NameSize != 0)
		{
			pRoadRecord[i].RoadName = (char *)malloc(pRoadRecord[i].NameSize+1);
			if(NULL == pRoadRecord[i].RoadName)
				printf("roadwrong");
			fread(pRoadRecord[i].RoadName, 1, pRoadRecord[i].NameSize+1, inMap);
			fseek(inMap, 1, SEEK_CUR);
		}
		else
		{
			pRoadRecord[i].RoadName = NULL;
		}
	}
	
	fclose(outMap);
	outMap = NULL;
}


void Sort1()   //////////////////////////////////////////////////////////////////////////////////////////
{
    cout<<"请选择排序方式："<<endl;
    cout<<"1.选择排序(按LinkID排序)"<<endl;
    cout<<"2.冒泡排序(按Bruch(岔道数)排序)"<<endl;
    cout<<"3.插入排序(按Class番号排序)"<<endl;
    cout<<"4.快速排序(按LinkID排序)"<<endl;
	cout<<"0.返回"<<endl;
    cout<<"  请选择：";
    int m;
    cin>>m;
	cout<<"sort start..."<<endl;
    switch(m)
    {
        case 1:
			{
				ChooseSort(pRoadRecord,RoadNum);
				FileWrite(".\\data\\choosesort.txt");
				cout<<"排好序的文件在.\\data\\choosesort.txt中"<<endl;
				break;
			}
        case 2:
			{
				BubbleSort(pRoadRecord,RoadNum);
				FileWrite(".\\data\\bubblesort.txt");
				cout<<"排好序的文件在.\\data\\bubblesort.txt中"<<endl;
				break;
			}
        case 3:
			{
				InsertSort(pRoadRecord,RoadNum);
				FileWrite(".\\data\\insertsort.txt");
				cout<<"排好序的文件在.\\data\\insertsort.txt中"<<endl;
				break;
			}
        case 4:
			{
				QuickSortTime(pRoadRecord,0,RoadNum-1);
				FileWrite(".\\data\\quicksort.txt");
				cout<<"排好序的文件在.\\data\\quicksort.txt中"<<endl;
				break;
			}
		case 0:
			{break;}
    }
}


void FileWrite(char * filename)  //////////////////////////////////////////////////////////////
{
	int i;
	FILE * outMap;

	outMap = fopen(filename,"r+");
	if(NULL==outMap)
		printf("wrong\n");

	for(i=0; i<RoadNum; ++i)
	{
		fprintf(outMap, "%9hd", pRoadRecord[i].RecordSize);
		fprintf(outMap, "%9d", pRoadRecord[i].LinkID);
		fprintf(outMap, "%9hd", pRoadRecord[i].NameSize);
		fprintf(outMap, "%9d", pRoadRecord[i].flag);
		fprintf(outMap, "%9hd", pRoadRecord[i].Bruch);
		fprintf(outMap, "%9hd     ", pRoadRecord[i].dispclass);
		if(pRoadRecord[i].RoadName != NULL)
			fprintf(outMap, "%s", pRoadRecord[i].RoadName);
		fprintf(outMap, "\n");
	}

	fclose(outMap);
	outMap = NULL;
}

void BinaryWrite(char * filename)    //////////////////////////////////////////////////////////////////
{
	int i;
	FILE * outMap;

	outMap = fopen(filename,"rb+");
	if(NULL==outMap)
		printf("wrong\n");

	for(i=0; i<RoadNum; ++i)
	{	
		pRoadRecord[i].RecordSize = MC_GET_SHORT(&pRoadRecord[i].RecordSize);
		pRoadRecord[i].LinkID = MC_GET_LONG(&pRoadRecord[i].LinkID);
		pRoadRecord[i].NameSize = MC_GET_SHORT(&pRoadRecord[i].NameSize);
		pRoadRecord[i].RoadInfo = MC_GET_LONG(&pRoadRecord[i].RoadInfo);

		fwrite(&pRoadRecord[i].RecordSize, 1, 2, outMap);
		fwrite(&pRoadRecord[i].LinkID,1,4,outMap);
		fwrite(&pRoadRecord[i].NameSize,1,2,outMap);
		fwrite(&pRoadRecord[i].RoadInfo,1,4,outMap);
		fwrite(pRoadRecord[i].RoadName, 1, pRoadRecord[i].lengh, outMap);
		
	}

	fclose(outMap);
	outMap = NULL;
}

int main()   ///////////////////////////////////////////////////////////////////////////////////////////
{
    system("color b");
    start2();
    int n;
sss:begin1();
    cin>>n;
    switch(n)
    {
        case 1:
			{
				system("cls");
				start1();
				char exeFullPath1[256];
				char exeFullPath2[256];
				char exeFullPath3[256];
				GetCurrentDirectory(256,exeFullPath1);
				GetCurrentDirectory(256,exeFullPath2);
				GetModuleFileName(NULL,exeFullPath3,256);

				strcat(exeFullPath1,"\\data\\GTBL.dat");
				strcat(exeFullPath2,"\\data\\out.txt");
				
				printf("%s\n",exeFullPath1);
				printf("%s\n",exeFullPath2);
				printf("%s\n",exeFullPath3);
				
				exit(0);
				FileRead(exeFullPath1,exeFullPath2);
				RoadInfomation(pRoadRecord,RoadNum);
				FileWrite(exeFullPath2);
				goto sss;
			}
        case 2:{
				system("cls");
				start1();
				Sort1();
				goto sss;
			   }
        case 3:
			{
				system("cls");
				start1();
				SortSelect(pRoadRecord,RoadNum);
				goto sss;
			}
        case 4:
			{
				system("cls");
				start1();
				BinaryWrite(".\\data\\sortGTBL.dat");
				cout<<"更新的文件在.\\data\\sortGTBL.dat中"<<endl;
				goto sss;
			}
        case 0:{break;}
    }
	return 0;
}