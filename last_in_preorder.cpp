/*Description:
You are given a rooted Binary Tree, please print the last element that appears in the preorder traversal.
*//*Note:
Each vertex of the tree is labeled n distinctly.

*//*Input:
The first line is n: The number of vertices of the tree.
Then followed by n lines. Each line contains li,ri
​li/ri denotes the left/right child of the ith vertex.
If the vertex has no left/right child, the coresponding li/ri will be -1.

*//*Restriction:
1≤n≤10^6

*//*Output:
Your output should be one line with one integer x.
x is the last element of the preorder traversal.
*/
#include<iostream>
#include<vector>
using namespace std;
struct vertex
{
    bool pointed=false;
    int data=0;
    vertex* left=NULL;
    vertex* right=NULL;
};
void DFS(int &arg_root,vector<vertex> &arg_binary_tree,vector<int> &arg_preorder_list);
int main()
{
    int num_of_V=0;cin>>num_of_V;
    vector<vertex> binary_tree(num_of_V+1);
    vector<int> preorder_list(1,0);
    for(int i=1;i<=num_of_V;i++)
    {
        binary_tree[i].data=i;
        int left_point=0;cin>>left_point;
        int right_point=0;cin>>right_point;
        if(left_point!=-1)
        {
            binary_tree[i].left=&binary_tree[left_point];
            binary_tree[left_point].pointed=true;
        }
        else{binary_tree[i].left=NULL;}
        if(right_point!=-1)
        {
            binary_tree[i].right=&binary_tree[right_point];
            binary_tree[right_point].pointed=true;
        }
        else{binary_tree[i].right=NULL;}
    }
    for(int i=1;i<=num_of_V;i++)
    {
        if(!binary_tree[i].pointed)
        {
            DFS(binary_tree[i].data,binary_tree,preorder_list);
        }
    }
    cout<<preorder_list[num_of_V]<<endl;
    return 0;
}
void DFS(int &arg_root,vector<vertex> &arg_binary_tree,vector<int> &arg_preorder_list)
{
    arg_preorder_list.emplace_back(arg_root);
    if(arg_binary_tree[arg_root].left!=NULL)
    {
        DFS((arg_binary_tree[arg_root].left)->data,arg_binary_tree,arg_preorder_list);
    }
    if(arg_binary_tree[arg_root].right!=NULL)
    {
        DFS((arg_binary_tree[arg_root].right)->data,arg_binary_tree,arg_preorder_list);
    }
    return;
}