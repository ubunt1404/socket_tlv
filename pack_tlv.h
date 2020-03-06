/****************************************************************
*	Author       : guhaiming 
*	Last modified: 2020-03-02 19:56
*	Email        : 2427779305@qq.com
*	blog         : https://blog.csdn.net/go_home_look
*	Filename     : pack_tlv.h
*	Description  : 
****************************************************************/
#ifndef TLV_PACK_H
#define	TLV_PACK_H 
int tlv_pack();
typedef struct
{
	using int		head;
		  char		type[20];
		  int		length;
		  int		value;
		  int		crc_value;
}tlv_type;
#endif

