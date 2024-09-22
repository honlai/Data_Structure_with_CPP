#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
        Node():_data(0),_label(0){};
        ~Node(){};
        int get_data();
        void set_data(const int &arg_int);
        int get_label();
        void set_label(const int &arg_int);
    private:
        int _data;
        int _label;
};
void merge(Node* &arg_iter1,Node* &arg_iter2,Node* &arg_end);
void merge_sort(Node* &arg_beg,Node* &arg_end);
int main()
{
    int num_of_lists=0;cin>>num_of_lists;
    for(int i=0;i<num_of_lists;i++)
    {
        int list_len=0;cin>>list_len;
        int head=0,tail=list_len+1;
        vector<Node> ori_list;
  	    for(int j=1;j<=list_len;j++)
        {
            Node node;
            node.set_data(j);
            node.set_label(j);
		    ori_list.push_back(node);
        }
        int num_of_commands=0;cin>>num_of_commands;
        for(int j=0;j<num_of_commands;j++)
        {
            char command=' ';cin>>command;
            int target=0;cin>>target;
            target--;
            if(command=='H')
            {
                ori_list[target].set_label(head);
                head--;
            }
            if(command=='T')
            {
                ori_list[target].set_label(tail);
                tail++;
            }
        }
  	    Node* iter_beg=&ori_list[0];
  	    Node* iter_end=(&ori_list[list_len-1])+1;
  	    merge_sort(iter_beg,iter_end);
  	    for(int j=0;j<list_len;j++)
        {
		    cout<<ori_list[j].get_data()<<' ';
        }
        cout<<endl;
    }
    return 0;
}
void merge(Node* &arg_iter1,Node* &arg_iter2,Node* &arg_end)
{
    vector<Node> new_list;
    int n=0,m=0;
    while((arg_iter1+n)!=arg_iter2||(arg_iter2+m)!=arg_end)
    {
        if((arg_iter1+n)!=arg_iter2)
        {
            if((arg_iter2+m)==arg_end||(arg_iter1+n)->get_label()<=(arg_iter2+m)->get_label())
            {
                new_list.push_back(*(arg_iter1+n));
                n++;
            }
        }
        if((arg_iter2+m)!=arg_end)
        {
            if((arg_iter1+n)==arg_iter2||(arg_iter1+n)->get_label()>(arg_iter2+m)->get_label())
            {
                new_list.push_back(*(arg_iter2+m));
                m++;
            }
        }
    }
    for(int i=0;i<n+m;i++)
    {
        *(arg_iter1+i)=new_list[i];
    }
    return;
}
void merge_sort(Node* &arg_beg,Node* &arg_end)
{
    if(arg_beg+1!=arg_end)
    {
        Node* iter_mid=arg_beg+(arg_end-arg_beg)/2;
        merge_sort(arg_beg,iter_mid);
        merge_sort(iter_mid,arg_end);
        merge(arg_beg,iter_mid,arg_end);
    }
    return;
}
int Node::get_data()
{
    return this->_data;
}
void Node::set_data(const int &arg_int)
{
    this->_data=arg_int;
    return;
}
int Node::get_label()
{
    return this->_label;
}
void Node::set_label(const int &arg_int)
{
    this->_label=arg_int;
    return;
}
