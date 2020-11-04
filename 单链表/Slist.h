#pragma once
#include"LinkList.h"

typedef struct SLIST_T
{
		  LinkList head;
		  LinkList tail;
		  size_t amount;
}SLIST_T;

void Satictics(SLIST_T slist, LinkList list);				//统计函数，用于信息的输出
