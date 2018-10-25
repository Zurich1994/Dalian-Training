#include"emap.h"
#include"emapui.h"
#include<cstdio>
#include<algorithm>
#include<cstring>

Road *roads;
// �������е�·������
int roadsSize;
// ��·����
bool sorted=false;
// ������ 

void clearMemory(){
	if (roads!=NULL)
		delete[] roads;
	roads=NULL;
	roadsSize=0;
}

void processPath(char * s){
	int len=strlen(s);
	if (s[0]=='"' && s[len-1]=='"'){
		for (int i=1;i<len;i++){
			s[i-1]=s[i];
		}
		s[len-2]=0;
	}
}

int main(){
	Road r,*pr;
	unsigned int b;
	int a=0,t1,t2,t3,t4,resc;
	char c[200],s[200];
	FILE *fp;
	while (true){
		switch(showMenu(mainMenu,mainMenuSize)){
			case 1:
				showReadMenu:
				switch(showMenu(readMenu,readMenuSize)){
					case 1:
						clearMemory();
						if (openFile("GTBL.dat")==0){
							a=1;
							printf("�ļ���ȡ�ɹ�����%d����¼��               \n",roadsSize);
                            system("pause");
						} else {
							printf("�ļ���ȡʧ�ܣ��볢��ָ���ļ�·����\n");
							goto first;
						}
						break;
					case 2:
                        first:
						printf("�������ļ�·����");
						gets(c);
						if(c[0]!='0' && c[0]!=0){
							clearMemory();
							processPath(c);
							if (openFile(c)==0){
								a=1;
								printf("�ļ���ȡ�ɹ�����%d����¼��           \n",roadsSize);
								system("pause");
							} 
							else {
								printf("�ļ���ȡʧ�ܣ����������룬��ֱ�ӻس��˳���\n");
								goto first;
							}
						}
						else break;
						break;
					case 0: break;
					default:
						goto showReadMenu;
				}
				break; 
			case 2:
				if(a==1){
				showSortMenu:
				switch(showMenu(sortMenu,sortMenuSize)){
					case 1:
						t1=bubbleSort();
	                       printf("ð��������ʱ��%.3f�롣\n",t1/1000.0);
						   system("pause");
						   break;
					case 2:
						t2=selectionSort();
	                       printf("ѡ��������ʱ��%.3f�롣\n",t2/1000.0);
						   system("pause");
						   break;
					case 3:
						t3=insertionSort();
	                       printf("����������ʱ��%.3f�롣\n",t3/1000.0);
						   system("pause");
						   break;
					case 4:
						t4=quickSort();
	                       printf("����������ʱ��%.3f�롣\n",t4/1000.0);
						   system("pause");
						   break;
					case 0:break;
					default:
						goto showSortMenu;
				}
				}
				else {
					printf("�ļ���δ��ȡ�����ȶ�ȡ�ļ�\n");
					system("pause");
				}
				break;
			case 3:
				if(a==1){
					showDispclassMenu:
					switch(showMenu(dispclassMenu,dispclassMenuSize)){
						case 1:
							printf("������LinkID����ֱ�ӻس��˳���");
							third:
							gets(s);
							if (s[0]==0){
								break;
							} else if (s[0]<'0' || s[0]>'9'){
								printf("��Ӧ���������֣�");
								goto third;
							}
							sscanf(s,"%d",&b);
							//if (b==0)
							//	break;
						    r=queryByLinkID(b);
							if(r==nullRoad){
								printf("��ѯʧ�ܣ����������룬��ֱ�ӻس��˳���");
								goto third;
							}
							else{
								pr=(Road*)malloc(sizeof(Road));
								if (pr==NULL) break;
								pr[0]=r;
								printAndSave(pr,1);
								free(pr);
							}
							break;
						case 2:
							printf("������ClassID����ֱ�ӻس��˳���");
							fourth:
							gets(s);
							if (s[0]==0){
								break;
							} else if (s[0]<'0' || s[0]>'9'){
								printf("��Ӧ���������֣�");
								goto fourth;
							}
							sscanf(s,"%d",&b);
							//if (b==0)
							//	break;
							pr=queryByDispClass(b,&resc);
							if(resc==0 || pr==NULL){
								printf("��ѯʧ�ܣ����������룬��ֱ�ӻس��˳���");
								goto fourth;
							}
							else{
								printAndSave(pr,resc);
							}
							break;
						case 3:
							printf("�������·������ֱ�ӻس��˳���");
							fifth:
							gets(s);
							if (s[0]==0){
								break;
							} else if (s[0]<'0' || s[0]>'9'){
								printf("��Ӧ���������֣�");
								goto fifth;
							}
							sscanf(s,"%d",&b);
							//if (b==-1)
							//	break;
							pr=queryByBranch(b,&resc);
							if(resc==0 || pr==NULL){
								printf("��ѯʧ�ܣ����������룬��ֱ�ӻس��˳���");
								goto fifth;
							}
							else{
								printAndSave(pr,resc);
							}
							break;
						case 4:
							printf("�������·���ƣ���ֱ�ӻس��˳�������");
							sixth:
							gets(s);
							if(s[0]=='0' || s[0]==0)
								break;
							sprintf(c,"����%s",s);
							pr=queryByName(c,&resc);
							if(resc==0 || pr==NULL){
								printf("��ѯʧ�ܣ����������룬��ֱ�ӻس��˳�������");
								goto sixth;
							}
							else{
								printAndSave(pr,resc);
							}
							break;
						case 5:
							if (!sorted){ 
								printf("������δ������������"); 
								system("pause");
								break;
							}
						 	printf("������LinkID��ֱ�ӻس��˳���");
							thirdBi:
							gets(s);
							if (s[0]==0){
								break;
							} if (s[0]<'0' || s[0]>'9'){
								printf("��Ӧ���������֣�");
								goto thirdBi;
							}
							sscanf(s,"%d",&b);
							if (b==0)
								break;
						    r=queryByLinkIDBinary(b);
							if(r==nullRoad){
								printf("��ѯʧ�ܣ����������룬ֱ�ӻس��˳���");
								goto thirdBi;
							}
							else{
								pr=(Road*)malloc(sizeof(Road));
								if (pr==NULL) break;
								pr[0]=r;
								printAndSave(pr,1);
								free(pr);
							}
							break;
						case 0:break;
						default:
							goto showDispclassMenu;
					}
				} else {
					printf("�ļ���δ��ȡ�����ȶ�ȡ�ļ���\n");
					system("pause");
				}
				break;
			case 4:
				if(a==1){
	                second:
					printf("�������ļ�����·������ֱ�ӻس��˳���");
					gets(s);
					if(s[0]!='0' && s[0]!=0){
						processPath(s);
						if(saveFile(s)==0){
							printf("�ļ�����ɹ���\n");
							system("pause");
						}
						else{
							printf("�ļ�����ʧ�ܣ�����������·������ֱ�ӻس��˳���\n");
							goto second;
						}
					}
				} else {
						printf("�ļ���δ��ȡ�����ȶ�ȡ�ļ���\n");
						system("pause");
				}
				break;
			case 5:
				if(a==1){
					printf("�������ļ�·����");
					txtOutputPath:
					gets(s);
					if (s[0]=='0' || s[0]==0)
						break;
					processPath(s);
					if ((fp=fopen(s,"w"))==NULL){
						printf("�ļ�����ʧ�ܣ�����������·������ֱ�ӻس��˳���");
						goto txtOutputPath; 
					}
					print(roads,roadsSize,fp);
					printf("�����ϡ�");
					fclose(fp);
					system("pause");
				} else {
					printf("�ļ���δ��ȡ�����ȶ�ȡ�ļ���\n");
					system("pause");
				}
				break;
			case 6:
				system("cls");
				puts(about);
				system("pause");
				break;
			case 0:
				clearMemory();
				return 0; 
			default:
				break;
		}
	}
	
}
