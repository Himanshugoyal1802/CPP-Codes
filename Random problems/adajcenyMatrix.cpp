#include <bits/stdc++.h>
using namespace std;

class Graph{
    private : 
    int numberOfVertices;
    int **AdjacencyMatrix;

    public:
    Graph(int noVertices){
        this->numberOfVertices = noVertices;
        AdjacencyMatrix  = new int*[numberOfVertices];

        for(int i=0 ; i < numberOfVertices ; i++){
            AdjacencyMatrix[i] = new int[numberOfVertices];
            for(int j=0;j<noVertices;j++){
                AdjacencyMatrix[i][j] = 0;
            }
        }
    }

    void AddEdge(int i , int j , int weight){
        AdjacencyMatrix[i][j] = weight;
    }

    void PrintGraph(){
        for(int i=0;i<numberOfVertices;i++){
            for(int j=0 ; j<numberOfVertices;j++){
                if (AdjacencyMatrix[i][j]!=0)
                    cout<<"\nStart Vertex: "<<i<<" End Vertex: "<<j<<" weight:"<<AdjacencyMatrix[i][j];
            }
        }
    }
};

int main(){

    Graph g1(7);
    int SV , EV, EdgeWeight;

    g1.AddEdge(0,1,40);
    g1.AddEdge(0,2,50);
    g1.AddEdge(1,2,70);
    g1.AddEdge(2,3,80);


    cout<<"Enter Start Vertex: ";
    cin>>SV;

    cout<<"Enter End Vertex: ";
    cin>>EV;

    cout<<"Enter the Weight: ";
    cin>>EdgeWeight;

    g1.AddEdge(SV,EV,EdgeWeight);

    g1.PrintGraph();


    return 0;
}