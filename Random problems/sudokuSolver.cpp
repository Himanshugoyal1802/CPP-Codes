#include<bits/stdc++.h>
using namespace std;
#define n 9

bool findEmptyLocation(int grid[n][n], int & row, int & col){
    for(int i=0 ; i<n ; i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafeCol(int grid[n][n], int col, int num){
    for(int i=0;i<n;i++){
        if(grid[i][col] == num){
            return false;
        }
    }
    return true;
}

bool isSafeBox(int grid[n][n], int row,int col, int num){

    int rowFactor = row - (row%3);
    int colFactor = col - (col%3);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i+row][j+col] == num){
                return false;
            }
        }
    }
    return true;
}

bool isSafeRow(int grid[n][n], int row, int num){
    for(int i=0; i<n; i++){
        if(grid[row][i] == num){
            return false;
        }
    }
    return true;
}

bool isSafe(int grid[n][n],int row, int col, int num){
    if(isSafeRow(grid,row,num) && isSafeCol(grid,col,num) && isSafeBox(grid,row,col,num)){
        return true;
    }
    return false;
}

bool solveSudoku(int grid[n][n]){
    int row,col;
    if(!findEmptyLocation(grid,row,col)){
        return true;
    }
    
    for(int i=0;i<n;i++){
        if(isSafe(grid,row,col,i)){
            grid[row][col] = i;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int grid[n][n];
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            grid[i][j] = s[j]-'0';
        }
    }

    if(solveSudoku(grid)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}