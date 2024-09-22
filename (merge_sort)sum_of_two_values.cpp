#include<iostream>
#include<vector>
using namespace std;
class Node
{
    public:
        Node():_data(0),_label(0){};
        ~Node(){};
        unsigned int get_data();
        void set_data(const unsigned int &arg_int);
        unsigned int get_label();
        void set_label(const unsigned int &arg_int);
    private:
        unsigned int _data;
        unsigned int _label;
};
void merge(Node* &arg_iter1,Node* &arg_iter2,Node* &arg_end);
void merge_sort(Node* &arg_beg,Node* &arg_end);
bool find_sum_of_two_values(Node* &arg_iter_small,Node* &arg_iter_big,const int &arg_list_len,const unsigned int &arg_target);
int main()
{
    int list_len=0;cin>>list_len;
    unsigned int target=0;cin>>target;
    vector<Node> input_list;
    int new_list_len=0;
  	for(int i=1;i<=list_len;i++)
    {
        unsigned int input=0;cin>>input;
        if(input<target)
        {
            Node node;
            node.set_data(input);
            node.set_label(i);
		    input_list.push_back(node);
            new_list_len++;
        }
    }
    if(new_list_len<=1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
  	Node* iter_beg=&input_list[0];
  	Node* iter_end=(&input_list[new_list_len-1])+1;
  	merge_sort(iter_beg,iter_end);
    if(input_list[0].get_data()+input_list[1].get_data()>target)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    if(input_list[new_list_len-2].get_data()+input_list[new_list_len-1].get_data()<target)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
  	Node* iter_small=&input_list[0];
  	Node* iter_big=&input_list[new_list_len-1];
    if(!find_sum_of_two_values(iter_small,iter_big,new_list_len,target))
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
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
            if((arg_iter2+m)==arg_end||(arg_iter1+n)->get_data()<=(arg_iter2+m)->get_data())
            {
                new_list.push_back(*(arg_iter1+n));
                n++;
            }
        }
        if((arg_iter2+m)!=arg_end)
        {
            if((arg_iter1+n)==arg_iter2||(arg_iter1+n)->get_data()>(arg_iter2+m)->get_data())
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
unsigned int Node::get_data()
{
    return this->_data;
}
void Node::set_data(const unsigned int &arg_int)
{
    this->_data=arg_int;
    return;
}
unsigned int Node::get_label()
{
    return this->_label;
}
void Node::set_label(const unsigned int &arg_int)
{
    this->_label=arg_int;
    return;
}

bool find_sum_of_two_values(Node* &arg_iter_small,Node* &arg_iter_big,const int &arg_list_len,const unsigned int &arg_target)
{
    while((arg_iter_small->get_data()+arg_iter_big->get_data())!=arg_target)
    {
        if(arg_iter_small->get_data()+arg_iter_big->get_data()>arg_target)
        {
            arg_iter_big--;
        }
        else if(arg_iter_small->get_data()+arg_iter_big->get_data()<arg_target)
        {
            arg_iter_small++;
        }
        if(arg_iter_small->get_label()==arg_iter_big->get_label())
        {
            return false;
        }
    }
    if((arg_iter_small->get_data()+arg_iter_big->get_data())==arg_target)
    {
        if(arg_iter_small->get_label()<arg_iter_big->get_label())
        {
            cout<<arg_iter_small->get_label()<<' '<<arg_iter_big->get_label()<<endl;
        }
        else
        {
            cout<<arg_iter_big->get_label()<<' '<<arg_iter_small->get_label()<<endl;
        }
        return true;
    }
    return false;
}
