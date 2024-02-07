#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node *next; //it will point always to the same type...self prefrencial pointer
};

class list : public node
{
    node *listptr, *temp;
    public:
        list()
        {
            listptr= NULL;    //Always initialize the pointer with NULL
            temp= NULL;
        }
    void create();
    void display();
};

void list ::create()
{

}

void list::display()
{

}

int main()
{
    int ch;
    list l;
    while(1)
    {
        cout<<"\nEnter your choice:"<<endl;
        cout<<"1. Create"<<endl;
        cout<<"2. Display"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                l.create();
                break;
            case 2:
                l.display();
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }
    return 0;
}