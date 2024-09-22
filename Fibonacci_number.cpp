#include<iostream>
using namespace std;
void fibonacci_generater(unsigned long int arg_pos,unsigned long int* arg_first,unsigned long int* arg_second);
int main()
{
	unsigned long int first=0,second=1;
  	unsigned long int pos=0;
  	cin>>pos;
  	fibonacci_generater(pos,&first,&second);
    return 0;
}
void fibonacci_generater(unsigned long int arg_pos,unsigned long int* arg_first,unsigned long int* arg_second)
{
  	*arg_first%=1000000007;
  	*arg_second%=1000000007;
	if(arg_pos==0){cout<<*arg_first;}
  	else
    {
      	*arg_first+=*arg_second;
      	fibonacci_generater(arg_pos-1,arg_second,arg_first);
    }
}