#include<iostream>
using namespace std;

void square_call_by_value(int n){
	n = n*n;
}

void square_call_by_reference_with_pointer_args(int *n){
	*n = *n * *n;
}

void square_call_by_reference_with_reference_args(int &n){
	n = n*n;
}

int main(){
	int n = 10;
	square_call_by_value(n);
	cout << n << endl;
	n = 10;
	square_call_by_reference_with_pointer_args(&n);
	cout << n << endl;
	n = 10;
	square_call_by_reference_with_reference_args(n);
	cout << n;
}