#include<iostream>
using namespace std;
void hanoi_moves(int arg_num,char arg_beg,char arg_mid,char arg_end);
int main()
{
  	int disk_num=0;
  	char beg='1',mid='2',end='3';
  	unsigned long int min_moves=1;
	cin>>disk_num;
  	for(int i=1;i<=disk_num;i++){min_moves*=2;}
  	min_moves--;
  	cout<<min_moves<<endl;
    hanoi_moves(disk_num,beg,mid,end);
    return 0;
}
void hanoi_moves(int arg_num,char arg_beg,char arg_mid,char arg_end)
{
	if(arg_num==1){cout<<arg_beg<<' '<<arg_end<<endl;}
  	else
    {
      	hanoi_moves(arg_num-1,arg_beg,arg_end,arg_mid);
    	hanoi_moves(1,arg_beg,arg_mid,arg_end);
      	hanoi_moves(arg_num-1,arg_mid,arg_beg,arg_end);
    }
    return;
}