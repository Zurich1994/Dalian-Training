#define M_CHG_INT16(data) ((data>>8)|(data<<8))//��ת�����ε�16λ������
#define M_CHG_INT32(data) ((data>>24)|((data &0xff0000)>>8)|((data &0xff00)<<8)|(data<<24))//��ת�����͵�16������

#define GET_FLAG(data) ((data &0x80)>>7)//��ȡ�Ƿ��е�·����
#define GET_BRUNCH(data) ((data &0x70)>>4)//��ȡ��֧��
#define GET_DISPCLASS(data) (data &0x0f) 

#define SET_FLAG(data,flag) ((data|((flag)<<7)))
#define SET_BRUNCH(data,brunch) ((data|((brunch)<<4)))
#define SET_DISPCLASS(data,dispclass) (data|(dispclass))


#define GTBL_SOURCE  "GTBL.dat"
#define GTBL_SORT_SOURCE_DAT "SORT_GTBL.dat"
#define GTBL_SORT_SOURCE_TXT "GTBL_SORT.txt"
#define GTBL_SORT_SOURCE_ADD_DAT "SORT_GTBL_ADD.dat"
#define GTBL_SORT_SOURCE_ADD_TXT "SORT_GTBL_ADD.txt"
#define GTBL_SORT_SOURCE_EDIT_DAT "SORT_GTBL_EDIT.dat"
#define GTBL_SORT_SOURCE_EDIT_TXT "SORT_GTBL_EDIT.txt"
#define GTBL_SORT_SOURCE_DEL_DAT "SORT_GTBL_DEL.dat"
#define GTBL_SORT_SOURCE_DEL_TXT "SORT_GTBL_DEL.txt"