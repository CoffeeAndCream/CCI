/*Cracking the Coding Interview
Chapter 3
Interview Question 3.3
Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, 
we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure 
SetOfStacks that mimics this. SetOfStacks should be composed of several stacks and should create a new stack
once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically to 
a single stack (that is, pop() should return the same values as it would if there were just a single stack).
*/

#include <iostream>

using namespace std;

void SetPlates(class SetOfStacks*);

#define MAX 7

class Stack{
    private:
        int arr[MAX];
        int top;
    public:
        Stack(){
            top = -1;
        }

        bool push(int a){
            top++;
            if(top < MAX){
                arr[top] = a;
                return true;
            }
            else{
                cout << "Stack full!" << endl;
                top = -1;
                return false;
            }
            return false;
        }

        int pop(){
            if(top == -1){
			    cout << "Stack empty!" << endl;
			    return 0;
		    }
            else{
                int data = arr[top];     
                arr[top] = 0;       
                top--;
                return data;
            }
        }
};

class SetOfStacks{
    private:
        int arr[MAX];
    public:
        int top;
        SetOfStacks(){
            top = -1;
        }

         void push(int a){
            top++;
            if(top < MAX){
                arr[top] = a;
            }
            else{
                cout << "Too many stacks!" << endl;
            }
        }

        int pop(){
            if(top == -1){
			    cout << "Stack empty!" << endl;
			    return 0;
		    }
            else{
                int data = arr[top];     
                arr[top] = 0;       
                top--;
                return data;
            }
        }
};

int main(){

    //TEST CASES
    SetOfStacks *set = new SetOfStacks;
    SetOfStacks *set2 = new SetOfStacks;
    SetPlates(set);
    SetPlates(set2);

    cout << "Unloading set of dishes #" << set->pop() << endl;
    cout << "Unloading set2 of dishes #" << set2->pop() << endl;
    cout << "Unloading set of dishes #" << set->pop() << endl;
    cout << "Unloading set2 of dishes #" << set2->pop() << endl;



    return 0;
}

void SetPlates(SetOfStacks *set){
    Stack plates;
    int i = 0;
    for(i; i < 42; i++){
        if(plates.push(i)){
            cout << "Stacking plate #" << i << endl;
        }
        else{
            cout << "Starting new stack..." << endl;
            set->push(set->top+1);
        }
    }
    cout << "Unloading set of dishes #" << set->pop() << endl;
}