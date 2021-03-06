#include <iostream>
#include <vector>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
};

//IMP: if  we need to assign this pointer to another, WAY 1
//we should use double pointer,which we are accepting as the parameter when defining
//we are passing the address of the pointer when calling
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

//IMP: if  we need to assign this pointer to another, WAY 2
//function definition should accept pointer address, i.e., accepting address of pointer when defining
//when called we pass the pointer
int pairwise_swap_elements(Node &head){
	//https://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/
	Node *first_in_pair, *second_in_pair;
	first_in_pair = &head;
	second_in_pair = first_in_pair -> next;
	int temp;
	while(second_in_pair!=NULL){		
		temp = first_in_pair -> data;
		first_in_pair -> data = second_in_pair -> data;
		second_in_pair -> data = temp;
		if (second_in_pair -> next != NULL){
			first_in_pair = second_in_pair -> next;
			second_in_pair = first_in_pair -> next;
		}else{
			return 0;
		}
	}
	return 0;
}

int count_repetition_of_node_data(Node *head, int key){
	//https://www.geeksforgeeks.org/write-a-function-that-counts-the-number-of-times-a-given-int-occurs-in-a-linked-list/
	if(head != NULL){
		if(head -> data == key){
			return 1 + count_repetition_of_node_data(head -> next, key);
		}
		else{
			return count_repetition_of_node_data(head -> next, key);
		}
	}else{
		return 0;
	}
}

void find_middle_node_of_linked_list_using_2_pointers(Node **head){
	Node *single_jump_ptr, *double_jump_ptr;
	single_jump_ptr = *head, double_jump_ptr = *head;
	while(double_jump_ptr -> next != NULL){
		if(double_jump_ptr -> next -> next != NULL){
			double_jump_ptr = double_jump_ptr -> next -> next;
		}else{
			double_jump_ptr = double_jump_ptr -> next;
		}
		single_jump_ptr = single_jump_ptr -> next;
	}
	cout << "The middle node of the linked list is = " <<single_jump_ptr -> data << endl;
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
	vector<int> arr = {1};
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

	find_middle_node_of_linked_list_using_2_pointers(&head);

	cout << "COUNT OF 1 = " <<count_repetition_of_node_data(head, 1) << endl;

	cout << endl << "BEFORE PAIR WISE ELEMENT SWAPPING" << endl;

	current_node = head;
	while(current_node!=NULL){
		cout << current_node -> data << "     "; 
		current_node = current_node -> next;
	}

	pairwise_swap_elements(*head);

	cout << endl << "AFTER PAIR WISE ELEMENT SWAPPING" << endl;
	// TRAVERSAL STARTS HERE
	current_node = head;
	while(current_node!=NULL){
		cout << current_node -> data << "     "; 
		current_node = current_node -> next;
	}
	// TRAVERSAL ENDS HERE
	return 0;
}