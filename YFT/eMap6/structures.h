#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_
#define INFO_SIZE 70000 
#define ROADNAME_SIZE 50 
#define FILENAME "sortedInfo.dat" 
#define RESULT_FILENAME "result.txt" 
#define PATH "GTBL.dat" 
#define SUCCESS 1
#define UNSUCCESS 0 
#define FLOWOUT -1 
#define TYPE_ID 0 
#define TYPE_BRUNCH 1
#define TYPE_CLASSNO 2
#define TYPE_NAME 3
#define CHINESE 0
#define ENGLISH 1


typedef struct RoadMsg_t
{
	int size; 
	int namesize;
	int linkID;
	int roadnameflag;
	int brunch;
	int dispclass;
	char* roadname;
} RoadMsg_t;


typedef struct RoadArray_t
{
	int length;
	RoadMsg_t  *roadMsgs;
}RoadArray_t;


typedef struct LinkListNode_t
{
	RoadMsg_t element;
    LinkListNode_t *link;
}LinkListNode_t;


typedef struct TreeNode_t
{
    RoadMsg_t *data;
    TreeNode_t *leftChild;
    TreeNode_t *rightChild;
}TreeNode_t,*TreeNode_Point;

#endif