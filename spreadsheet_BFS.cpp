#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int &arg_size,vector<vector<int>> &arg_graph,vector<int> &arg_spreadsheet,vector<int> &arg_pointed);
int main()
{
    int num_of_cells=0;cin>>num_of_cells;
    int num_of_formula=0;cin>>num_of_formula;
    vector<vector<int>> graph(num_of_cells+1);
    vector<int> spreadsheet(num_of_cells+1);
    vector<int> pointed(num_of_cells+1,0);
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
            pointed[pointA]+=1;
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
            pointed[pointA]+=2;
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
            pointed[pointA]+=3;
            spreadsheet[pointA]=value;
        }
    }
    bfs(num_of_cells,graph,spreadsheet,pointed);
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
void bfs(int &arg_size,vector<vector<int>> &arg_graph,vector<int> &arg_spreadsheet,vector<int> &arg_pointed) 
{
    queue<int> temp1,temp2;
    bool use_temp1=true;
    for(int point=1;point<=arg_size;point++)
    {
        if(arg_pointed[point]==0)
        {
            temp1.push(point);
        }
    }
    while((!temp1.empty())||(!temp2.empty()))
    {
        for(int i:arg_graph[use_temp1?temp1.front():temp2.front()])
        {
            arg_spreadsheet[i]+=arg_spreadsheet[use_temp1?temp1.front():temp2.front()];
            arg_pointed[i]--;
            if(arg_pointed[i]==0)
            {
                use_temp1?temp2.push(i):temp1.push(i);
            }
        }
        use_temp1?temp1.pop():temp2.pop();
        if((use_temp1&&temp1.empty())||((!use_temp1)&&temp2.empty()))
        {
            use_temp1=(temp1.empty()?false:true);
        }
    }
    return;
}
