/*Same Tree
Description
Trent, Alexander, and Arnold are brothers. They were each given some binary tree of the same size which stores strings to traverse. They decide to traverse the binary tree with preorder, inorder and postorder respectively.
They want to know whether they are given the same binary tree or not.

*//*Input
There are multiple testcases.
The first line of each input is t - The number of testcases.
Then the first line of each testcase contains n - The number of nodes of the binary tree.

Then followed by three lines.
pre - The preorder traversal of a tree.
in - The inorder traversal of a tree.
post - The postorder traversal of a tree.
Each index stored by the node of the tree is a string s. Each index in the traversal is seperated by an empty space.

*//*Restriction
1≤t≤5
1≤n≤2∗10^5
1≤s.length≤10
It is promised that the nodes of each traversals are the same. Only the order of each nodes varies.

*//*Output
For each testcase, if the three traversal is from the same tree, print "yes" in lowercase.
Otherwise, print "no" in lowercase.
*/

/*Sample
IN
3
5
ls nlsl fgyh slae yhn 
fgyh nlsl slae ls yhn 
fgyh slae nlsl yhn ls 
6
w wbt ymwb ow qb yd 
ymwb wbt qb ow yd w 
ymwb qb yd ow wbt w 
6
a j fxs sqwb ia g 
fxs j a ia sqwb g 
fxs j ia g sqwb a 

OUT
yes
yes
yes
*/
#include<iostream>
#include<vector>
#include <unordered_map>
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
    int testcase=0;cin>>testcase;
    for(;testcase>0;testcase--)
    {
        int num_of_V=0;cin>>num_of_V;
        unordered_map<string, int> umap={};
    	vector<int> preorder_list(1,0);
	    vector<int> inorder_list(1,0);
        vector<vertex> binary_tree(num_of_V+1);
	    string temp="";
        /*input_preorder & construct unordered_map*/
	    for(int i=1;i<=num_of_V;i++)
        {
            binary_tree[i].data=i;
	    	cin>>temp;
            umap[temp]=i;
	    	preorder_list.push_back(i);
	    }
        /*input_inorder*/
	    for(int i=1;i<=num_of_V;i++)
        {
	    	cin>>temp;
	    	inorder_list.push_back(umap[temp]);
	    }
        /*tree_construct*/
        binary_tree_constructor(num_of_V,preorder_list,inorder_list,binary_tree);
        /*postorder_generate*/
        vector<int> postorder_list(1,0);
        DFS(preorder_list[1],binary_tree,postorder_list);
        bool graph_exist=true;
        for(int i=1;i<=num_of_V;i++)
        {
	    	cin>>temp;
            if(umap[temp]!=postorder_list[i]){graph_exist=false;}
	    }
        if(graph_exist){cout<<"yes"<<endl;}
        else{cout<<"no"<<endl;}
    }
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
    //cout<<arg_root<<' '<<flush;
    arg_postorder_list.emplace_back(arg_root);
    return;
}