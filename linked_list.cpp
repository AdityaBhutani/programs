#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
};

int main(){
	int arr[] = {1,2,3,4,5};
	Node *new_node, *current_node, *head=NULL;
	// APPEND STARTS HERE
	for(int i=0; i<5;i++){
		new_node = new Node();
		new_node -> data = arr[i];
		new_node -> next = NULL;
		if(head == NULL){
			head = new_node;
			current_node = new_node;
		}
		else{
			current_node -> next = new_node;
			current_node = new_node;
		}
	};
	// APPEND ENDS HERE

	// DELETE FOR KEY STARTS HERE
	int delete_node_value = 3;
	Node *prev_node;
	current_node = head, prev_node = NULL;
	while(current_node != NULL){		
		if(prev_node == NULL && current_node -> data == delete_node_value){			
			head = current_node -> next;
			free(current_node);
		}
		else if(current_node -> data == delete_node_value){			
			prev_node -> next = current_node -> next;
			free(current_node);
		}
		else{
			prev_node = current_node;			
		}
		current_node = current_node -> next;
	}
	// DELETE FOR KEY ENDS HERE

	// TRAVERSAL STARTS HERE
	current_node = head;
	while(current_node!=NULL){
		cout << current_node -> data << "     "; 
		current_node = current_node -> next;
	}
	// TRAVERSAL ENDS HERE
	return 0;
}