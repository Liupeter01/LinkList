/**
* @file	  Slist.h
* @brief			基础的LinkList的升级版，增加了更多控制的细节
* @details	    This is the detail description.
* @author		LPH
* @date		    2020.11.4
* @version	    v0.1
* @par Copyright(c): 	LPH corporation
* @par History:
*	version: author, date, desc\n
*/
#pragma once
#include"LinkList.h"

typedef struct SLIST_T
{
		  LinkList first;				//用于存放链表的头结点
		  LinkList last;					//用于存放链表的最后一个节点
		  size_t amount;				//用于存放链表的节点总数
}SLIST_T;

void InitSlist(SLIST_T* SL);			//初始化

/*插入系列*/
void SListPushBack(SLIST_T* SL);	//单链表的尾插法
void SListPushFront(SLIST_T* SL);//单链表的头插法
void SListInsertBackByPos(SLIST_T* SL, int pos, ElemType e);		  //单链表按照位序尾插

/*删除系列*/
void SListPopBack(SLIST_T* SL);			//单链表的尾部删除
void SListPopFront(SLIST_T* SL);			//单链表的头部删除
