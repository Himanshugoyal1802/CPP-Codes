#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
     int src;
     int dest;
     int weight;

};

bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int findParent(int v, int * parent){
    if(parent[v] == v){
        return v;
    }
    return findParent(parent[v] , parent);
}

void kruskal(Edge * input, int n, int e){
    //firstly sort the input array acc to each edge weight
    sort(input, input+e, compare);

    //make an output array of size n-1 ( n-1 is bcz if n vertex are there then there 
    // is only n-1 edges are needed to connect all vertex in a tree)
    // output array contains our MST(minimum spanning tree)

    Edge * output = new Edge[n-1];

    // making a parent array which stores the parent vertex of each vertex
    //(initially each vertex has its same parent vertex)

    int * parent = new int[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    //count variable is for number of edges added in our MST(we can add only n-1 edges in our MST)
    //variable i is for iterating over sorted input array
    int count =0;
    int i =0;

    while(count != n-1){
        Edge currentEdge = input[i];
        int sourceParent = findParent(currentEdge.src, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if(sourceParent != destParent){
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    //printing the MST or say our output array

    for(int i=0;i<n-1;i++){
        if(output[i].src < output[i].dest){
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
        }
    }
}

int main(){
    int n, e;
    cin>>n>>e;

    Edge * input = new Edge[e];

    for(int i = 0; i<e; i++){
        int s,d,w;
        cin>>s>>d>>w;

        input[i].src = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskal(input, n, e);
}