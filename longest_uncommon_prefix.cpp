#include <iostream>
#include<vector>
using namespace std;
int main()
{
 	int len=0;
	cin>>len;
  	vector<int> count(len,0);
	string s="";
    cin>>s;
	for(int i=1;i<len;i++)
    {
      for(int j=0;j<len-i;j++)
      {
        if(s[j]!=s[j+i]){count[i-1]++;}
        else{break;}
      }
      cout<<count[i-1]<<endl;
    }
    return 0;
}