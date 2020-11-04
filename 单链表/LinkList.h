#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<assert.h>

#define ElemType int

typedef struct LinkNode
{
		  ElemType data;
		  struct LinkNode* next;
}LinkNode,*LinkList;

void InitLinkList(LinkList* list);				  //单链表的初始化

/*插入系列*/
void LinkList_PushBack(LinkList* list);	//单链表的尾插法
void LinkList_PushFront(LinkList* list);	//单链表的头插法
BOOL LinkListInsertFrontByPos(LinkList* L, int pos, ElemType e); //单链表按位序插入元素(前插法)
BOOL LinkListInsertBackByPos(LinkList* L, int pos, ElemType e); //单链表按位序插入元素(尾插法)

BOOL LinkListInsertFrontByNum(LinkList* L, ElemType Num, ElemType e); //单链表按照数值进行前插
BOOL LinkListInsertBackByNum(LinkList* L, ElemType Num, ElemType e); //单链表按照数值进行尾插

void DisplayLinkList(LinkList list);	//单链表的输出