#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool have_same_element(vector<bool> &arg_list1,vector<bool> &arg_list2,int &arg_list_len);
int main()
{
    int num_of_testcases=0;cin>>num_of_testcases;
    for(int i=0;i<num_of_testcases;i++)
    {
        int list_len=0;cin>>list_len;
        vector<bool> link_list(list_len,false);
        vector<vector<bool>> graph(list_len,link_list);
        int num_of_edge=0;cin>>num_of_edge;
        int num_of_test=0;cin>>num_of_test;
        for(int j=0;j<num_of_edge;j++)
        {
            int pointA=0;cin>>pointA;
            int pointB=0;cin>>pointB;
            graph[pointA-1][pointB-1]=true;
            graph[pointB-1][pointA-1]=true;
        }
        for(int j=0;j<num_of_test;j++)
        {
            int pointA=0;cin>>pointA;
            pointA--;
            int pointB=0;cin>>pointB;
            pointB--;
            if(have_same_element(graph[pointA],graph[pointB],list_len))
            {
                cout<<'Y'<<endl;
            }
            else
            {
                cout<<'N'<<endl;
            }
        }
    }
    return 0;
}
bool have_same_element(vector<bool> &arg_list1,vector<bool> &arg_list2,int &arg_list_len)
{
    for(int i=0;i<arg_list_len;i++)
    {
        if(arg_list1[i]&&arg_list2[i])
        {
            return true;
        }
    }
    return false;
}