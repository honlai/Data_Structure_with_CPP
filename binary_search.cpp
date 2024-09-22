#include<iostream>
#include<vector>
using namespace std;
void binary_search(long int* arg_iter,int arg_len,long int* arg_input);
int main()
{
	int a_len=0,a_new_len=0,q_len=0;
	vector<long int> a_list;
  	long int input,temp;
  	cin>>a_len>>q_len;
  	for(int i=0;i<a_len;i++)
    {
      	cin>>input;
      	if(input!=temp)
        {
          	a_new_len++;
      		a_list.push_back(input);
        }
      	temp=input;
    }
  	for(int i=0;i<q_len;i++)
    {
      	cin>>input;
      	int pos= (a_new_len-1)/2;
      	long int* iter=&a_list[pos];
      	binary_search(iter,a_new_len,&input);
    }
    return 0;
}
void binary_search(long int* arg_iter,int arg_len,long int* arg_input)
{
  	if(*arg_iter==*arg_input)
    {
      	cout<<'Y'<<' ';
    	return;
    }
  	else if(arg_len==0 || arg_len==1)
    {
      	cout<<'N'<<' ';
    	return;
    }
    else
    {
    	if(*arg_iter<*arg_input)//<<-
    	{
            int chanage=(arg_len+3)/4;
          	int new_len=(arg_len-1)/2;
            binary_search(arg_iter-chanage,new_len,arg_input);
    	}
  		if(*arg_iter>*arg_input)//>>+
    	{
            int chanage=(arg_len+2)/4;
          	int new_len=arg_len/2;
            binary_search(arg_iter+chanage,new_len,arg_input);
        }
    }
}