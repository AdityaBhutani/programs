https://leetcode.com/problems/min-stack/
#include <iostream>
#include <stack>
using namespace std;

// Find the smallest element in a stack in constant time complexity - O(1)
// Using one main stack for all the normal operations, secondary stack also maintained, 
// called small_stack. small_stack's top will maintain the minimum element in main stack
// At push, x will be pushed to small_stack if the value is smaller than the top element of small_stack
// At pop, if the smallest element is being popped, we'll check if it is the smallest element of the stack
// i.e., the top of small_stack, if yes pop from small_stack as well to maintain the smallest element in primary stack
class MinStack {
	public:
		stack<int> s;
		stack<int> small_stack;
	 	MinStack() {}
    
    void push(int x) {
      s.push(x);
      if(small_stack.size() == 0 || x <= small_stack.top()){
      	small_stack.push(x);
      }
    }
    
    void pop() {
    	if(s.top() == small_stack.top()){
    		small_stack.pop();
    	}
    	s.pop();
    }
    
    int top() {
    	return s.top();      
    }
    
    int getMin() {
      return small_stack.top();
    }

    bool empty(){
    	return s.empty();
    }

    int size(){
    	return s.size();
    }

};

void show_stack(MinStack st){
	while(st.size() > 0){
		cout << st.top() << endl;
		st.pop();
	}
}

int main(){
	MinStack st;
	st.push(0);
	st.push(1);
	st.push(0);
	st.pop();
	show_stack(st);		
	cout << "GET MIN = ";
	cout << st.getMin() << "\t";	
	// st.pop();
	// cout << st.getMin() << "\t";	
	// st.pop();
	// cout << st.getMin() << "\t";	
  return 0;
}