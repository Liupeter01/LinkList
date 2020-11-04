#include"LinkList.h"

void InitLinkList(LinkList* list)				  //������ĳ�ʼ��
{
		  (*list) = (LinkNode*)malloc(sizeof(LinkNode));
		  assert(*list != NULL);
		  (*list)->next = NULL;					  //��ʼ��
}

void LinkList_PushBack(LinkList* list)	//�������β�巨
{
		  if (*list == NULL)					//������û�б���ʼ��
		  {
					InitLinkList(list);
		  }
		  LinkList ptr = (*list)->next;	//ָ����Ԫ���
		  //������������ֻ����һ��ͷ���ʱ(����������Ԫ���)
		  ElemType item = 0;
		  printf("��������Ҫͨ��β�巨���������(-1��������):>");
		  while (scanf("%d", &item) &&item!=-1)
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = item;
					s->next = NULL;
					if (ptr == NULL)			  //û����Ԫ�ڵ�
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
					printf("��������Ҫͨ��β�巨���������(-1��������):>");
		  }
}

void LinkList_PushFront(LinkList* list)	//�������ͷ�巨
{
		  if (*list == NULL)					//������û�б���ʼ��
		  {
					InitLinkList(list);
		  }
		  printf("��������Ҫͨ��ͷ�巨���������(-1��������):>");
		  ElemType item = 0;
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = item;
					s->next = NULL;
					if ((*list)->next == NULL)			  //û����Ԫ�ڵ�
					{
							  (*list)->next = s;			//s��Ϊ��Ԫ�ڵ�
					}
					else									//����Ԫ�ڵ�
					{
							  s->next = (*list)->next;
							  (*list)->next = s;
					}
					printf("��������Ҫͨ��ͷ�巨���������(-1��������):>");
		  }
}

BOOL LinkListInsertFrontByPos(LinkList* L, int pos, ElemType e) //������λ�����Ԫ��(ǰ�巨)
{
		  if (L == NULL)
		  {
					printf("������û�б�����������ʧ��\n");
					return FALSE;
		  }
		  if (pos < 1)
		  {
					printf("������Ĳ���λ�÷Ƿ�������ʧ��\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;		//����ͷ������Ԫ�ڵ㿪ʼ
		  int counter = 1;
		  while (p != NULL && counter++ < pos - 1)
		  {
					p = p->next;
		  }
		  if (p != NULL)				//�ж������ҵ��ڵ�
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
					return FALSE;				  //û���ҵ��ڵ�
		  }
}

BOOL LinkListInsertBackByPos(LinkList* L, int pos, ElemType e)//������λ�����Ԫ��(β�巨)
{
		  if (L == NULL)
		  {
					printf("������û�б�����������ʧ��\n");
					return FALSE;
		  }
		  if (pos < 1)
		  {
					printf("������Ĳ���λ�÷Ƿ�������ʧ��\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;		//����ͷ������Ԫ�ڵ㿪ʼ
		  int counter = 0;
		  while (p != NULL && counter++ < pos - 1)
		  {
					p = p->next;
		  }
		  if (p != NULL)				//�ж������ҵ��ڵ�
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = e;
					s->next = NULL;

					if (p->next == NULL)		  //�ýڵ������һ���ڵ�û�к��
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
					return FALSE;				  //û���ҵ��ڵ�
		  }
}

BOOL LinkListInsertFrontByNum(LinkList* L, ElemType Num, ElemType e) //����������ֵ����ǰ��
{
		  if (L == NULL)
		  {
					printf("������û�б�����������ʧ��\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;
		  LinkNode* pre = NULL;
		  while (p != NULL && p->data != Num)
		  {
					pre = p;
					p = p->next;
		  }
		  if (p != NULL)				//�ж��Ƿ��ҵ�
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
					return FALSE;				  //û���ҵ�
		  }
}

BOOL LinkListInsertBackByNum(LinkList* L, ElemType Num, ElemType e) //����������ֵ����β��
{
		  if (L == NULL)
		  {
					printf("������û�б�����������ʧ��\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;
		  LinkNode* pnext = NULL;
		  while (p != NULL && p->data != Num)
		  {
					p = p->next;
		  }
		  pnext = p->next;	  //ָ��������һ��
		  if (p != NULL)				//�ж��Ƿ��ҵ�
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = e;
					s->next = NULL;
					if (pnext == NULL)			  //�����ǰ����ֵ�Ĳ�û����һ��Ԫ��
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
					return FALSE;				  //û���ҵ�
		  }
}

LinkNode* LocateElemByNum(LinkList* L, ElemType key) //����ֵ���в��� 
{
		  if (L == NULL)
		  {
					printf("������û�б�����������ʧ��\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;
		  for (p; p != NULL && p->data != key; p = p->next);
		  return p;
}

LinkNode* LocateElemByPos(LinkList* L, int pos) //����λ����в��� 
{
		  if (L == NULL)
		  {
					printf("������û�б�����������ʧ��\n");
					return NULL;
		  }
		  int counter = 0;
		  LinkNode* p = (*L)->next;		//����Ԫ�ڵ㿪ʼѭ��
		  while (p != NULL && counter++ != pos)
		  {
					p = p->next;
		  }
		  if (p == NULL)	  //û���ҵ�
		  {
					return NULL;
		  }
		  else
		  {
					return p;
		  }
}

BOOL LinkListDeleteByPos(LinkList* L, int pos, ElemType* e) //������λ��ɾ��Ԫ��
{
		  if (L == NULL)
		  {
					printf("������û�б�������ɾ��ʧ��\n");
					return FALSE;
		  }
		  if (pos < 1)
		  {
					printf("������������λ�÷Ƿ���ɾ��ʧ��\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;		//����ͷ������Ԫ�ڵ㿪ʼ
		  int counter = 1;
		  while (p != NULL && counter++ < pos - 1)
		  {
					p = p->next;
		  }
		  if (p != NULL)				//�ж������ҵ��ڵ�
		  {
					LinkNode* ptemp = p->next;
					*e = ptemp->data;
					p->next = ptemp->next;
					free(ptemp);
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //û���ҵ��ڵ�
		  }
}

BOOL LinkListDeleteByNum(LinkList* L, ElemType Num, ElemType* e) //����������ֵ����ɾ��
{
		  if (L == NULL)
		  {
					printf("������û�б�������ɾ��ʧ��\n");
					return FALSE;
		  }
		  LinkNode* p = (*L)->next;
		  LinkNode* pre = NULL;
		  while (p != NULL && p->data != Num)
		  {
					pre = p;
					p = p->next;
		  }
		  if (p != NULL)				//�ж��Ƿ��ҵ�
		  {
					pre->next = p->next;
					*e = p->data;
					free(p);			//��pɾ��
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //û���ҵ�
		  }
}

BOOL IsEmpty(LinkList list)				  //�пղ���
{
		  return (list->next == NULL);
}

int LinkListLength(LinkList list)				  //������ı�
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

void DisplayLinkList(LinkList list)	//����������
{
		  LinkNode* p = list->next;
		  while (p != NULL)
		  {
					printf("%-5d", p->data);
					p = p->next;
		  }
		  printf("\n");
}