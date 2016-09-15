/*Cracking the Coding Interview
Chapter 3
Interview Question 3.5
Implement a MyQueue class which implements a queue using two stacks.
*/

#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct sNode{
	int data;
	struct sNode *next;
};

struct queue{
	struct sNode *stack1;
};

void push(struct sNode** top_ref, int new_data);
int pop(struct sNode** top_ref);

void enQueue(struct queue *q, int x){
	push(&q->stack1, x);
}

int deQueue(struct queue *q){
	int x, res;

	if (q->stack1 == NULL){
		printf("Q is empty");
		getchar();
		exit(0);
	}
	else if (q->stack1->next == NULL){
		return pop(&q->stack1);
	}
	else{
		/* pop an item from the stack1 */
		x = pop(&q->stack1);

		/* store the last dequeued item */
		res = deQueue(q);

		/* push everything back to stack1 */
		push(&q->stack1, x);

		return res;
	}
}

void push(struct sNode** top_ref, int new_data){
	/* allocate node */
	struct sNode* new_node =
		(struct sNode*) malloc(sizeof(struct sNode));

	if (new_node == NULL){
		printf("Stack overflow \n");
		getchar();
		exit(0);
	}

	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

/* Function to pop an item from stack*/
int pop(struct sNode** top_ref){
	int res;
	struct sNode *top;

	/*If stack is empty then error */
	if (*top_ref == NULL){
		printf("Stack overflow \n");
		getchar();
		exit(0);
	}
	else{
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

/* Driver function to test above functions */
int main(){
	/* Create a queue with items 1 2 3*/
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->stack1 = NULL;
	cout << "Queueing up the line...\n\n";
	cout << "1, 2, 3!\n";
	enQueue(q, 1);
	enQueue(q, 2);
	enQueue(q, 3);

	/* Dequeue items */
	cout << "Queue " << deQueue(q) << endl;
	cout << "Queue " << deQueue(q) << endl;
	cout << "Queue " << deQueue(q) << endl;

	system("pause");
	return 0;
}