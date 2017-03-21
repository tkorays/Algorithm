/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;
        int m = n/2;
        int t = climbStairs(m);
        if(m==n-m) return t*t;
        else return t*t-1;
    }
};

int main() {
    Solution s;
    cout<<s.climbStairs(1)<<endl;
    cout<<s.climbStairs(2)<<endl;
    cout<<s.climbStairs(3)<<endl;
    cout<<s.climbStairs(4)<<endl;
    cout<<s.climbStairs(45)<<endl;
    cout<<s.climbStairs(50)<<endl;


    return 0;
}

