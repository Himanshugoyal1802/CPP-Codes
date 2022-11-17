#include<iostream>
using namespace std;
#define n 4

void matrixMultiplication(int matrix1[][n], int matrix2[][n]){
    int result[n][n];

    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            result[i][j] = 0;
            for(int k=0;k<n;k++){
                result[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }

    cout << "Result matrix is \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
}

int main(){
    
    int matrix1[n][n];
    cout<<"Enter the elements of matrix1 : "<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix1[i][j];
        }
    }

    cout<<endl;

    int matrix2[n][n];
    cout<<"Enter the elements of matrix2 : "<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix2[i][j];
        }
    }


    matrixMultiplication(matrix1,matrix2);
    return 0;
}