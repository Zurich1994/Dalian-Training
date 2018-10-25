#pragma once

#include"emap.h"
#include<cstdio>
#include<cstdlib>

extern int roadsSize;

const string mainMenu[]={"读取文件", "排序","检索","更新（输出二进制文件）","输出文本文件","关于","退出"};
const int mainMenuSize=7;
const string readMenu[]={"打开默认文件(GTBL.dat)", "输入文件路径并打开","返回"};
const int readMenuSize=3;
const string sortMenu[]={"冒泡排序", "选择排序","插入排序","快速排序（推荐）","返回"};
const int sortMenuSize=5;
const string dispclassMenu[]={"指定LinkID检索", "指定交叉Link列表示Class番号检索","指定岔路数检索","指定道路名称检索","二分查找LinkID","返回"};
const int dispclassMenuSize=6;
char logo[]=
"────────────────────────────────────────\n"
"      　┌─　　　┌────┐　┐┌　┌　┌────┐\n"
"      ┌┼───┐　　　┌─┘┌┼├─┼┐│├──┐│        Ver. 2013\n"
"      ││　　　│　　　╰╮　　││　│││╯─┌╯│\n"
"      ├┼───┤└───┼┘　││　│││─┬╯─│\n"
"      └┼───╯　　　　│　　││　│╯│└──╮│       管 理 系 统\n"
"      　╰───┘╰───┘　╰┴╰──┘└────╯  \n"
"\n"
"────────────────────────────────────────\n";

char about[]=
"　　　　　　　　　┌─　　　┌────┐　┐┌　┌　┌────┐\n"
"　　　　　　　　┌┼───┐　　　┌─┘┌┼├─┼┐│├──┐│\n"
"　　　　　　　　││　　　│　　　╰╮　　││　│││╯─┌╯│\n"
"　　　　　　　　├┼───┤└───┼┘　││　│││─┬╯─│\n"
"　　　　　　　　└┼───╯　　　　│　　││　│╯│└──╮│\n"
"　　　　　　　　　╰───┘╰───┘　╰┴╰──┘└────╯\n"
"\n"
"     　　  　   Designed by eMapper in Dalian, Coded in Neusoft\n"
"       　  　　            哈尔滨工程大学软件学院\n"
"\n"
"\n"
"　　　　　　　　　　　　　　首席软件架构师　康明青\n"
"　　　　　　　　　　　　　　首席界面设计师　孔庆瑜\n"
"　　　　　　　　　　　　　　首席软件测试员　张玮琳\n"
"　　　　　　　　　　　　　　首席算法设计师　赵梦蕉\n"
"　　　　　　　　　　　　　　首席新闻发言人　王　贺\n";
 

inline void showLogo(){
	printf("%s",logo);
}
inline int showMenu(const string items[],int itemSize){
	system("cls");
	printf("当前数据量：%d条\n",roadsSize);
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
