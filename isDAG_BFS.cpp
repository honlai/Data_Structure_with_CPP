#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool not_DAG=false;

void bfs(int &arg_size,vector<vector<int>> &arg_graph,vector<int> &arg_pointed);
int main()
{
    int size_of_V=0;cin>>size_of_V;
    int size_of_E=0;cin>>size_of_E;
    vector<vector<int>> graph(size_of_V+1);
    vector<int> pointed(size_of_V+1,0);
    for(;size_of_E>0;size_of_E--)
    {
        int pointA=0;cin>>pointA;
        int pointB=0;cin>>pointB;
        pointed[pointB]++;
        graph[pointA].emplace_back(pointB);
    }
    bfs(size_of_V,graph,pointed);
    if(not_DAG){cout<<"NO"<<endl;}
    else{cout<<"YES"<<endl;}
    return 0;
}
void bfs(int &arg_size,vector<vector<int>> &arg_graph,vector<int> &arg_pointed) 
{
    queue<int> temp1,temp2;
    bool use_temp1=true;
    int count=0;
    for(int point=1;point<=arg_size;point++)
    {
        if(arg_pointed[point]==0)
        {
            temp1.push(point);
            count++;
        }
    }
   while((!temp1.empty())||(!temp2.empty()))
    {
        for(int i:arg_graph[use_temp1?temp1.front():temp2.front()])
        {
            arg_pointed[i]--;
            if(arg_pointed[i]==0)
            {
                use_temp1?temp2.push(i):temp1.push(i);
                count++;
            }
        }
        use_temp1?temp1.pop():temp2.pop();
        if((use_temp1&&temp1.empty())||((!use_temp1)&&temp2.empty()))
        {
            use_temp1=(temp1.empty()?false:true);
        }
    }
    if(count!=arg_size)
    {
        not_DAG=true;
        return;
    }
    return;
}
