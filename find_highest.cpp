#include <iostream>
using namespace std;
int main()
{
  int village_value=0,max_high=0,count=0,temp=0;
  cin>>village_value;
  for(int i = village_value;i>0;i--)
  {
    cin>>temp;
    if(max_high<temp)
    {
      max_high=temp;
      count=village_value-i+1;
    }
  }
  cout<<count;
    return 0;
}