#pragma once

#include"emap.h"
#include<cstdio>
#include<cstdlib>

extern int roadsSize;

const string mainMenu[]={"��ȡ�ļ�", "����","����","���£�����������ļ���","����ı��ļ�","����","�˳�"};
const int mainMenuSize=7;
const string readMenu[]={"��Ĭ���ļ�(GTBL.dat)", "�����ļ�·������","����"};
const int readMenuSize=3;
const string sortMenu[]={"ð������", "ѡ������","��������","���������Ƽ���","����"};
const int sortMenuSize=5;
const string dispclassMenu[]={"ָ��LinkID����", "ָ������Link�б�ʾClass���ż���","ָ����·������","ָ����·���Ƽ���","���ֲ���LinkID","����"};
const int dispclassMenuSize=6;
char logo[]=
"��������������������������������������������������������������������������������\n"
"      ������������������������������������������������\n"
"      ���੤��������������������������ੴ������������        Ver. 2013\n"
"      �������������������t�r�����������������s�����s��\n"
"      ���੤�����ȩ��������੼�����������������Шs����\n"
"      ���੤�����s�����������������������s���������r��       �� �� ϵ ͳ\n"
"      ���t���������t�����������t�بt�����������������s  \n"
"\n"
"��������������������������������������������������������������������������������\n";

char about[]=
"����������������������������������������������������������������\n"
"�������������������੤��������������������������ੴ������������\n"
"�����������������������������������t�r�����������������s�����s��\n"
"�������������������੤�����ȩ��������੼�����������������Шs����\n"
"�������������������੤�����s�����������������������s���������r��\n"
"�������������������t���������t�����������t�بt�����������������s\n"
"\n"
"     ����  ��   Designed by eMapper in Dalian, Coded in Neusoft\n"
"       ��  ����            ���������̴�ѧ����ѧԺ\n"
"\n"
"\n"
"������������������������������ϯ�����ܹ�ʦ��������\n"
"������������������������������ϯ�������ʦ�������\n"
"������������������������������ϯ��������Ա��������\n"
"������������������������������ϯ�㷨���ʦ�����ν�\n"
"������������������������������ϯ���ŷ����ˡ�������\n";
 

inline void showLogo(){
	printf("%s",logo);
}
inline int showMenu(const string items[],int itemSize){
	system("cls");
	printf("��ǰ��������%d��\n",roadsSize);
	showLogo();
	_flushall();
	int i,maxLength=-1;
	for (i=0;i<itemSize;i++){
		int len=items[i].length();
		if (len>maxLength)
			maxLength=items[i].length();
	}
	for (i=0;i<itemSize;i++){
		int j;
		for (j=0;j<(80-maxLength-3)/2;j++)
			printf(" ");
		int num=(i==itemSize-1?0:i+1);
		printf("%d. %s\n",num,items[i].c_str());
	}
	char c=getchar()-'0';
	_flushall();
	return c;
}