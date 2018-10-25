#include"emap.h"
#include"emapui.h"
#include<cstdio>
#include<algorithm>
#include<cstring>

Road *roads;
// 保存所有道路的数组
int roadsSize;
// 道路数量
bool sorted=false;
// 已排序 

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
							printf("文件读取成功，共%d条记录。               \n",roadsSize);
                            system("pause");
						} else {
							printf("文件读取失败，请尝试指定文件路径。\n");
							goto first;
						}
						break;
					case 2:
                        first:
						printf("请输入文件路径：");
						gets(c);
						if(c[0]!='0' && c[0]!=0){
							clearMemory();
							processPath(c);
							if (openFile(c)==0){
								a=1;
								printf("文件读取成功，共%d条记录。           \n",roadsSize);
								system("pause");
							} 
							else {
								printf("文件读取失败，请重新输入，或直接回车退出。\n");
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
	                       printf("冒泡排序用时：%.3f秒。\n",t1/1000.0);
						   system("pause");
						   break;
					case 2:
						t2=selectionSort();
	                       printf("选择排序用时：%.3f秒。\n",t2/1000.0);
						   system("pause");
						   break;
					case 3:
						t3=insertionSort();
	                       printf("插入排序用时：%.3f秒。\n",t3/1000.0);
						   system("pause");
						   break;
					case 4:
						t4=quickSort();
	                       printf("快速排序用时：%.3f秒。\n",t4/1000.0);
						   system("pause");
						   break;
					case 0:break;
					default:
						goto showSortMenu;
				}
				}
				else {
					printf("文件尚未读取，请先读取文件\n");
					system("pause");
				}
				break;
			case 3:
				if(a==1){
					showDispclassMenu:
					switch(showMenu(dispclassMenu,dispclassMenuSize)){
						case 1:
							printf("请输入LinkID，或直接回车退出：");
							third:
							gets(s);
							if (s[0]==0){
								break;
							} else if (s[0]<'0' || s[0]>'9'){
								printf("您应当输入数字：");
								goto third;
							}
							sscanf(s,"%d",&b);
							//if (b==0)
							//	break;
						    r=queryByLinkID(b);
							if(r==nullRoad){
								printf("查询失败，请重新输入，或直接回车退出：");
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
							printf("请输入ClassID，或直接回车退出：");
							fourth:
							gets(s);
							if (s[0]==0){
								break;
							} else if (s[0]<'0' || s[0]>'9'){
								printf("您应当输入数字：");
								goto fourth;
							}
							sscanf(s,"%d",&b);
							//if (b==0)
							//	break;
							pr=queryByDispClass(b,&resc);
							if(resc==0 || pr==NULL){
								printf("查询失败，请重新输入，或直接回车退出：");
								goto fourth;
							}
							else{
								printAndSave(pr,resc);
							}
							break;
						case 3:
							printf("请输入岔路数，或直接回车退出：");
							fifth:
							gets(s);
							if (s[0]==0){
								break;
							} else if (s[0]<'0' || s[0]>'9'){
								printf("您应当输入数字：");
								goto fifth;
							}
							sscanf(s,"%d",&b);
							//if (b==-1)
							//	break;
							pr=queryByBranch(b,&resc);
							if(resc==0 || pr==NULL){
								printf("查询失败，请重新输入，或直接回车退出：");
								goto fifth;
							}
							else{
								printAndSave(pr,resc);
							}
							break;
						case 4:
							printf("请输入道路名称，或直接回车退出：１＝");
							sixth:
							gets(s);
							if(s[0]=='0' || s[0]==0)
								break;
							sprintf(c,"１＝%s",s);
							pr=queryByName(c,&resc);
							if(resc==0 || pr==NULL){
								printf("查询失败，请重新输入，或直接回车退出：１＝");
								goto sixth;
							}
							else{
								printAndSave(pr,resc);
							}
							break;
						case 5:
							if (!sorted){ 
								printf("数据尚未排序，请先排序。"); 
								system("pause");
								break;
							}
						 	printf("请输入LinkID，直接回车退出：");
							thirdBi:
							gets(s);
							if (s[0]==0){
								break;
							} if (s[0]<'0' || s[0]>'9'){
								printf("您应当输入数字：");
								goto thirdBi;
							}
							sscanf(s,"%d",&b);
							if (b==0)
								break;
						    r=queryByLinkIDBinary(b);
							if(r==nullRoad){
								printf("查询失败，请重新输入，直接回车退出：");
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
					printf("文件尚未读取，请先读取文件。\n");
					system("pause");
				}
				break;
			case 4:
				if(a==1){
	                second:
					printf("请输入文件保存路径，或直接回车退出：");
					gets(s);
					if(s[0]!='0' && s[0]!=0){
						processPath(s);
						if(saveFile(s)==0){
							printf("文件保存成功。\n");
							system("pause");
						}
						else{
							printf("文件保存失败，请重新输入路径，或直接回车退出：\n");
							goto second;
						}
					}
				} else {
						printf("文件尚未读取，请先读取文件。\n");
						system("pause");
				}
				break;
			case 5:
				if(a==1){
					printf("请输入文件路径：");
					txtOutputPath:
					gets(s);
					if (s[0]=='0' || s[0]==0)
						break;
					processPath(s);
					if ((fp=fopen(s,"w"))==NULL){
						printf("文件保存失败，请重新输入路径，或直接回车退出：");
						goto txtOutputPath; 
					}
					print(roads,roadsSize,fp);
					printf("输出完毕。");
					fclose(fp);
					system("pause");
				} else {
					printf("文件尚未读取，请先读取文件。\n");
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
