#include<iostream>
#include<stdlib.h>
using namespace std;
struct Stack
    {
        int top;
        int capacity;
        int *arr;
    };
class project
{
    public:

    struct Stack* createStack(int cap)
    {
        struct Stack*s;
        s=(struct Stack*)malloc(sizeof(struct Stack));
        s->capacity=cap;
        s->arr=(int *)malloc(sizeof(int)*s->capacity);
        s->top=-1;
        return s;
    }
    bool IsFull(struct Stack*s)
    {
        if(s->top==s->capacity-1)
        {
            cout<<"overflow condition"<<endl;
            return(true);
        }
        else
            return (false);
    }
    bool IsEmpty(struct Stack*s)
    {
        if(s->top==-1)
        {
            cout<<"underflow condition"<<endl;
            return(true);
        }
        else
            return(false);
    }
    void push(struct Stack*s,int x)
    {
        if(!IsFull(s)){
          s->top++;
          s->arr[s->top]=x;
          }
    }
    int pop(struct Stack*s)
    {
        int item;
        if(!IsEmpty(s))
        {
            item=s->arr[s->top];
            s->top--;
            return item;
        }
    }
};
int main()
{int ch,n,y,item;
project p;
struct Stack *s;
    s=p.createStack(4);
    while(1)
    {
        cout<<"enter the choice";
        cin>>ch;
        switch(ch)
        {

            case 1:
                {
                    cout<<"enter the value";
                    cin>>y;
                   p.push(s,y);
                    break;
                }
            case 2:
                {
                    item=p.pop(s);
                    cout<<"popped item is "<<item;
                    break;
                }
            case 3:
                {
                    exit(0);
                }
        }
    }

    return 0;
}
