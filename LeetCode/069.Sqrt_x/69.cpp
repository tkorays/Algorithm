/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        if(x < 0) return 0;
        while(left+1 < right) {
            int mid = (left+right)>>1;
            long t = (long)mid*mid;
            if(t < x) {left = mid; continue;}
            else if(t > x) {right = mid; continue;}
            else return mid;
        }
        if((long)right*right <= x){ return right;}
        else return left;
    }
};

int main(){
    Solution s;
    cout<<s.mySqrt(1)<<endl;
    cout<<s.mySqrt(4)<<endl;
    cout<<s.mySqrt(10)<<endl;
    cout<<s.mySqrt(64)<<endl;
    cout<<s.mySqrt(100)<<endl;
    cout<<s.mySqrt(2147483647)<<endl;
    cout<<s.mySqrt(2147395599)<<endl;
    return 0;
}