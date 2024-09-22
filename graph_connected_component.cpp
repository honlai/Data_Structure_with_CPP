#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>> &arg_graph,vector<bool> &arg_visited,int &arg_point);
int main()
{
    int  num_of_testcases=0;cin>>num_of_testcases;
    for(;num_of_testcases>0;num_of_testcases--)
    {
        int size_of_V=0;cin>>size_of_V;
        int num_of_connected_components=0;
        vector<vector<int>> graph(size_of_V);
        vector<bool> visited(size_of_V,false);
        int size_of_E=0;cin>>size_of_E; 
        for(;size_of_E>0;size_of_E--)
        {
            int pointA=0;cin>>pointA;
            int pointB=0;cin>>pointB;
            graph[pointA-1].emplace_back(pointB);
            graph[pointB-1].emplace_back(pointA);
        }
        for(;size_of_V>0;size_of_V--)
        {
            if(!visited[size_of_V-1])
            {
                num_of_connected_components++;
                int point=size_of_V;
                dfs(graph,visited,point);
            }
        }
        cout<<num_of_connected_components<<endl;
    }
    return 0;
}
void dfs(vector<vector<int>> &arg_graph,vector<bool> &arg_visited,int &arg_point)
{
    arg_visited[arg_point-1]=true;
    for(int i:arg_graph[arg_point-1])//for i in arg_graph[arg_point-1]
    {
        if(!arg_visited[i-1])
        {
            dfs(arg_graph,arg_visited,i);
        }
    }
}
/*
void bfs(vector<vector<int> > &arg_graph,vector<bool> &arg_visited,int &arg_point){
	vector<vector<int>> subgraph(1,vector<int>(2,0));
    arg_visited[arg_point-1]=true;
	subgraph[0][0]=arg_point;
    for(int i:arg_graph[arg_point-1])
    {
        arg_visited[i-1]=true;
        vector<int> node(2,0);
        node[0]=i;
        node[1]=1;
        subgraph.emplace_back(node);
    }
}
*/