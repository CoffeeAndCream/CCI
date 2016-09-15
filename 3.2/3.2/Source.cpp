/*Cracking the Coding Interview
Chapter 3
Interview Question 3.2
How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time.

NOTES:
	1. STACK STRUCTURE USING LINKED LISTS
*/

#include <iostream>
#define MAX 100

using namespace std;


class Stack
{
private:
	struct Node{
		Node *next;
		int data;
		Node(Node* next, int data)
			: next(next)
			, data(data)
		{}
	};

	Node *top = NULL;
	Node *top_temp = NULL;

public:

	int count = 0;

	Stack(){
	}

	void push(int a){
		if (top){
			Node *temp = new Node(top, a);
			top = temp;
		}
		else{
			top = new Node(NULL, a);
		}
	}

	void pop(){
		top_temp = top;

		if (top_temp){
			top_temp = top_temp->next;
			cout << "Popping... " << top->data << "\n";
			free(top); 
			top = top_temp;
		}
		else{
			cout << "Empty stack\n";
			return;
		}
	}
};


class Stack_for_Min {

	int arr[MAX];
	int count = 0;

	public:

		Stack_for_Min(){
		}
	
		void push(int value){
			count++;
			arr[count] = value;
		}

		void pop(){
			count--;
		}

		void display(){
			cout << "Minimum... " << arr[count] << endl;
		}
};


int main(){
	Stack a;
	Stack_for_Min min;

	a.push(3);
	a.push(10);
	a.push(15);

	a.pop();
	a.pop();
	a.pop();

	a.push(100);
	a.push(20);

	system("pause");
	return 0;
}
