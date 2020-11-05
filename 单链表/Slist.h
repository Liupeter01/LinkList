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

#pragma warning(disable:6011)

typedef struct SLIST_T
{
		  LinkList first;				//用于存放链表的头结点
		  LinkList last;					//用于存放链表的最后一个节点
		  size_t amount;				//用于存放链表的节点总数
}SLIST_T;

void InitSlist(SLIST_T* SL);			//初始化
void  SListSort(LinkNode* left, LinkNode* right);			//排序
void SListDistroy(SLIST_T* SL);					  //链表的摧毁
void SListClear(SLIST_T* SL);			//链表的清空
void SListReverse(SLIST_T* SL);			//链表的反转

/*插入系列*/
void SListPushBack(SLIST_T* SL);	//单链表的尾插法
void SListPushFront(SLIST_T* SL);//单链表的头插法
void SListInsertBackByPos(SLIST_T* SL, int pos, ElemType e);		  //单链表按照位序尾插

/*删除系列*/
void SListPopFront(SLIST_T* SL);			//单链表的头部删除
void SListPopBack(SLIST_T* SL);		//单链表的尾部删除
BOOL SListDeleteByPos(SLIST_T* SL,int pos,ElemType *e);			//单链表的通过位序删除
BOOL SListDeleteByNum(SLIST_T* SL,ElemType key,ElemType *e);			//单链表的通过数值删除