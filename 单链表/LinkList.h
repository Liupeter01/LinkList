/**
* @file	  LinkList.h
* @brief	
* @details	    This is the detail description.
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

/*插入系列*/
void LinkList_PushBack(LinkList* list);	//单链表的尾插法
void LinkList_PushFront(LinkList* list);	//单链表的头插法

BOOL LinkListInsertFrontByPos(LinkList* L, int pos, ElemType e); //单链表按位序插入元素(前插法)
BOOL LinkListInsertBackByPos(LinkList* L, int pos, ElemType e); //单链表按位序插入元素(尾插法)

BOOL LinkListInsertFrontByNum(LinkList* L, ElemType Num, ElemType e); //单链表按照数值进行前插
BOOL LinkListInsertBackByNum(LinkList* L, ElemType Num, ElemType e); //单链表按照数值进行尾插

/*搜索系列*/
LinkNode* LocateElemByNum(LinkList* L, ElemType e); //按照值进行查找 
LinkNode* LocateElemByPos(LinkList* L, int pos); //按照位序进行查找 

/*删除系列*/
BOOL LinkListDeleteFrontByPos(LinkList* L, int pos, ElemType* e); //单链表按位序前部删除元素
BOOL LinkListDeleteBackByPos(LinkList* L, int pos, ElemType* e); //单链表按位序前部删除元素

BOOL LinkListDeleteFrontByNum(LinkList* L, ElemType Num, ElemType *e); //单链表按照数值进行前部删除
BOOL LinkListDeleteBackByNum(LinkList* L, ElemType Num, ElemType *e); //单链表按照数值进行尾部删除

/*显示系列*/
void DisplayLinkList(LinkList list);	//单链表的输出