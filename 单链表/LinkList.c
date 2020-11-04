#include"LinkList.h"

void InitLinkList(LinkList* list)				  //单链表的初始化
{
		  (*list) = (LinkNode*)malloc(sizeof(LinkNode));
		  assert(*list != NULL);
		  (*list)->next = NULL;					  //初始化
}

void LinkList_PushBack(LinkList* list)	//单链表的尾插法
{
		  if (*list == NULL)					//该链表没有被初始化
		  {
					InitLinkList(list);
		  }
		  LinkList ptr = (*list)->next;	//指向首元结点
		  //当整个链表中只存在一个头结点时(即不存在首元结点)
		  ElemType item = 0;
		  printf("请输入需要通过尾插法插入的数据(-1结束输入):>");
		  while (scanf("%d", &item) &&item!=-1)
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = item;
					s->next = NULL;
					if (ptr == NULL)			  //没有首元节点
					{
							  ptr = (*list)->next = s;
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
					printf("请输入需要通过尾插法插入的数据(-1结束输入):>");
		  }
}

void LinkList_PushFront(LinkList* list)	//单链表的头插法
{
		  if (*list == NULL)					//该链表没有被初始化
		  {
					InitLinkList(list);
		  }
		  printf("请输入需要通过头插法插入的数据(-1结束输入):>");
		  ElemType item = 0;
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = item;
					s->next = NULL;
					if ((*list)->next == NULL)			  //没有首元节点
					{
							  (*list)->next = s;			//s作为首元节点
					}
					else									//有首元节点
					{
							  s->next = (*list)->next;
							  (*list)->next = s;
					}
					printf("请输入需要通过头插法插入的数据(-1结束输入):>");
		  }
}

BOOL LinkListInsertFrontByPos(LinkList* L, int pos, ElemType e) //单链表按位序插入元素(前插法)
{
		  if (L == NULL)
		  {
					printf("单链表没有被创建，插入失败\n");
					return FALSE;
		  }
		  if (pos < 1)
		  {
					printf("单链表的插入位置非法，插入失败\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;		//跳过头结点从首元节点开始
		  int counter = 1;
		  while (p != NULL && counter++ < pos - 1)
		  {
					p = p->next;
		  }
		  if (p != NULL)				//判断有无找到节点
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = e;
					s->next = NULL;
					s->next = p->next;
					p->next = s;
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //没有找到节点
		  }
}

BOOL LinkListInsertBackByPos(LinkList* L, int pos, ElemType e)//单链表按位序插入元素(尾插法)
{
		  if (L == NULL)
		  {
					printf("单链表没有被创建，插入失败\n");
					return FALSE;
		  }
		  if (pos < 1)
		  {
					printf("单链表的插入位置非法，插入失败\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;		//跳过头结点从首元节点开始
		  int counter = 0;
		  while (p != NULL && counter++ < pos - 1)
		  {
					p = p->next;
		  }
		  if (p != NULL)				//判断有无找到节点
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = e;
					s->next = NULL;

					if (p->next == NULL)		  //该节点是最后一个节点没有后继
					{
							  p->next = s;
					}
					else
					{
							  s->next = p->next;
							  p->next = s;
					}
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //没有找到节点
		  }
}

BOOL LinkListInsertFrontByNum(LinkList* L, ElemType Num, ElemType e) //单链表按照数值进行前插
{
		  if (L == NULL)
		  {
					printf("单链表没有被创建，插入失败\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;
		  LinkNode* pre = NULL;
		  while (p != NULL && p->data != Num)
		  {
					pre = p;
					p = p->next;
		  }
		  if (p != NULL)				//判断是否找到
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = e;
					s->next = NULL;
					s->next = pre->next;
					pre->next = s;
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //没有找到
		  }
}

BOOL LinkListInsertBackByNum(LinkList* L, ElemType Num, ElemType e) //单链表按照数值进行尾插
{
		  if (L == NULL)
		  {
					printf("单链表没有被创建，插入失败\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;
		  LinkNode* pnext = NULL;
		  while (p != NULL && p->data != Num)
		  {
					p = p->next;
		  }
		  pnext = p->next;	  //指向它的下一个
		  if (p != NULL)				//判断是否找到
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = e;
					s->next = NULL;
					if (pnext == NULL)			  //如果当前的数值的并没有下一个元素
					{
							  p->next = s;
					}
					else
					{
							  p->next = s;
							  s->next = pnext;
					}
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //没有找到
		  }
}

LinkNode* LocateElemByNum(LinkList* L, ElemType key) //按照值进行查找 
{
		  if (L == NULL)
		  {
					printf("单链表没有被创建，查找失败\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;
		  for (p; p != NULL && p->data != key; p = p->next);
		  return p;
}

LinkNode* LocateElemByPos(LinkList* L, int pos) //按照位序进行查找 
{
		  if (L == NULL)
		  {
					printf("单链表没有被创建，查找失败\n");
					return NULL;
		  }
		  int counter = 0;
		  LinkNode* p = (*L)->next;		//从首元节点开始循环
		  while (p != NULL && counter++ != pos)
		  {
					p = p->next;
		  }
		  if (p == NULL)	  //没有找到
		  {
					return NULL;
		  }
		  else
		  {
					return p;
		  }
}

BOOL LinkListDeleteByPos(LinkList* L, int pos, ElemType* e) //单链表按位序删除元素
{
		  if (L == NULL)
		  {
					printf("单链表没有被创建，删除失败\n");
					return FALSE;
		  }
		  if (pos < 1)
		  {
					printf("单链表的输入的位置非法，删除失败\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;		//跳过头结点从首元节点开始
		  int counter = 1;
		  while (p != NULL && counter++ < pos - 1)
		  {
					p = p->next;
		  }
		  if (p != NULL)				//判断有无找到节点
		  {
					LinkNode* ptemp = p->next;
					*e = ptemp->data;
					p->next = ptemp->next;
					free(ptemp);
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //没有找到节点
		  }
}

BOOL LinkListDeleteByNum(LinkList* L, ElemType Num, ElemType* e) //单链表按照数值进行删除
{
		  if (L == NULL)
		  {
					printf("单链表没有被创建，删除失败\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;
		  LinkNode* pre = NULL;
		  while (p != NULL && p->data != Num)
		  {
					pre = p;
					p = p->next;
		  }
		  if (p != NULL)				//判断是否找到
		  {
					pre->next = p->next;
					*e = p->data;
					free(p);			//将p删除
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //没有找到
		  }
}

BOOL IsEmpty(LinkList list)				  //判空操作
{
		  return (list->next == NULL);
}

int LinkListLength(LinkList list)				  //单链表的表长
{
		  if (list->next == NULL)
		  {
					return 0;
		  }
		  int counter = 0;
		  LinkNode* px = list->next;
		  for (px; px != NULL; px = px->next)
		  {
					counter++;
		  }
		  return counter;
}

void DisplayLinkList(LinkList list)	//单链表的输出
{
		  LinkNode* p = list->next;
		  while (p != NULL)
		  {
					printf("%-5d", p->data);
					p = p->next;
		  }
		  printf("\n");
}