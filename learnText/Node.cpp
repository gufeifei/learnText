//
//  Node.cpp
//  learnText
//
//  Created by mc on 2019/11/21.
//  Copyright © 2019 mc. All rights reserved.
//

#include "Node.hpp"
#include <stdlib.h>
#include <string.h>


///创建单向链表
list_single* NodeClass:: creatListNote(int data) {
    list_single *node = NULL;
    node = (list_single *)malloc(sizeof(list_single));
    if (node == NULL) {
        printf("malloc  fair !\n");
    }
    memset(node, 0, sizeof(list_single));
    node->data = data;
    node->next = NULL;
    printf("链表的值：%d\n",node->data);
    return node;
}
///创建链表头节点
list_single* NodeClass:: creatListNote() {
    list_single *node = NULL;
    node = (list_single *)malloc(sizeof(list_single));
    if (node == NULL) {
        printf("malloc  fair !\n");
    }
    memset(node, 0, sizeof(list_single));
    node->next = NULL;
    printf("链表的头部\n");
    return node;
}
///遍历简单的单向链表、没有环
void NodeClass:: scanList(list_single *headerNode) {
    if (headerNode == nullptr) {
        printf("空指针\n");
    }
    if (headerNode->next == nullptr) {
        printf("这是一个空链表\n");
    }
    list_single *node = headerNode;
    while (node->next != nullptr) {
        node = node->next;
        printf("该节点的值是：%d\n",node->data);
    }
    printf("单向，没有环链表遍历完成\n");
}

///判断是否有环
/*两个指针分别从起点开始遍历,fast每次一步,slow每次两步,
 若两个指针有相遇的时候,则表示有环,
 因为如果存在环,快的指针肯定会在环中与慢的指针相遇,就像分针和秒针一样 .
 */
int NodeClass::isLoopList(list_single *headerNode) {
    if (headerNode == nullptr) {
        printf("空指针\n");
        return 0;
    }
    if (headerNode->next == nullptr) {
        printf("只有头节点，没有元素\n");
        return 0;
    }
    list_single *slow = headerNode;
    list_single *fast = headerNode;
    while (1) {
        if (fast->next == nullptr) {
            //快指针 的下一个节点是空，说明没有环
            return 0;
        } else {
            if (fast->next != nullptr && fast->next->next != nullptr) {
                fast = fast->next->next;//快指针走两步
                slow = slow->next;//慢指针走一步
                printf("slow----%d\n",slow->data);
                printf("fast----%d\n",fast->data);
            } else {
                //快指针的下下个节点是空，说明没有环
                return 0;
            }
        }
        if (slow == fast) {
            //快慢指针相遇，说明存在环
            return 1;
        }
    }
    return 0;
}
//查找环的起点
/**
 找出环的起点：在判断是否有环的基础上，从两个指针相遇的点处，每次一步移动一个指针，直到指针转了一圈回来，
 这样就可以知道环的大小C。之后，两个指针从链表起点出发，每次一步，让其中一个指针先走C步，则两个指针相遇的点就是环的起点。
 */
int NodeClass::findLoopBeginNode(list_single *headerNode) {
    if (headerNode == nullptr) {
        printf("空指针\n");
        return 0;
    }
    if (headerNode->next == nullptr) {
        printf("只有头节点，没有元素\n");
        return 0;
    }
    list_single *slow = headerNode;
    list_single *fast = headerNode;
    int c = 0;//环的大小
    while (1) {
        if (fast->next == nullptr) {
            //快指针 的下一个节点是空，说明没有环
            return 0;
        } else {
            if (fast->next != nullptr && fast->next->next != nullptr) {
                fast = fast->next->next;//快指针走两步
                slow = slow->next;//慢指针走一步
                printf("slow----%d\n",slow->data);
                printf("fast----%d\n",fast->data);
            } else {
                //快指针的下下个节点是空，说明没有环
                return 0;
            }
        }
        if (slow == fast) {
            //快慢指针相遇，说明存在环
            //从两个指针相遇的点处，每次一步移动一个指针，直到指针转了一圈回来，这样就可以知道环的大小c
            fast = fast->next;
            c ++;
            while (fast != slow) {
                fast = fast->next;
                c ++;
            }
            //从链表起点开始，其中一个指针先走c步，当两个指针相遇时就是环的起点
            fast = headerNode;
            slow = headerNode;
            //fast先快走c步
            while (c != 0) {
                fast = fast->next;
                c --;
                printf("快走的fast----%d\n",fast->data);
            }
            //当fast和slow相遇，说明是环的起点
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
                printf("一起走的fast----%d\n",fast->data);
                printf("一起走的slow----%d\n",slow->data);
            }
            return fast->data;
        }
    }
    return 0;
}
