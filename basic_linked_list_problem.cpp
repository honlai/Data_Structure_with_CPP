#include<iostream>
using namespace std;
class Basic_Linked_List;
class List_Node
{
    friend Basic_Linked_List;
    public:
        List_Node():_data(0),_prev(NULL),_next(NULL){}
        ~List_Node(){}
    private:
        int _data;
        List_Node* _prev;
        List_Node* _next;
};
class Basic_Linked_List
{
    public:
        Basic_Linked_List():_len(0),_head(NULL),_tail(NULL){}
        void input_command(int &arg_num);
        ~Basic_Linked_List(){}
    private:
        int _len;
        List_Node* _head;
        List_Node* _tail;
        void _insert_head(const int &arg_data);
        void _insert_tail(const int &arg_data);
        void _remove_head();
        void _remove_tail();
        void _search(const int &arg_int);
        void _output();
};
int main()
{
    int line_num=0;cin>>line_num;
    Basic_Linked_List L;
    L.input_command(line_num);
    return 0;
}
void Basic_Linked_List::input_command(int &arg_num)
{
    for(int i=0;i<arg_num;i++)
    {
        string command="";cin>>command;
        if(command=="IH")
        {
            int data;cin>>data;
            _insert_head(data);
            continue;
        }
        if(command=="IT")
        {
            int data;cin>>data;
            _insert_tail(data);
            continue;
        }
        if(command=="RH")
        {
            _remove_head();
            continue;
        }
        if(command=="RT")
        {
            _remove_tail();
            continue;
        }
        if(command=="S")
        {
            int data;cin>>data;
            _search(data);
            continue;
        }
        if(command=="O")
        {
            _output();
            continue;
        }
    }
    return;
}
void Basic_Linked_List::_insert_head(const int &arg_data)
{
    List_Node* temp=_head;
    _head = new List_Node;
    (*_head)._data=arg_data;
    (*_head)._next=temp;
    if(_len==0)
    {
        _tail=_head;
    }
    else
    {
        (*(*_head)._next)._prev=_head;
    }
    _len++;
    return;
}
void Basic_Linked_List::_insert_tail(const int &arg_data)
{
    List_Node* temp=_tail;
    _tail = new List_Node;
    (*_tail)._data=arg_data;
    (*_tail)._prev=temp;
    if(_len==0)
    {
        _head=_tail;
    }
    else
    {
        (*(*_tail)._prev)._next=_tail;
    }
    _len++;
    return;
}
void Basic_Linked_List::_remove_head()
{
    if(_len!=0)
    {
        if(_len==1)
        {
          	delete _head;
            _head=NULL;
            _tail=NULL;
        }
        else
        {
            _head=(*_head)._next;
          	delete (*_head)._prev;
            (*_head)._prev=NULL;
        }
        _len--;
    }
    return;
}
void Basic_Linked_List::_remove_tail()
{
    if(_len!=0)
    {
        if(_len==1)
        {
          	delete _head;
            _head=NULL;
            _tail=NULL;
        }
        else
        {
            _tail=(*_tail)._prev;
          	delete (*_tail)._next;
            (*_tail)._next=NULL;
        }
        _len--;
    }
    return;
}
void Basic_Linked_List::_search(const int &arg_int)
{
    List_Node* iter=_head;
    if(_len==0)
    {
        cout<<'E'<<endl;
        return;
    }
    while(iter!=NULL)
    {
        if((*iter)._data==arg_int)
        {
            cout<<'Y'<<endl;
            break;
        }
        iter=(*iter)._next;
    }
    if(iter==NULL)
    {
        cout<<'N'<<endl;
    }
    return;
}
void Basic_Linked_List::_output()
{
    List_Node* iter=_head;
    if(_len==0)
    {
        cout<<'E'<<endl;
        return;
    }
    while(iter!=NULL)
    {
        cout<<(*iter)._data<<' ';
        iter=(*iter)._next;
    }
    cout<<endl;
    return;
}