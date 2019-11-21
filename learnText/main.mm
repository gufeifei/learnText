//
//  main.m
//  learnText
//
//  Created by mc on 2019/10/30.
//  Copyright © 2019 mc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import <stdio.h>
#import <stdlib.h>
#import <string.h>
#include "Sort.hpp"


int main(int argc, char * argv[]) {
    SortClass::logStr();

    NSString * appDelegateClassName;
    ///找到数组中第二大的数
    int array[5] = {1,3,2,4,6};
    int i = SortClass:: findSec(array,5);
    NSLog(@"打印结果%d",i);
    
    
    ///已知两个数组有序实现方法将他们合并后仍然有序
    int array5[5] = {1,5,9,11,12};
    int array6[8] = {2,3,7,10,11,12,13,14};
    int len1 = sizeof(array5) / sizeof(int);
    int len2 = sizeof(array6) / sizeof(int);
    int newArray[13] = {};
    SortClass::mergeSort(newArray, array5, len1, array6, len2);
    

    ///冒泡排序
    int array1[5] = {1,11,9,5,12};
    SortClass::bubbleSort(array1, 5);
    
    ///选择排序
    int array2[5] = {1,11,9,5,12};
    SortClass::selectSort(array2, 5);
    
    ///统计出一个字符串每种字母出现的次数
    char *str = "11aaduuuffggwwZZww333wp";
    SortClass::countLetter(str);
    
    ///实现一个打印出1- 1000之间的所有素数的方法
    SortClass::printPrime();
    ///已知一个数组已经降序排序请用二分查字法找出其中的某一个元素，找到返回索引否则返回-1
    int array3[10] = {20,19,9,8,7,6,5,4,3,1};
    int re = SortClass::binarySearch(array3, 10, 8);
    printf("%d",re);

    @autoreleasepool {
        // Setup code that might create autoreleased objects goes here.
        appDelegateClassName = NSStringFromClass([AppDelegate class]);
    }
    return UIApplicationMain(argc, argv, nil, appDelegateClassName);
}

