#include "ioFile.h"
#include "structures.h"
/*********************************************************************************************************
** FileName:                  ioFile.h                                                                   *
** Last version date:         2013-07-30                                                                 *
** Description:         Read the data in the database,and by sorting sorting                             *                                     
** Author:                   颜凡腾 王晓楠                                                               *
*********************************************************************************************************/

#define  GET_SHORT(date)    ((((date)&0x00ff)<<8)|((date)>>8))
#define  GET_INT(date)      ((GET_SHORT( date & 0x0000ffff))<<16)|(GET_SHORT(date>>16))
#define  GET_CLASS(date)    (date & 15)
#define  GET_CROSS(date)    ((date>>4) & 7)
#define  GET_FLAG(date)     ((date>>7) & 1)
#define  SET_NODE(date1,date2,date3)    ( (date1)|(date2<<4)|(date3<<7))

/*function :read the file and story the date to a array*/

int readToArray(char* fileName, RoadArray_t* data)
{   
	unsigned short  usLinkSize=0;
	unsigned int    uiLinkID=0;  
	unsigned short  usNameSize=0;
	unsigned int    uiNode=0;    
	
	int i = 0;                  
	FILE *out;                   
	
	data->roadMsgs = (RoadMsg_t*) malloc (sizeof(RoadMsg_t)*INFO_SIZE);
	
	out=fopen(fileName,"rb");//打开一个文件
	
	if(NULL==out)
	{
		
		printf("can't open it\n");
		
		return UNSUCCESS;
		
	}
    
	while(0 != fread(&usLinkSize,2,1,out))
	{ 
	 	
		 
		
		if(i<INFO_SIZE)    
		{
			fread(&uiLinkID,4,1,out);
			fread(&usNameSize,2,1,out);
			fread(&uiNode,4,1,out);
			data->roadMsgs[i].size  = GET_SHORT(usLinkSize);
			data->roadMsgs[i].linkID  = GET_INT(uiLinkID);
			data->roadMsgs[i].namesize = GET_SHORT(usNameSize);
			data->roadMsgs[i].brunch  = GET_CROSS(GET_INT(uiNode));
			data->roadMsgs[i].dispclass  = GET_CLASS(GET_INT(uiNode));
			data->roadMsgs[i].roadnameflag = GET_FLAG (GET_INT(uiNode));
				
			data->roadMsgs[i].roadname = (char *)malloc(GET_SHORT(usLinkSize)-12);
			
			memset( data->roadMsgs[i].roadname,'\0',GET_SHORT(usLinkSize)-12);
			fread(data->roadMsgs[i].roadname,GET_SHORT(usLinkSize)-12,1,out);
	
			
		}
		
		else
		{
			
			printf("内存溢出!!!\n");
			return FLOWOUT;
			
		}

		i++;
		
		
	}
	data->length = i ;
	
	if(out != NULL)
		fclose(out);

	return SUCCESS;
	
} 
/*funcation :read the array and  date */   


int readToTree(TreeNode_Point  * root, RoadArray_t *data)
{

   TreeNode_Point   p , q,f;
   int i = 0;                
   
   if(*root == NULL)
        (*root) = (TreeNode_t*) malloc (sizeof(TreeNode_t));
   (*root)->leftChild = NULL;
   (*root)->rightChild = NULL;
   (*root)->data = &(data->roadMsgs[i]);

  
   
   i++;
   
   while(i<(*data).length)
   {   

	   q = (TreeNode_t*) malloc (sizeof(TreeNode_t));
	  
	  
       
	   q->leftChild = NULL;
	   q->rightChild = NULL;
	   q->data = &(data->roadMsgs[i]);
	  
	   p = (*root);

	  while(p)
	  {
	   if( q->data->linkID <p->data->linkID)
	   {
	       f= p;
		   p =p->leftChild;
	       
	   } 
	   else
		   if(q->data->linkID > p->data->linkID)
		   {
             f=p;
		     p = p->rightChild;
		   }
	        
		   else
		   {
		    printf("对不起LinkID号有相等的情况，数据有误，请查证!!!\n");
			return UNSUCCESS;
		   }

	  }

	  if(f->data->linkID <q->data->linkID)
	  {
	      f->rightChild =q;
	  }
	    else
	  {
		  f->leftChild = q;
	  }
    


	  i++; 

	 }
   
  return SUCCESS;

}
/* function :writer the file from the array*/


int writeFromArray(char* fileName, RoadArray_t *data)
{
	unsigned short  usLinkSize=0;
	unsigned int    uiLinkID=0;  
	unsigned short  usNameSize=0;
	unsigned int    uiNode=0;   
	
	int i = 0 ;
	
	FILE * in ;
	in=fopen(fileName,"wb+");
	
	if(in==NULL)
	{
		
		printf("can't open it\n");
		
		return UNSUCCESS;
		
	}
	
	while(i<(*data).length)
	{
		
		usLinkSize = GET_SHORT((*data).roadMsgs[i].size);
		uiLinkID = GET_INT((*data).roadMsgs[i].linkID);  
		usNameSize = GET_SHORT((*data).roadMsgs[i].namesize);
		uiNode =GET_INT( SET_NODE((*data).roadMsgs[i].dispclass,(*data).roadMsgs[i].brunch,(*data).roadMsgs[i].roadnameflag));//inverse the node with the three variable 
		
		fwrite(&usLinkSize,2,1,in);
		fwrite(&uiLinkID,4,1,in);
		fwrite(&usNameSize,2,1,in);
		fwrite(&uiNode,4,1,in);
		fwrite((*data).roadMsgs[i].roadname,(*data).roadMsgs[i].size - 12,1,in);
		
		i++;
	}

	if(in != NULL)
		fclose(in);
    
	printf("\n排序结果被保存在文件 %s 中（The result is stored in the file %s）\n", fileName,fileName);
	return SUCCESS;
	
}
/*
   
	 function : write the file from the tree 

*/


int writeFromTree(char* fileName, TreeNode_Point  * root)
{
   if((*root)==NULL)
   {
    printf("Error\n");
   }
 
  TreeNode_Point *stack; 
  TreeNode_Point p;

  unsigned short  usLinkSize=0;
  unsigned int    uiLinkID=0;  
  unsigned short  usNameSize=0;
  unsigned int    uiNode=0;   

  int top = 0;
  int i = 0;
  
  FILE * in ;
  in=fopen(fileName,"wb");
  
  if(in==NULL)
  {

   printf("文件打开失败！（Fail to open the file!）\n");
   
   return UNSUCCESS;

  }
  
  stack = (TreeNode_Point *)malloc(sizeof(TreeNode_Point ) * INFO_SIZE);
  stack[top] = *root;

  while (top!=-1)
     { 
	   while(NULL!=stack[top])
	   {
	   top=top+1;         	   
       stack[top]=stack[top-1]->leftChild;  
	   }

       top=top-1;

       if(top!=-1) 
	   { 
		   p=stack[top];

		   usLinkSize = GET_SHORT(p->data->size);
           uiLinkID = GET_INT(p->data->linkID);
           usNameSize = GET_SHORT(p->data->namesize);
           uiNode =GET_INT( SET_NODE(p->data->dispclass,p->data->brunch,p->data->roadnameflag));
           
           fwrite(&usLinkSize,2,1,in);
		   
           fwrite(&uiLinkID,4,1,in);
           fwrite(&usNameSize,2,1,in);
           fwrite(&uiNode,4,1,in);
		   fwrite(p->data->roadname,p->data->size-12,1,in); 
		   
		   i++;

           stack[top]=p->rightChild;  

	  }
     }
 free(stack);  
 fclose(in);
 return SUCCESS;
}
/*
function : printf the result of search to the txt file

*/
int writeresult(char* fileName, RoadArray_t *data)
{
	int i = 0 ;
	
	FILE * in ;
	in=fopen(fileName,"w+");//打开一个二进制文件
	
	if(in==NULL)
	{
		
		printf("can't open it\n");
		
		return UNSUCCESS;
		
	}
	  fprintf(in,"                  *******本次查找结果*******\n\n\n");
	while(i<(*data).length)
	{
      fprintf(in,"            第%d条记录\n\n",i+1);
	  fprintf(in,"道路名称：%s\n",(*data).roadMsgs[i].roadname+4);
	  fprintf(in,"道路标号：%d\n",(*data).roadMsgs[i].linkID);
	  fprintf(in,"道路岔路：%d\n",(*data).roadMsgs[i].brunch);
	  fprintf(in,"道路番号：%d\n",(*data).roadMsgs[i].dispclass);
	  fprintf(in,"道路标记：%d\n",(*data).roadMsgs[i].roadnameflag);

		
	  i++;
	}
	
	if(in != NULL)//关闭文件

		fclose(in);

	return SUCCESS;
	
}
