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
//定位：TLV_pack这个函数要实现的功能有，将client收集到的字符串传到这个函数里进行打包，然后将包好的数据通过后面的通信过程发出去

//用结构体来实现发现不具有通用性，在给函数设计参数时不好做扩展
int pack_tlv(int head,char separator,char *type,int length,char *value_temperat,tlv *pack)
{
	pack->tag_head=head;
	pack->separator1=separator;

	//pack->type=type;			//给结构体中的字符串赋值；
    
	//void *memcpy(void *dest, const void *src, size_t n);
	memcpy(pack->type,type,5);

	printf("pack->type is :%s\n",pack->type);

	pack->separator2=separator;
	pack->length=length;
	pack->separator3=separator;
	memcpy(pack->value,value_temperat,9);
	return 1;
}

