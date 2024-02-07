#include<iostream>
using namespace std;

class node 
{
		node *left;
		int data;
		node *right;

	public:
		node(int n) 
        {
			data = n;
			left = right = NULL;
		}
		friend class bst;
};

class bst 
{
    void preorder(node *currentnode);
    void inorder(node *currentnode);
    void postorder(node *currentnode);
	public:
		node *root;
		bst() 
        {
			root = NULL;
		}
        void preorder();
        void inorder();
        void postorder();
		void create();
		node* search(int value);
		void deletion();
};

void bst::create() 
{
	node *newnode, *temp ;
	int n;
	char ans ;
	do 
	{
		cout<<"\nEnter the data to be inserted:";
		cin>>n;
		newnode=new node(n);
		if (root == NULL)
			root = newnode ;
		else 
		{
			temp = root;
			while (1) 
            {
				if(n <temp->data)
					if (temp->left==NULL) 
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
		cout<<"Any more numbers?(y/n)";
		cin>>ans;
	} while((ans=='y'||ans=='Y'));
}

node* bst::search(int value) 
{
	node *temp=root;
	while(temp!=NULL) 
    {
		if(value==temp->data) 
        {
			return temp;
		} 
        else if(value<temp->data) 
        {
			temp=temp->left;
		} 
        else 
        {
			temp=temp->right;
		}
	}
	return NULL;
}

void bst::deletion() 
{
	int d;
	node *temp,*parent=NULL,*father,*r = NULL,*son;
	temp=root;
	cout<<"Enter data to be deleted: ";
	cin>>d;
	while((temp->data!=d)&&(temp!=NULL)) 
    {
		if(d<temp->data) 
        {
			parent=temp;
			temp=temp->left;
		} 
		else 
		{
			parent=temp;
			temp=temp->right;
		}
	}
	if(temp==NULL) 
    {
		cout<<"Number not found!";
		return;
	}
	
	if(temp->left==NULL) 
		r=temp->right;
	else if(temp->right==NULL)
		r=temp->left;
		
	else 
    { 
		father=temp;
		r=temp->right;
		son=r->left; 

		while(son!=NULL) 
        {
			father=r;
			r=son;
			son=r->left;
		}
		
		if(father!=temp) 
        {
			father->left=r->right;
			r->right=temp->right; 
		}
		r->left=temp->left;
	}
	
	if(parent==NULL)
	    root=r;	
	else if(temp==parent->left) 
		parent->left=r; 
	else
		parent->right=r;
	delete temp;
}

void bst::preorder()
{
    preorder(root);
}

void bst::preorder(node *currentnode)
{
    if(currentnode!=NULL)
    {
        cout<<currentnode->data<<" ";
        preorder(currentnode->left);
        preorder(currentnode->right);
    }
}

void bst::inorder()
{
    inorder(root);
}

void bst::inorder(node *currentnode)
{
    if(currentnode!=NULL)
    {
        inorder(currentnode->left);
        cout<<currentnode->data<<" ";
        inorder(currentnode->right);
    }
}

void bst::postorder()
{
    postorder(root);
}

void bst::postorder(node *currentnode)
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
	bst b;
	int ch,ele,d,ch2;
	node *p;
	while(1) 
    {
        cout<<endl;
		cout<<"\nBINARY SEARCH TREE\n";
		cout<<"1.Create"<<endl;
        cout<<"2.Search"<<endl;
        cout<<"3.Delete"<<endl;
        cout<<"4.Display"<<endl;
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch) 
        {
			case 1:
				b.create();
				break;
			case 2:
                cout<<"\nEnter element you want to search:";
				cin>>ele;
				p=b.search(ele);
				if(p!=NULL) 
                {
					cout<<"Element found!";
				} 
				else
					cout<<"Element Not Found!";
				break;
			case 3:
				b.deletion();
				cout<<"\nElement deleted succcessfully";
				break;
            case 4:
                cout<<"1.Preorder traversal"<<endl;
                cout<<"2.Inorder "<<endl;
                cout<<"3.Postorder"<<endl;
                cout<<"Enter choice:";
                cin>>ch2;
                switch(ch2)
                {
                    case 1:
                        b.preorder();
                        break;
                    case 2:
                        b.inorder();
                        break;
                    case 3:
                        b.postorder();
                        break;
                }
                break;
			default:
				cout<<"Invalid choice";
				break;
		}
	}
}
