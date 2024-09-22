#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int len=0;cin>>len;
    int k=0;cin>>k;
    priority_queue<int> tree;
    for(int i=1;i<=len;i++)
    {
        int input=0;cin>>input;
        tree.push((-1)*input);
        if(i>=k)
        {
            if(i>k){tree.pop();}
            cout<<(-1)*tree.top()<<endl;
        }
    }
    return 0;
}