/*Cracking the Coding Interview
Chapter 4
Interview Question 4.1
Implement a function to check if a binary tree is balanced. For the purposes of this question, a balanced tree 
is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.
*/

#include <iostream>

using namespace std;

class Tree{
	private:
		struct TreeNode {
			int item;         // The data in this node.
			TreeNode *left;   // Pointer to the left subtree.
			TreeNode *right;  // Pointer to the right subtree.

			TreeNode(TreeNode* left = NULL, TreeNode* right = NULL, int item = 0)
				: left(left)
				, right(right)
				, item(item)
			{}
		};

	public:
		Tree(){	}

		TreeNode *root = new TreeNode(0);

		void treeInsert(TreeNode *&root, int item) {
			if (root == NULL) {
				root = new TreeNode(NULL, NULL, item);	
				return;
			}
			else if (item < root->item) {
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
};

int main(){
	Tree a;
	for (int i = 0; i < 6; i++){
		a.treeInsert(a.root, i);
	}
	a.postorderPrint(a.root);
	system("pause");
	return 0;
}


