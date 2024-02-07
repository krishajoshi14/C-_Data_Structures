#include<iostream>
using namespace std;

class list
{
    class node
    {
        public:
            int data;
            node *next;
    };
    node *prevnode,*current,*nextnode;
    node *head,*temp,*q, *temp2, *head2;
    public:
        list()
        {
            head=NULL;
            temp=NULL;
            head2=NULL;
            temp2=NULL;
        }
    void create();
    void create2();
    void display();
    void insertInBeg();
    void insertInEnd();
    void insertAfter();
    void deleteBeg();
    void deleteEnd();
    void deleteAtPosition();
    void reverse();
    void concatenation();
};

void list:: create()
{
    int x,n,i;
	cout<<"Enter the number of elements:";
	cin>>n;

    for(i=0;i<n;i++)
	{
		cout<<"Enter data:";
		cin>>x;
		node *newnode= new node();
		newnode->data=x;
		newnode->next=NULL;

        if(head==NULL)
        {
            head=temp=newnode;
            newnode->next=head;
        }
        else
		{
			temp->next=newnode;
			temp=newnode;
            newnode->next=head;
		}

    }
}



void list:: display()
{
    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<"->";
        cout<<temp->next->data<<endl;
    }

}

void list::insertInBeg()
{
    int val;
    node *newnode= new node();
    cout<<"Enter data to be inserted:";
    cin>>val;
    newnode->data=val;
    newnode->next=NULL;
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    newnode->next=head;
    head=newnode;
    temp->next=newnode;
}

void list::insertAfter()
{
    int val,pos;
    node *newnode= new node();
    cout<<"Ennter the position after which you want to insert:";
    cin>>pos;
    cout<<"Enter data to be inserted:";
    cin>>val;
    newnode->data=val;
    newnode->next=NULL;
    int i=1;
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void list:: insertInEnd()
{
    int val;
    node *newnode= new node();
    cout<<"Enter data to be inserted:";
    cin>>val;
    newnode->data=val;
    newnode->next=NULL;
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
}

void list::deleteBeg()
{
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    q=head;
    head=head->next;
    temp->next=head;
    delete(q);
}

void list:: deleteAtPosition()
{
    temp=head;
    int i=1,pos;
    cout<<"Enter the position of node you want to delete:";
    cin>>pos;
    while(i<pos)
    {
        q=temp;
        temp=temp->next;
        i++;
    }
    q->next=temp->next;
    delete(temp);
}

void list:: deleteEnd()
{
    temp=head;
    while(temp->next->next!=head)
    {
        temp=temp->next;
    }
    q=temp->next;
    temp->next=head;
    delete(q);
}

void list :: reverse()
{
    nextnode=head;
    current=NULL;
    while(nextnode->next!=head)
    {
        prevnode=current;
        current=nextnode;
        nextnode=nextnode->next;
        current->next=prevnode;
    }
    prevnode=current;
    current=nextnode;
    nextnode=nextnode->next;
    current->next=prevnode;
    head=current;
    nextnode->next=current;
}
void list::create2()
{
    int x;
    node *newnode = new node();
    cout<<"Enter data:";
    cin>>x;
    newnode ->data=x;
    newnode ->next=NULL;
    
    if(head2==NULL)
    {
        
        head2=temp2=newnode;
        newnode->next=head2;
    }
    else
    {
        temp2->next=newnode;
        newnode->next=head2;
        temp2=newnode;
    }
}

void list:: concatenation()
{
    int ele,i=0;
    cout<<"Enter the number of elements: ";
    cin>>ele;
    while(i<ele)
    {
        create2();
        i++;
    }
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head2;
    temp2=head2;
    while(temp2->next!=head2)
    {
        temp2=temp2->next;
    }
    temp2->next=head;
}

int main()
{

    int ch;
    list k;
    while(1)
    {
        cout<<"1. Create"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Insert"<<endl;
        cout<<"4. Delete"<<endl;
        cout<<"5. Reverse"<<endl;
        cout<<"6. Concatenation"<<endl;
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                k.create();
                break;
            case 2:
                k.display();
                break;
            case 3:
                int n;
                cout<<"1. Insert in the beginning"<<endl;
                cout<<"2. Insert in the end"<<endl;
                cout<<"3. Insert after a node"<<endl;
                cout<<"Enter option:";
                cin>>n;
                switch(n)
                {
                    case 1:
                        k.insertInBeg();
                        break;
                    case 2:
                        k.insertInEnd();
                        break;
                    case 3:
                        k.insertAfter();
                        break;
                }
                break;
            case 4:
                int s;
                cout<<"1. Delete in the beginning"<<endl;
                cout<<"2. Delete in the end"<<endl;
                cout<<"3. Delete at specific position"<<endl;
                cout<<"Enter option:";
                cin>>s;
                switch(s)
                {
                    case 1:
                        k.deleteBeg();
                        break;
                    case 2:
                        k.deleteEnd();
                        break;
                    case 3:
                        k.deleteAtPosition();
                        break;
                }
                break;
            case 5:
                k.reverse();
                break;
            case 6: 
                k.concatenation();
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }
}