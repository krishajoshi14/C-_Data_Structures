#include <iostream>
#include <stdlib.h>
using namespace std;

class node
{
    char data;
    node *left;
    node *right;
    public:
        node(char n)
        {
            data=n;
            left=NULL;
            right=NULL;
        }
    friend class tree;
};

class tree
{
    node *root;
    void preorder(node *currentnode);
    void inorder(node *currentnode);
    void postorder(node *currentnode);
    public:
        tree()
        {
            root=NULL;
        }
    void create();
    void preorder();
    void inorder();
    void postorder();
};

void tree::create()
{
    node *temp,*newnode;
    char ans, choice;
    char x;
    do
    {
        cout<<"Enter the element to be attached:";
        cin.ignore();
        x=getchar();
        newnode=new node(x);

        if(root==NULL)
            root=newnode;
        else
        {
            temp=root;
            while(1)
            {
                cout<<"Left or Right(l/r) of "<<temp->data<<"? ";
                cin>>ans;
                if(ans=='l')
                    if(temp->left==NULL)
                    {
                        temp->left=newnode;
                        break;
                    }
                    else
                        temp=temp->left;
                else
                    if(temp->right==NULL)
                    {
                        temp->right=newnode;
                        break;
                    }
                    else
                        temp=temp->right;
            }
        }
        cout<<"Any more nodes? ";
        cin>>choice;
    }while((choice=='y')||(choice=='Y'));
}

void tree::preorder()
{
    preorder(root);
}

void tree::preorder(node *currentnode)
{
    if(currentnode!=NULL)
    {
        cout<<currentnode->data<<" ";
        preorder(currentnode->left);
        preorder(currentnode->right);
    }
}

void tree::inorder()
{
    inorder(root);
}

void tree::inorder(node *currentnode)
{
    if(currentnode!=NULL)
    {
        inorder(currentnode->left);
        cout<<currentnode->data<<" ";
        inorder(currentnode->right);
    }
}

void tree::postorder()
{
    postorder(root);
}

void tree::postorder(node *currentnode)
{
    if(currentnode!=NULL)
    {
        postorder(currentnode->left);
        postorder(currentnode->right);
        cout<<currentnode->data<<" ";
    }
}

int main()
{
    int ch;
    tree t;
    while(1)
    {
        cout<<endl;
        cout<<"1. Create"<<endl;
        cout<<"2. Preorder"<<endl;
        cout<<"3. Inorder"<<endl;
        cout<<"4. Postorder"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                t.create();
                break;
            case 2:
                t.preorder();
                break;
            case 3:
                t.inorder();
                break;
            case 4:
                t.postorder();
                break;
            default:
                cout<<"Invalid choice:"<<endl;
                break;
        }
    }
    return 0;
}