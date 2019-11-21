//
//  Sort.cpp
//  learnText
//
//  Created by mc on 2019/11/21.
//  Copyright © 2019 mc. All rights reserved.
//

#include "Sort.hpp"
void SortClass:: logStr(){
    printf("hello---\n");
}
///--------------------找到数组中第二大的数
int SortClass:: findSec(int *p,int len){
    int maxv = p[0];
    int secv = p[0];
    for (int i = 1; i < len; ++i) {
        if (maxv < p[i]) {
            secv = maxv;
            maxv = p[i];
        }
    }
    return secv;
}

///--------------已知两个数组有序实现方法将他们合并后仍然有序

void SortClass:: mergeSort (int *pMerge,int *p1,int p1len,int *p2,int p2len) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < p1len && j < p2len) {
        if (p1[i] < p2[j]) {
            pMerge[k] = p1[i];
            ++k;
            ++i;
        } else {
            pMerge[k] = p2[j];
            ++k;
            ++j;
        }
    }
    while (i < p1len) {
        pMerge[k] = p1[i];
        ++k;
        ++i;
    }
    while (j < p2len) {
        pMerge[k] = p2[j];
        ++k;
        ++j;
    }
    int  count = (p1len + p2len);
    for (int h = 0; h < count; ++h) {
        printf("%d",pMerge[h]);
    }
}

///--------------冒泡排序
void SortClass:: bubbleSort(int *array ,int count) {
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                const int temp = array[j];
                array[j] = array[j + 1];
                array[j+1] = temp;
            }
        }
    }
    //打印结果
    for (int h = 0; h < count; ++h) {
        printf("%d",array[h]);
    }
}

///---------------选择排序
void SortClass:: selectSort(int *pArray,int count) {
    for (int i = 0; i < count; ++i) {
        int minValue = pArray[i];
        int minIndex = i;
        for (int j = i + 1; j < count; ++j) {
            if (pArray[j] < minValue) {
                minValue = pArray[j];
                minIndex = j;
            }
        }
        //将找到的最小元素放在数组低位上面
        const int temp = pArray[i];
        pArray[i] = minValue;
        pArray[minIndex] = temp;
    }
    //打印结果
    for (int h = 0; h < count; ++h) {
        printf("%d",pArray[h]);
    }
}

///----------------统计出一个字符串每种字母出现的次数要求时间复杂度未O(n)
void SortClass:: countLetter(const char *pStr) {
    int count[256] = {};
    for (; *pStr != '\0'; ++pStr) {
        const char c = *pStr;
        if ((c <'A' || c > 'Z') && (c <'a' || c > 'z') ) {
            continue;
        }
        int index = c;
        ++count[index];
    }
    //打印结果
    for (int h = 0; h < 256; ++h) {
        char c = h;
        printf("%c=====%d\n",c,count[h]);
    }
}

///---------------实现一个打印出1- 1000之间的所有素数的方法
void SortClass:: printPrime() {
    //1不是素数，2是最小的非奇数素数，直接从3开始
    printf("2\n");
    bool b = false;
    for (int i = 3; i <= 1000; ++i) {
        b = true;
        for (int j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                b = false;
                break;
            }
        }
        if (b) {
            printf("%d\n",i);
        }
    }
}

///-已知一个数组已经降序排序请用二分查字法找出其中的某一个元素，找到返回索引否则返回-1
int SortClass:: binarySearch(int *pArray,int count, int value) {
    int left = 0;
    int right = count - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (value < pArray[mid]) {
            left = mid + 1;
        } else  if (value > pArray[mid]){
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
