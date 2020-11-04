#include"Slist.h"

void InitSlist(SLIST_T* SL)			//初始化
{
		  SL->first = SL->last = (LinkNode*)malloc(sizeof(LinkNode));			//初始化头结点
		  assert(SL->first != NULL);
		  SL->first->next = SL->last->next = NULL;
		  SL->amount = 0;
}

void SListPushBack(SLIST_T* SL)	//单链表的尾插法
{
		  if (SL == NULL)					//该链表没有被初始化
		  {
					InitSlist(SL);
		  }
		  LinkList ptr = SL->first->next;	//指向首元结点
		  //当整个链表中只存在一个头结点时(即不存在首元结点)
		  ElemType item = 0;
		  printf("请输入需要通过尾插法插入的数据(-1结束输入):>");
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = item;
					s->next = NULL;
					if (ptr == NULL)			  //没有首元节点
					{
							  ptr = SL->first->next = s;			  
					}
					else
					{
							  while (ptr->next != NULL)
							  {
										ptr = ptr->next;
							  }
							  ptr->next = s;
							  ptr = s;
					}
					SL->last = ptr;					//记录尾部
					SL->amount++;					//结点数增加了
		  }
}

void SListPushFront(SLIST_T* SL)//单链表的头插法
{
		  if (SL == NULL)					//该链表没有被初始化
		  {
					InitSlist(SL);
		  }
		  printf("请输入需要通过头插法插入的数据(-1结束输入):>");
		  ElemType item = 0;
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = item;
					s->next = NULL;
					if (SL->first->next == NULL)			  //没有首元节点
					{
							  SL->first->next = s;			//s作为首元节点
							  SL->last = SL->first->next;	//如果没有首元节点，则需要新建首元节点并作为尾指针
					}
					else									//有首元节点
					{
							  s->next = SL->first->next;
							  SL->first->next = s;
					}
					SL->amount++;					//数量自增
		  }
}