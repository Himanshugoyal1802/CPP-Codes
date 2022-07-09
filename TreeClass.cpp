#include <iostream>
using namespace std;
template <typename T>       //using template so that we can make tree of any dataType
class TreeNode{
    public:
    T data;
    vector <TreeNode<T>*> children;    //using vector for no size issue (array has size issue)

    TreeNode(int val){
        this->data = val;
    }
};
