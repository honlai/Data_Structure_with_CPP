/*Description
Maintain an integer set, which supports the following operations:
I x : Insert. If x is NOT in the set, insert x into the set. Otherwise, don't do anything. Print the size of the set after finishing the operation.
D x : Delete. If x is in the set, delete x from the integer set. Otherwise, don't do anything. Print the size of the set after finishing the operation.
S x : Search. If x is in the set, print "YES". Otherwise, print "NO".
L x : Lower bound. Print the smallest element greater than or equal to x in the set. If the element doesn't exist, print "−1".
U x : Upper bound. Print the smallest element greater than x in the set. If the element doesn't exist, print "−1".

There are at least two ways to get AC.
One is to write a binary search tree by yourself. The template below gives the functions of the BST for reference.
Another way is to use set<int> and maintain the set by functions in the standard library.
Note: The numbers x in this problem are generated randomly.

*//*Input
The first line is an integer n which is the number of operations.
Following n lines, each line contains one of the operations described above.

Restrictions
1≤n≤10^5
1≤x≤10^9 for every x in all operations

*//*Output
For each operation:
I x or D x : Print the size of the set after finishing the operation.
S x : If x is in the set, print "YES". Otherwise, print "NO".
L x or U x : Print the element if the required element is in the set. Otherwise, print "-1".
*/

#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int label=0;
    node* parent_ptr=NULL;
    node* left_ptr=NULL;
    node* right_ptr=NULL;
};
void insert_node(int &arg_data,node* &arg_node_ptr,int &arg_count);
void delete_node(int &arg_data,node* &arg_node_ptr,int &arg_count,node* &arg_root_ptr);
node* search_node(int &arg_data,node* &arg_node_ptr);
node* get_lowerbound(int &arg_data,node* &arg_node_ptr);
node* get_upperbound(int &arg_data,node* &arg_node_ptr);
node* get_max_child(node* &arg_node_ptr);
node* get_min_child(node* &arg_node_ptr);
int main()
{
    int count=0;
    node* root_ptr=NULL;
    int num_of_operations=0;cin>>num_of_operations;
    for(;num_of_operations>0;num_of_operations--)
    {
        char command=' ';cin>>command;
        int data=0;cin>>data;
        switch(command)
        {
            case 'I':
                if(root_ptr!=NULL)
                {
                    insert_node(data,root_ptr,count);
                }
                else
                {
                    root_ptr=new node;
                    root_ptr->label=data;
                    count++;
                }
                cout<<count<<endl;
                continue;
            case 'D':
                if(root_ptr!=NULL)
                {
                    delete_node(data,root_ptr,count,root_ptr);
                }
                cout<<count<<endl;
                continue;
            case 'S':
                if(root_ptr==NULL)
                {
                    cout<<"NO"<<endl;
                }
                else if(search_node(data,root_ptr)!=NULL)
                {
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
                continue;
            case 'L':
                if(root_ptr==NULL)
                {
                    cout<<"-1"<<endl;
                }
                else
                {
                    node* lb_ptr=get_lowerbound(data,root_ptr);
                    if(lb_ptr!=NULL)
                    {
                        cout<<lb_ptr->label<<endl;
                    }
                    else
                    {
                        cout<<"-1"<<endl;
                    }
                }
                continue;
            case 'U':
                if(root_ptr==NULL)
                {
                    cout<<"-1"<<endl;
                }
                else
                {
                    node* ub_ptr=get_upperbound(data,root_ptr);
                    if(ub_ptr!=NULL)
                    {
                        cout<<ub_ptr->label<<endl;
                    }
                    else
                    {
                        cout<<"-1"<<endl;
                    }
                }
                continue;
        }
    }
    return 0;
}

void insert_node(int &arg_data,node* &arg_node_ptr,int &arg_count)
{
    if(arg_data < arg_node_ptr->label)
    {
        if(arg_node_ptr->left_ptr == NULL)
        {
            node* new_node_ptr=new node;
            new_node_ptr->label=arg_data;
            new_node_ptr->parent_ptr=arg_node_ptr;
            arg_node_ptr->left_ptr=new_node_ptr;
            arg_count++;
            return;
        }
        else
        {
            insert_node(arg_data,arg_node_ptr->left_ptr,arg_count);
        }
    }
    if(arg_node_ptr->label < arg_data)
    {
        if(arg_node_ptr->right_ptr == NULL)
        {
            node* new_node_ptr=new node;
            new_node_ptr->label=arg_data;
            new_node_ptr->parent_ptr=arg_node_ptr;
            arg_node_ptr->right_ptr=new_node_ptr;
            arg_count++;
            return;
        }
        else
        {
            insert_node(arg_data,arg_node_ptr->right_ptr,arg_count);
        }
    }
    return;
    
}
void delete_node(int &arg_data,node* &arg_node_ptr,int &arg_count,node* &arg_root_ptr)
{
    node* tmp_ptr=search_node(arg_data,arg_node_ptr);
    if(tmp_ptr==NULL)
    {
        return;
    }
    else
    {
        if(tmp_ptr->left_ptr!=NULL&&tmp_ptr->right_ptr!=NULL)
        {
            node* max_child_ptr=get_max_child(tmp_ptr->left_ptr);
            max_child_ptr->right_ptr=tmp_ptr->right_ptr;
            tmp_ptr->right_ptr->parent_ptr=max_child_ptr;
        }
        else if(tmp_ptr->left_ptr!=NULL)
        {
            tmp_ptr->left_ptr->parent_ptr=tmp_ptr->parent_ptr;
        }
        else if(tmp_ptr->right_ptr!=NULL)
        {
            tmp_ptr->right_ptr->parent_ptr=tmp_ptr->parent_ptr;
        }
        if(tmp_ptr==arg_root_ptr)
        {
            arg_root_ptr=(tmp_ptr->left_ptr!=NULL)?tmp_ptr->left_ptr:tmp_ptr->right_ptr;
        }
        else
        {
            if(tmp_ptr->parent_ptr->label < tmp_ptr->label)
            {
                tmp_ptr->parent_ptr->right_ptr=(tmp_ptr->left_ptr!=NULL)?tmp_ptr->left_ptr:tmp_ptr->right_ptr;
            }
            else
            {
                tmp_ptr->parent_ptr->left_ptr=(tmp_ptr->left_ptr!=NULL)?tmp_ptr->left_ptr:tmp_ptr->right_ptr;
            }
        }
        delete(tmp_ptr);
        arg_count--;
        return;
    }
}
node* search_node(int &arg_data,node* &arg_node_ptr)
{
    if(arg_node_ptr->label==arg_data)
    {
        return arg_node_ptr;
    }
    if(arg_data<arg_node_ptr->label)
    {
        if(arg_node_ptr->left_ptr!=NULL)
        {
            return search_node(arg_data,arg_node_ptr->left_ptr);
        }
    }
    if(arg_node_ptr->label<arg_data)
    {
        if(arg_node_ptr->right_ptr!=NULL)
        {
            return search_node(arg_data,arg_node_ptr->right_ptr);
        }
    }
    return NULL;
}
node* get_lowerbound(int &arg_data,node* &arg_node_ptr)
{
    if(arg_data <= arg_node_ptr->label)
    {
        if(arg_node_ptr->left_ptr == NULL)
        {
            return arg_node_ptr;
        }
        else if(arg_node_ptr->left_ptr->label < arg_data)
        {
            return arg_node_ptr;
        }
        else 
        {
            return get_lowerbound(arg_data,arg_node_ptr->left_ptr);
        }
    }
    if(arg_node_ptr->label < arg_data)
    {
        if(arg_node_ptr->right_ptr == NULL)
        {
            return NULL;
        }
        else
        {
            return get_lowerbound(arg_data,arg_node_ptr->right_ptr);
        }
    }
}
node* get_upperbound(int &arg_data,node* &arg_node_ptr)
{
    if(arg_node_ptr->label==arg_data)
    {
        if(arg_node_ptr->right_ptr != NULL)
        {
            return get_min_child(arg_node_ptr->right_ptr);
        }
        else
        {
            return NULL;
        }
    }
    if(arg_data < arg_node_ptr->label)
    {
        if(arg_node_ptr->left_ptr == NULL)
        {
            return arg_node_ptr;
        }
        else if(arg_node_ptr->left_ptr->label <= arg_data)
        {
            return arg_node_ptr;
        }
        else
        {
            return get_upperbound(arg_data,arg_node_ptr->left_ptr);
        }
    }
    if(arg_node_ptr->label < arg_data)
    {
        if(arg_node_ptr->right_ptr == NULL)
        {
            return NULL;
        }
        else
        {
            return get_upperbound(arg_data,arg_node_ptr->right_ptr);
        }
    }
}
node* get_max_child(node* &arg_node_ptr)
{
    if(arg_node_ptr->right_ptr==NULL)
    {
        return arg_node_ptr;
    }
    else
    {
        return get_max_child(arg_node_ptr->right_ptr);
    }
}
node* get_min_child(node* &arg_node_ptr)
{
    if(arg_node_ptr->left_ptr==NULL)
    {
        return arg_node_ptr;
    }
    else
    {
        return get_min_child(arg_node_ptr->left_ptr);
    }
}