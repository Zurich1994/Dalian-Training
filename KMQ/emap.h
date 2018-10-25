#pragma once

#include<string> 
#include<cstdio>
using namespace std;

/* 基本部分 */ 
struct Road{
	unsigned int linkID;    // LinkID
	bool nameFlag;			// 路线名称有无Flag 
	int branch;				// 岔路数 
	int dispClass;			// 交叉Link列表示Class番号
	char name[32];	 		// 道路名称

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
// 交换函数，传入指针，交换两个道路。
void swap(Road &a, Road &b);
// 交换函数（引用版）
void sv(Road &a, const Road &b);
// 赋值函数 

const Road nullRoad(0,false,0,0,"");

/* 文件输入输出部分 */
int openFile(string path);
// 打开文件, 0: 成功，1: 失败
Road readSingleRoad(FILE *&fp);
// 读取一条记录并返回这个记录
int saveFile(string path);
// 保存文件, 0: 成功，1: 失败
int writeSingleRoad(FILE *&fp, Road source);
// 写入单条记录
int saveFile(string path, Road * source, int size);
// 保存部分文件, 0: 成功，1: 失败
int print(Road* a,int n,FILE * fp);
// 输出表格
void printAndSave(Road* a,int n);
// 在标准输出输出查询结果，询问保存方式 
int printCSV(FILE * fp,Road * a,int n);
// 输出.csv 

/* 排序部分 */
int bubbleSort();
// 冒泡排序
int selectionSort();
// 选择排序
int insertionSort();
// 插入排序
int quickSort();
// 快速排序  

/* 查询部分 */
Road queryByLinkID(const unsigned int linkID);
// 按LinkID查询 
struct Road* queryByDispClass(const unsigned int dispClass,int * n);
// 按dispClass查询，返回一个包含n个元素的数组 
struct Road* queryByName(char * const name,int * n);
// 按道路名称查询，返回一个包含n个元素的数组 
struct Road* queryByBranch(int branch,int *n);
// 按分岔数查询，返回一个包含n个元素的数组 
Road queryByLinkIDBinary(const unsigned int linkID);
// 按LinkID查询（折半）
 
void processPath(char * s);
// 处理带引号的路径 

