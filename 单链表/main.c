#include"LinkList.h"

int main()
{
		  LinkList list;
		  InitLinkList(&list);					  //³õÊ¼»¯
		  LinkList_PushBack(&list);
		  LinkNode *px = LocateElemByPos(&list, 7);
		  if (px != NULL)
					printf("result = %d\n", px->data);
		  else
					printf("error\n");
		  DisplayLinkList(list);
		  return 0;
}