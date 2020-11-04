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

void InitLinkList(LinkList* list);				  //������ĳ�ʼ��

/*����ϵ��*/
void LinkList_PushBack(LinkList* list);	//�������β�巨
void LinkList_PushFront(LinkList* list);	//�������ͷ�巨

BOOL LinkListInsertFrontByPos(LinkList* L, int pos, ElemType e); //������λ�����Ԫ��(ǰ�巨)
BOOL LinkListInsertBackByPos(LinkList* L, int pos, ElemType e); //������λ�����Ԫ��(β�巨)

BOOL LinkListInsertFrontByNum(LinkList* L, ElemType Num, ElemType e); //����������ֵ����ǰ��
BOOL LinkListInsertBackByNum(LinkList* L, ElemType Num, ElemType e); //����������ֵ����β��

/*����ϵ��*/
LinkNode* LocateElemByNum(LinkList* L, ElemType e); //����ֵ���в��� 
LinkNode* LocateElemByPos(LinkList* L, int pos); //����λ����в��� 

/*ɾ��ϵ��*/
BOOL LinkListDeleteFrontByPos(LinkList* L, int pos, ElemType* e); //������λ��ǰ��ɾ��Ԫ��
BOOL LinkListDeleteBackByPos(LinkList* L, int pos, ElemType* e); //������λ��ǰ��ɾ��Ԫ��

BOOL LinkListDeleteFrontByNum(LinkList* L, ElemType Num, ElemType *e); //����������ֵ����ǰ��ɾ��
BOOL LinkListDeleteBackByNum(LinkList* L, ElemType Num, ElemType *e); //����������ֵ����β��ɾ��

/*��ʾϵ��*/
void DisplayLinkList(LinkList list);	//����������