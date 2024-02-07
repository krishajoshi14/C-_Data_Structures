#include<iostream>
using namespace std;

class stack
{
    class node
    {
        public:
            int data;
            node *next;
    };
    node *top, *temp;
    node *q;
    public:
        stack()
        {
            top=NULL;
            q=NULL;
            temp=NULL;
        }
    void push();
    void pop();
    void display();
    void isEmpty();
};

void stack:: push()
{
    int x;
    cout<<"Enter data to be inserted:";
    cin>>x;
    node *newnode= new node();
    newnode->data=x;
    newnode->next=NULL;

    if(top==NULL)
    {
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
    
}

void stack :: pop()
{
    if(top==NULL)
    {
        cout<<"Stack underflow"<<endl;
    }
    else
    {
        cout<<"The element to be poppeed is: "<<top->data<<endl;
        q=top;
        top=top->next;
        delete(q);
    }

}

void stack:: isEmpty()
{
    if(top==NULL)
    {
        cout<<"The stack is Empty"<<endl;
    }
    else
    {
        cout<<"The stack is not Empty"<<endl;
    }
}

void stack:: display()
{
    temp = top;
	
	cout<<endl<<"The Stack is - ";
	cout<<endl<<endl;
	
	while(temp!=NULL)
	{
		cout<<"  "<<temp -> data<<endl;
		temp = temp -> next; 
		cout<<"  "<<"|"<<endl<<endl;
	}
    cout<<"---------"<<endl;
}

int main()
{
    int ch;
    stack s;
    while(1)
    {
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Is Empty"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.isEmpty();
                break;
            case 4:
                s.display();
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }
    return 0;
}