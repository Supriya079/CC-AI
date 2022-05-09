/* Implement depth first search algorithm. Use an undirected graph and develop a 
	recursive algorithm for searching all the vertices of a graph or tree data structure. */
	
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;

// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // adjacency lists
public:
    // Constructor
    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }
 
    // function to add an edge to graph
    void addEdge(int v, int w); 
 
    // prints DFS traversal from a given source s
    void DFS(int src);  

    //prints BFS traversal from a given source s
    void BFS(int src);

    //prints adjacency list of each vertex
    void printGraph(){
        for (int v = 0; v < V; ++v){
            cout << "\nAdjacency list of vertex "<< v << ": " << v;
            for (auto x : adj[v])
                cout << "-> " << x;
                cout<<"\n";
        }
    }
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v);
}

// prints all not yet visited vertices reachable from s
void Graph::DFS(int src)
{
    // Initially mark all verices as not visited
    vector<bool> visited(V, false);
 
    // Create a stack for DFS
    stack<int> stk;
 
    // Push the current source node.
    stk.push(src);
 
    while (!stk.empty())
    {
        // Pop a vertex from stack and print it
        int t = stk.top();
        stk.pop();
 
        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited[t])
        {
            cout << t << " ";
            visited[t] = true;
        }
 
        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it
        // to the stack.
        for (auto i = adj[t].begin(); i != adj[t].end(); i++){
            if (!visited[*i]){
                stk.push(*i);
            }
        }
    }
}

void Graph::BFS(int src)
{
    // Mark all the vertices as not visited
    vector<bool> visited(V+1, false);
 
    // Create a queue for BFS
    queue<int> q;
 
    // Mark the current node as visited and enqueue it
    visited[src] = true;
    q.push(src);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    //list<int>::iterator i;
 
    while(!q.empty())
    {
        // Dequeue a vertex from queue and print it
        int f = q.front();
        cout<<f<<" ";
        q.pop();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited, 
        // then mark it visited and enqueue it
        for (auto i = adj[f].begin(); i != adj[f].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
}

int main(){
    Graph g(11);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 7);
    g.addEdge(2, 8);
    g.addEdge(3, 10);
    g.addEdge(3, 9);
    g.addEdge(4, 3);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(5, 8);
    g.addEdge(7, 8);

    g.printGraph();
    cout<<endl;

    cout<<"DFS Traversal from vertex 1: ";
    g.DFS(1);
    
    cout<<"\nBFS Traversal from vertex 1: ";
    g.BFS(1);

    return 0;
}