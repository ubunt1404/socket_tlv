/****************************************************************
*	Author       : guhaiming 
*	Last modified: 2020-03-02 19:57
*	Email        : 2427779305@qq.com
*	blog         : https://blog.csdn.net/go_home_look
*	Filename     : pack_tlv.c
*	Description  : 
****************************************************************/
#include <string.h>
#include <stdio.h>
#include "pack_tlv.h"
#define		PACK_FIXED_SIZE		24
typedef struct
{
	int		tag_head;
	char	separator1;	//这里的分割符取  "/"

	char	type[5];
	char	separator2;	//用字符形式标明是什么类型的数据"int "、"char"....
	
	char	value[8];	//我去以前的树莓派上逛了一下发现发过来的数据是8位数 
	char	separator3;	//我找到了，前面学长的博客，他们在处理大小时，都先约定一个固定的大小
	
	int		length;		//length=24。先只做这些,等这些实现了再做crc的
}tlv;					//用结构体来做会涉及到结构体对齐的问题，必须调换元素顺序，或者
						//改变元素的数据类型,解决方法：

//定位：TLV_pack这个函数要实现的功能有，将client收集到的字符串传到这个函数里进行打包，然后将包好的数据通过后面的通信过程发出去

//用结构体来实现发现不具有通用性，在给函数设计参数时不好做扩展
int tlv_pack(int head,char separator,char *type,int length,char *value_temperat,tlv *pack)
{
	pack->head=head;
	pack->separator1=separator;

	//pack->type=type;			//给结构体中的字符串赋值；
    
	//void *memcpy(void *dest, const void *src, size_t n);
	memcpy(pack->type,type,5);

	printf("pack->type is :%s\n",pack->type);

	pack->separator2=separator;
	pack->length=length;
	pack->separator3=separator;
	pack->value=value_temperat;
	
	return 1;
}

