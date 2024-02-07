#include<iostream>
using namespace std;

class graphnode
{
    int vertex;
    graphnode *next;
    public:
        graphnode()
        {
            vertex = 0;
            next = NULL;
        }
        graphnode(int n)
        {
            vertex=n;
            next=NULL;
        }
    friend class listgraph;
};

class listgraph
{       
    graphnode *list[50];
    int n;
    int *visited;
    public:
        listgraph(int nov)
        {
            n=nov;
            for(int j=0;j<n;j++)
            {
                list[j]=NULL;
            }
        }
    void create();
    void display();
    void recDFS(int);
    void DFS(int); //helper function to recdfs
};

void listgraph::create()
{
    int i,j;
    graphnode *temp, *newnode;
    char ans;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<"\nIs there an edge between vertex? "<<i+1<<" and "<<j+1<<": ";
            cin>>ans;
            if(ans=='y')
            {
                newnode=new graphnode(j+1);
                //attach newnode to the list
                if(list[i]==NULL)
                {
                    list[i]=temp=newnode;
                }
                else
                {
                    temp->next=newnode;
                    temp=newnode;
                }
            }
        }
    }
}

void listgraph::display()
{
    graphnode *temp;
    int i;
    for(i=0;i<n;i++)
    {
        cout<<endl;
        cout<<"Vertex"<<i+1<<"->";
        temp=list[i];
        while(temp!=NULL)
        {
            cout<<"V"<<temp->vertex<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
    }
}

void listgraph::recDFS(int start)
{
    visited= new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }

    DFS(start-1);
}

void listgraph::DFS(int v)
{
    visited[v]=1;
    cout<< v+1 <<" ";

    graphnode *temp=list[v];
    while(temp!=NULL)
    {
        int vert=temp->vertex-1;
        if(!visited[vert])
        {
            DFS(vert);
        }
        temp=temp->next;
    }
}

int main()
{
    int vertices;
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    listgraph g(vertices);
    int ch;
    while(1)
    {
        cout<<endl;
        cout<<"1. Create"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Recursive DFS"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                g.create();
                break;
            case 2:
                g.display();
                break;
            case 3:
                int start;
                cout<<"Enter the starting point:";
                cin>>start;
                g.recDFS(start);
            case 4:
                exit(0);
        }
    }
    return 0;
}