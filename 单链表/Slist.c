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
							  SL->last = ptr;					//记录尾部
							  SL->amount++;					//结点数增加了
					}
					else
					{
							  while (ptr->next != NULL)
							  {
										ptr = ptr->next;
							  }
							  ptr->next = s;
							  ptr = s;
							  SL->last = ptr;					//记录尾部
							  SL->amount++;					//结点数增加了
					}
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
					if (SL->first->next == NULL && SL->amount == 0)			  //没有首元节点
					{
							  SL->first->next = s;			//s作为首元节点
							  SL->last = s;	//如果没有首元节点，则需要新建首元节点并作为尾指针
							  SL->amount++;					//数量自增
					}
					else									//有首元节点
					{
							  s->next = SL->first->next;
							  SL->first->next = s;
							  SL->amount++;					//数量自增
					}
		  }
}

void SListInsertBackByPos(SLIST_T* SL, int pos, ElemType e)  //单链表按照位序尾插
{
		  if (SL == NULL)
		  {
					printf("单链表没有被创建，插入失败\n");
					return;
		  }
		  if (pos < 1 && pos>(int)SL->amount)
		  {
					printf("单链表的插入位置非法，插入失败\n");
					return ;
		  }
		  LinkNode* p = SL->first->next;		//跳过头结点从首元节点开始
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
							  SL->last = s;					//修改last指针为新插入的最后一个元素
							  SL->amount++;
					}
					else
					{
							  s->next = p->next;
							  p->next = s;
							  SL->amount++;
					}
					return ;
		  }
		  else
		  {
					return ;				  //没有找到节点
		  }
}

void SListPopBack(SLIST_T* SL)		//单链表的尾部删除
{
		  if (SL->amount == 0)					  //不存在节点
		  {
					printf("链表的长度为空，无法进行删除操作\n");
					return;
		  }
		  else
		  {
					LinkNode* p = SL->first->next;
					if (p->next == NULL)					//只剩下一个节点了
					{
							  free(p);
							  SL->last = SL->first;
							  SL->last->next = SL->first->next = NULL;
							  SL->amount--;				  // 个数减少一个
					}
					else
					{
							  while (p->next != SL->last)	  //先找到倒数的第二个节点
							  {
										p = p->next;
							  }
							  p->next = NULL;				  //p的后继赋值为NULL
							  free(SL->last);							//释放最后一个节点
							  SL->last = p;							//将倒数第二个节点最为最后一个节点
							  SL->amount--;				  // 个数减少一个
					}
		  }
}

void SListPopFront(SLIST_T* SL)			//单链表的头部删除
{
		  if (SL->amount == 0)					  //不存在节点
		  {
					printf("链表的长度为空，无法进行删除操作\n");
					return;
		  }
		  else
		  {
					LinkNode* p = SL->first->next;
					if (p->next == NULL)					//只剩下一个节点了
					{
							  free(p);
							  SL->last = SL->first;
							  SL->last->next = SL->first->next = NULL;
							  SL->amount--;				  // 个数减少一个
					}
					else
					{
							  SL->first->next = p->next;
							  free(p);
							  SL->amount--;				  // 个数减少一个
					}
		  }
}