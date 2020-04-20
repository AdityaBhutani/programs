// https://leetcode.com/problems/merge-two-sorted-lists/
#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
};

// Creating new linked list which will be appended values from sorted linked lists - l1 and l2 by comaparing their values
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode *cnl1 = l1, *cnl2 = l2;
  ListNode *new_head = NULL, *cn_new_list = NULL;
  ListNode *new_node;
  int cnl1_val, cnl2_val;
  
  while(cnl1 != NULL || cnl2 != NULL){
    if(cnl1 != NULL){
      cnl1_val = cnl1->val;
    }else{
      cnl1_val = INT_MAX;
    }
    if(cnl2 != NULL){
      cnl2_val = cnl2->val;
    }else{
      cnl2_val = INT_MAX;
    }
    if(cnl1 != NULL && cnl1_val <= cnl2_val){
      new_node = new ListNode();
      new_node->val = cnl1_val;
      new_node->next = NULL;
      if(new_head == NULL){
        new_head = new_node;
        cn_new_list = new_node;
      }else{
        cn_new_list->next = new_node;
        cn_new_list = new_node;
      }
      cnl1 = cnl1->next;
    }
    else if(cnl2 != NULL && cnl2_val < cnl1_val){
      new_node = new ListNode();
      new_node->val = cnl2_val;
      new_node->next = NULL;
      if(new_head == NULL){
        new_head = new_node;
        cn_new_list = new_node;
      }else{
        cn_new_list->next = new_node;
        cn_new_list = new_node;
      }
      cnl2 = cnl2->next;
    }                                                         
  }
  cn_new_list = new_head;
  while(cn_new_list != NULL){
    cout << cn_new_list->val;
    cn_new_list = cn_new_list->next;
  }
  return new_head;
}

int main(){
  //creating testing linked lists
  // Linked List 1
  ListNode *new_node, *l1=NULL, *l2=NULL, *cn_l1=NULL, *cn_l2=NULL;
  vector<int> l1_vals = {1,2,4};
  vector<char> l2_vals = {1,3,4};
  for(int i=0; i<l1_vals.size(); i++){
    new_node = new ListNode();
    new_node->val = l1_vals[i];
    new_node->next = NULL;
    if (l1 == NULL){
      l1 = new_node;
      cn_l1 = new_node;
    }
    else{
      cn_l1->next = new_node;
      cn_l1 = new_node;
    }
  }
  for(int i=0; i<l2_vals.size(); i++){
    new_node = new ListNode();
    new_node->val = l2_vals[i];
    new_node->next = NULL;
    if (l2 == NULL){
      l2 = new_node;
      cn_l2 = new_node;
    }
    else{
      cn_l2->next = new_node;
      cn_l2 = new_node;
    }
  }


  mergeTwoLists(l1, l2);


  return 0;
}