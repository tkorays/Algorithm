#include <iostream>

using namespace std;
#include "xseqlist.h"
int main()
{
    XSeqList<int>* s = new XSeqList<int>();
    s->Add(1);
    s->Add(2);
    s->Add(3);
    s->Add(22);
    cout<<"Size of s:"<<s->Count()<<endl;
    cout<<"Index of 2:"<<s->IndexOf(2)<<endl;
    cout<<"show s:";
    for(int i=0;i<s->Count();i++){
        cout<<s->GetByIndex(i)<<"->";
    }
    cout<<endl;
    s->Insert(5,1);
    cout<<"Index of 5:"<<s->IndexOf(5)<<endl;
    cout<<"show s:";
    for(int i=0;i<s->Count();i++){
        cout<<s->GetByIndex(i)<<"->";
    }
    cout<<endl;



    return 0;
}
