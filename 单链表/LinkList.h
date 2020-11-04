/**
* @file	  LinkList.h
* @brief	
* @details	    这是低版本的底层框架
* @author		LPH
* @date		    2020.11.4
* @version	    v0.1
* @par Copyright(c): 	LPH corporation
* @par History: 
*	version: author, date, desc\n
*/
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
BOOL IsEmpty(LinkList list);					  //判空操作
int LinkListLength(LinkList list);				  //单链表的表长

/*插入系列*/
void LinkList_PushBack(LinkList* list);	//单链表的尾插法
void LinkList_PushFront(LinkList* list);	//单链表的头插法

BOOL LinkListInsertFrontByPos(LinkList* L, int pos, ElemType e); //单链表按位序插入元素(前插法)
BOOL LinkListInsertBackByPos(LinkList* L, int pos, ElemType e); //单链表按位序插入元素(尾插法)

BOOL LinkListInsertFrontByNum(LinkList* L, ElemType Num, ElemType e); //单链表按照数值进行前插
BOOL LinkListInsertBackByNum(LinkList* L, ElemType Num, ElemType e); //单链表按照数值进行尾插

/*搜索系列*/
LinkNode* LocateElemByNum(LinkList* L, ElemType key); //按照值进行查找 
LinkNode* LocateElemByPos(LinkList* L, int pos); //按照位序进行查找 

/*删除系列*/
BOOL LinkListDeleteByPos(LinkList* L, int pos, ElemType* e);//单链表按位序删除元素
BOOL LinkListDeleteByNum(LinkList* L, ElemType Num, ElemType* e); //单链表按照数值进行删除

/*显示系列*/
void DisplayLinkList(LinkList list);	//单链表的输出