/*文件读取*/
int LoadFile(unsigned char *filepath,struct Road **roadlist);
/*创造链表*/
void CreateLink(FILE *fp,struct Road **roadlist);            
/*根据道路的ID检索道路信息*/
void Sort_LinkID(struct Road **Head,long linkID);            
/*根据道路的Class码检索道路信息*/
void Sort_DisClass(struct Road **Head,int disClass);         
/*根据道路的岔路数检索道路信息*/
void Sort_RoadBrunch(struct Road **Head,int flag);           
 /*根据道路的名称检索道路的信息*/
void Sort_RoadName(struct Road **Head,char name[20]);       
/*将链表转化为数组*/
void LinkToArray(struct Road **Head,int choice);             
/*进行数据更新*/
void LinkToArray_2(struct Road **Head,int choice); 
/*将已经排序好的数组写进新的二进制文件中*/
void FILEIO_ArrayTo2DAT(struct Road_Info *array,char *filepath,int nodeNum); 
/*将已经排序号的数组写入新的文本文件中*/
void FILEIO_ArrayTo2TXT(struct Road_Info *array,char *filepath,int nodeNum);

//将链表中的数据保存进文本文件
void FILEIO_LinkTo2TXT(struct Road **array,char *pfilepath);
//将链表中的数据保存到二进制文件DAT中
void FILEIO_LinkTo2DAT(struct Road **array,char *pfilepath);

