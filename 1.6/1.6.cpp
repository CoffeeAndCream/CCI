
/*Cracking the Coding Interview
Chapter 1
Interview Question 1.6
Given an image represented by a NxN matrix, where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degrees. Can you do this in place?


Notes: 
1. Each pixel is one int (4 bytes). 
2. The NxN matrix needs to be scalable.

Hint:
1. Rotate the outer layers first. Move inward.
2. It's a simple swap.
3. It's a square (ie. input should be one dimensional).
*/
#include <iostream>

using namespace std;

void rotate(int[5][5], int);

int main(){
    int MATRIX[5][5]; //number of rows & columns
    int n = 3; //number of layers?
    rotate(MATRIX, n);

    return 0;
}

void rotate(int MATRIX[5][5], int n){
    for(int layer = 0; layer < n/2; layer++){
        int first = layer;
        int last = n - layer - 1;
        for(int j = 0; j < last; j++){
            //...swap
            int offset = j - first;
            //save top
            int top = MATRIX[first][j];
            //left->top
            MATRIX[first][j] = MATRIX[last-offset][first];
            //bottom->left
            MATRIX[last-offset][first] = MATRIX[last][last-offset];
            //right->bottom
            MATRIX[last][last-offset] = MATRIX[j][last];
            //top->right
            MATRIX[j][last] = top;
        }
    }
}