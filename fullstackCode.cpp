#include <bits/stdc++.h>

using namespace std;

class FullStack{
    private:
    vector<stack<int>> stacks;
    stack<int> srqst;
    stack<int> scrud;
    stack<int> sservice;
    stack<int> sdatabase;
    stack<string> serror;
    stack<int> sresponse;
    
    public:
    
    FullStack(){
        srqst.push(0);
        srqst.push(1);
        
        for(int i=1;i<=4;i++){
            scrud.push(i);
            sservice.push(i);
            sdatabase.push(i);
        }
        
        serror.push("ERROR");
        serror.push("EXCEPTION");
        
        
        stacks.push_back(srqst);
        stacks.push_back(scrud);
        stacks.push_back(sservice);
        stacks.push_back(sdatabase);
    }
    
    bool isfound(stack<int> s, int val){
        while(!s.empty()){
            if(s.top() == val){
                return true;
            }
            s.pop();
        }
        return false;
    }
    
    void response(int arr[]){
        if(arr[0] == 0){
            while(serror.top() != "ERROR"){
                serror.pop();
            }
            cout<<"ERROR";
            return;
        }
        
        for(int i=1;i<4;i++){
            if(isfound(stacks[i],arr[i])){
                sresponse.push(arr[i]); 
            }
            else{
                cout<<"EXCEPTION";
                return;
            }
        }
        
        sresponse.push(0);
        print(sresponse);
    }
    
    void print(stack<int> s){
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    
};

int main()
{
    FullStack fs;
    
    int arr[4];
    for(int i=0;i<4;i++){
        cin>>arr[i];
    }
    
    fs.response(arr);
    
    return 0;
}
