#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void topological_sort(int &arg_size,vector<vector<int>> &arg_graph,vector<int> &arg_spreadsheet,vector<int> &arg_pointed);
void dfs(vector<vector<int>> &arg_graph,vector<vector<bool>> &arg_visited,vector<int> &arg_spreadsheet,int &arg_point);
int main()
{
    int num_of_cells=0;cin>>num_of_cells;
    int num_of_formula=0;cin>>num_of_formula;
    vector<vector<int>> graph(num_of_cells+1);
    vector<int> spreadsheet(num_of_cells+1);
    vector<bool> pair(3,false);
    vector<vector<bool>> visited(num_of_cells+1,pair);
    for(;num_of_formula>0;num_of_formula--)
    {
        char command=' ';cin>>command;
        if(command=='A')
        {
            int pointA=0;cin>>pointA;
            int value=0;cin>>value;
            spreadsheet[pointA]=value;
        }
        if(command=='B')
        {
            int pointA=0;cin>>pointA;
            int pointB=0;cin>>pointB;
            int value=0;cin>>value;
            graph[pointB].emplace_back(pointA);
            spreadsheet[pointA]=value;
        }
        if(command=='C')
        {
            int pointA=0;cin>>pointA;
            int pointB=0;cin>>pointB;
            int pointC=0;cin>>pointC;
            int value=0;cin>>value;
            graph[pointB].emplace_back(pointA);
            graph[pointC].emplace_back(pointA);
            spreadsheet[pointA]=value;
        }
        if(command=='D')
        {
            int pointA=0;cin>>pointA;
            int pointB=0;cin>>pointB;
            int pointC=0;cin>>pointC;
            int pointD=0;cin>>pointD;
            int value=0;cin>>value;
            graph[pointB].emplace_back(pointA);
            graph[pointC].emplace_back(pointA);
            graph[pointD].emplace_back(pointA);
            spreadsheet[pointA]=value;
        }
    }
    topological_sort(num_of_cells,graph,spreadsheet,pointed);
    for(int point=1;point<=num_of_cells;point++)
    {
        if(!pointed[point])
        {
            cout<<spreadsheet[point]<<endl;
        }
        else
        {
            cout<<"#REF!"<<endl;
        }
    }
    return 0;
}
void topological_sort(int &arg_size,vector<vector<int>> &arg_graph,vector<int> &arg_spreadsheet,vector<int> &arg_pointed)
{
    vector<bool> pair(3,false);
    vector<vector<bool>> visited(arg_size+1,pair);
    for(int point=1;point<=arg_size;point++)
    {
        dfs(arg_graph,visited,arg_spreadsheet,point);
    }
    return;
}
void dfs(vector<vector<int>> &arg_graph,vector<vector<bool>> &arg_visited,vector<int> &arg_spreadsheet,int &arg_point)
{
    arg_visited[arg_point][0]=true;
    for(int i:arg_graph[arg_point])
    {
        if(!arg_visited[i][0])
        {
            if(!arg_visited[i][1])
            {dfs(arg_graph,arg_visited,arg_spreadsheet,i);}
        }
        else
        {
            arg_visited[i][2]=true;
            dfs(arg_graph,arg_visited,arg_spreadsheet,i);
            //is_DAG=false;
            return;
        }
    }
    arg_visited[arg_point][0]=false;
    arg_visited[arg_point][1]=true;
    return;
}