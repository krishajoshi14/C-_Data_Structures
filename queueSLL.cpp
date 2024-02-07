#include<iostream>
using namespace std;

class queue
{
    class node
    {
        public:
            int data;
            node *next;
    };
    node *front, *rear, *temp;
    public:
        queue()
        {
            front=NULL;
            rear=NULL;
            temp=NULL;
        }
    void enqueue();
    void dequeue();
    void isEmpty();
    void display();
};

void queue:: enqueue()
{
    int x;
    cout<<"Enter data: ";
    cin>>x;
    node *newnode= new node();
    newnode->data=x;
    newnode->next=NULL;
    
    if(front==NULL && rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void queue:: dequeue()
{
    if(front==NULL)
    {
        cout<<"The queue is empty"<<endl;
    }
    else
    {
        temp=front;
        front=front->next;
        delete(temp);
    }
}

void queue:: isEmpty()
{
    if(front==NULL)
    {
        cout<<"The queue is Empty"<<endl;
    }
    else
    {
        cout<<"The queue is not Empty"<<endl;
    }
}

void queue:: display()
{
    if(front==NULL && rear==NULL)
    {
        cout<<"The queue is Empty"<<endl;
    }
    else
    {
        temp=front;
        while(temp)
        {
            cout<<temp->data<<" | ";
            temp=temp->next;
        }
        cout<<endl<<endl;
    }     
}

int main()
{
    int ch;
    queue q;
    while(1)
    {
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Is Empty"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                q.enqueue();
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.isEmpty();
                break;
            case 4:
                q.display();
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }
    return 0;
}