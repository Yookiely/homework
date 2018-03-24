//
//  IntList.h
//  IntList
//
//  Created by Yevon Zhang on 18/3/19.
//  Copyright (c) 2018年 Yevon Zhang. All rights reserved.
//

#ifndef __IntList__IntList__
#define __IntList__IntList__

#include <stdio.h>
#include <iostream>

class IntList {

public:
    //function members
    IntList(int numVals = 0, int val = 0); // constructor
    IntList(const IntList &il); // copy constructor
    ~IntList(); // destructor
    IntList& operator=(const IntList &il); // = operator
    int size() const; // size of the list
    // resize list
    //当n大于原来的size，使用val初始化多出的元素
    //当n小于原来的size，直接截断原list
    void resize(int n = 0, int val = 0);// resize list
    void push_back(int val); // add new last element
    //print the list
    //输出格式  列表长度：元素1 元素2 元素3 ...
    void print()//print the list
    {
        std::cout<< this->numberValues << ":";
        for (int i = 0; i < this->size(); ++i)
            std::cout<< this->values[i] << " ";
        std::cout << std::endl;
    }

private:
    // data members
    int * values; //pointer to elements
    int numberValues; //size of list
};

#endif /* defined(__IntList__IntList__) */
