#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
    int NumberOfVertices;
    struct node{
        int Vertex;
        int Weight;
        node * next;
    };

    struct node** AdjacencList;

    public:

    Graph(int NoOfVertices){
        this->NumberOfVertices = NoOfVertices;

        AdjacencList = new node*[NoOfVertices];

        for(int i=0;i<NoOfVertices;i++){
            AdjacencList[i] = NULL;
        }
    }

    void AddEdge(int SV, int EV, int wt){
        struct node * s1 = new node();

        s1->Vertex = EV;
        s1->Weight = wt;
        s1->next = NULL;

        struct node *start;
        start = AdjacencList[SV];
        if(start == NULL){
            AdjacencList[SV] = s1;
        }
        else{
            while(start->next != NULL){
                start = start->next;
            }
            start ->next = s1;
        }
    }

        void PrintEdgeList(int SV){
            struct node * start;

            start = AdjacencList[SV];
            if(start == NULL){
                cout<<"No outgoing list exists from the vertex: "<<SV;
            }
            else{
                while(start != NULL){
                    cout<<"Start Vertex: "<<SV<<" "<<",End Vertex: "<<start->Vertex<<",Weight: "<<start->Weight<<endl;
                    start = start->next;
                }
            }
        }  
};

int main(){

    Graph G1(4);
    G1.AddEdge(0,1,23);
    G1.AddEdge(0,2,45);
    G1.AddEdge(1,3,56);
    G1.AddEdge(1,2,78);
    G1.AddEdge(2,3,67);
    G1.AddEdge(3,0,20);
    
    G1.PrintEdgeList(0);
    G1.PrintEdgeList(1);
    G1.PrintEdgeList(2);
    G1.PrintEdgeList(3);
    

    return 0;
}