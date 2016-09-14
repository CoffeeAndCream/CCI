/*Cracking the Coding Interview
Chapter 1
Interview Question 1.7
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0
*/

#include <iostream>
#include <time.h>
#include <stdlib.h> 
#include <map>

using namespace std;

void zeroed(int, int);

int main(){
    int m = 5;
    int n = 10;

    zeroed(m, n); 
    
    return 0;
}

void zeroed(int m, int n){
    map<int, int> matrix;
    bool row, column;

    srand (time(NULL));    
    cout << "\nMatrix\n_________________\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            matrix[i, j] = rand()%10;
            if(matrix[i, j] == 0){
                row[i] = true
                column[j] = true;
            }
            cout << matrix[i, j]; 
        }
        cout << "\n";
    }
}

//unfinished row and column deletion...