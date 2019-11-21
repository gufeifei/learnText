//
//  Sort.hpp
//  learnText
//
//  Created by mc on 2019/11/21.
//  Copyright © 2019 mc. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>

class SortClass {
public:
    static void logStr();
    static int findSec(int *p,int len);
    static void mergeSort (int *pMerge,int *p1,int p1len,int *p2,int p2len);
    static void bubbleSort(int *array ,int count);
    static void selectSort(int *pArray,int count);
    static void countLetter(const char *pStr);
    static void printPrime();
    static int binarySearch(int *pArray,int count, int value);
};


#endif /* Sort_hpp */
