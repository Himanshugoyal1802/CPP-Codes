#include<bits/stdc++.h>
using namespace std;

class DynamicArray{
    int *data;
    int nextIndex;
    int capacity;

    public:
    DynamicArray(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    DynamicArray(DynamicArray const &d1){           //we are making copy constructor to avoid shallow copy
        //this->data = d1.data;       //shallow copy but we have to do always deep copy

        this->data = new int[d1.capacity];      //this is deep copy ,where we are making a new array for new object every time
        for(int i=0;i<d1.nextIndex;i++){
            this->data[i] = d1.data[i];
        }
        this->nextIndex = d1.nextIndex;
        this->capacity = d1.capacity;
    }
    
    void operator=(DynamicArray const &d1){     //similary here we are making copy assignment operator function to avoid shallow copy 
        this->data = new int[d1.capacity];      
        for(int i=0;i<d1.nextIndex;i++){
            this->data[i] = d1.data[i];
        }
        this->nextIndex = d1.nextIndex;
        this->capacity = d1.capacity;
    }

    void add(int e){
        if(nextIndex == capacity){
            int *newData = new int[2*capacity];
            for(int i=0;i<nextIndex;i++){
                newData[i] = data[i];
            }
            delete []data;
            data = newData;
            capacity *= 2;
        }
        data[nextIndex] = e;
        nextIndex++;
    }

    int geti(int i) const{
        if(i<nextIndex){
            return data[i];
        }else{
            return -1;
        }
    }

    void addElement(int i, int e){
        if(i<nextIndex){
            data[i] = e;
        }else if(i == nextIndex){
            add(e);
        }else{
            return;
        }
    }

    void print() const{
        for(int i=0;i<nextIndex;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    DynamicArray d;
    d.add(10);
    d.add(20);
    d.add(30);
    d.add(40);
    d.add(50);
    d.add(60);

    d.print();

    DynamicArray d1(d);     //copy constructor will call here (but we make our own copy constructor)

    d1.print();

    DynamicArray d2;
    d2 = d;             //copy assignment operator function will be call
}