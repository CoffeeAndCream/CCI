/*Cracking the Coding Interview
Chapter 2
Interview Question 2.2
Find the kth to the last element of a linked list*/

#include <iostream>

using namespace std;

#include <iostream>
#include <map>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Node;
void Print();
void Add();
void RemoveDup();
void FindK(int);

struct Node{
	int data;
	Node *next;
};  Node *root = new Node;

int main(){
	root->next = NULL;
	root->data = 0;

	int k = 5;

	srand(time(NULL));
	for (int i = 0; i < 10; i++){
		Add();
	}
	Print();
	cout << "\n";
	FindK(k);
	system("pause");
	return 0;
}

void Print(){
	Node *temp = root;
	while (temp->next){
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL\n";
}

void Add(){
	Node *add = new Node;
	Node *temp = root;

	int num = rand() % 10;
	add->data = num;
	add->next = NULL;

	if (temp->next){
		while (temp->next){
			temp = temp->next;
		}
		temp->next = add;
	}
	else{
		cout << "Empty list\n";
		temp->next = add;
	}
}

void RemoveDup(){
	if (root){
		Node* current = root;
		Node* runner;

		while (current){
			runner = current;
			while (runner->next){
				if (current->data == runner->next->data){
					Node* temp = runner->next;
					runner->next = runner->next->next;
					cout << "Duplicate Found: " << temp->data << " removed" << endl;
					delete temp;
				}
				else{
					runner = runner->next;
				}
			}
			current = current->next;
		}
	}
}

void FindK(int k){
	Node *temp = root;
	
	for (int i = 0; i < k; i++){
		temp = temp->next;
	}

	while (temp->next){
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL\n";
}