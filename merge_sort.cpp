// https://www.geeksforgeeks.org/merge-sort/
#include <iostream>
#include <vector>
using namespace std;
// Merge Sort is a divide and conuqer algorithm

// We compare the values in the left sub array and right sub array, which are divided by the mid element
// computed in merge_sort function.
void merge(int arr[], int start, int mid, int end){
	int l_arr_length = mid-start+1;
	int r_arr_length = end-mid;
	int l_index = 0;
	int r_index = 0;
	int arr_index = start;
	int L[l_arr_length], R[r_arr_length];

	// Creating left sub array
	for(int i=0; i<l_arr_length;i++){		
		L[i] = arr[start + i];
	}
	// Creating right sub array
	for(int i=0; i<r_arr_length;i++){
		R[i] = arr[mid + 1 + i];
	}

	// comparing values in left and right array and setting values in the main sub array for the recursion
	while(l_index < l_arr_length && r_index < r_arr_length){
		if(L[l_index] <= R[r_index]){
			arr[arr_index] = L[l_index];
			l_index++;
		}else{
			arr[arr_index] = R[r_index];
			r_index++;
		}
		arr_index++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while(l_index < l_arr_length){
		arr[arr_index] = L[l_index];
		l_index++;
		arr_index++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while(r_index < r_arr_length){
		arr[arr_index] = R[r_index];
		r_index++;
		arr_index++;
	}

}

void merge_sort(int arr[], int start, int end){
	if (start < end){
		int mid = start + (end-start)/2;
		
		// Left subarray, it is recursively called till the last call which returns and generates 
		// returns on it's way up to the first call. This means, merge_sort is called for left subarray 
		// for each array till its last(base) condition, ie., "start < end". We solve the smallest subarray 
		// ie., the one which is generated at the last. This merge_sort call
		merge_sort(arr, start, mid); 
		// Right Sub array, recursively called, reaches the last/base condition and returns values one by one
		// for each recursion until it returns value for the first call. The calling of the method is 
		// top to bottom, the return of the result is bottom to up.
		merge_sort(arr, mid+1, end);
		// This merges the left and right sub array at each recursion
		merge(arr, start, mid, end);
	}
}

int main(){
	int arr[] = {12, 11, 13, 5, 6, 7}; 
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0; i<n; i++){
 		cout << arr[i] << ", ";
 	}
	merge_sort(arr, 0, n - 1); 	 	
	cout << endl << endl;
	for(int i=0; i<n; i++){
 		cout << arr[i] << ", ";
 	}
}