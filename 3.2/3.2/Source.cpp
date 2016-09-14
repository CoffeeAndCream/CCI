/*Cracking the Coding Interview
Chapter 3
Interview Question 3.2
How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time.

NOTES:
	1. STACK STRUCTURE USING LINKED LISTS
*/

#include <iostream>

using namespace std;


class Stack
{
private:
	struct Node{
		Node *next;
		int data;
	}; Node *root = new Node;

public:
	Stack(){
		root->next = NULL;
	}

	void push(int a){
		Node *temp = root;
		Node *node = new Node;
		node->data = a;
		node->next = NULL;

		while (temp->next){
			temp = temp->next;
		}
		temp->next = node;
	}

	int pop(){
		Node *temp = root;
		if (temp->next){
			while (temp->next->next){
				temp = temp->next;
			}

			int data = temp->next->data;
			temp->next = NULL;
			return data;
		}
		else{
			cout << "Stack empty\n";
			return -1;
		}
	}
};

int main(){
	Stack a;

	a.push(3);
	a.push(10);
	a.push(15);

	cout << a.pop() << " is popped\n";
	cout << a.pop() << " is popped\n";
	cout << a.pop() << " is popped\n";

	system("pause");
	return 0;
}
