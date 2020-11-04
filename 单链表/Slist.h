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

typedef struct SLIST_T
{
		  LinkList first;				//���ڴ�������ͷ���
		  LinkList last;					//���ڴ����������һ���ڵ�
		  size_t amount;				//���ڴ������Ľڵ�����
}SLIST_T;

void InitSlist(SLIST_T* SL);			//��ʼ��

/*����ϵ��*/
void SListPushBack(SLIST_T* SL);	//�������β�巨
void SListPushFront(SLIST_T* SL);//�������ͷ�巨
void SListInsertBackByPos(SLIST_T* SL, int pos, ElemType e);		  //��������λ��β��

/*ɾ��ϵ��*/
void SListPopBack(SLIST_T* SL);			//�������β��ɾ��
void SListPopFront(SLIST_T* SL);			//�������ͷ��ɾ��
