/*Description
Given an undirected graph with n vertices. The graph doesn't have any edge initially.
Then you will be given m undirected edges. Add the edges to the graph sequentially.
After each addition of edge, calculate the number of connected components in the graph and the size of the largest connected component.
It is guaranteed that the graph remains simple (no multiple edge, no self-loop) after each addition of edge.

Note that:
A connected component of an undirected graph is a connected subgraph that is not part of any larger connected subgraph.
An isolated vertex which can not reached by any other vertices should be considered as one connected component.

*//*Input
The first line of the input contains two integers n and m — the number of vertices and the number of edges. The vertices are denoted by 1,2,...,n.
Then m lines follow, each line contains two integers u and v, being an edge to add.

Constraints
2≤n≤10^5
1≤m≤min(n(n−1)/2,2×10^5)
1≤u,v≤n ; u≠v

*//*Output
For each addition of edge, output one line: the number of connected components in the graph and the size of the largest connected component.
*/
/*Sample
IN
5 3
1 2
1 3
4 5
OUT
4 2
3 3
2 3
*/
#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int connected_size=1;
    node* parent_ptr=NULL;
};
node* find_root(node* &arg_node);
int main()
{
    int num_of_V=0;cin>>num_of_V;
    vector<node> graph(num_of_V+1);
    int num_of_E=0;cin>>num_of_E;
    int max_size=1;
    for(;num_of_E>0;num_of_E--)
    {
        int pointA=0;cin>>pointA;
        int pointB=0;cin>>pointB;
        node* pointA_ptr=&graph[pointA];
        node* pointB_ptr=&graph[pointB];
        node* rootA_ptr=find_root(pointA_ptr);
        node* rootB_ptr=find_root(pointB_ptr);
        if(rootA_ptr!=rootB_ptr)
        {
            num_of_V--;/*number of connected components*/
            rootB_ptr->parent_ptr=rootA_ptr;
            rootA_ptr->connected_size+=rootB_ptr->connected_size;
        }
        if(rootA_ptr->connected_size>max_size)
        {
            max_size=rootA_ptr->connected_size;
        }
        cout<<num_of_V<<' '<<max_size<<endl;
    } 
    return 0;
}
node* find_root(node* &arg_node)
{
    if(arg_node->parent_ptr==NULL)
    {
        return arg_node;
    }
    else
    {
        arg_node->parent_ptr=find_root(arg_node->parent_ptr);
        return arg_node->parent_ptr;
    }
}
