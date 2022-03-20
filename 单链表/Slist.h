/**
* @file	  Slist.h
* @brief			������LinkList�������棬�����˸�����Ƶ�ϸ��
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
		  LinkList first;				//���ڴ�������ͷ���
		  LinkList last;					//���ڴ����������һ���ڵ�
		  size_t amount;				//���ڴ������Ľڵ�����
}SLIST_T;

void Swap(ElemType* a1, ElemType* a2);
void SwapLinkNodePointer(LinkNode** a1, LinkNode** a2);
LinkNode* CreateNode(ElemType x);		//�ڵ㴴������

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitSlist(SLIST_T* SL);			//��ʼ��

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void  SListSort(LinkNode* left, LinkNode* right);			//����
void  SListQuickSort(LinkNode* left, LinkNode* right);			//��������
void SListBubbleSort(LinkNode* left);						//ð������

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SListDistroy(SLIST_T* SL);					  //����Ĵݻ�
void SListClear(SLIST_T* SL);			//��������

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SListReverse(SLIST_T* SL);			//����ķ�ת
void SListReverseByLiner(SLIST_T* SL);			//�������Է�ת(ʹ��ѭ���ṹ)
void SListReverseByRecursion(SLIST_T* SL);   //����ݹ鷴ת��㺯��
void RevByRecursion(SLIST_T* SL, LinkNode** phead); //����ݹ鷴ת����

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SListPushBack(SLIST_T* SL);	//�������β�巨
void SListPushFront(SLIST_T* SL);//�������ͷ�巨
void SListInsertBackByPos(SLIST_T* SL, int pos, ElemType e);		  //��������λ��β��

//////////////////////////////////////////////////////////ɾ��ϵ��///////////////////////////////////////////////////
void SListPopFront(SLIST_T* SL);			//�������ͷ��ɾ��
void SListPopBack(SLIST_T* SL);		//�������β��ɾ��
BOOL SListDeleteByPos(SLIST_T* SL,int pos,ElemType *e);			//�������ͨ��λ��ɾ��
BOOL SListDeleteByNum(SLIST_T* SL,ElemType key,ElemType *e);			//�������ͨ����ֵɾ��

////////////////////////////////////////////////////////�����ں�//////////////////////////////////////////////////////////////
void SListPushBackSingle(SLIST_T* SL, ElemType data);	//�������β�巨
SLIST_T* SListMergeSort(SLIST_T* SL1, SLIST_T* SL2);  //����ĺϲ�������

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
LinkNode* SListFindMiddle(SLIST_T* SL);			  //Ѱ�������м�ֵ