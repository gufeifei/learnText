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
/////链表
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node list_single;

void NodeClass:: creatListNote() {
    list_single *headerNode = NULL;
    headerNode = (list_single *)malloc(sizeof(list_single));
    if (headerNode == NULL) {
        printf("malloc  fair !\n");
    }
    memset(headerNode, 0, sizeof(list_single));
    headerNode->data = 100;
    headerNode->next = NULL;
    printf("%d\n",headerNode->data);
    free(headerNode);
}
