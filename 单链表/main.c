#include"LinkList.h"

int main()
{
		  LinkList list;
		  InitLinkList(&list);					  //��ʼ��
		  LinkList_PushBack(&list);

		  /*
		  *
		  */

		  DisplayLinkList(list);
		  return 0;
}