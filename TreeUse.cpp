#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#include "TreeClass.cpp"
TreeNode<int> * takeInputLevelWise(){
    int rootData;                       
    cout<<"Enter the rootData: "<<endl;         //enter the first main root of the tree
    cin>>rootData;

    TreeNode<int> * root = new TreeNode<int>(rootData);         //making root node dynamically
            //IMPORTANT :: we will make all the nodes dynamically bcz statically made nodes will get  
            //              automatically delete when the scope of this function is complete
    
    queue<TreeNode<int>*> pendingNodes;     //using queue for implememtation of tree

    pendingNodes.push(root);            
    
    while(!pendingNodes.empty()){

        TreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();

        int numChilds;
        cout<<"Enter the number of childs of " << front->data << endl;
        cin>>numChilds;

        for(int i = 0; i< numChilds ; i++){

            int childData;
            cout<<"Enter data of "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;

            TreeNode<int> * child = new TreeNode<int>(childData);   

            pendingNodes.push(child);
            front->children.push_back(child); 
        }
    }
    return root;
}

void printTree(TreeNode<int> * root){

    if(root == NULL){
        return;
    }

    cout<<root->data<<":";
    for(int i=0 ; i < root->children.size(); i++){
        cout<< root->children[i]->data << ",";
    }
    cout<<endl;
    for(int i = 0; i<root->children.size();i++){
        printTree(root->children[i]);
    }
}

int main(){
    TreeNode<int> * root = takeInputLevelWise();
    printTree(root);

}
