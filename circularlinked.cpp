#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class project
{
    public:

    typedef struct node
    {
        int info;
        struct node *link;
    }X;
    X*last=NULL;
    X*createnode()
    {
       X*n;
       n=(X*)malloc(sizeof(X));
       return n;
    }

    void insert_node()
    {
        X*temp,*p;
        int n;
        temp=createnode();
        cout<<"enter the value ";
        cin>>n;
        temp->info=n;
        if(last==NULL)
        {
            last=temp;
            last->link=last;
        }
        else{
                 p=last;
                 last=temp;
                 last->link=p->link;
                 p->link=temp;

        }
       // cout<<last->info;
    }
    void insert_first()
    {int n;
        X*temp,*p;
        temp=createnode();
        cout<<"enter the value ";
        cin>>n;
        temp->info=n;
        p=last->link;
        temp->link=p;
        last->link=temp;
        free(temp);
    }
    void traverse()
    {
        X*p;
        if(last==NULL)
        {
            cout<<"nothing present in circular linked  list";
        }
        else
        {
            p=last->link;
            do
            {
                cout<<p->info<<endl;
                p=p->link;
            }while(p!=last->link);

        }
    }
    void insert_between(int pos)
    {
        int i=1,n;
        X*temp,*p;
        temp=createnode();
        cout<<"enter the value";
        cin>>n;
        temp->info=n;
        p=last->link;
        if(pos==1)
        {
            void insert_first();
        }
        else{
            while(i<pos-1)
            {
                p=p->link;
                i++;
            }
        temp->link=p->link;
        p->link=temp;
    }
    }
    void delete_first()
    {
        X*p;
        if(last==NULL)
        {
            cout<<"nothing to delete";
        }
        else{
            p=last->link;
            p=p->link;
            last->link=p;
        }
    }
    void delete_last()
    {
        X*p;
        p=last->link;
        while(p->link!=last)
        {
            p=p->link;
        }
        p->link=last->link;
        last=p;
    }
    void delete_between(int pos)
    {int i=1;
        X*p,*t;
        p=last->link;
        while(i<pos-1)
        {
            p=p->link;
            i++;
        }
        t=p->link;
        p->link=t->link;
    }
};
int main()
{
    project p;
    int ch;
    while(1)
    {
        cout<<"enter the choice";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                p.insert_node();
                break;
            }
            case 2:
            {
                p.insert_first();
                break;
            }
            case 3:
            {
                int pos;
                cout<<"enter position";
                cin>>pos;
                p.insert_between(pos);
                break;
            }
            case 4:
            {
                p.delete_first();
                break;
            }
            case 5:
            {
                p.delete_last();
                break;
            }
            case 6:
            {int n;
                cout<<"enter the position";
                cin>>n;
                p.delete_between(n);
                break;
            }
            case 7:
            {
                p.traverse();
                break;
            }
        }
    }
}


