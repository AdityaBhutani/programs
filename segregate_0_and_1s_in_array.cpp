#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> vect = {0, 1, 0, 1, 0, 1, 0, 1, 0};
	int count_zero = 0;
	for(int i=0; i<vect.size(); i++){
		if(vect[i] == 0){
			count_zero = count_zero + 1;
		}
	}
	vect.assign(vect.size(), 1);
	for(int i=0; i<count_zero; i++){
		vect[i] = 0;
	}
	// for(int i=0; i<vect.size(); i++){
	// 	cout << vect[i];
	// }
	for(int x : vect){
		cout << x;
	}
	return 0;
}