#include <iostream>
#include "Node.h"
using namespace std;

Node * insertNodeRecursively(Node * head, int i, int data){
    Node * temp = head;
    if(head == NULL){
        return head;
    }

    if(i==0){
        Node * newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node * newHead = insertNodeRecursively(temp->next,i-1,data);
    temp->next = newHead;
    head = temp;
    return head;

}

Node* insertNode(Node * head, int i, int data){
    Node * newNode = new Node(data);
    int count = 0;
    if(i==0){
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node * temp = head;
    while(temp!= NULL && count<i-1){
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
        Node * a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }
    return head;
    
}

Node * deleteNode(Node * head, int i){
    Node * temp = head;
    if(head == NULL){
        return head;
    }
    if(i == 0){
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    while(temp != NULL && count<i-1){
        temp = temp->next;
        count++;
    }
    if(temp!= NULL && temp->next !=NULL){
        Node * a = temp->next;
        temp->next = temp->next->next;
        delete a;
    }

    return head;
    
}

Node * deleteNodeRecursively(Node * head, int i){
    Node * temp = head;
    if(temp == NULL){
        return head;
    }

    if(i==0){
        head = head->next;
        delete temp;
        return head;
    }

    Node * newHead = deleteNodeRecursively(temp->next,i-1);
    temp->next = newHead;
    temp = head;
    return head;
}