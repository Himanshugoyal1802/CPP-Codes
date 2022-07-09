#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* insertNodeAtPosition(Node * head, int pos, int data){
    Node * newNode = new Node(data);
    if(pos == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }

    int count = 0;
    Node * temp = head;

    while(temp != NULL && count < pos-1){
        count++;
        temp = temp->next;
    }
    if(temp != NULL){
    newNode->next = temp->next;
    temp->next = newNode;
    }else{
        cout<<"Out of bound index,so no change"<<endl;
    }

    return head;

}

void print(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


Node* takeInput_better(){           //order of complexity is n
    int data;
    cin>>data;
    Node * head = NULL;
    Node * tail = NULL;
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

int main(){
    // Node * head = takeInput();       //order of complexity is n^2
    Node * head = takeInput_better();
    insertNodeAtPosition(head,7,6);
    print(head);
}