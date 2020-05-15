#include <iostream>
using namespace std;

// INSERTION SORT
// ARR[i] BECOMES KEY, IT'S CHECKED WITH PREVIOUS ELEMENTS FOR COMPARISON CONDITION
// IF COMPARISON CONDITION HOLDS TRUE, IE., ARR[i] < ANY PREVIOUS ELEMENT
// WE SWAP POSITION OF BOTH THE ELEMENTS(ARR[i] AND PREVIOUS ELEMENT)

// WORST CASE TIME COMPLEXITY FOR VANILLA INSERTION SORT IS O(n^2)

void insertion_sort(int arr[], int n){
	int swap_temp, key, k;
	for(int i=1; i<n; i++){
		key = arr[i];
		k=0;
		for(int j=i-1; j>=0; j--){			
			if(key < arr[j]){		
				// swapping with i-k as with each swap, the position of the key changes
				swap_temp = arr[i-k];
				arr[i-k] = arr[j];
				arr[j] = swap_temp;
				k++;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout << arr[i] << endl;
	}
}

int main(){
	int arr[6] = {5,2,4,6,1,3};
	insertion_sort(arr, 6);
}