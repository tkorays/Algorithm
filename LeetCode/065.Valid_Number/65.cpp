/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) return false;
        int i = 0;
        while(s[i] == ' ') ++i;
        if(s[i]=='+' || s[i]=='-') ++i;
        bool fn = 0, fd = 0, fe = 0;
        for(; s[i] && s[i] != ' '; i++) {
            if((s[i] < '0' || s[i] > '9') && s[i]!='.' && s[i] != 'e') return false;
            if(!fn && s[i] == 'e') return false;
            if(fd && s[i] == '.') return false;
            if(fe && (s[i] == 'e' || s[i] == '.')) return false;
            else if(!fn && s[i] >= '0' && s[i] <= '9') fn = true;
            else if(s[i] == '.') fd = true;
            else if(s[i] == 'e') {
                if(s[i+1] == '+' || s[i+1] == '-') ++i;
                fn = false;
                fd = false;
                fe = true;
            }
        }
        for(; s[i] == ' '; i++) ;
        return i == s.length() && fn;
    }
};

int main() {
    Solution s;
    cout<<s.isNumber("0")<<endl;
    cout<<s.isNumber(" 0.1 ")<<endl;
    cout<<s.isNumber("123e123")<<endl;
    cout<<s.isNumber(".1")<<endl;
    cout<<"false:"<<endl; 
    cout<<s.isNumber(" ")<<endl;
    cout<<s.isNumber(".")<<endl;
    cout<<s.isNumber("e")<<endl;
    cout<<s.isNumber("1 a")<<endl;
    cout<<s.isNumber("+13e45e")<<endl;
    cout<<s.isNumber("abc")<<endl;
    cout<<s.isNumber("123.356e.1236")<<endl;
    cout<<s.isNumber("123.356e")<<endl;
    cout<<s.isNumber("+123e0.123")<<endl;
    cout<<s.isNumber("+123e-0.123")<<endl;
    return false;
}