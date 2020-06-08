#include <iostream>
using namespace std;

struct TreeNode{
	int key;
	TreeNode *left, *right, *parent;
};

TreeNode* new_tree_node(int val){
	TreeNode *new_node;
	new_node = new TreeNode();
	new_node -> key = val;
	new_node -> left = NULL;
	new_node -> right = NULL;
	new_node -> parent	= NULL;
	return new_node;
}

// inserting values and setting left, right and parent pointer
TreeNode* insert(TreeNode *predecessor, TreeNode *node, int val){
	if(node == NULL){
		TreeNode *new_node;
		new_node = new_tree_node(val);
		new_node -> parent = predecessor;
		return new_node;
	}
	if(val <= node -> key){
		TreeNode *left_child;
		left_child = insert(node, node -> left, val);
		node -> left = left_child;
		left_child -> parent = node;
	}else{
		TreeNode *right_child;
		right_child = insert(node, node -> right, val);
		node -> right = right_child;
		right_child -> parent = node;
	}
	return node;
}

void inorder(TreeNode *root){
	if(root == NULL){
		return;
	}
	inorder(root -> left);
	cout << root -> key << endl;
	inorder(root -> right);
}

TreeNode* search(TreeNode *root, int val){
	if(root == NULL){
		cout << "value not found";
		return root;
	}
	if(root -> key == val){
		cout << "Value found";		
		return root;
	}
	if(val <= root -> key){
		return search(root -> left, val);
	}else{
		return search(root -> right, val);
	}
}

// finding the next max value for a given val. First searching the val.
// On finding the val, if node has right child, then it is the next max.
// If node doesnt have right child, check if parent exists, if it does then it will be the next max
TreeNode* find_next_max(TreeNode *node, int val){
	if(node == NULL){
		cout << "value not found";
		// exit();
		return node;
	}
	if(node -> key == val){
		if(node -> right != NULL){
			cout << "Number searched = " << node -> key << ", Next Max = " << node -> right -> key;
			return node -> right;
		}
		if(node -> parent != NULL){
			cout << "Number searched = " << node -> key << ", Next Max = " << node -> parent -> key;
			return node -> parent;
		}
		cout << "if we reached here, we are finding next_max for root which doesnt have right subtree";
		return node;
	}
	if(val <= node -> key){
		return find_next_max(node -> left, val);
	}else{
		return find_next_max(node -> right, val);
	}
}

int main(){
	TreeNode *root = NULL;
	TreeNode *node;
	root = insert(root, root, 20);
	node = insert(root, root, 10);
	node = insert(root, root, 30);
	inorder(root);
	// search(root, 20);
	find_next_max(root, 30);
	return 0;
}