/*Description
One day Mr. K gives you a recipe:

////Section I   Ingredients
////   - A weighted connected undirected graph G with n vertices and m edges
////   - Another graph T using same vertices with G but having no edge
////
////Section II  Procedure
////   1. Pick an edge e with smallest weight among unprocessed edges in graph G.
////      (If there are more than one such edges, pick any.)
////   2. If edge e forms an cycle along with the edges in graph T, throw edge e away.
////     Otherwise, add edge e into graph T.
////   3. Repeat step 1 and 2 until all edges in graph G are processed.
////   4. Finally, you construct a cool graph T!

You are so curious what this recipe is about. Luckily, you always bring a weighted connected undirected graph with you so you can start following the recipe right away. Please follow the instruction in the recipe to construct a cool graph (the T mentioned in the recipe) and output its total edge weight.

*//*Input
The first line contains two integers n and m, being the number of vertex and the number of edges in your weighted undirected graph.

The following m lines describes the edges. Each line contains three integers u,v,w, denoting an undirected edge uv with weight w.

Constraints
1≤n≤2⋅10^5
1≤m≤10^6
1≤w≤10^9for each edge
*//*Output
Please print the answer in one line.
*/
/*Sample
IN
6 8
1 2 4
1 3 8
2 3 9
4 3 8
5 3 7
4 5 6
4 6 3
5 6 10
OUT
28
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
    int data=0;
    node* parent_ptr=NULL;
};
node* find_root(node* &arg_node);
struct edge
{
    long long cost=0;
    node* A=NULL;
    node* B=NULL;
};
bool compare(edge* a, edge* b);
int main()
{
    int num_of_V=0;cin>>num_of_V;
    int num_of_E=0;cin>>num_of_E;
    vector<node> graph(num_of_V+1);
    vector<edge*> edges;
    for(;num_of_E>0;num_of_E--)
    {
        int pointA=0;cin>>pointA;
        int pointB=0;cin>>pointB;
        int edge_cost=0;cin>>edge_cost;
        edge* edge_ptr=new edge;
        edge_ptr->A=&graph[pointA];
        edge_ptr->A->data=pointA;
        edge_ptr->B=&graph[pointB];
        edge_ptr->B->data=pointB;
        edge_ptr->cost=edge_cost;
        edges.emplace_back(edge_ptr);
    }
    sort(edges.begin(),edges.end(),compare);
    long long min_cost=0;
    for(edge* e_ptr:edges)
    {
        node* pointA_ptr=&graph[e_ptr->A->data];
        node* pointB_ptr=&graph[e_ptr->B->data];
        node* rootA_ptr=find_root(pointA_ptr);
        node* rootB_ptr=find_root(pointB_ptr);
        if(rootA_ptr!=rootB_ptr)
        {
            rootB_ptr->parent_ptr=rootA_ptr;
            min_cost+=e_ptr->cost;
        }
    }
    cout<<min_cost<<endl;
    return 0;
}
bool compare(edge* a, edge* b)
{
	return a->cost < b->cost;
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

