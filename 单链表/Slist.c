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
					LinkNode* s = CreateNode(item);
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
					LinkNode* s = CreateNode(item);
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
					LinkNode* s = CreateNode(e);
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

BOOL SListDeleteByPos(SLIST_T* SL, int pos, ElemType* e)//�������ͨ��λ��ɾ��
{
		  if (SL == NULL || SL->amount == 0)
		  {
					printf("����ĳ���Ϊ�գ��޷�����ɾ������\n");
					return FALSE;
		  }
		  if (pos <0 || pos>(int)SL->amount)
		  {
					printf("�������Ҫɾ����λ�÷Ƿ����޷�����ɾ������\n");
					return FALSE;
		  }
		  LinkNode* p = SL->first->next;		//����ͷ������Ԫ�ڵ㿪ʼ
		  int counter = 1;
		  while (p != NULL && counter++ < pos - 1)
		  {
					p = p->next;//��¼ǰһ��
		  }
		  if (p != NULL)				//�ж������ҵ��ڵ�
		  {
					LinkNode* ptemp = p->next;
					if (ptemp->next == NULL)			  //�ýڵ㲻������һ���ڵ�(��ǰ��β���ڵ�)
					{
							  *e = ptemp->data;					//ȡ������
							  p->next = NULL;
							  SL->last = p;				//�����ڶ����ڵ�Ϊβ���
							  free(ptemp);
							  SL->amount--;				  //��������
					}
					else
					{
							  *e = ptemp->data;
							  p->next = ptemp->next;
							  free(ptemp);
							  SL->amount--;				  //��������
					}
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //û���ҵ��ڵ�
		  }
}

BOOL SListDeleteByNum(SLIST_T* SL, ElemType key, ElemType* e)		//�������ͨ����ֵɾ��
{
		  if (SL == NULL || SL->amount == 0)
		  {
					printf("����ĳ���Ϊ�գ��޷�����ɾ������\n");
					return FALSE;
		  }
		  LinkNode* p = SL->first->next;		//����ͷ������Ԫ�ڵ㿪ʼ
		  LinkNode* pre = NULL;
		  while (p != NULL && p->data != key)
		  {
					pre = p;
					p = p->next;
		  }
		  if (p != NULL)				//�ж��Ƿ��ҵ�
		  {
					if (p->next == NULL)			  //��ǰ�ڵ�Ϊ����һ���ڵ�
					{
							  *e = p->data;					//ȡ������
							  pre->next = NULL;
							  SL->last = pre;
							  free(p);
							  SL->amount--;
					}
					else
					{
							  pre->next = p->next;
							  *e = p->data;
							  free(p);			//��pɾ��
							  SL->amount--;
					}
					return TRUE;
		  }
		  else
		  {
					return FALSE;				  //û���ҵ�
		  }
}

void Swap(ElemType* a1, ElemType* a2)
{
		  ElemType temp = *a1;
		  *a1 = *a2;
		  *a2 = temp;
}

void  SListSort(LinkNode *left,LinkNode *right)			//����
{
		  if (left != NULL && right != NULL)
		  {
					LinkNode* pslow = left;		  //�ȼ��������е�ָ��i
					LinkNode* pfast = left->next; //�ȼ��������е�ָ��j
					LinkNode* pre = NULL;		   //��¼��һ��pslow����ֵ���ڷ���
					while (pfast!=NULL)
					{
							  if (pfast->data < left->data)
							  {
										pre = pslow;				  //��¼��һ��pslow����ֵ���ڷ���
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

void SListReverse(SLIST_T* SL)			//����ķ�ת
{
		  if (SL->amount == 0 || SL->amount == 1)
		  {
					return;				//�������Ĵ�СΪ0������1��û�б�Ҫ���в���
		  }
		  else
		  {
					SL->last = SL->first->next;				//����Ԫ�ڵ��¼Ϊβ���ڵ�
					LinkNode* p = SL->first->next;			//ָ����Ԫ�ڵ�
					LinkNode* pnext = p->next;			//ָ��p֮��Ľڵ�
					while (pnext != NULL)
					{
							  LinkNode* temp = pnext;				  //��ʱ��¼�ڵ�λ��
							  if (temp->next == NULL)
							  {
										pnext->next = p;
										SL->first->next = pnext;
										break;
							  }
							  else
							  {
										pnext = pnext->next;		  //pȥ��һ���ڵ�
										temp->next = p;		
										p = temp;			//p������һ��Ԫ��
							  }				  
					}
					SL->last->next = NULL;
		  }
}

void SListDistroy(SLIST_T* SL)					  //����Ĵݻ�
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

void SListClear(SLIST_T* SL)		//��������
{
		  LinkNode* px = SL->first->next;
		  while (px != NULL)
		  {
					SL->first->next = px->next;
					free(px);
					px = SL->first->next;
		  }
		  SL->last = SL->first;
		  SL->amount = 0;	  //��СΪ0
}

LinkNode* CreateNode(ElemType x)				  //�ڵ㴴��
{
		  LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
		  assert(s != NULL);
		  s->data = x;
		  s->next = NULL;
		  return s;
}