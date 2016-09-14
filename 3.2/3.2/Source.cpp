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
		Node(Node* next, int data)
			: next(next)
			, data(data)
		{}
	};

	Node *top = NULL;
	Node *top_temp = NULL;

public:

	int count = 0;
	int min_val = NULL;

	Stack(){
	}

	void push(int a){
		min(a);
		if (top){
			Node *temp = new Node(top, a);
			top = temp;
		}
		else{
			top = new Node(NULL, a);
		}
		count++;
	}

	void pop(){
		top_temp = top;

		if (top_temp){
			top_temp = top_temp->next;
			cout << "Popping... " << top->data << "\n";
			free(top); 
			top = top_temp;
			count--;
		}
		else{
			cout << "Empty stack\n";
			return;
		}
	}

	void min(int a){
		if (min_val){
			if (min_val > a){
				min_val = a;
			}
		}
		else{
			min_val = a;
		}
		cout << "MINIMUM VAL: " << min_val << endl;
	}
};

int main(){
	Stack a;

	a.push(3);
	a.push(10);
	a.push(15);

	a.pop();
	a.pop();
	a.pop();

	system("pause");
	return 0;
}
