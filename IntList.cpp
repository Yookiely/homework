#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList(int numVals, int val)
{
    if(numVals>0){
        values = new int[numVals];
        numberValues = numVals;
        for(int i =0 ;i<numVals;i++){
            values[i]=val;
        }
    }else{
     numberValues =0;
    }
}
IntList::IntList(const IntList &il)
{
    this->numberValues=il.size();
    if(il.size()>0){
        values= new int[numberValues];
        for(int i = 0;i<numberValues;i++ ){
            values[i]=il.values[i];
        }
    }
}

IntList::~IntList()
{
    delete [] values;
}

int IntList::size() const
{
    return numberValues;
}

IntList& IntList::operator=(const IntList &il)
{
    if(this != &il){
            if(size() != il.size()){
                delete [] values;
                numberValues = il.size();
                values = new int[numberValues];
            }
        for(int i =0; i< numberValues ;i++){
            values[i] = il.values[i];
        }
    }
    return *this;
}
void IntList::resize(int n, int val){
     int *temp=new int[n];

     if (n>numberValues){
            for (int i=0;i<numberValues;++i){
                    temp[i]=values[i];
            }
            for (int j=numberValues;j<n;++j){
                    temp[j]=val;
            }
     }
     else{
            for(int i=0;i<n;++i){
                 temp[i]=values[i];
            }
     }
     delete[]values;
     values=temp;
     numberValues=n;
}

void IntList::push_back(int val){
    numberValues++;
    int *newValues = new int[numberValues];
    for(int i =0 ;i<numberValues-1;i++){
        newValues[i] = values[i];
    }
    newValues[numberValues -1] = val;
    int *temp = values;
    values = newValues;
    delete [] temp;
}



