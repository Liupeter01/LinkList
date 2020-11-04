/**
* @file	  LinkList.h
* @brief	
* @details	    ���ǵͰ汾�ĵײ���
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

void InitLinkList(LinkList* list);				  //������ĳ�ʼ��
BOOL IsEmpty(LinkList list);					  //�пղ���
int LinkListLength(LinkList list);				  //������ı�

/*����ϵ��*/
void LinkList_PushBack(LinkList* list);	//�������β�巨
void LinkList_PushFront(LinkList* list);	//�������ͷ�巨

BOOL LinkListInsertFrontByPos(LinkList* L, int pos, ElemType e); //������λ�����Ԫ��(ǰ�巨)
BOOL LinkListInsertBackByPos(LinkList* L, int pos, ElemType e); //������λ�����Ԫ��(β�巨)

BOOL LinkListInsertFrontByNum(LinkList* L, ElemType Num, ElemType e); //����������ֵ����ǰ��
BOOL LinkListInsertBackByNum(LinkList* L, ElemType Num, ElemType e); //����������ֵ����β��

/*����ϵ��*/
LinkNode* LocateElemByNum(LinkList* L, ElemType key); //����ֵ���в��� 
LinkNode* LocateElemByPos(LinkList* L, int pos); //����λ����в��� 

/*ɾ��ϵ��*/
BOOL LinkListDeleteByPos(LinkList* L, int pos, ElemType* e);//������λ��ɾ��Ԫ��
BOOL LinkListDeleteByNum(LinkList* L, ElemType Num, ElemType* e); //����������ֵ����ɾ��

/*��ʾϵ��*/
void DisplayLinkList(LinkList list);	//����������