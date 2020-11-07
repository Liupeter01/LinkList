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
					LinkNode* s = CreateNode(item);
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
					LinkNode* s = CreateNode(item);
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
					LinkNode* s = CreateNode(e);
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

BOOL SListDeleteByPos(SLIST_T* SL, int pos, ElemType* e)//单链表的通过位序删除
{
		  if (SL == NULL || SL->amount == 0)
		  {
					printf("链表的长度为空，无法进行删除操作\n");
					return FALSE;
		  }
		  if (pos <0 || pos>(int)SL->amount)
		  {
					printf("输入的需要删除的位置非法，无法进行删除操作\n");
					return FALSE;
		  }
		  LinkNode* p = SL->first->next;		//跳过头结点从首元节点开始
		  int counter = 1;
		  while (p != NULL && counter++ < pos - 1)
		  {
					p = p->next;//记录前一个
		  }
		  if (p != NULL)				//判断有无找到节点
		  {
					LinkNode* ptemp = p->next;
					if (ptemp->next == NULL)			  //该节点不存在下一个节点(当前是尾部节点)
					{
							  *e = ptemp->data;					//取出数据
							  p->next = NULL;
							  SL->last = p;				//倒数第二个节点为尾结点
							  free(ptemp);
							  SL->amount--;				  //数量减少
					}
					else
					{
							  *e = ptemp->data;
							  p->next = ptemp->next;
							  free(ptemp);
							  SL->amount--;				  //数量减少
					}
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //没有找到节点
		  }
}

BOOL SListDeleteByNum(SLIST_T* SL, ElemType key, ElemType* e)		//单链表的通过数值删除
{
		  if (SL == NULL || SL->amount == 0)
		  {
					printf("链表的长度为空，无法进行删除操作\n");
					return FALSE;
		  }
		  LinkNode* p = SL->first->next;		//跳过头结点从首元节点开始
		  LinkNode* pre = NULL;
		  while (p != NULL && p->data != key)
		  {
					pre = p;
					p = p->next;
		  }
		  if (p != NULL)				//判断是否找到
		  {
					if (p->next == NULL)			  //当前节点为最后的一个节点
					{
							  *e = p->data;					//取出数据
							  pre->next = NULL;
							  SL->last = pre;
							  free(p);
							  SL->amount--;
					}
					else
					{
							  pre->next = p->next;
							  *e = p->data;
							  free(p);			//将p删除
							  SL->amount--;
					}
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //没有找到
		  }
}

void Swap(ElemType* a1, ElemType* a2)
{
		  ElemType temp = *a1;
		  *a1 = *a2;
		  *a2 = temp;
}

void  SListSort(LinkNode *left,LinkNode *right)			//排序
{
		  if (left != NULL && right != NULL)
		  {
					LinkNode* pslow = left;		  //等价于数组中的指针i
					LinkNode* pfast = left->next; //等价于数组中的指针j
					LinkNode* pre = NULL;		   //记录上一个pslow的数值用于分治
					while (pfast!=NULL)
					{
							  if (pfast->data < left->data)
							  {
										pre = pslow;				  //记录上一个pslow的数值用于分治
										pslow = pslow->next;
										Swap(&pslow->data, &pfast->data);
							 }
							  pfast = pfast->next;
					}
					Swap(&left->data, &pslow->data);
					SListSort(left, pre);
					SListSort(pslow->next, right);
		  }
}

void SListReverse(SLIST_T* SL)			//链表的反转
{
		  if (SL->amount == 0 || SL->amount == 1)
		  {
					return;				//如果链表的大小为0个或者1个没有必要进行操作
		  }
		  else
		  {
					SL->last = SL->first->next;				//将首元节点记录为尾部节点
					LinkNode* p = SL->first->next;			//指向首元节点
					LinkNode* pnext = p->next;			//指向p之后的节点
					while (pnext != NULL)
					{
							  LinkNode* temp = pnext;				  //临时记录节点位置
							  if (temp->next == NULL)
							  {
										pnext->next = p;
										SL->first->next = pnext;
										break;
							  }
							  else
							  {
										pnext = pnext->next;		  //p去下一个节点
										temp->next = p;		
										p = temp;			//p紧跟上一个元素
							  }				  
					}
					SL->last->next = NULL;
		  }
}

void SListDistroy(SLIST_T* SL)					  //链表的摧毁
{
		  LinkNode* ptemp = NULL;
		  for (LinkNode* px = SL->first->next;  px!=NULL; px = ptemp)
		  {
					LinkNode* ptemp = px->next;
					px->next = NULL;
					free(px);
		  }
		  SL->amount = 0;
}

void SListClear(SLIST_T* SL)		//链表的清空
{
		  LinkNode* px = SL->first->next;
		  while (px != NULL)
		  {
					SL->first->next = px->next;
					free(px);
					px = SL->first->next;
		  }
		  SL->last = SL->first;
		  SL->amount = 0;	  //大小为0
}

LinkNode* CreateNode(ElemType x)				  //节点创建
{
		  LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
		  assert(s != NULL);
		  s->data = x;
		  s->next = NULL;
		  return s;
}