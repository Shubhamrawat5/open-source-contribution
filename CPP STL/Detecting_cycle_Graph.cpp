#include<iostream>
#include <list>
#include <limits.h>
using namespace std;

class Graph
{
    int vertices;  
   
    list<int> *AdjustantArray; 
    bool isCyclicUtil(int v, bool visited[],int parent);
public:
   
    Graph(int V);  
    void ConnectEdge(int Vertices, int wieght);
    bool isCyclic(); 
};
 
Graph::Graph(int Vertices)
{
    this->vertices = Vertices;
    AdjustantArray = new list<int>[Vertices];
}
 
void Graph::ConnectEdge(int Vertices, int wieght)
{
    AdjustantArray[Vertices].push_back(wieght);
    AdjustantArray[wieght].push_back(Vertices);
}
 
bool Graph::isCyclicUtil(int Vertices,bool visited[], int parent)
{
    visited[Vertices] = true;
    list<int>::iterator i;
    for (i = AdjustantArray[Vertices].begin(); i !=AdjustantArray[Vertices].end(); ++i)
    {
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, visited, Vertices))
              return true;
        }
        else if (*i != parent)
           return true;
    }
    return false;
}
 
bool Graph::isCyclic()
{
    bool *visited = new bool[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = false;
    for (int u = 0; u < vertices; u++)
    {
        if (!visited[u])
          if (isCyclicUtil(u, visited, -1))
             return true;
    }
    return false;
}
 
int main()
{
    Graph Graph1(5);
    Graph1.ConnectEdge(1, 0);
    Graph1.ConnectEdge(0, 2);
    Graph1.ConnectEdge(2, 1);
    Graph1.ConnectEdge(0, 3);
    Graph1.ConnectEdge(3, 4);
    Graph1.isCyclic()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";

       Graph Graph2(3);
    Graph2.ConnectEdge(0, 1);
    Graph2.ConnectEdge(1, 2);
    Graph2.isCyclic()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
 
    return 0;
 
    return 0;
}
