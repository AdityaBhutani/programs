#include <iostream>
#include <vector>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
};

//IMP: if  we need to assign this pointer to another,
//we should use double pointer,which we are passing as the parameter.
void delete_entire_linked_list(Node **head){
	Node *next_node, *current_node;
	current_node = *head;
	while(current_node!=NULL){
		next_node = current_node -> next;
		free(current_node);
		current_node = next_node;
	}
	free(next_node);
	*head = NULL;
}

void find_middle_node_of_linked_list(Node **head){
	Node *single_jump, *double_jump;
	single_jump = *head, double_jump = *head;
	while(double_jump -> next != NULL){
		if(double_jump -> next -> next != NULL){
			double_jump = double_jump -> next -> next;
		}else{
			double_jump = double_jump -> next;
		}
		single_jump = single_jump -> next;
	}
	cout << "The middle node of the linked list is = " <<single_jump -> data << endl;
}

bool search_linked_list_iteratively(Node *current_node, int search_val){
	while(current_node!=NULL){
		if(current_node->data == search_val){
			cout << "FOUND VALUE ITERATIVELY= " << search_val << endl;
			return true;
		}
		current_node = current_node -> next;
	}
	cout << "COULDN'T FIND VALUE ITERATIVELY= " << search_val << endl;	
	return false;
}

bool search_linked_list_recursively(Node *current_node, int search_val){
	if(current_node == NULL){
		cout << "COULDN'T FIND VALUE RECURSIVELY= " << search_val << endl;
		return false;
	}else if(current_node->data == search_val){
		cout << "FOUND VALUE RECURSIVELY= " << search_val << endl;
		return true;
	}
	return search_linked_list_recursively(current_node->next, search_val);
}

int main(){
	vector<int> arr = {1,2,3,4,5};
	Node *new_node, *current_node, *head=NULL;
	// APPEND STARTS HERE
	for(int i=0; i<arr.size(); i++){
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
	int delete_node_value = 31;
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
		prev_node = current_node;
		current_node = current_node -> next;
	}
	// DELETE FOR KEY ENDS HERE

	// delete_entire_linked_list(&head);

	search_linked_list_iteratively(head, 3);
	search_linked_list_recursively(head, 3);

	find_middle_node_of_linked_list(&head);

	// TRAVERSAL STARTS HERE
	current_node = head;
	while(current_node!=NULL){
		cout << current_node -> data << "     "; 
		current_node = current_node -> next;
	}
	// TRAVERSAL ENDS HERE
	return 0;
}