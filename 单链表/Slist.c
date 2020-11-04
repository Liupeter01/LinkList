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
							  SL->last = ptr;					//��¼β��
							  SL->amount++;					//�����������
					}
					else
					{
							  while (ptr->next != NULL)
							  {
										ptr = ptr->next;
							  }
							  ptr->next = s;
							  ptr = s;
							  SL->last = ptr;					//��¼β��
							  SL->amount++;					//�����������
					}
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
					if (SL->first->next == NULL && SL->amount == 0)			  //û����Ԫ�ڵ�
					{
							  SL->first->next = s;			//s��Ϊ��Ԫ�ڵ�
							  SL->last = s;	//���û����Ԫ�ڵ㣬����Ҫ�½���Ԫ�ڵ㲢��Ϊβָ��
							  SL->amount++;					//��������
					}
					else									//����Ԫ�ڵ�
					{
							  s->next = SL->first->next;
							  SL->first->next = s;
							  SL->amount++;					//��������
					}
		  }
}

void SListInsertBackByPos(SLIST_T* SL, int pos, ElemType e)  //��������λ��β��
{
		  if (SL == NULL)
		  {
					printf("������û�б�����������ʧ��\n");
					return;
		  }
		  if (pos < 1 && pos>(int)SL->amount)
		  {
					printf("������Ĳ���λ�÷Ƿ�������ʧ��\n");
					return ;
		  }
		  LinkNode* p = SL->first->next;		//����ͷ������Ԫ�ڵ㿪ʼ
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
							  SL->last = s;					//�޸�lastָ��Ϊ�²�������һ��Ԫ��
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
					return ;				  //û���ҵ��ڵ�
		  }
}

void SListPopBack(SLIST_T* SL)		//�������β��ɾ��
{
		  if (SL->amount == 0)					  //�����ڽڵ�
		  {
					printf("����ĳ���Ϊ�գ��޷�����ɾ������\n");
					return;
		  }
		  else
		  {
					LinkNode* p = SL->first->next;
					if (p->next == NULL)					//ֻʣ��һ���ڵ���
					{
							  free(p);
							  SL->last = SL->first;
							  SL->last->next = SL->first->next = NULL;
							  SL->amount--;				  // ��������һ��
					}
					else
					{
							  while (p->next != SL->last)	  //���ҵ������ĵڶ����ڵ�
							  {
										p = p->next;
							  }
							  p->next = NULL;				  //p�ĺ�̸�ֵΪNULL
							  free(SL->last);							//�ͷ����һ���ڵ�
							  SL->last = p;							//�������ڶ����ڵ���Ϊ���һ���ڵ�
							  SL->amount--;				  // ��������һ��
					}
		  }
}

void SListPopFront(SLIST_T* SL)			//�������ͷ��ɾ��
{
		  if (SL->amount == 0)					  //�����ڽڵ�
		  {
					printf("����ĳ���Ϊ�գ��޷�����ɾ������\n");
					return;
		  }
		  else
		  {
					LinkNode* p = SL->first->next;
					if (p->next == NULL)					//ֻʣ��һ���ڵ���
					{
							  free(p);
							  SL->last = SL->first;
							  SL->last->next = SL->first->next = NULL;
							  SL->amount--;				  // ��������һ��
					}
					else
					{
							  SL->first->next = p->next;
							  free(p);
							  SL->amount--;				  // ��������һ��
					}
		  }
}