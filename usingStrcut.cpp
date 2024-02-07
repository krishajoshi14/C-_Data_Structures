#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void display(node *temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data <<endl;
        temp=temp->next;
    }
}

int main()
{
    node *head;
    node *first=new node();
    node *second=new node();
    node *third=new node();
    head=first;
    first->data=10;
    first->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=NULL;

    display(head);

    return 0;
}