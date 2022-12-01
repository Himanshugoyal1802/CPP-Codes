#include<iostream>
#include<climits>
using namespace std;

class twoStack{
    int *arr;
    int top1,top2;
    int size;

    public:
    twoStack(int n = 100){
        arr = new int[n];
        size = n;
        top1 = -1;
        top2 = n;
    }

    void push1(int n);
    void push2(int n);
    int pop1();
    int pop2();
};

void twoStack :: push1(int val){
    if(top1<top2-1){
        top1++;
        arr[top1] = val;
    }else{
        cout<<"Stack1 OverFlow"<<endl;
        exit(1);
    }
}

void twoStack :: push2(int val){
    if(top1<top2-1){
        top2--;
        arr[top2] = val;
    }
    else{
        cout<<"Stack2 OverFlow"<<endl;
        exit(1);
    }
}

int twoStack :: pop1(){
    if(top1 == -1){
        cout<<"Stack1 is Empty"<<endl;
        exit(1);
    }
    int a = arr[top1];
    top1--;
    return a;
}

int twoStack :: pop2(){
    if(top2 == size){
        cout<<"Stack2 is Empty"<<endl;
        exit(1);
    }
    int a = arr[top2];
    top2++;
    return a;
}

int main(){
    twoStack ts(5);

    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is "
         << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ts.pop2();
    return 0;
}