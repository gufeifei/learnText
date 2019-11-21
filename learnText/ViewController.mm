//
//  ViewController.m
//  learnText
//
//  Created by mc on 2019/10/30.
//  Copyright © 2019 mc. All rights reserved.
//

#import "ViewController.h"
#include "Node.hpp"

@interface ViewController ()
@end


@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
   
    self.view.backgroundColor = [UIColor redColor];
    //---------------单向链表、有无环的相关算法调用----------------------
    list_single *headerNode = [self creatList];//创建链表
//    NodeClass::scanList(headerNode);//遍历单向无环链表
    int i = NodeClass::isLoopList(headerNode);//判断链表是否有环
    NSLog(@"是否有环：%d",i);
    int value = NodeClass::findLoopBeginNode(headerNode);//查找环的起点
    NSLog(@"环的起点的节点data是：%d",value);
}

//创建一个链表多个节点
- (list_single *)creatList {
    list_single *headerNode = NodeClass::creatListNote();
    list_single *node1 = NodeClass::creatListNote(1);
    list_single *node2 = NodeClass::creatListNote(2);
    list_single *node3 = NodeClass::creatListNote(3);
    list_single *node4 = NodeClass::creatListNote(4);
    list_single *node5 = NodeClass::creatListNote(5);
    list_single *node6 = NodeClass::creatListNote(6);

    headerNode->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node4;
    return headerNode;
}

@end

