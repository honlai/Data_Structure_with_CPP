/*Description
You are given the preorder and inorder traversal of a binary tree. Your job is to reconstruct the tree and print the postorder traversal of the tree.

*//*Note
Each vertex of the tree is labeled 1~num_of_V distinctly.

*//*Input
Each input is given in three lines.
The first line contains an integer num_of_V: The number of vertices of the binary tree.
The second line is the preorder traversal of the tree.
The last line is the inorder traversal of the tree.

*//*Note
For both traversals, each vertex is seperated by an empty space.

*//*Restriction
1≤n≤2∗10^5
 
*//*Output
Output should be printed in one line. Containing the postorder traversal of the tree. Each vectex of the traversal should be seperated with an empty space.
*/

/*Sample
IN
10
1 2 4 7 8 5 3 6 9 10
7 4 8 2 5 1 3 9 6 10
OUT
7 8 4 5 2 9 10 6 3 1 

IN
15
15 8 7 4 1 3 2 6 5 14 13 12 11 9 10
1 4 2 3 7 6 5 8 15 13 12 9 11 10 14
OUT
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
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
void binary_tree_constructor(int &arg_num_of_V,vector<int> &arg_preorder_list,vector<int> &arg_inorder_list,vector<vertex> &arg_binary_tree);
void DFS(int &arg_root,vector<vertex> &arg_binary_tree,vector<int> &arg_postorder_list);
int main()
{
    int num_of_V=0;cin>>num_of_V;
	vector<int> preorder_list(1,0);
	vector<int> inorder_list(1,0);
    vector<vertex> binary_tree(num_of_V+1);
	int temp=0;
	for(int i=1;i<=num_of_V;i++)
    {
        binary_tree[i].data=i;
		cin>>temp;
		preorder_list.push_back(temp);
	}
	for(int i=1;i<=num_of_V;i++)
    {
		cin>>temp;
		inorder_list.push_back(temp);
	}
    binary_tree_constructor(num_of_V,preorder_list,inorder_list,binary_tree);
    int top=preorder_list[1];
    vector<int> postorder_list;
    DFS(top,binary_tree,postorder_list);
    return 0;
}
void binary_tree_constructor(int &arg_num_of_V,vector<int> &arg_preorder_list,vector<int> &arg_inorder_list,vector<vertex> &arg_binary_tree)
{
    int *iter_pre=&arg_preorder_list[1];
    int *iter_in=&arg_inorder_list[1];
    while((iter_pre)!=&arg_preorder_list[arg_num_of_V])
    {
        //cout<<" iter_pre "<<*iter_pre<<endl;
        if(*iter_pre==*iter_in)
        {
            while(arg_binary_tree[*(iter_in+1)].left!=NULL)
            {
                iter_in++;
            }
            iter_pre++;
            arg_binary_tree[*iter_in].right=&arg_binary_tree[*iter_pre];
            //cout<<*iter_in<<" r "<<*iter_pre<<endl;
            iter_in++;
        }
        else
        {
            arg_binary_tree[*iter_pre].left=&arg_binary_tree[*(iter_pre+1)];
            //cout<<*iter_pre<<" l "<<*(iter_pre+1)<<endl;
            iter_pre++;
        }
	}

}
void DFS(int &arg_root,vector<vertex> &arg_binary_tree,vector<int> &arg_postorder_list)
{
    if(arg_binary_tree[arg_root].left!=NULL)
    {
        DFS((arg_binary_tree[arg_root].left)->data,arg_binary_tree,arg_postorder_list);
    }
    if(arg_binary_tree[arg_root].right!=NULL)
    {
        DFS((arg_binary_tree[arg_root].right)->data,arg_binary_tree,arg_postorder_list);
    }
    cout<<arg_root<<' '<<flush;
    arg_postorder_list.emplace_back(arg_root);
    return;
}