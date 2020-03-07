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
int pack_tlv(int head,char *separator,char *type,int length,char *value_temperat,tlv *pack)
{
	pack->tag_head=head;
	printf("pack->tag_head is :%0x\n",pack->tag_head);
	
	
	memcpy(pack->separator1,separator,1);
	printf("pack->separator is :%s\n",pack->separator1);

	//pack->type=type;			//给结构体中的字符串赋值；
    
	//void *memcpy(void *dest, const void *src, size_t n);
	
	memcpy(pack->type,type,5);
	printf("pack->type is :%s\n",pack->type);

	memcpy(pack->separator2,separator,1);
	printf("pack->separator is :%s\n",pack->separator2);

	pack->length=length;
	printf("pack->length is :%d\n",pack->length);
	
	memcpy(pack->separator3,separator,1);
	printf("pack->separator is :%s\n",pack->separator3);

	memset(pack->value,0,sizeof(pack->value));
	memcpy(pack->value,value_temperat,8);	
	printf("pack->value is :%s\n",pack->value);

	return 1;
}

