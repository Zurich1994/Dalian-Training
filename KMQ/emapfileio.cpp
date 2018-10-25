#include"emap.h"
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

extern Road *roads;
// �������е�·������
extern int roadsSize;
// ��·����
extern bool sorted;
// ������ 

const char inIcon[]=
"\n""\n"
"�����������������������������Шv\n"
"���������������������������������v\n"
"������������������DAT ������������\n"
"����������������������������������\n"
"����������������������������������\n"
"����������������������������������\n"
"����������������������������������\n"
"�������������������������������������v�������ةةةةةةةةة�\n"
"���������������������������������������v���ȡ�������������������\n"
"���������������������������������������u���ȡ�������������������\n"
"�������������������������������������u�����ȡ�������������������\n"
"���������������������������������������������ЩЩЩЩЩЩЩЩЩ�\n"
"\n""\n";

const char outIcon[]=
"\n""\n"
"�����������������������������Шv\n"
"���������������������������������v\n"
"������������������%s������������\n"
"����������������������������������\n"
"����������������������������������\n"
"����������������������������������\n"
"����������������������������������\n"
"�����������������������������u���������������ةةةةةةةةة�\n"
"���������������������������u���������������ȡ�������������������\n"
"���������������������������v���������������ȡ�������������������\n"
"�����������������������������v�������������ȡ�������������������\n"
"���������������������������������������������ЩЩЩЩЩЩЩЩЩ�\n"
"\n""\n";


int swapEndian(void *ptr,int size){
	char *p=(char*)ptr;
	char *temp=(char*)malloc(size);
	if (temp==NULL) return 1;
	int i;
	for (i=0;i<size;i++)
		*(temp+size-i-1)=*(p+i);
	for (i=0;i<size;i++)
		*(p+i)=*(temp+i);
	return 0;
}

Road readSingleRoad(FILE * & fp){
	unsigned short size,nameSize;
	unsigned int linkID,info;
	char* name;
	
	// ��ȡ��¼��С������޷���ȡ�򷵻ؿ�ֵ
	if (fread(&size,2,1,fp)<0){
		return nullRoad;
	}
	swapEndian(&size,sizeof(short));
	if (size<12 || size>12+32){
		fseek(fp,size-2,SEEK_CUR);
		return nullRoad;
	}
	// ��ȡlinkID
	fread(&linkID,4,1,fp);
	swapEndian(&linkID,sizeof(int));
	// ��ȡ·������
	fread(&nameSize,2,1,fp);
	swapEndian(&nameSize,sizeof(short));
	// ·������+1�����ȱ�ʾΪ-1(0xFFFF)���㳤·��ǡ�ñ�ת��Ϊ0��
	nameSize++; 
	if (nameSize>32 || nameSize<0){
		return nullRoad;
	}
	// ��ȡ��·��Ϣ
	fread(&info,4,1,fp);
	swapEndian(&info,sizeof(int));
	// ��ȡ·��
	if (nameSize>0){
		name=(char*)malloc(nameSize);
		fread(name,nameSize,1,fp);
	} else {
		name="";
	}
	fseek(fp,size-2-4-2-4-nameSize,SEEK_CUR);
	// �����·��Ϣ

	bool nameFlag=((info&0x80)>0);
	int branch=(info&0x70)>>4;
	int dispClass=info&0xf;
	
	// ���ɵ�·���󲢷���
	Road r(linkID,nameFlag,branch,dispClass,name);
	if (nameSize>0)
		free(name);
	return r;
}

int openFile(string path){
	system("cls");
	puts(inIcon);
	printf("�ļ���ȡ��....                \r");
	FILE *fp;
	fp=fopen(path.c_str(),"rb");
	if (fp==NULL) return 1;
	roadsSize=0;
	while (!feof(fp)){
		Road r=readSingleRoad(fp);
		if (r==nullRoad)
			break;
		roadsSize++;
	}
	roads=new Road[roadsSize];
	fp=fopen(path.c_str(),"rb");
	if (fp==NULL) return 1;
	int i=0;
	while (!feof(fp)){
		Road r=readSingleRoad(fp);
		if (r==nullRoad) break;
		roads[i]=r;
		i++;
		if (i%100==0 || i==roadsSize-2){
	    	printf("�ļ���ȡ��");
	    	int k;
	    	for (k=0;k<i/100%5;k++) printf(".");
	    	for (k=0;k<5-i/100%5;k++) printf(" ");
	    	printf("%7.2f%%\r",(float)i*100/roadsSize); _flushall();
	    }
	}
	if (i<roadsSize) return 1;
	fclose(fp);
	sorted=false;
	return 0;
}

int writeSingleRoad(FILE *&fp, Road source){
	if (fp==NULL) return 1;
	unsigned short nameSize=strlen(source.name);
	unsigned short size;
	if (nameSize==0){
		nameSize=-1;
		size=2+4+2+4; // �ο����ݸ�ʽ
	} else {
		size=2+4+2+4+nameSize+1+1; // �ο����ݸ�ʽ
	}
	swapEndian(&size,sizeof(short));
	swapEndian(&nameSize,sizeof(short));
	unsigned int linkID=source.linkID;
	swapEndian(&linkID,sizeof(int));
	fwrite(&size,2,1,fp);
	fwrite(&linkID,4,1,fp);
	fwrite(&nameSize,2,1,fp);
	int info=source.dispClass+(source.branch<<4);
	if (source.nameFlag)
		info|=(1<<7);
	swapEndian(&info,sizeof(int));
	fwrite(&info,4,1,fp);
	fwrite(source.name,strlen(source.name),1,fp);
	char last=0;
	if (nameSize!=(unsigned short)-1){
		fwrite(&last,1,1,fp);
		fwrite(&last,1,1,fp);
	}
	return 0;
}

int saveFile(string path){
	return saveFile(path,roads,roadsSize);
}

int saveFile(string path, Road * source, int size){
	system("cls");
	printf(outIcon,"DAT ");
	FILE * fp=fopen(path.c_str(),"wb");
	if (fp==NULL) return 1;
	for (int i=0;i<size;i++)
		writeSingleRoad(fp,source[i]);
	fclose(fp);
	return 0;
}

int print(Road* a,int n,FILE * fp){
	if (fp==NULL) return 1;
	if (fp!=stdout) {
		system("cls");	
		printf(outIcon,"TXT ");
	}
	fprintf(fp,
		"���������������Щ��������������Щ��������Щ��������Щ�����������������������\n"
		"��   LinkID   �� ·������Flag �� ��·�� �� ClassID��       ��·����       ��\n"
		);
	string flag;
	for (int i=0;i<n;i++){
		if (i>=30 && fp==stdout){
			fprintf(fp,
				"���������������ة��������������ة��������ة��������ة�����������������������\n"
				"��               ��ѯ�����%5d�����뱣�浽�ļ�������н����            ��\n"
				"����������������������������������������������������������������������������\n",
				n);
			return 0;
		}
		if (a[i].nameFlag)
			flag="��";
		else
			flag="��";
		fprintf(fp,
			"���������������੤�������������੤�������੤�������੤����������������������\n"
			"��   %6d   ��      %s      ��  %4d  ��  %4d  ��%-22s��\n",
			a[i].linkID,flag.c_str(),a[i].branch,a[i].dispClass,a[i].name);
	}
	fprintf(fp,
		"���������������ة��������������ة��������ة��������ة�����������������������\n"
		);
	return 0;
}

int printCSV(FILE * fp,Road * a,int n){
	system("cls");
	printf(outIcon,"CSV ");
	if (fp==NULL) return 1;
	fprintf(fp,"LinkID,·������Flag,��·��,ClassID,��·����\n");
	string flag;
	for (int i=0;i<n;i++){
		if (a[i].nameFlag)
			flag="��";
		else
			flag="��";
		fprintf(fp,"%d,%s,%d,%d,%s\n",
			a[i].linkID,flag.c_str(),a[i].branch,a[i].dispClass,a[i].name);
	}
	fclose(fp);
	return 0;
}

void printAndSave(Road * a,int n){
	print(a,n,stdout);
	sel:
	printf(
		"\n"
		"     ��ϣ����α����ѯ�����\n"
		"         1. ���浽.txt�ļ�\n"
		"         2. ���浽.dat�ļ�\n"
		"         3. ���浽.csv�ļ�\n" 
		"     ֱ�Ӱ��س����������˵���\n" 
		);
	char s[256];
	_flushall();
	char c=getchar();
	_flushall();
	FILE *fp;
	switch(c-'0'){
		case 1:
			printf("�������ļ�·����");
			gets(s);
			if (s[0]=='0' || s[0]==0)
				break;
			processPath(s);
			fp=fopen(s,"w");
			if (print(a,n,fp)==1){
				printf("�ļ��������������ѡ��\n");
				goto sel;
			}
			fclose(fp);
			printf("�ļ������ϣ�");
			system("pause");
			break;
		case 2:
			printf("�������ļ�·����");
			gets(s);
			if (s[0]=='0' || s[0]==0)
				break;
			processPath(s);
			if (saveFile(s,a,n)==1){
				printf("����ļ�����������ѡ��\n");
				goto sel;
			}
			printf("�ļ������ϣ�");
			system("pause");
			break;
		case 3:
			printf("�������ļ�·����");
			gets(s);
			if (s[0]=='0' || s[0]==0)
				break;
			processPath(s);
			fp=fopen(s,"w");
			if (printCSV(fp,a,n)==1){
				printf("�ļ��������������ѡ��\n");
				goto sel;
			}
			fclose(fp);
			printf("�ļ������ϣ�");
			system("pause");
			break;
			break;
		default : return;
	}
}
