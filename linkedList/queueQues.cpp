#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int>q1;
    q1.push(0);
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    queue<int>q2;
    q2.push(10);
    q2.push(11);
    q2.push(12);
    q2.push(13);
    q2.push(14);
    q2.push(15);

    queue<int>q3;
    for(int i = 0; i<6;i++){
        int a1 = q1.front();
        q1.pop();
        int a2 = q2.front();
        q2.pop();
        q3.push(a1);
        q3.push(a2);
    }
    queue<int>temp = q3;
    while(!temp.empty()){
        cout<<temp.front()<<" ";
        temp.pop();
    }
}