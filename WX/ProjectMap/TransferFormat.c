#define M_CHG_INT16(__data__) ((__data__>>8)|(__data__<<8))//反转短整形的16位进制码
#define M_CHG_INT32(__data__) ((__data__>>24)|((__data__&0xff0000)>>8)|((__data__&0xff00)<<8)|(__data__<<24))//反转长整型的16进制码

#define GET_FLAG(__data__) ((__data__&0x80)>>7)//获取是否有道路名称
#define GET_BRUNCH(__data__) ((__data__&0x70)>>4)//获取分支数
#define GET_DISPCLASS(__data__) (__data__&0x0f) 