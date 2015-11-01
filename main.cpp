#include <iostream>
#include <vector>
#include "findmedian.h"
using namespace std;

 vector<int> mysort(vector<int>& x){ //non-descending order
        vector<int> arr = x;
        if(arr.size() == 1){
            return arr;
        }
        if(arr.size() == 2){
            if(arr[0]>arr[1]){
                int tmp = arr[0];
                arr[0] = arr[1];
                arr[1] = tmp;
            }
            return arr;
        }
        int midpoint = arr.size() / 2;
        vector<int> lo (arr.begin(),arr.begin() + midpoint);
        vector<int> hi (arr.begin() + midpoint, arr.end());
        lo = mysort(lo);
        hi = mysort(hi);
        vector<int> retval;
        retval.reserve(lo.size()+hi.size());
        int ptr1 = 0, ptr2 = 0;
        while(lo.size() > ptr1  && hi.size() > ptr2){
            if(lo[ptr1]<hi[ptr2]){
                retval.push_back((int)lo[ptr1]);
                ptr1++;
                if(ptr1 >= lo.size()){
                    retval.insert(retval.end(), hi.begin() + ptr2, hi.end());
                }//end if
            }else{
                retval.push_back((int)hi[ptr2]);
                ptr2++;
                if(ptr2 >= hi.size()){
                    retval.insert(retval.end(), lo.begin() + ptr1, lo.end());
                }//end if
            }//end if lo and hi
        }//end while
        return retval;
    }//end mysort

int main()
{
    findmedian mym;
    mym.addNum(1);
    mym.addNum(2);
    mym.addNum(3);
    mym.addNum(4);
    mym.addNum(5);
    mym.addNum(6);
    mym.addNum(7);
    mym.addNum(8);
    mym.addNum(9);
    mym.addNum(10);
    mym.addNum(11);
    return 0;
}
