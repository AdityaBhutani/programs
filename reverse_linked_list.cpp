// https://leetcode.com/problems/reverse-linked-list
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
};

// We'll create new linked list - the first node of given linked list will be made last node 
// of new linked list and so on
// Iterate the given Linked List(head), create new_node at each iteration assign prev_node = new_node
// In the next iteration on given LL, create new_node whose next will be assigned as the 
// prev_node(which was set in the previous iteration), this is continues till cn!=NULL 

ListNode* reverseList(ListNode* head) {
	ListNode *new_head=NULL, *cn=head, *new_node, *prev_node;
	while(cn!=NULL){
		if(cn == head){
			new_node = new ListNode();
			new_node -> val = cn -> val;
			new_node -> next = NULL;
			prev_node = new_node;
			cn = cn -> next;
		}else{
			new_node = new ListNode();
			new_node -> val = cn -> val;
			new_node -> next = prev_node;
			prev_node = new_node;
			cn = cn -> next;
		}
	}
	new_head = prev_node;
  return new_head;
}

int main(){
	ListNode *head = NULL, *new_node, *cn = head;
	int input[5] = {1,2,3,4,5};
	for(int i=0; i< 5; i++){
		new_node = new ListNode();
		new_node -> val = input[i];
		new_node -> next = NULL;
		if(head == NULL){
			head = new_node;
			cn = new_node;
		}else{
			cn -> next = new_node;
			cn = new_node;
		}
	}
	// cn = head;
	// while(cn!=NULL){
	// 	cout << cn->val << "\t";
	// 	cn = cn->next;
	// }

	cn = reverseList(head);
	while(cn!=NULL){
		cout << cn->val << "\t";
		cn = cn->next;
	}
	return 0;	
}