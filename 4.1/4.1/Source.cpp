/*Cracking the Coding Interview
Chapter 4
Interview Question 4.1
Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree 
is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class Tree{
	private:
		struct TreeNode {
			int item;         // The data in this node.
			TreeNode *left;   // Pointer to the left subtree.
			TreeNode *right;  // Pointer to the right subtree.

			TreeNode(int item = 0)
				:  item(item)
			{
				left, right = NULL;
			}
			
		};

	public:
		Tree(){	}

		TreeNode *root = NULL;

		void treeInsert(TreeNode *&root, int item) {
			if (root == NULL) {
				root = new TreeNode(item);
				return;
			}
			else if (item > root->item) {
				treeInsert(root->left, item);
			}
			else {
				treeInsert(root->right, item);
			}
		}  

		void postorderPrint(TreeNode *root) {
			if (root) {
				postorderPrint(root->left);
				postorderPrint(root->right);
				cout << "Node: " << root->item << " \n";
			}
		} 

		void inorderPrint(TreeNode *root) {     
			if (root){
				inorderPrint(root->left);
				cout << "Node: " << root->item << endl;     
				inorderPrint(root->right); 
			}
    	 }
	 
		int size(TreeNode *root) { 
			if (root == NULL) { 
				return(0); 
			} 
			else { 
				return(size(root->left) + 1 + size(root->right)); 
			} 
		} 

		int maxDepth(TreeNode* root) { 
			if (root==NULL) { 
				return(0); 
			} 
			else { 
				int lDepth = maxDepth(root->left); 
				int rDepth = maxDepth(root->right);

				if (lDepth > rDepth) return(lDepth+1); 
				else return(rDepth+1); 
			} 
		} 
};

int main(){
	Tree a;
	srand(time(NULL));
	
	for (int i = 0; i < 6; i++){
		a.treeInsert(a.root, rand()%10);
	}
	a.postorderPrint(a.root);
	return 0;
}


