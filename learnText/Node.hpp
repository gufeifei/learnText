//
//  Node.hpp
//  learnText
//
//  Created by mc on 2019/11/21.
//  Copyright © 2019 mc. All rights reserved.
//  链表

#include <stdio.h>

//单向链表结构体
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node list_single;

class NodeClass {
public:
    static list_single* creatListNote(int data);//创建链表节点
    static list_single* creatListNote();//创建链表头节点
    static void scanList(list_single *headerNode);//遍历简单的单向链表、没有环
    static int isLoopList(list_single *headerNode);//判断是否有环
    static int findLoopBeginNode(list_single *headerNode);//寻找链表环的起始位置
    static list_single* reverseList(list_single *headerNode);//链表反转
};

