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
            case 0:cout<<"���������������������������������������"<<endl;
                   cout<<"�������������������������������������������������������������"<<endl;
                   cout<<"��������ǩ����������������������ǩǩ��ǩ����ǩ���������������"<<endl;
                   cout<<"������������������������t�r�����������������s�����s����������"<<endl;
                   cout<<"��������ǩǩ������ϩ��������ǩ������������������רs������������"<<endl;
                   cout<<"��������ǩ������s�����������������������s���������r����������"<<endl;
                   cout<<"��������  �t���������t�����������t�ߨt�����������������s��������"<<endl;

                   break;
            case 1:
                   cout<<"���������������������������������������"<<endl;
                   cout<<"�������������������������������������������������������������"<<endl;
                   cout<<"��������ǩ����������������������ǩǩ��ǩ����ǩ���������������"<<endl;
                   cout<<"������������������������t�r�����������������s�����s����������"<<endl;
                   cout<<"��������ǩǩ������ϩ��������ǩ������������������רs������������"<<endl;
                   cout<<"�������嗢�ǩ������s�����������������������s���������r����������"<<endl;
                   cout<<"��������  �t���������t�����������t�ߨt�����������������s��������"<<endl;
                   break;
            case 2:
                   cout<<"���������������������������������������"<<endl;
                   cout<<"�������������������������������������������������������������"<<endl;
                   cout<<"��������ǩ����������������������ǩǩ��ǩ����ǩ���������������"<<endl;
                   cout<<"������������������������t�r�����������������s�����s����������"<<endl;
                   cout<<"��������ǩǩ������ϩ��������ǩ������������������רs������������"<<endl;
                   cout<<"��������ǩ������s�����������������������s���������r����������"<<endl;
                   cout<<"��������  �t���������t�����������t�ߨt�����������������s��������"<<endl;
                   break;
            case 3:
                   cout<<"���������������������������������������"<<endl;
                   cout<<"�������������������������������������������������������������"<<endl;
                   cout<<"��������ǩ����������������������ǩǩ��ǩ����ǩ���������������"<<endl;
                   cout<<"�������逸�����������������t�r�����������������s�����s����������"<<endl;
                   cout<<"��������ǩǩ������ϩ��������ǩ������������������רs������������"<<endl;
                   cout<<"��������ǩ������s�����������������������s���������r����������"<<endl;
                   cout<<"��������  �t���������t�����������t�ߨt�����������������s��������"<<endl;
                   break;
            case 4:
                   cout<<"���������������������������������������"<<endl;
                   cout<<"�������������������������������������������������������������"<<endl;
                   cout<<"�������侀�ǩ����������������������ǩǩ��ǩ����ǩ���������������"<<endl;
                   cout<<"������������������������t�r�����������������s�����s����������"<<endl;
                   cout<<"��������ǩǩ������ϩ��������ǩ������������������רs������������"<<endl;
                   cout<<"��������ǩ������s�����������������������s���������r����������"<<endl;
                   cout<<"��������  �t���������t�����������t�ߨt�����������������s��������"<<endl;
                   break;
            case 5:
                   cout<<"���������������������������������������"<<endl;
                   cout<<"�������������������������������������������������������������"<<endl;
                   cout<<"��������ǩ����������������������ǩǩ��ǩ����ǩ���������������"<<endl;
                   cout<<"������������������������t�r�����������������s�����s����������"<<endl;
                   cout<<"��������ǩǩ������ϩ��������ǩ������������������רs������������"<<endl;
                   cout<<"��������ǩ������s�����������������������s���������r����������"<<endl;
                   cout<<"��������  �t���������t�����������t�ߨt�����������������s��������"<<endl;
                   break;
            case 6:
                   cout<<"���������������������������������������"<<endl;
                   cout<<"�������������������������������������������������������������"<<endl;
                   cout<<"��������ǩ����������������������ǩǩ��ǩ����ǩ���������������"<<endl;
                   cout<<"������������������������t�r�����������������s�����s����������"<<endl;
                   cout<<"��������ǩǩ������ϩ��������ǩ������������������רs������������"<<endl;
                   cout<<"��������ǩ������s�����������������������s���������r����������"<<endl;
                   cout<<"��������  �t���������t�����������t�ߨt�����������������s��������"<<endl;
                   break;
        }
        cout<<"���������������������������������������"<<endl;
		cout<<"____________________________________________________________________________"<<endl;
		cout<<"                          --Dream of Miracle  ��Ʒ--                        "<<endl;
		cout<<"                             --���ո������--                                  "<<endl;
		if(GetAsyncKeyState(' ')) {break;}
        system("cls");
		}
cout<<endl;
}
void start1()
{
	system("cls");    
	cout<<"���������������������������������������"<<endl;
        cout<<"�������������������������������������������������������������"<<endl;
        cout<<"��������ǩ����������������������ǩǩ��ǩ����ǩ���������������"<<endl;
        cout<<"������������������������t�r�����������������s�����s����������"<<endl;
        cout<<"��������ǩǩ������ϩ��������ǩ������������������רs������������"<<endl;
        cout<<"��������ǩ������s�����������������������s���������r����������"<<endl;
        cout<<"��������  �t���������t�����������t�ߨt�����������������s��������"<<endl;
		cout<<"���������������������������������������"<<endl;
		cout<<"____________________________________________________________________________"<<endl;
		cout<<"                          --Dream of Miracle  ��Ʒ--                        "<<endl;
		
}
void begin1()
{
    cout<<endl;
    cout<<"��ѡ���������ࣺ"<<endl;
    cout<<"         1:��ȡ�ļ�"<<endl;
    cout<<"         2:����"<<endl;
    cout<<"         3:����"<<endl;
    cout<<"         4:����"<<endl;
    cout<<"         0:�˳�"<<endl;
    cout<<"  ��ѡ��";
}
RoadRecord * pRoadRecord;
int RoadNum;

void FileRead(char * filename1, char * filename2)/////////////////////////////////////////////////////////////
{
	cout<<"��ȡ�ļ�������"<<endl;
	cout<<"��ȡ�С�����"<<endl;
	int i;
	UINT1 Size=0;
	FILE * inMap;
	FILE * outMap;
	RoadNum=0;
	inMap = fopen(filename1,"rb");
	if(NULL==inMap)
		{cout<<"Դ�ļ������ڣ�"<<endl;
        cout<<"���ֶ������ļ���·����"<<endl;}
    else cout<<"    �ļ���ȡ�ɹ���"<<endl<<"    Success!"<<endl;

	outMap = fopen(filename2,"r+");
	if(NULL==outMap)
	{
		printf("out.txt�����ڣ�\n");
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
    cout<<"��ѡ������ʽ��"<<endl;
    cout<<"1.ѡ������(��LinkID����)"<<endl;
    cout<<"2.ð������(��Bruch(�����)����)"<<endl;
    cout<<"3.��������(��Class��������)"<<endl;
    cout<<"4.��������(��LinkID����)"<<endl;
	cout<<"0.����"<<endl;
    cout<<"  ��ѡ��";
    int m;
    cin>>m;
	cout<<"sort start..."<<endl;
    switch(m)
    {
        case 1:
			{
				ChooseSort(pRoadRecord,RoadNum);
				FileWrite(".\\data\\choosesort.txt");
				cout<<"�ź�����ļ���.\\data\\choosesort.txt��"<<endl;
				break;
			}
        case 2:
			{
				BubbleSort(pRoadRecord,RoadNum);
				FileWrite(".\\data\\bubblesort.txt");
				cout<<"�ź�����ļ���.\\data\\bubblesort.txt��"<<endl;
				break;
			}
        case 3:
			{
				InsertSort(pRoadRecord,RoadNum);
				FileWrite(".\\data\\insertsort.txt");
				cout<<"�ź�����ļ���.\\data\\insertsort.txt��"<<endl;
				break;
			}
        case 4:
			{
				QuickSortTime(pRoadRecord,0,RoadNum-1);
				FileWrite(".\\data\\quicksort.txt");
				cout<<"�ź�����ļ���.\\data\\quicksort.txt��"<<endl;
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
				cout<<"���µ��ļ���.\\data\\sortGTBL.dat��"<<endl;
				goto sss;
			}
        case 0:{break;}
    }
	return 0;
}