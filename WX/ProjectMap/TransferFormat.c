#define M_CHG_INT16(__data__) ((__data__>>8)|(__data__<<8))//��ת�����ε�16λ������
#define M_CHG_INT32(__data__) ((__data__>>24)|((__data__&0xff0000)>>8)|((__data__&0xff00)<<8)|(__data__<<24))//��ת�����͵�16������

#define GET_FLAG(__data__) ((__data__&0x80)>>7)//��ȡ�Ƿ��е�·����
#define GET_BRUNCH(__data__) ((__data__&0x70)>>4)//��ȡ��֧��
#define GET_DISPCLASS(__data__) (__data__&0x0f) 