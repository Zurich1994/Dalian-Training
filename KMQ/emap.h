#pragma once

#include<string> 
#include<cstdio>
using namespace std;

/* �������� */ 
struct Road{
	unsigned int linkID;    // LinkID
	bool nameFlag;			// ·����������Flag 
	int branch;				// ��·�� 
	int dispClass;			// ����Link�б�ʾClass����
	char name[32];	 		// ��·����

	Road();
	Road(const unsigned int linkID, const bool nameFlag, const int branch,
		const int dispClass, char* const name);
	Road(const Road &source);
	~Road();
	bool operator <(const Road that) const;
	bool operator <=(const Road that) const;
	bool operator ==(const Road that) const;
	Road& operator =(const Road that);
};
void swap(Road * a, Road * b);
// ��������������ָ�룬����������·��
void swap(Road &a, Road &b);
// �������������ð棩
void sv(Road &a, const Road &b);
// ��ֵ���� 

const Road nullRoad(0,false,0,0,"");

/* �ļ������������ */
int openFile(string path);
// ���ļ�, 0: �ɹ���1: ʧ��
Road readSingleRoad(FILE *&fp);
// ��ȡһ����¼�����������¼
int saveFile(string path);
// �����ļ�, 0: �ɹ���1: ʧ��
int writeSingleRoad(FILE *&fp, Road source);
// д�뵥����¼
int saveFile(string path, Road * source, int size);
// ���沿���ļ�, 0: �ɹ���1: ʧ��
int print(Road* a,int n,FILE * fp);
// ������
void printAndSave(Road* a,int n);
// �ڱ�׼��������ѯ�����ѯ�ʱ��淽ʽ 
int printCSV(FILE * fp,Road * a,int n);
// ���.csv 

/* ���򲿷� */
int bubbleSort();
// ð������
int selectionSort();
// ѡ������
int insertionSort();
// ��������
int quickSort();
// ��������  

/* ��ѯ���� */
Road queryByLinkID(const unsigned int linkID);
// ��LinkID��ѯ 
struct Road* queryByDispClass(const unsigned int dispClass,int * n);
// ��dispClass��ѯ������һ������n��Ԫ�ص����� 
struct Road* queryByName(char * const name,int * n);
// ����·���Ʋ�ѯ������һ������n��Ԫ�ص����� 
struct Road* queryByBranch(int branch,int *n);
// ���ֲ�����ѯ������һ������n��Ԫ�ص����� 
Road queryByLinkIDBinary(const unsigned int linkID);
// ��LinkID��ѯ���۰룩
 
void processPath(char * s);
// ��������ŵ�·�� 

