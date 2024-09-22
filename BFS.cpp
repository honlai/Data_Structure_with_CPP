#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool no_cookie=true;
void bfs(int &arg_start,int &arg_counts,vector<vector<int>> &arg_graph,vector<bool> &arg_visited,vector<bool> &arg_cookies);
int main()
{
    int testcase=0;cin>>testcase;
    for(;testcase>0;testcase--)
    {
        int counts=0;
        int num_of_V=0;cin>>num_of_V;
        int num_of_E=0;cin>>num_of_E;
        vector<vector<int>> graph(num_of_V+1); 
        vector<bool> visited(num_of_V+1,false);
        vector<bool> cookies(num_of_V+1,false);
        for(;num_of_E>0;num_of_E--)
        {
            int pointA=0;cin>>pointA;
            int pointB=0;cin>>pointB;
            graph[pointA].emplace_back(pointB);
            graph[pointB].emplace_back(pointA);
        }  
        int start=0;cin>>start;
        int num_of_cookies=0;cin>>num_of_cookies;
        for(;num_of_cookies>0;num_of_cookies--)
        {
            int point=0;cin>>point;
            cookies[point]=true;
        }
        bfs(start,counts,graph,visited,cookies);
        if(no_cookie)
        {
            cout<<"SAD"<<endl;
        }
        else
        {
            cout<<counts<<endl;
            no_cookie=true;
        }
    }
    return 0;
}
void bfs(int &arg_start,int &arg_counts,vector<vector<int>> &arg_graph,vector<bool> &arg_visited,vector<bool> &arg_cookies) 
{
    queue<int> temp1,temp2;
    temp1.push(arg_start);
    if(arg_cookies[arg_start])
    {
        no_cookie=false;
        return;
    }
    bool use_temp1=true;
   while((!temp1.empty())||(!temp2.empty()))
    {
        for(int i:arg_graph[use_temp1?temp1.front():temp2.front()])
        {
            if(!arg_visited[i])
            {
                arg_visited[arg_start]=true;
                if(arg_cookies[i])
                {
                    no_cookie=false;
                    arg_counts++;
                    return;
                }
                use_temp1?temp2.push(i):temp1.push(i);
            }
        }
        use_temp1?temp1.pop():temp2.pop();
        if((use_temp1&&temp1.empty())||((!use_temp1)&&temp2.empty()))
        {
            arg_counts++;
            use_temp1=(temp1.empty()?false:true);
        }
    }
    return;
}