#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    
    Node (int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertathead(Node * &head, int data){
    Node * newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertattail(Node * &head, int data){
    Node * newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node * tail = head;
    while(tail->next != NULL) tail = tail->next;
    tail->next = newNode;
    
}

void insertatposition(Node * &head, int i, int data){
    Node * newNode = new Node(data);
    if(i == 0){
        newNode->next = head;
        head = newNode;
        return;
    }
    Node * temp = head;
    while(i != 1){
        i--;
        temp = temp->next;
        if(temp == NULL)break;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertafter(Node * &head, int key, int data){
    Node * newNode = new Node(data);
    if(key == head->data){
        newNode->next = head->next;
        head->next = newNode;
        return;
    }
    int count = 0;
    Node * temp = head;
    while(temp->data != key){
        temp = temp->next;
        if(temp == NULL)return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deletenodestart(Node * &head){
    if(head == NULL){
        cout<<"Linked List is Empty!"<<endl;
        return;
    }
    Node * temp = head;
    head = head->next;
    delete temp;
}

void deletenodeend(Node * &head){
    if(head == NULL){
        cout<<"Linked List is empty!"<<endl;
        return;
    }
    Node * temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node * a = temp->next;
    temp->next = NULL;
    delete a;
}

void deletenodeatposition(Node * &head, int pos){
    Node * prev = NULL;
    Node * temp = head;
    if(pos == 1){
        head = head->next;
        delete temp;
        return;
    }

    while(pos != 1 && temp != NULL){
        pos--;
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;
    
}

void deletegivenkey(Node * &head, int key){
    Node * temp = head;
    Node * prev = NULL;
    if(head->data == key){
        head = head->next;
        delete temp;
        return;
    }

    while(temp->data != key){
        prev = temp;
        temp = temp->next;
        if(temp == NULL){
            cout<<"No key exists"<<endl;
            return;
        }
    }
    prev->next = temp->next;
    delete temp;
}

void print(Node * head){
    while(head != NULL){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node * head = NULL;
    insertathead(head,1);
    insertathead(head,2);
    cout << "After insertion at head: ";
    print(head);

    insertattail(head, 4);
    insertattail(head, 5);
    cout << "After insertion at tail: ";
    print(head);
    cout << endl;

    insertafter(head, 1, 2);
    insertafter(head, 5, 6);
    cout << "After insertion at a given position: ";
    print(head);
    cout << endl;

    insertatposition(head, 3, 3);  //2 1 2 3 4 5 6
    insertatposition(head, 7, 7);  //2 1 2 3 4 5 6 7
    cout << "After insertion at a given position: ";
    print(head);
    cout << endl;

    deletenodestart(head);
    cout<<"After Deletion from beggining : ";
    print(head);
    cout<<endl;

    deletenodeend(head);
    cout<<"After Deletion from end : ";
    print(head);
    cout<<endl;

    deletenodeatposition(head,3);
    cout<<"Deletion of node at the 3rd position : ";
    print(head);
    cout<<endl;

    deletegivenkey(head,5);
    deletegivenkey(head,6);
    deletegivenkey(head,6);
    cout<<"Deletion of given node value : ";
    print(head);
    cout<<endl;
    return 0;   
}