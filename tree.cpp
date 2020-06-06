#include <iostream>
using namespace std;

class BST{
	int key;
	BST *left, *right;

	public:
	// Basic Constructor, if not added, program gives errors
	BST(){
		key = 0;
		left = right = NULL;
	}
	// Constructor which acts to create a new Node
	BST(int val){
		key = val;
		left = right = NULL;
	}

	BST* insert(BST *parent, int val){
		if(parent == NULL){
			return new BST(val);
		}
		if (val <= parent -> key ){
			parent -> left = insert(parent -> left, val);
		}else{
			parent -> right = insert(parent -> right, val);
		}
		return parent;
	}

	void inorder(BST *root){
		if(root == NULL){
			return;
		}
		inorder(root -> left);
		cout << root -> key << endl;
		inorder(root -> right);
	}

	BST* search(BST *root, int val){
		if(root == NULL){
			cout << "Value not Found" << endl;
			return root;
		}
		if(root -> key == val){
			cout << "Value Found" << endl;
			return root;
		}	
		if(val < root -> key){
			return search(root -> left, val);
		}else{
			return search(root -> right, val);
		}
	}
};

int main(){
	BST tree, *root = NULL;
	root = tree.insert(root, 20);
	tree.insert(root, 30);
	tree.insert(root, 10);
	tree.search(root, 12);
	tree.inorder(root);
	// tree.search(root, 30);
}