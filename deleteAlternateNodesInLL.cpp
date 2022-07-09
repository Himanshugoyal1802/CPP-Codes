//delete alternate Node in a linked list
#include <iostream>

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    ~Node() {
        if(next) {
            delete next;
        }
    }
};


void deleteAlternateNodes(Node *head) {
    
    if(head == NULL || head->next == NULL){
        return;
    }
    
    Node * prev = NULL;
    Node * curr = head;
    Node * front = curr->next;
    
    int count = 1;
    
    while(curr != NULL){
        
        if(count %2 == 0){
            Node * a = curr;
            prev->next = front;
            curr = front;
            if(front!=NULL){
            	front = front->next;    
            } 
            delete a;
            
        }else{
            prev = curr;
            curr = curr->next;
            front = front->next;
        }
        count++;
    }
    
    
}




using namespace std;
// #include "solution.h"

Node* takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}