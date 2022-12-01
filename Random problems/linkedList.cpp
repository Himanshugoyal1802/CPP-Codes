/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int n){
        this->data = n;
        this->next = NULL;
    }
};

class LinkedList{
    private:
    Node * head;
    Node * tail;
    
    public:
    
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    Node * insert(){
    int n;
    cin>>n;
        while(n==-1){
            Node * newNode = new Node(n);
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            tail->next = newNode;
            tail = newNode;
        }
        cout<<"hello";
        return head;
    }
    void print(Node * head){
        cout<<"entered";
        Node * temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

};


int main()
{
    LinkedList ll;
    Node * newHead = ll.insert();
    ll.print(newHead);
    return 0;
}
