//
// Created by admin on 2023/1/31.
//
#include <stdlib.h>
#include <mmcobj.h>
#include <assert.h>

#ifndef STUDY_LIST_H
#define STUDY_LIST_H

#endif //STUDY_LIST_H
//链表结点的结构体
typedef struct NODE
{
    int x;
    int y;
    int speed;
    struct NODE *next;//指针，指向下一个结点；

}MNode;
//链表结点的结构体
typedef struct LinkList {

    struct NODE* head;//头指针
    struct NODE* end;//尾指针，

} LL;
//创建链接结点函数

MNode *Node_init(int x, int y, int speed) {
    MNode *temp = (MNode *) malloc(sizeof(MNode));
    assert(temp);
    temp->x = x;
    temp->y = y;
    temp->speed = speed;
    temp->next = NULL;
    return temp;

}
void LinkList_insert(LL *list,int x, int y ,int speed){
    if (list ==NULL){
        return;
    }
    if (list->head==NULL){
        list->head = list->end = Node_init(x,y,speed);
    }else{
        list->end ->next = Node_init(x,y,speed);
        list->end = list->end->next;//更新尾指针

    }

}
