#include"menu.h"

/*菜单*/
void Menu(SLIST_T* list)
{
          int select = 1;
          while (select)
          {
                    printf("*****************************************************************\n");
                    printf("*   [1]  push_back       \t[2] push_front           \t*\n");
                    printf("*   [3]  show_list         \t[4] pop_back             \t*\n");
                    printf("*   [5]  pop_front        \t[6] insert_pos            \t*\n");
                    printf("*   [7]  find                 \t[8] length                   \t*\n");
                    printf("*   [9]  delete_pos      \t[10] delete_val           \t*\n");
                    printf("*   [11]  Sort               \t[12] reverse               \t*\n");
                    printf("*   [13]  Clear             \t[14] Destroy(Dangerous!!) \t*\n");
                    printf("*   [15]  Cls                \t[0] Quit                       \t*\n");
                    printf("*****************************************************************\n");
                    printf("请选择：>");
                    scanf("%d", &select);
                    if (!select)         //选择值为0 
                    {
                              //Destory(list);      //z 防止内存泄漏仍然清空内存
                              break;              //退出并结束
                    }
                    else
                    {
                              switch (select)
                              {
                              case 1:SListPushBack(list); break; //数据初始化尾部插入
                              case 2: SListPushFront(list); break; //数据初始化头部插入
                              case 3:DisplayLinkList(list->first); break;
                              case 4:SListPopBack(list); break;
                              case 5:SListPopFront(list); break;
                              case 6:    //数据的位序插入，当前默认使用后插法
                              {
                                        printf("请输入需要插入的数据：>");
                                        ElemType item = 0;  //数据
                                        scanf("%d", &item);
                                        printf("请输入需要插入的位置：>");
                                        int pos = 0;   //位置
                                        scanf("%d", &pos);
                                        SListInsertBackByPos(list, pos, item);
                                        break;
                              }

                              case 7:   //数据的查找
                              {
                                        printf("请输入需要查找的数据：>");
                                        ElemType item = 0;
                                        scanf("%d", &item);
                                        LinkNode* node = LocateElemByNum(&(list->first), item);
                                        if (node == NULL)
                                        {
                                                  printf("查找的数据%d在链表中不存在\n", item);
                                        }
                                        else
                                        {
                                                  printf("查找的数据%d在链表中存在\n", item);
                                        }
                                        break;
                              }

                              case 8:printf("链表的长度为：%d\n", list->amount); break;
                              case 9: //删除数据所在位序的元素
                              {
                                        //printf("请输入需要删除的元素所在的位序：>");
                                        //ElemType item;               //存放删除的数据
                                        //int pos = 0;
                                        //scanf("%d", &pos);
                                        //if (!ListDeleteByPos(list, pos, &item))
                                        //{
                                        //          printf("数据删除失败\n");
                                        //}
                                        //break;
                              }
                              case 10://删除指定的数据元素
                              {
                                        //printf("请输入需要删除的元素：>");
                                        //ElemType num;               //删除的数据
                                        //ElemType item;               //存放删除的数据
                                        //scanf("%d", &num);
                                        //if (!ListDeleteByNumber(list, num, &item))
                                        //{
                                        //          printf("数据删除失败\n");
                                        //}
                                        //break;
                              }
                              case 11: break;             //快速排序(也可以选择堆排序)
                              case 12: break;            //逆转
                              case 13: break;
                              case 14:break;
                              case 15:system("cls"); break;
                              default:printf("输入错误请重新输入\n"); break;
                              }
                    }
          }
          return;
}