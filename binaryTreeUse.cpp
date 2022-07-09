#include <bits/stdc++.h>
#include "binaryTreeClass.h"
#include <queue>
using namespace std;

BinaryTreeNode<int> * takeInputLevelWise(){
    int rootData;
    cout<<"Enter Root Data : "<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> q;

    q.push(root);

    while(q.size() != 0){
        BinaryTreeNode<int> * front = q.front();
        q.pop();

        cout<<"Enter the left of "<<front->data<<endl;
        int leftChild;
        cin>>leftChild;
        if(leftChild != -1){
            BinaryTreeNode<int> * child = new BinaryTreeNode<int>(leftChild);
            front->left = child;
            q.push(child);
        }

        cout<<"Enter the right of "<<front->data<<endl;
        int rightChild;
        cin>>rightChild;
        if(rightChild != -1){
            BinaryTreeNode<int> * child = new BinaryTreeNode<int>(rightChild);
            front->right = child;
            q.push(child);
        }

    }

    return root;
}


void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        return;
    }
        
    queue<BinaryTreeNode<int>*> q;
    
    q.push(root);
    
    while(q.size()!=0){
        BinaryTreeNode<int>* front = q.front();
        cout<<front->data;
        q.pop();
        if(front->left != NULL){
            cout<<":L:"<<front->left->data<<",";
            q.push(front->left);
        }else{
            cout<<":L:"<<"-1"<<",";
        }
        
        if(front->right != NULL){
            cout<<"R:"<<front->right->data<<endl;
            q.push(front->right);
        }else{
            cout<<"R:"<<"-1"<<endl;
        }   
    } 
}

void printTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left != NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right != NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

pair<int,int> heightDiameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);

    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1+ max(lh,rh);
    int diameter = max(lh+rh,max(ld,rd));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

// 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    // printTree(root);
    printLevelWise(root);
    cout<<endl;
    pair<int,int> p = heightDiameter(root);

    cout<<"Height : "<<p.first<<endl;
    cout<<"Diameter : "<<p.second<<endl;
}