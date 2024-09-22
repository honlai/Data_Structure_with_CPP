#include<iostream>
#include<vector>
using namespace std;

bool is_DAG=true;

void topological_sort(int &arg_size, vector<vector<int>> &arg_graph,vector<int> &arg_pointed); 
void dfs(vector<vector<int>> &arg_graph,vector<vector<bool>> &arg_visited,int &arg_point);
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
    topological_sort(size_of_V,graph,pointed);
    if(is_DAG){cout<<"YES"<<endl;}
    else{cout<<"NO"<<endl;}
    return 0;
}
void topological_sort(int &arg_size,vector<vector<int>> &arg_graph,vector<int> &arg_pointed)
{
    vector<bool> pair(2,false);
    vector<vector<bool>> visited(arg_size+1,pair);
    for(int point=1;point<=arg_size;point++)
    {
        dfs(arg_graph,visited,point);
    }
    return;
}
void dfs(vector<vector<int>> &arg_graph,vector<vector<bool>> &arg_visited,int &arg_point)
{
    arg_visited[arg_point][0]=true;
    for(int i:arg_graph[arg_point])
    {
        if(!arg_visited[i][0])
        {
            if(!arg_visited[i][1])
            {dfs(arg_graph,arg_visited,i);}
        }
        else
        {
            is_DAG=false;
            return;
        }
    }
    arg_visited[arg_point][0]=false;
    arg_visited[arg_point][1]=true;
    return;
}