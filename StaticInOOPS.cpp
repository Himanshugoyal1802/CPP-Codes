#include <bits/stdc++.h>
using namespace std;

class Student{

    static int totalStudents;

    public:
    int age;
    int rollNumber;


    Student(){
        totalStudents++;
    }

    int getRollNumber(){
        return rollNumber;
    }
    static int getTotalStudents(){
        return totalStudents;
    }
};

int Student :: totalStudents = 0;

int main(){

    Student s;
    s.rollNumber = 1;
    s.age = 12;

Student s1;
    s1.rollNumber = 2;
    s1.age = 14;

    Student s3;
    s3.rollNumber = 1;
    s3.age = 12;

    Student s4;
    s4.rollNumber = 1;
    s4.age = 12;

    cout<< s.age << " "<< s.getRollNumber()<<endl;
    cout<<Student :: getTotalStudents();
}