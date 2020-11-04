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

void DisplayLinkList(LinkList list);	//����������