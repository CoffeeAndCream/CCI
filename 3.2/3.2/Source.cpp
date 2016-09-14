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
	Node *top = (struct Node *)malloc(1 * sizeof(struct Node));
	Node *top_temp = (struct Node *)malloc(1 * sizeof(struct Node));

public:

	int count = 0;

	Stack(){
	}

	void push(int a){
		if (top == NULL)
		{
			top->next = NULL;
			top->data = a;
		}
		else
		{
			Node *temp = (struct Node *)malloc(1 * sizeof(struct Node));
			temp->next = top;
			temp->data = a;
			top = temp;
		}
		count++;
	}

	void pop(){
		top_temp = top;

		if (top_temp == NULL){
			cout << "Empty stack\n";
			return;
		}
		else{
			top_temp = top_temp->next;
			cout << "Popping... " << top->data << "\n";
			free(top);
			top = top_temp;
			count--;
		}
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
