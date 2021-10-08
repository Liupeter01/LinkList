#include"Slist.h"
#include"menu.h"

int main()
{
		  SLIST_T list,ps;
		  InitSlist(&list);
		  InitSlist(&ps);
		  //Menu(&list);
		  SListPushBack(&list);
		  SListPushBack(&ps);
		  SLIST_T* meg = SListMergeSort(&list, &ps);
		  Menu(meg);
		  return 0;
}