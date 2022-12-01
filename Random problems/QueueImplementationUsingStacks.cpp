#include<iostream>
#include<stack>
using namespace std;

class QueueUsingStack{
    //using two Stacks
    /*stack<int> s1,s2;
    public:
    void enQueue(int val){
        s1.push(val);
        return;
    }

    int deQueue(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int ans = s2.top();
        s2.pop();
        return ans;
    }
    */

   //using one stack
    stack<int>s;

    public:
    void enQueue(int val){
        s.push(val);
        return;
    }

    int deQueue(){
        if(s.empty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        int topEle = s.top();
        s.pop();

        if(s.empty())return topEle;

        int ans = deQueue();

        s.push(topEle);
        return ans; 
    }
};

int main(){
    QueueUsingStack q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
 
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
}