/*�ļ���ȡ*/
int LoadFile(unsigned char *filepath,struct Road **roadlist);
/*��������*/
void CreateLink(FILE *fp,struct Road **roadlist);            
/*���ݵ�·��ID������·��Ϣ*/
void Sort_LinkID(struct Road **Head,long linkID);            
/*���ݵ�·��Class�������·��Ϣ*/
void Sort_DisClass(struct Road **Head,int disClass);         
/*���ݵ�·�Ĳ�·��������·��Ϣ*/
void Sort_RoadBrunch(struct Road **Head,int flag);           
 /*���ݵ�·�����Ƽ�����·����Ϣ*/
void Sort_RoadName(struct Road **Head,char name[20]);       
/*������ת��Ϊ����*/
void LinkToArray(struct Road **Head,int choice);             
/*�������ݸ���*/
void LinkToArray_2(struct Road **Head,int choice); 
/*���Ѿ�����õ�����д���µĶ������ļ���*/
void FILEIO_ArrayTo2DAT(struct Road_Info *array,char *filepath,int nodeNum); 
/*���Ѿ�����ŵ�����д���µ��ı��ļ���*/
void FILEIO_ArrayTo2TXT(struct Road_Info *array,char *filepath,int nodeNum);

//�������е����ݱ�����ı��ļ�
void FILEIO_LinkTo2TXT(struct Road **array,char *pfilepath);
//�������е����ݱ��浽�������ļ�DAT��
void FILEIO_LinkTo2DAT(struct Road **array,char *pfilepath);

