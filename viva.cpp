#include<iostream>
using namespace std;

int V=0;    // global variable V with an initial value of 0. 
            //This variable will store the number of vertices in the graph.


//this function is used to find the vertex with minimum key value that has not been visited yet
int min_Key(int key[], bool visited[])
{
    int min = 999, min_index; // 999 represents an Max Cost value

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && key[v] < min)//checks if the vertex is not visited yet and the key value is less than min key value
        {
            // vertex should not be visited 
            // if the condition is true,it updates the minimum key value and corresponding vertex index
            min = key[v];
            min_index = v;
        }
    }
    return min_index; //the function returns the index of the vertex with the minimum key value.
}

// Function to print the final MST stored in parent[],This function is used to print the
// edges and their corresponding weights in the Minimum Spanning Tree (MST).
void print_MST(int parent[], int **cost)
{
    int minCost = 0;
    cout << "Edges \tWeight\n";
    //For each vertex (except the root vertex), the function prints the edge between the 
    //vertex and its parent along with its weight. The parent vertex is retrieved from the parent array.
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] + 1 << " - " << i + 1 << " \t" << cost[i][parent[i]]<<"\n";
        minCost += cost[i][parent[i]];//updates the minCost variable with the weight of each edge.
    }
    cout << "\nTotal cost is: " << minCost<<"\n";
}

//this func is used to print adjacency matrix
void printGraph(int **cost) //** means it is a 2D array
{
    //loop to iterate over all the rows of "cost" array
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}

//func used to find the minimum spanning tree of any graph using prims algorithm
void find_MST(int **cost)
{
    int parent[V]; //stores parent of each vertex in the MST
    int key[V]; //stores the minimum cost to reach a vertex from the root vertex
    bool visited[V]; //stores whether the vertex is visited or not

    // Initialize all the arrays
    for (int i = 0; i < V; i++)
    {
        key[i] = 999; // 999 represents an Max Cost value
        visited[i] = false;
        parent[i] = -1;
    }
    //function sets the key value of the root vertex to 0 and its parent to -1.
    key[0] = 0;
    parent[0] = -1;

    for (int x = 0; x < V - 1; x++)
    {
        int u = min_Key(key, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (cost[u][v] != 0 && visited[v] == false && cost[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }
    print_MST(parent, cost);
}

int main()
{
    cout << "\nEnter number of vertices : ";
    cin >> V;

    cout << "\nEnter Graph in form of Adjacency Cost Matrix !\nEnter Weights";

    int **cost = new int *[V];
    cout << "\n\nEnter the vertices for a graph with " << V << " vetices " <<endl;
    for (int i = 0; i < V; i++)
    {
        cost[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            cin >> cost[i][j];
        }
    }
    cout << "\nYour Graph is\n";
    printGraph(cost);
    cout << endl;
    find_MST(cost);
    return 0;
}