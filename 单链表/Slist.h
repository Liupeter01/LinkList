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

#define QUICKSORT
#pragma warning(disable:6011)

typedef struct SLIST_T
{
		  LinkList first;				//用于存放链表的头结点
		  LinkList last;					//用于存放链表的最后一个节点
		  size_t amount;				//用于存放链表的节点总数
}SLIST_T;

void Swap(ElemType* a1, ElemType* a2);
void SwapLinkNodePointer(LinkNode** a1, LinkNode** a2);
LinkNode* CreateNode(ElemType x);		//节点创建方法

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitSlist(SLIST_T* SL);			//初始化

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void  SListSort(LinkNode* left, LinkNode* right);			//排序
void  SListQuickSort(LinkNode* left, LinkNode* right);			//快速排序
void SListBubbleSort(LinkNode* left);						//冒泡排序

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SListDistroy(SLIST_T* SL);					  //链表的摧毁
void SListClear(SLIST_T* SL);			//链表的清空

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SListReverse(SLIST_T* SL);			//链表的反转
void SListReverseByLiner(SLIST_T* SL);			//链表线性反转(使用循环结构)
void SListReverseByRecursion(SLIST_T* SL);   //链表递归反转外层函数
void RevByRecursion(SLIST_T* SL, LinkNode** phead); //链表递归反转函数

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SListPushBack(SLIST_T* SL);	//单链表的尾插法
void SListPushFront(SLIST_T* SL);//单链表的头插法
void SListInsertBackByPos(SLIST_T* SL, int pos, ElemType e);		  //单链表按照位序尾插

//////////////////////////////////////////////////////////删除系列///////////////////////////////////////////////////
void SListPopFront(SLIST_T* SL);			//单链表的头部删除
void SListPopBack(SLIST_T* SL);		//单链表的尾部删除
BOOL SListDeleteByPos(SLIST_T* SL,int pos,ElemType *e);			//单链表的通过位序删除
BOOL SListDeleteByNum(SLIST_T* SL,ElemType key,ElemType *e);			//单链表的通过数值删除

////////////////////////////////////////////////////////链表融合//////////////////////////////////////////////////////////////
void SListPushBackSingle(SLIST_T* SL, ElemType data);	//单链表的尾插法
SLIST_T* SListMergeSort(SLIST_T* SL1, SLIST_T* SL2);  //链表的合并和排序

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
LinkNode* SListFindMiddle(SLIST_T* SL);			  //寻找链表中间值