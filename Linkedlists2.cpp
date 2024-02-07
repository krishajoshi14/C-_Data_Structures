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
    
    node *currentnode, *nextnode;
    node *head,*temp;
    node *prevnode;
    node *head2,*temp2;

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

void list :: create()
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
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
    }
}

void list::create2()
{
    int x;
    cout<<"Enter data:";
    cin>>x;

    node *newnode = new node();
    newnode ->data=x;
    newnode ->next=NULL;

    if(head2==NULL)
    {
        head2=temp2=newnode;
    }
    else
    {
        temp2->next=newnode;
        temp2=newnode;
    }
}

void list::display()
{
    temp=head;
    while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}

void list::insertInBeg()
{
    int val;
    cout<<"Enter data to be inserted:";
    cin>>val;

    node *newnode= new node;
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

void list::insertInEnd()
{
    int val;
    cout<<"Enter data to be inserted:";
    cin>>val;

    node *newnode = new node();
    newnode->data=val;
    newnode->next=NULL;
    
    if(head==NULL)
    {
        head=newnode;
    }
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

void list::insertAfter()
{
    int i=1,pos,val;
    node *newnode =new node();
    cout<<"Enter the position after which you wish to insert: ";
    cin>>pos;
    temp=head;
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    cout<<"Enter the data to be inserted:";
    cin>>val;
    newnode->data=val;
    newnode->next=temp->next;
    temp->next=newnode;
}

void list:: deleteBeg()
{
    temp=head;
    head=head->next;
    delete(temp); 
}

void list::deleteEnd()
{
    temp=head;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=NULL;
    delete(temp);
}

void list::deleteAtPosition()
{
    int pos,i=1;
    cout<<"Enter the position of node you want to delete:";
    cin>>pos;
    temp=head;
    while(i<pos)
    {
        prevnode=temp;
        temp=temp->next;
        i++;
    }
    prevnode->next=temp->next;
    delete(temp);
}

void list::reverse()
{
    prevnode=0;
    currentnode=nextnode=head;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}

void list::concatenation()
{
    int ele,i;
    cout<<"Enter the number of elements: ";
    cin>>ele;
    for(i=0;i<ele;i++)
    {
        create2();
    }
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head2;
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
    return 0;
}