/*Cracking the Coding Interview
Chapter 4
Interview Question 4.1
Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree 
is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.
*/


#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>

using namespace std;

class BinaryTree
{
	private:
		struct node{
			int data;
			node *left;
			node *right;

			node(int data = 0)
				: data(data){
				left = NULL;
				right = NULL;
			}
		};
	public:
		BinaryTree(){	//constructor
		}

		node *root = NULL;

		void insert(node *&root, int data){
			if (root){
				if (data < root->data){
					insert(root->left, data);
				}
				else{
					insert(root->right, data);
				}
			}
			else{
				root = new node(data);
				return;
			}
		}

		void postorder(node *&root, int indent = 0){
			if (root != NULL) {
				if (root->right) {
					postorder(root->right, indent + 4);
				}
				if (indent) {
					cout << setw(indent) << ' ';
				}
				if (root->right) {
					cout << " /\n" << setw(indent) << ' ';
				}
				cout << root->data << "\n ";
				if (root->left) {
					cout << setw(indent) << ' ' << " \\\n";
					postorder(root->left, indent + 4);
				}
			}
		}
		int getHeight(node *root){
			if (root == NULL)return 0;
			return (1 + max(getHeight(root->left), getHeight(root->right)));
		}

		bool isBalancedNaive(node *root){
			if (root == NULL){
				return true;
			}
			int heightdifference = getHeight(root->left) - getHeight(root->right);
			if (abs(heightdifference)>1){
				return false;
			}
			else{
				return isBalancedNaive(root->left) && isBalancedNaive(root->right);
			}
		}
};

int main(){

	BinaryTree a, b;

	a.insert(a.root, 5);
	a.insert(a.root, 2);
	a.insert(a.root, 6);
	a.insert(a.root, 10);
	a.insert(a.root, 15);

	b.insert(b.root, 5);
	b.insert(b.root, 2);
	b.insert(b.root, 6);

	cout << "\nTree 'A'\n\n";
	a.postorder(a.root);
	cout << "Tree is balanced: " << a.isBalancedNaive(a.root) << endl;

	cout << "\nTree 'B'\n\n";
	b.postorder(b.root);
	cout << "Tree is balanced: " << b.isBalancedNaive(b.root) << endl;

	system("pause");
	return 0;
}