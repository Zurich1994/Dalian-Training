#ifndef _IOFILE_H_
#define _IOFILE_H_

#include "structures.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <time.h>
#define  GET_SHORT(date)    ((((date)&0x00ff)<<8)|((date)>>8))//�����������ֽ���
#define  GET_INT(date)      ((GET_SHORT( date & 0x0000ffff))<<16)|(GET_SHORT(date>>16))//����int�������ֽڵ�λ��
#define  GET_CLASS(date)    (date & 15)//���dispclassֵ
#define  GET_CROSS(date)    ((date>>4) & 7)//���branchֵ
#define  GET_FLAG(date)     ((date>>7) & 1)//���flagֵ
#define  SET_NODE(date1,date2,date3)    ( (date1)|(date2<<4)|(date3<<7))

int readToArray(char*, RoadArray_t*);
int readToTree(TreeNode_Point* , RoadArray_t*);
int writeFromArray(char*, RoadArray_t*);
int writeFromTree(char*, TreeNode_Point*);
int writeresult(char*, RoadArray_t*);

#endif