#include"Slist.h"

void InitSlist(SLIST_T* SL)			//��ʼ��
{
		  SL->first = SL->last = (LinkNode*)malloc(sizeof(LinkNode));			//��ʼ��ͷ���
		  assert(SL->first != NULL);
		  SL->first->next = SL->last->next = NULL;
		  SL->amount = 0;
}

void SListPushBack(SLIST_T* SL)	//�������β�巨
{
		  if (SL == NULL)					//������û�б���ʼ��
		  {
					InitSlist(SL);
		  }
		  LinkList ptr = SL->first->next;	//ָ����Ԫ���
		  //������������ֻ����һ��ͷ���ʱ(����������Ԫ���)
		  ElemType item = 0;
		  printf("��������Ҫͨ��β�巨���������(-1��������):>");
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = item;
					s->next = NULL;
					if (ptr == NULL)			  //û����Ԫ�ڵ�
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
					SL->last = ptr;					//��¼β��
					SL->amount++;					//�����������
		  }
}

void SListPushFront(SLIST_T* SL)//�������ͷ�巨
{
		  if (SL == NULL)					//������û�б���ʼ��
		  {
					InitSlist(SL);
		  }
		  printf("��������Ҫͨ��ͷ�巨���������(-1��������):>");
		  ElemType item = 0;
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
					s->data = item;
					s->next = NULL;
					if (SL->first->next == NULL)			  //û����Ԫ�ڵ�
					{
							  SL->first->next = s;			//s��Ϊ��Ԫ�ڵ�
							  SL->last = SL->first->next;	//���û����Ԫ�ڵ㣬����Ҫ�½���Ԫ�ڵ㲢��Ϊβָ��
					}
					else									//����Ԫ�ڵ�
					{
							  s->next = SL->first->next;
							  SL->first->next = s;
					}
					SL->amount++;					//��������
		  }
}