#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;      //no of vertices
    list<int> * adj;
    void topologicalSortUtil(int V, bool visited[] , stack<int> & stack);

    public:
    Graph(int V);
    void addEdge(int v,int w);
    void topologicalSort();
};

Graph :: Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[] ,stack<int>&stack){
    visited[v] = true;
    list<int> :: iterator it;
    for(it = adj[v].begin(); it!= adj[v].end();it++){
        if(!visited[*it]){
            topologicalSortUtil(*it,visited,stack);
        }
    }
    stack.push(v);
}

void Graph::topologicalSort(){
    stack<int> stack;
    bool * visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }

    for(int i=0;i<V;i++){
        if(visited[i] == false){
            topologicalSortUtil(i,visited,stack);
        }
    }

    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
}

int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given "
            "graph \n";
 
    // Function Call
    g.topologicalSort();
 
    return 0;
}