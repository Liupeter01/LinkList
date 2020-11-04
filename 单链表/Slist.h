#pragma once
#include"LinkList.h"

typedef struct SLIST_T
{
		  LinkList head;
		  LinkList tail;
		  size_t amount;
}SLIST_T;