#include<iostream>
#include<queue>
using namespace std;
int main()
{
  int num_of_operation=0;cin>>num_of_operation;
  priority_queue<int> tree;
  for(int i=0;i<num_of_operation;i++)
  {
    char command=' ';cin>>command;
    if(command=='1')
    {
      int input=0;cin>>input;
      tree.push((-1)*input);
    }
    if(command=='2')
    {
      if(!tree.empty())
      {
        tree.pop();
      }
    }
    if(command=='3')
    {
      if(!tree.empty())
      {
        cout<<(-1)*tree.top()<<endl;
      }
      else
      {
        cout<<"EMPTY"<<endl;
      }
    }
  }
  return 0;
}